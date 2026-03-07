#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

int main(){
    ifstream file("notas.txt");
    ofstream file1("Alumnos.txt");
    if(!file&&!file1){
        cout<<"No se abre"<<endl;
        return 1;
    }
    //leer el archivoi
    string codigo,nombre,nota1,nota2,nota3;
    int cantidadDeCodigos=0;
    while(getline(file,codigo,' ')){
        cantidadDeCodigos++;
        getline(file,nombre,' ');
        getline(file,nota1,' ');
        getline(file,nota2,' ');
        getline(file,nota3);
        cout<<codigo<<"  "<<nombre<<"  "<<nota1<<"  "<<nota2<<"  "<<nota3<<endl;

    }
    //calcular el promedio de cada estudiante
    //Como voler al inicio
    file.clear();
    file.seekg(0,ios::beg);
    double *promedio = new double[cantidadDeCodigos];
    int j=0;
    string elemento;
    while(getline(file,codigo,' ')){
        getline(file,nombre,' ');
        getline(file,nota1,' ');
        getline(file,nota2,' ');
        getline(file,nota3);
        double n1=stof(nota1);
        double n2=stof(nota2);
        double n3=stof(nota3);
        promedio[j]=(n1+n2+n3)/3.0;
        j++;
        
    }
    j=0;
    file.clear();
    file.seekg(0,ios::beg);
      while(getline(file,codigo,' ')){
        getline(file,nombre,' ');
        getline(file,nota1,' ');
        getline(file,nota2,' ');
        getline(file,nota3);
        file1<<codigo<<"  "<<nombre<<"  "<<promedio[j]<<"  ";
        if(promedio[j]>=10){
            file1<<"APROVADO"<<endl;
            j++;
        }else if(promedio[j]<5){
            file1<<"DESAPROVADO POR REGLA ACADEMICA"<<endl;
            j++;
        }else{
            file1<<"DESAPROVADO"<<endl;
            j++;
        }

      }

    delete[] promedio;
    return 0;
}