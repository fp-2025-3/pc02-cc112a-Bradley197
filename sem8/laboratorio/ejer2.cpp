#include <iostream>
#include <fstream>
using namespace std;

struct CuentaBancaria {
    int numeroCuenta;
    char titular[40];
    double saldo;
    bool activa;
};

// ======================== FUNCION AUXILIAR ========================
void abrirArchivo(fstream& archivo) {
    archivo.open("cuentas.dat", ios::binary | ios::out | ios::in);
    if (!archivo) {
        archivo.open("cuentas.dat", ios::out | ios::binary);
        archivo.close();
        archivo.open("cuentas.dat", ios::binary | ios::out | ios::in);
    }
}

// ======================== FUNCION 1 ========================
void crearArchivo(int N) {
    fstream archivo;
    abrirArchivo(archivo);

    CuentaBancaria cuenta;
    for (int i = 0; i < N; ++i) {
        cout << "\nNumero de cuenta: ";
        cin >> cuenta.numeroCuenta;

        int posicion = sizeof(CuentaBancaria) * (cuenta.numeroCuenta - 1);

        archivo.seekg(posicion);
        CuentaBancaria temp;
        archivo.read((char*)&temp, sizeof(CuentaBancaria));

        if (archivo) {
            cout << "Ya existe una cuenta con este numero." << endl;
            i--;
        } else {
            archivo.clear();
            archivo.seekp(posicion);
            cout << "Titular: "; cin >> cuenta.titular;
            cout << "Saldo: ";   cin >> cuenta.saldo;
            cuenta.activa = true;
            archivo.write((char*)&cuenta, sizeof(CuentaBancaria));
        }
    }
    archivo.close();
    cout << "Archivo creado correctamente." << endl;
}

// ======================== FUNCION 2 ========================
bool buscarCuenta(int numeroCuenta, CuentaBancaria& resultado, int& posicion) {
    fstream archivo;
    abrirArchivo(archivo);

    posicion = sizeof(CuentaBancaria) * (numeroCuenta - 1);

    archivo.seekg(posicion);
    archivo.read((char*)&resultado, sizeof(CuentaBancaria));

    if (!archivo) {
        archivo.close();
        return false;
    }

    archivo.close();
    return resultado.numeroCuenta == numeroCuenta;
}

// ======================== FUNCION 3 ========================
void operacion() {
    int num;
    cout << "Numero de cuenta: "; cin >> num;

    CuentaBancaria cuenta;
    int posicion;

    if (!buscarCuenta(num, cuenta, posicion)) {
        cout << "Cuenta no encontrada." << endl;
        return;
    }

    if (!cuenta.activa) {
        cout << "Cuenta inactiva. No se permiten operaciones." << endl;
        return;
    }

    cout << "Titular: "     << cuenta.titular << endl;
    cout << "Saldo actual: "<< cuenta.saldo   << endl;
    cout << "1. Depositar"  << endl;
    cout << "2. Retirar"    << endl;
    cout << "Opcion: ";
    int op; cin >> op;

    double monto;
    cout << "Monto: "; cin >> monto;

    if (op == 1) {
        cuenta.saldo += monto;
    } else if (op == 2) {
        if (cuenta.saldo - monto < 0) {
            cout << "Saldo insuficiente. No se permite saldo negativo." << endl;
            return;
        }
        cuenta.saldo -= monto;
    }

    fstream archivo;
    abrirArchivo(archivo);
    archivo.seekp(posicion);
    archivo.write((const char*)(&cuenta), sizeof(CuentaBancaria));
    archivo.close();

    cout << "Operacion realizada. Nuevo saldo: " << cuenta.saldo << endl;
}

// ======================== FUNCION 4 ========================
void desactivarCuenta() {
    int num;
    cout << "Numero de cuenta a desactivar: "; cin >> num;

    CuentaBancaria cuenta;
    int posicion;

    if (!buscarCuenta(num, cuenta, posicion)) {
        cout << "Cuenta no encontrada." << endl;
        return;
    }

    if (!cuenta.activa) {
        cout << "La cuenta ya estaba inactiva." << endl;
        return;
    }

    cuenta.activa = false;

    fstream archivo;
    abrirArchivo(archivo);
    archivo.seekp(posicion);
    archivo.write((const char*)(&cuenta), sizeof(CuentaBancaria));
    archivo.close();

    cout << "Cuenta desactivada correctamente." << endl;
}

// ======================== FUNCION 5 ========================
void mostrarActivas() {
    fstream archivo;
    abrirArchivo(archivo);

    CuentaBancaria cuenta;
    int encontradas = 0;

    archivo.seekg(0, ios::beg);
    while (archivo.read((char*)(&cuenta), sizeof(CuentaBancaria))) {
        if (cuenta.activa) {
            cout << "\nNumero:  " << cuenta.numeroCuenta << endl;
            cout << "Titular: "  << cuenta.titular      << endl;
            cout << "Saldo:   "  << cuenta.saldo        << endl;
            encontradas++;
        }
    }

    if (encontradas == 0)
        cout << "No hay cuentas activas." << endl;

    archivo.close();
}

// ======================== MAIN ========================
int main() {
    int opcion;

    do {
        cout << "\n===== SISTEMA BANCARIO =====" << endl;
        cout << "1. Crear cuentas"              << endl;
        cout << "2. Buscar cuenta"              << endl;
        cout << "3. Depositar / Retirar"        << endl;
        cout << "4. Desactivar cuenta"          << endl;
        cout << "5. Mostrar cuentas activas"    << endl;
        cout << "0. Salir"                      << endl;
        cout << "Opcion: ";
        cin  >> opcion;

        if (opcion == 1) {
            int n;
            cout << "Cuantas cuentas desea ingresar? "; cin >> n;
            crearArchivo(n);
        } else if (opcion == 2) {
            int num;
            cout << "Numero de cuenta: "; cin >> num;
            CuentaBancaria c; int pos;
            if (buscarCuenta(num, c, pos)) {
                cout << "Cuenta encontrada!"     << endl;
                cout << "Titular: " << c.titular << endl;
                cout << "Saldo:   " << c.saldo   << endl;
                cout << "Activa:  " << (c.activa ? "Si" : "No") << endl;
            } else {
                cout << "Cuenta no encontrada." << endl;
            }
        } else if (opcion == 3) {
            operacion();
        } else if (opcion == 4) {
            desactivarCuenta();
        } else if (opcion == 5) {
            mostrarActivas();
        }

    } while (opcion != 0);

    cout << "Hasta luego." << endl;
    return 0;
}
