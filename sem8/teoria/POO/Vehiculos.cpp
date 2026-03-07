#include "Vehiculos.h"

// ======================== VEHICULO ========================

Vehiculo::Vehiculo() {
    cout << "Llamando al constructor por defecto" << endl;
}

Vehiculo::Vehiculo(string p, string m, int a, double pb)
    : placa(p), marca(m), anio(a), precioBase(pb) {
    cout << "Llamando al constructor de parametro" << endl;
}

Vehiculo::~Vehiculo() {}

void Vehiculo::mostrar() const {
    cout << "Placa: "       << placa      << endl;
    cout << "Marca: "       << marca      << endl;
    cout << "Anio: "        << anio       << endl;
    cout << "Precio Base: " << precioBase << endl;
}


// ======================== AUTOMOVIL ========================

Automovil::Automovil() {}

Automovil::Automovil(string p, string m, int a, double pv, int np)
    : Vehiculo(p, m, a, pv), numeroPuertas(np) {}

Automovil::~Automovil() {}

double Automovil::calcularPrecioFinal() const {
    return precioBase * 1.05;
}

void Automovil::guardar(ofstream& out) const {
    size_t len;

    len = placa.size();
    out.write((const char*)(&len), sizeof(len));
    out.write(placa.c_str(), len);

    len = marca.size();
    out.write((const char*)(&len), sizeof(len));
    out.write(marca.c_str(), len);

    out.write((const char*)(&anio),          sizeof(anio));
    out.write((const char*)(&precioBase),    sizeof(precioBase));
    out.write((const char*)(&numeroPuertas), sizeof(numeroPuertas));
}

void Automovil::cargar(ifstream& in) {
    size_t len;
    char buffer[256];

    in.read((char*)(&len), sizeof(len));
    in.read(buffer, len);
    buffer[len] = '\0';
    placa = buffer;

    in.read((char*)(&len), sizeof(len));
    in.read(buffer, len);
    buffer[len] = '\0';
    marca = buffer;

    in.read((char*)(&anio),          sizeof(anio));
    in.read((char*)(&precioBase),    sizeof(precioBase));
    in.read((char*)(&numeroPuertas), sizeof(numeroPuertas));
}

void Automovil::mostrar() const {
    Vehiculo::mostrar();
    cout << "Numero de Puertas: " << numeroPuertas << endl;
    cout << "Precio Final: "      << calcularPrecioFinal() << endl;
}


// ======================== CAMION ========================

Camion::Camion() {}

Camion::Camion(string p, string m, int a, double pv, double cp)
    : Vehiculo(p, m, a, pv), capacidad(cp) {}

Camion::~Camion() {}

double Camion::calcularPrecioFinal() const {
    return precioBase * 1.12;
}

void Camion::guardar(ofstream& out) const {
    size_t len;

    len = placa.size();
    out.write((const char*)(&len), sizeof(len));
    out.write(placa.c_str(), len);

    len = marca.size();
    out.write((const char*)(&len), sizeof(len));
    out.write(marca.c_str(), len);

    out.write((const char*)(&anio),       sizeof(anio));
    out.write((const char*)(&precioBase), sizeof(precioBase));
    out.write((const char*)(&capacidad),  sizeof(capacidad));
}

void Camion::cargar(ifstream& in) {
    size_t len;
    char buffer[256];

    in.read((char*)(&len), sizeof(len));
    in.read(buffer, len);
    buffer[len] = '\0';
    placa = buffer;

    in.read((char*)(&len), sizeof(len));
    in.read(buffer, len);
    buffer[len] = '\0';
    marca = buffer;

    in.read((char*)(&anio),       sizeof(anio));
    in.read((char*)(&precioBase), sizeof(precioBase));
    in.read((char*)(&capacidad),  sizeof(capacidad));
}

void Camion::mostrar() const {
    Vehiculo::mostrar();
    cout << "Capacidad de carga: " << capacidad << " ton" << endl;
    cout << "Precio Final: "       << calcularPrecioFinal() << endl;
}


// ======================== MOTOCICLETA ========================

Motocicleta::Motocicleta() {}

Motocicleta::Motocicleta(string p, string m, int a, double pv, double pt)
    : Vehiculo(p, m, a, pv), potencia(pt) {}

Motocicleta::~Motocicleta() {}

double Motocicleta::calcularPrecioFinal() const {
    return precioBase * 1.03;
}

void Motocicleta::guardar(ofstream& out) const {
    size_t len;

    len = placa.size();
    out.write((const char*)(&len), sizeof(len));
    out.write(placa.c_str(), len);

    len = marca.size();
    out.write((const char*)(&len), sizeof(len));
    out.write(marca.c_str(), len);

    out.write((const char*)(&anio),       sizeof(anio));
    out.write((const char*)(&precioBase), sizeof(precioBase));
    out.write((const char*)(&potencia),   sizeof(potencia));
}

void Motocicleta::cargar(ifstream& in) {
    size_t len;
    char buffer[256];

    in.read((char*)(&len), sizeof(len));
    in.read(buffer, len);
    buffer[len] = '\0';
    placa = buffer;

    in.read((char*)(&len), sizeof(len));
    in.read(buffer, len);
    buffer[len] = '\0';
    marca = buffer;

    in.read((char*)(&anio),       sizeof(anio));
    in.read((char*)(&precioBase), sizeof(precioBase));
    in.read((char*)(&potencia),   sizeof(potencia));
}

void Motocicleta::mostrar() const {
    Vehiculo::mostrar();
    cout << "Potencia: "     << potencia << " cc" << endl;
    cout << "Precio Final: " << calcularPrecioFinal() << endl;
}