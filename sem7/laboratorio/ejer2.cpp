#include<iostream>
#include<fstream>
#include<cstring>
//#include<iomanip>
using namespace std;
int main(){
    ifstream file1("entradas/baseUNI.txt");
    if(!file1){
        cout<<"NO SE ABRIO"<<endl;
        return 1;
    }
    /*string linea,nombre,apellidos;
    int numero;

    
    string numero;
    while(){
        getline(file1,numero,'.');
        cout<<" "<<numero<<"    ";
        string apellidos;
        getline(file1,apellidos,',');
        cout<<apellidos<<"   ";
        string nombre;
        getline(file1,nombre,'-');
        cout<<nombre<<"    ";   
        string nota1;
        getline(file1,nota1,'-');
        cout<<nota1<<"   ";
        string nota2;
        getline(file1,nota2);
        cout<<nota2<<"   ";
        float promedio;
        promedio=(stof(nota1)+stof(nota2))/2.0;
        cout<<promedio<<endl;
    }*/
    cout<<"NUM   APELLIDOS   NOMBRE   NOTA1  NOTA2  PROMEDIO"<<endl;
    string numero, apellidos, nombre, nota1, nota2;
    float promMax=0;
    string alm;
    while (getline(file1, numero, '.')) {
        
        // Leemos el resto de datos de la línea actual
        getline(file1, apellidos, ',');
        getline(file1, nombre, '-');
        getline(file1, nota1, '-');
        getline(file1, nota2); // Lee hasta el final de la línea (\n)

        // Convertimos los strings a float para operar
        float n1 = stof(nota1);
        float n2 = stof(nota2);
        float promedio = (n1 + n2) / 2.0;
        cout<<" "<<numero<<"    "<<apellidos<<"   "<<nombre<<"    "<<nota1<<"   "<<nota2<<"    "<<promedio<<endl;
        if(promMax<promedio){
            promMax=promedio;
            alm=nombre +" "+ apellidos;
        }
    }

    cout<<"El promedio maximo: "<<promMax<<endl;
    cout<<"Alumno: "<<alm<<endl;
    return 0;
    
}