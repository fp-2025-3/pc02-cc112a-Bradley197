
#include "Vehiculos.h"
#include <fstream>

int main() {

    const int MAX = 100;
    Vehiculo* vehiculos[MAX];
    int cantidad = 0;

    int opcion;

    do {
        cout << "\n===== SISTEMA DE VEHICULOS =====" << endl;
        cout << "1. Registrar Automovil"             << endl;
        cout << "2. Registrar Camion"                << endl;
        cout << "3. Registrar Motocicleta"           << endl;
        cout << "4. Mostrar todos los vehiculos"     << endl;
        cout << "5. Guardar en archivo"              << endl;
        cout << "6. Cargar desde archivo"            << endl;
        cout << "0. Salir"                           << endl;
        cout << "Opcion: ";
        cin  >> opcion;

        if (opcion == 1) {
            string p, m; int a; double pv; int np;
            cout << "Placa: ";        cin >> p;
            cout << "Marca: ";        cin >> m;
            cout << "Anio: ";         cin >> a;
            cout << "Precio base: ";  cin >> pv;
            cout << "Num puertas: ";  cin >> np;
            vehiculos[cantidad] = new Automovil(p, m, a, pv, np);
            cantidad++;
            cout << "Automovil registrado." << endl;

        } else if (opcion == 2) {
            string p, m; int a; double pv, cp;
            cout << "Placa: ";           cin >> p;
            cout << "Marca: ";           cin >> m;
            cout << "Anio: ";            cin >> a;
            cout << "Precio base: ";     cin >> pv;
            cout << "Capacidad (ton): "; cin >> cp;
            vehiculos[cantidad] = new Camion(p, m, a, pv, cp);
            cantidad++;
            cout << "Camion registrado." << endl;

        } else if (opcion == 3) {
            string p, m; int a; double pv, pt;
            cout << "Placa: ";       cin >> p;
            cout << "Marca: ";       cin >> m;
            cout << "Anio: ";        cin >> a;
            cout << "Precio base: "; cin >> pv;
            cout << "Potencia: ";    cin >> pt;
            vehiculos[cantidad] = new Motocicleta(p, m, a, pv, pt);
            cantidad++;
            cout << "Motocicleta registrada." << endl;

        } else if (opcion == 4) {
            if (cantidad == 0) {
                cout << "No hay vehiculos registrados." << endl;
            } else {
                for (int i = 0; i < cantidad; i++) {
                    cout << "\n--- Vehiculo " << (i+1) << " ---" << endl;
                    vehiculos[i]->mostrar();
                }
            }

        } else if (opcion == 5) {
            ofstream out("vehiculos.dat", ios::binary);
            if (!out) {
                cout << "Error al abrir el archivo." << endl;
            } else {
                out.write((const char*)(&cantidad), sizeof(cantidad));
                for (int i = 0; i < cantidad; i++) {
                    int tipo = 0;
                    if      (dynamic_cast<Automovil*>  (vehiculos[i])) tipo = 1;
                    else if (dynamic_cast<Camion*>     (vehiculos[i])) tipo = 2;
                    else if (dynamic_cast<Motocicleta*>(vehiculos[i])) tipo = 3;
                    out.write((const char*)(&tipo), sizeof(tipo));
                    vehiculos[i]->guardar(out);
                }
                out.close();
                cout << "Vehiculos guardados correctamente." << endl;
            }

        } else if (opcion == 6) {
            ifstream in("vehiculos.dat", ios::binary);
            if (!in) {
                cout << "Error al abrir el archivo." << endl;
            } else {
                for (int i = 0; i < cantidad; i++) {
                    delete vehiculos[i];
                    vehiculos[i] = nullptr;
                }
                cantidad = 0;
                in.read((char*)(&cantidad), sizeof(cantidad));
                for (int i = 0; i < cantidad; i++) {
                    int tipo = 0;
                    in.read((char*)(&tipo), sizeof(tipo));
                    if      (tipo == 1) vehiculos[i] = new Automovil();
                    else if (tipo == 2) vehiculos[i] = new Camion();
                    else if (tipo == 3) vehiculos[i] = new Motocicleta();
                    vehiculos[i]->cargar(in);
                }
                in.close();
                cout << "Vehiculos cargados correctamente." << endl;
            }
        }

    } while (opcion != 0);

    // Liberar memoria
    for (int i = 0; i < cantidad; i++) {
        delete vehiculos[i];
        vehiculos[i] = nullptr;
    }

    cout << "Hasta luego." << endl;
    return 0;
}