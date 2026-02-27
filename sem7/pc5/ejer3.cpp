#include<iostream>
#include<fstream>
using namespace std;
struct Empleado{
    int id; //comienza en 1 
    char nombre[30];
    double salario;
};

int main(){
    int id;
    cout<<"Ingrese el ID de emnpleado: "<<endl;
    cin>>id;
    if(id<1){
        cout<<"No es posible"<<endl;
    }
    cout<<"---DATOS DEL EMPLEADO---"<<endl;
    cout<<"ID: "<<id<<endl;
    ifstream file("empleados.dat",ios::binary);
    if(!file){
        cout<<"NO SE ABRE"<<endl;
        return 1;
    }
    Empleado empleado;
    while(file.read((char*)&empleado,sizeof(Empleado))){
        if(id==empleado.id){
            cout<<"Nombre: "<<empleado.nombre<<endl;
            cout<<"Salario: "<<empleado.salario<<endl<<endl;
        }
    }
    double nuevoSalario;
    cout<<"Ingrese nuevo salario(>0): ";
    cin>>nuevoSalario;
    if(nuevoSalario<=0){
        cout<<"No es valido"<<endl;
        return 1;
    }
    cout<<endl<<"Salario actualizado correctamente"<<endl;
    return 0;
}