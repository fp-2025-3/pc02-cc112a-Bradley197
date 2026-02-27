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
    file.seekg(0,ios::beg);
    double *promedio = new double[cantidadDeCodigos];
    string elemento;
    for(int j=0;j<cantidadDeCodigos;j++){
        getline(file,codigo,' ');
        getline(file,nombre,' ');
        getline(file,nota1,' ');
        getline(file,nota2,' ');
        getline(file,nota3);
        double n1=stof(nota1);
        double n2=stof(nota2);
        double n3=stof(nota3);
        promedio[j]=(n1+n2+n3)/3.0;
    }
    
    file.seekg(0,ios::beg);
    string cod,nom,no;
      for(int j=0;j<cantidadDeCodigos;j++){
        file.seekg(j,ios::beg);
        getline(file,cod,' ');
        getline(file,nom,' ');
        getline(file,no);
        if(promedio[j]>=10){
            file1<<"APROVADO"<<endl;
        }else if(promedio[j]<5){
            file1<<"DESAPROVADO POR REGLA ACADEMICA"<<endl;
        }else{
            file1<<"DESAPROVADO"<<endl;
        }

      }

    delete[] promedio;
    return 0;
}