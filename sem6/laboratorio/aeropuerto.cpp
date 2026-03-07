#include<iostream>
using namespace std;
struct Pasajero{
    int dni;
    char nombre[50];
};

struct Asiento{
    int numero;
    bool reservado;
    Pasajero* pasajero;
};
struct NodoReserva{
    Pasajero pasajero;
    int numeroAsiento;
};
struct Vuelo{
    char codigo[10];
    char destino[50];
    int capacidad;
    Asiento* asientos;
    NodoReserva* listaReservas;
};
Vuelo vuelo;
void crearVuelo(vuelo.codigo,vuelo.destino,vuelo.capacidad){
    vuelo.asientos=new Asiento[capacidad];
    for(int i=0;i<capacidad;i++){
        numero=i+1;
        reservado=false;
        pasajero=nullptr;
    }
};
int main(){
    vuelo.codigo="196";
    vuelo.destino="Honduras";
    vuelo.capacidad=20;
    crearVuelo(vuelo.codigo,vuelo.destino,vuelo.capacidad);
    return 0;
}