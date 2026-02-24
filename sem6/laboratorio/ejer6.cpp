#include<iostream>
#include<fstream>
using namespace std;
struct Empleado{
    int id;
    char nombre[20];
    float salario;
};
void crearArchivo(){
  ofstream archivo("empleados.bin",ios::binary);
  if(!archivo){
    cout<<"Error al crear el archivo"<<endl;
    return;
  }  
  Empleado lista[8] = {
    {1,"Juan",1500.0},{2,"Maria",2000.0},
    {3,"Pedro",1800.0},{4,"Ana",2200.0},
    {5,"Luis",1700.0},{6,"Rosa",2500.0},
    {7,"Carlos",1900.0},{8,"Elena",2100.0}
  };
  archivo.write((char*)lista,sizeof(lista));
  archivo.close();
  cout<<"archivo creado"<<endl;
};
void mostrar(){
    ifstream archivo("empleados.bin",ios::in|ios::binary);
    if(!archivo){
    cout<<"Error al crear el archivo"<<endl;
    return;
    }
    Empleado e;
    while(archivo.read((char*)&e,sizeof(Empleado))){
        cout<<"El id : "<<e.id<<"| El nombre: "<<e.nombre<<"| El salario: "<<e.salario<<endl;
    }
    archivo.close();
};
void rangos(float minSalario, float maxSalario){
    ifstream archivo("empleados.bin",ios::in|ios::binary);
    if(!archivo){
    cout<<"Error al crear el archivo"<<endl;
    return;
    }
    Empleado e;
    while(archivo.read((char*)&e,sizeof(Empleado))){
        if(e.salario>=minSalario&&e.salario<=maxSalario){
            cout<<"El id : "<<e.id<<"| El nombre: "<<e.nombre<<"| El salario: "<<e.salario<<endl;
        }
    }
    archivo.close();
};
int main(){
     crearArchivo();
     mostrar();
     float minSalario,maxSalario;
     cout<<"Ingrese el minimo y maximo salario del intervalo que quieres buscar: "<<endl;
     cin>>minSalario;
     cin>>maxSalario;
     rangos(minSalario,maxSalario);
    return 0;
}