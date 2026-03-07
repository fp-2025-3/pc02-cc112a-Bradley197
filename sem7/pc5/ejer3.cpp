#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int main(){
    const int FILAS=21;
    const int COLUMNAS=80;
    const double PI=3.141592;
    
    char lienzo[FILAS][COLUMNAS];
    for(int i=0;i<FILAS;i++){
        for(int j=0;j<COLUMNAS;j++){
            lienzo[i][j]=' ';
        }
    }
    for(int j=0;j<COLUMNAS;j++){
        lienzo[10][j]='-';
    }
    for(int i=0;i<FILAS;i++){
        lienzo[i][0]='|';
    }
    for(int j=0;j<COLUMNAS;j++){
        double x=(double)j*(2.0*PI)/(COLUMNAS-1);
        double y=sin(5*x);
        int fila=static_cast<int>(round(10.0-(y*10.0)));
        if(fila>=0 && fila<FILAS){
        lienzo[fila][j]='*';
        }
    }  
    ofstream archivo("grafico.txt");
    if(!archivo){
        cout<<"no se abre"<<endl;
        return 1;
    }
    if(archivo.is_open()){
        for(int i=0;i<FILAS;i++){
            for(int j=0;j<COLUMNAS;j++){
                archivo<<lienzo[i][j];
            }
            archivo<<endl;
        }
        archivo.close();
    }
    return 0;
}