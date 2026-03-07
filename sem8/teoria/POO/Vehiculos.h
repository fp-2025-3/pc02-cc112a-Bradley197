#ifndef VEHICULOS_H
#define VEHICULOS_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Clase base ABSTRACTA
class Vehiculo {
protected:
    string placa;
    string marca;
    int anio;
    double precioBase;
public:
    Vehiculo();
    Vehiculo(string p, string m, int a, double pb);
    virtual ~Vehiculo();
    virtual double calcularPrecioFinal() const = 0;
    virtual void guardar(ofstream& out) const = 0;
    virtual void cargar(ifstream& in) = 0;       // sin const: modifica el objeto
    virtual void mostrar() const;
};

class Automovil: public Vehiculo {
private:
    int numeroPuertas;
public:
    Automovil();
    Automovil(string p, string m, int a, double pv, int np);
    ~Automovil();
    double calcularPrecioFinal() const override;
    void guardar(ofstream& out) const override;
    void cargar(ifstream& in) override;
    void mostrar() const override;
};

class Camion: public Vehiculo {
private:
    double capacidad;
public:
    Camion();
    Camion(string p, string m, int a, double pv, double cp);
    ~Camion();
    double calcularPrecioFinal() const override;
    void guardar(ofstream& out) const override;
    void cargar(ifstream& in) override;
    void mostrar() const override;
};

class Motocicleta: public Vehiculo {
private:
    double potencia;   // corregido: era "pontencia"
public:
    Motocicleta();
    Motocicleta(string p, string m, int a, double pv, double pt);
    ~Motocicleta();
    double calcularPrecioFinal() const override;
    void guardar(ofstream& out) const override;
    void cargar(ifstream& in) override;
    void mostrar() const override;
};

#endif