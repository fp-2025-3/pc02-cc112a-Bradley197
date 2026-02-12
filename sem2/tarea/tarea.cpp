// TAREA
/*
Se tiene un arreglo de cadenas definido mediante
const char* cad[];

Implemente una función que cuente cuántas cadenas tienen longitud mayor 
que  la longitud promedio del arreglo
*/
#include<iostream>
#include<cstring>
using namespace std;
int cantCadenasMayores(const char* cad[],int cantElementos){
    //aca la longitud promedio
    float longitudTotal=0;
    const char **inicio=cad;
    const char **finale=cad+cantElementos;
    for(const char **i=inicio;i<finale;i++){
        longitudTotal=longitudTotal+strlen(*i);
    }
    float longitudPromedio=longitudTotal/cantElementos;
    int cantidad=0;
    for(const char **i=inicio;i<finale;i++){
        if(strlen(*i)>longitudPromedio){
            cantidad++;
        }
    }
    return cantidad;
}
int main(){
    const char* cad[]={
     "H",
     "profe",
     "Americo",
     "Josiasr"
    };
    int cantElementos=sizeof(cad)/sizeof(cad[0]);
    int resultado=cantCadenasMayores(cad,cantElementos);
    cout<<resultado<<endl;
return 0;
}