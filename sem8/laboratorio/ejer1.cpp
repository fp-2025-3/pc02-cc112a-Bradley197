#include<iostream>
#include<fsttream>
using namespace std;
struct CuentaBancaria {
    int numeroCuenta;
    char titular[40];
    double saldo;
    bool activa;
};
void abrirArchivo(fstream& archivo){
    archivo.open("cuentas.dat", ios::binary|ios::out|ios::in);   
    if(!archivo){
        archivo.open("cuentas.dat", ios::binary|ios::out);
        archivo.close();
        archivo.open("cuentas.dat", ios::binary|ios::out|ios::in);

    }
}
void crearArchivo(int N){
    fstream archivo;
    abrirArchivo(archivo);

    CuentaBancaria cuenta;
    for(int i=0;i<cuenta.numeroCuenta;i++){
        cout<<endl<<"Numero de cuenta "<<endl;
        cin>>cuenta.numeroCuenta;

        int ṕosicion=sizeof(CuentaBancaria)*(cuenta.numeroCuenta-1);
        archivo.seekg(posicion);
        CuentaBancaria temp;
        archivo.read((char*)&temp,sizeof(CuentaBancaria));
        if(archivo){
            cout<<"La cuenta ya existe "<<endl;
            i--;
        }else{
            archivo.clear();
            archivo.seekp(posicion);
            cout<<"Titular :"<<endl;
            cin>>cuenta.titular;
            cout<<"Saldo :"<<endl;
            cin>>cuenta.saldo;
            cuenta.activa=true;
            archivo.write((char*)&cuenta,sizeof(CuentaBancaria));

        }
    }
    archivo.close();
    cout<<"Archivo creado"<<endl;

}
bool buscarCuenta(int numeroCuenta, CuentaBancaria& resultado, int&posicion){
    fstream archivo;
    abrirArchivo(archivo);

    posicion=sizeof(CuentaBancaria)*(numeroCuenta-1);
    archivo.seekg(posicion);
    archivo.read((char*)&resultado, sizeof(CuentaBancaria));

    if(!archivo){
        archivo.close();
        return false;
    }
    archivo.close();
    return resultado.numeroCuenta==numeroCuenta;
}

void operacion(){
    int num;
    cout<<"Ingrese el numero de cuenta: "<<endl;
    cin>>num;
    CuentaBancaria cuenta;
    int posicion;

    if(!buscarCuenta(num,cuenta,posicion)){
        cout<<"Cuenta no encontrada"<<endl;
        return;
    }
    if(!cuenta.activa){
        cout<<"La cuenta esta inactiva"<<endl;
        return;
    }
    cout<<"Titular: "<<cuenta.titular<<endl;
    cout<<"Saldo Actual"<<cuenta.saldo<<endl;
    cout<<"1.Depositar "<<endl;
    cout<<"2.Retirar "<<endl;
    int opcion;
    cin>>opcion;
    double monto;
    cout<<"Monto: "<<endl;
    cin>>monto;
    if(opcion==1){
        monto+=cuenta.saldo;
    }
    if(opcion==2){
        if(cuenta.saldo-monto<0){
            cout<<"Saldo Insuficiente probre "<<endl;
            return ;
        }else{
           monto=cuenta.saldo-monto; 
        }
    }
    fstream archivo;
    abrirArchivo(archivo);
    archivo.seekp(posicion);
    archivo.write((const char*)&cuenta, sizeof(CuentaBancaria));
    archivo.close();
    cout << "Operacion realizada. Nuevo saldo: " << cuenta.saldo << endl;
}
void desactivarCuenta(){
    int num;
    cout<<"Ingrese numero de cuenta a desactivar"<<endl;
    cin>>num;
    CuentaBancaria=cuenta;
    int posicion;
    if(!buscarCuenta(num,cuenta,posicion)){
        cout<<"La cuenta no existe"<<endl;
        return;
    }
    if(!cuenta.activa){
        cout<<"La cuenta ya estaba inactica"<<endl;
        return ;
    }
    cuenta.activa=false;
    fstream archivo;
    abrirArchivo(archivo);
    archivo.seekp(archivo);
    archivo.write((const char*)&cuenta, sizeof(CuentaBancaria));
    archivo.close();
}
void mostrarCuenta(){
    fstream archivo;
    abrirArchivo(archivo);
    CuentaBancaria cuenta;
    int encontradas=0;

    archivo.seekg(0,ios::beg);
    while(archivo.read((char*)&cuenta, sizeof(CuentaBancaria))){
        if(cuenta.activa){
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
int main(){
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

    return 0;
}