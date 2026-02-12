#include<iostream>
#include <string>
using namespace std;
struct Fecha{
    int dia;
    int mes;
    int año;
};
struct contacto{
    char nombre[20];
    Fecha fecha;
};
//leer datos
void leer(int N, contacto *P){
    for(int i=0;i<N;i++){
        cout<<"Contacto "<<i+1<<" :"<<endl;
        cout<<"Ingrese el nombre: ";
        cin>>P[i].nombre;
        cout<<"Ingrese el dia: ";
        cin>>P[i].fecha.dia;
        cout<<"Ingrese el mes: ";
        cin>>P[i].fecha.mes;
        cout<<"Ingrese el año: ";
        cin>>P[i].fecha.año;
    }
    cout<<endl;
}
//mostras los nacidos en el mismo año
/*int arreglito(int N,contacto *P,int contador){
    bool newElemento = true;
    int* anios = new int [N];
    anios[0] = P[0].fecha.año;//aca se guarda l primer año ahora buscaremos los demas en caso no halla mas se termina
    //y si sacamos los ñaos que existen y con ello digo que si son iguales se imprima 
    for(int i=1;i<N;i++){
        for(int j=i-1;j>=0;j--){
            if(P[i].fecha.año!=P[j].fecha.año){
                newElemento=true;
            }else{
                newElemento=false;
            }
    }
    if(newElemento==true){
        anios[contador]=P[i].fecha.año;
        contador++;
    }
}
    return anios;
}*/





void mismoAño(int N, contacto *P){
    int contador=1;
    bool newElemento = true;
    int* anios = new int [N];
    anios[0] = P[0].fecha.año;//aca se guarda l primer año ahora buscaremos los demas en caso no halla mas se termina
    //y si sacamos los ñaos que existen y con ello digo que si son iguales se imprima 
    for(int i=1;i<N;i++){
        for(int j=i-1;j>=0;j--){
            if(P[i].fecha.año!=P[j].fecha.año){
                newElemento=true;
            }else{
                newElemento=false;
            }
    }
    if(newElemento==true){
        anios[contador]=P[i].fecha.año;
        contador++;
    }
}
    //ahora ya sabemos cuantos años hay y la cantidad 
    for(int i=0;i<contador;i++){
        cout<<"Los nombres que nacieron en el año "<<P[i].fecha.año<<" son: "<<endl;
        for(int j=0;j<N;j++){
            if(P[i].fecha.año==P[j].fecha.año){
                cout<<P[j].nombre<<" ";
            }
        }
        cout<<endl;
    }

}

int main(){
    int N;
    cout<<"Ingrese la cantidad de contactos: "<<endl;
    cin>>N;
    contacto *P = new contacto[N];
    leer(N,P);
    mismoAño(N,P);

    ret