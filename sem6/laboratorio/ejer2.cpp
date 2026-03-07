#include<iostream>
#include<fstream>
using namespace std;
int cantidadEstudiantes(){
    ifstream archivo("notas.txt");
    int elemento;
    int contador=0;
    if(!archivo){
        cout<<"No se puede abrir el archivo: "<<endl;
        archivo.close();
        return 0;
    }
    while(archivo>>elemento){
        contador++;
    }
    archivo.close();
    return contador;
}
float promedioGeneral(int cantidadEstudiantes){
    ifstream archivos("notas.txt");
    float suma=0;
    int elemento;
    while(archivos>>elemento){
        suma+=elemento;
    }
    float promedio;
    promedio=suma/cantidadEstudiantes;
    archivos.close();
    return promedio;
}
int notaAlta(){
    ifstream archivo("notas.txt");
    int elemento;
    int mayorNota=-1;
    if(!archivo){
        cout<<"No se abre el archivo"<<endl;
        archivo.close();
        return 0;
    }
    while(archivo>>elemento){
        if(mayorNota<elemento){
            mayorNota=elemento;
        }
    }
    archivo.close();
    return mayorNota;
}
int notaBaja(){
    ifstream archivo("notas.txt");
    int menorNota=21;
    int elementos;
    if(!archivo){
        cout<<"No se abre el archivo: "<<endl;
        archivo.close();
        return 0;
    }
    while(archivo>>elementos){
        if(menorNota>elementos){
            menorNota=elementos;
        }
    }
    archivo.close();
    return menorNota;
}
int cantAprovados(){
    ifstream archivo("notas.txt");
    int cantidadAprovados=0;
    int elemento;
    if(!archivo){
        cout<<"No se puede abrir el archivo "<<endl;
        archivo.close();
        return 0;
    }
    while(archivo>>elemento){
        if(elemento>=10){
            cantidadAprovados++;
        }
    }
    archivo.close();
    return cantidadAprovados;
}
int cantDesaprovados(){
    ifstream archivo("notas.txt");
    int cantidadDesaprovados=0;
    int elemento;
    if(!archivo){
        cout<<"No se abre el archivo"<<endl;
        archivo.close(); 
        return 0;
    }
    while(archivo>>elemento){
        if(elemento<10){
            cantidadDesaprovados++;
        }
    }
    archivo.close();
    return cantidadDesaprovados;
}
int main(){
    //aca sacar los archivos es reporte.txt
    ofstream archivo("reporte.txt");
    if(!archivo){
        cout<<"No se puede abrir"<<endl<<endl;
        return 0;
    }
    archivo<<"REPORTE GENERAL"<<endl;
    archivo<<"---------------------"<<endl;
    archivo<<"La cantidad de Estudiantes es: "<<cantidadEstudiantes()<<endl;
    int cantEstudiantes=cantidadEstudiantes();
    archivo<<"El promedio general es: "<<promedioGeneral(cantEstudiantes)<<endl;
    archivo<<"La nota mas alta es: "<<notaAlta()<<endl;
    archivo<<"La nota mas baja es: "<<notaBaja()<<endl;
    archivo<<"Cantidad de estudiantes aprovados: "<<cantAprovados()<<endl;
    archivo<<"Cantidad de estudiantes desaprovados: "<<cantDesaprovados()<<endl;
    return 0;
}