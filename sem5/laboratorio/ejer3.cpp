#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct seleccion
{
    int PG;
    int PE;
    int PP;
};
//las suma de PG y todo lo dema =100
void ruedasa(seleccion Pais0){
    Pais0.PG=rand() % 100 + 1;
    bool suma=true;
    if(Pais0.PG<100){
        Pais0.PE=rand() % 100-Pais0.PG + 1;
        if(Pais0.PG+Pais0.PE>100){
            suma=false;
            while(suma==false){
                Pais0.PE=rand() % 100-Pais0.PG + 1;
                if(Pais0.PG+Pais0.PE<100){
                    suma=true;
                }
            }
        }
        if(Pais0.PG+Pais0.PE<100 && suma==true){
            Pais0.PP=100-Pais0.PG-Pais0.PE;
        }
        if(Pais0.PG+Pais0.PE==100){
            Pais0.PP=0;
        }
    }
    if(Pais0.PG==100){
        Pais0.PE=0;
        Pais0.PP=0;
    }
    
    double puntaje0=3*(Pais0.PG)+Pais0.PP;
    double rendimiento0=puntaje0/3;
    cout<<Pais0.PG<<"     "<<Pais0.PP<<"     "<<Pais0.PE<<"    "<<puntaje0<<"    "<<rendimiento0<<endl;
}
int main(){
    srand(std::time(0));

    seleccion Pais0;
    seleccion Pais1;
    seleccion Pais2;
    seleccion Pais3;
    seleccion Pais4;
//hacer solo el primero ponerlo en una funcion y ya
    cout<<"SELECCION           PG       PP      PE      PUNTAJE      RENDIMIENTO"<<endl;
    cout<<"SELECCION PAIS0     ";
    ruedasa(Pais0);
    cout<<"SELECCION PAIS1     ";
    ruedasa(Pais1);
    cout<<"SELECCION PAIS2     ";
    ruedasa(Pais2);
    cout<<"SELECCION PAIS3     ";
    ruedasa(Pais3);
    cout<<"SELECCION PAIS4     ";
    ruedasa(Pais4);
    return 0;
}