#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
struct seleccion{
    char nombre[20];
    int PG,PE,PP;
    int GC,GF,DG;
    int puntos;
    double rendimiento;
};
void generarPartidos(seleccion &s){
    s.PG= rand()%101;
    s.PE= rand()%(101-s.PG);
    s.PP= 100-s.PG-s.PE;
}
void generarGoles(seleccion& s){
    s.GF=0;
    s.GC=0;
    for(int i=0;i<s.PG;i++){
        int gf,gc;
        do{
            gf=rand()%6;
            gc=rand()%6;
        }while(gf<=gc);
        s.GF+=gf;
        s.GC+=gc;
    }
    for(int i=0;i<s.PE;i++){
        int goles=rand()%6;
        s.GF+=goles;
        s.GC+=goles;
    }
        for(int i=0;i<s.PP;i++){
        int gf,gc;
        do{
            gf=rand()%6;
            gc=rand()%6;
        }while(gf>=gc);
        s.GF+=gf;
        s.GC+=gc;
        }

}
void calcularEstadistica(seleccion &s){
    s.puntos=3*s.PG+s.PE;
    s.DG=s.GF-s.GC;
    s.rendimiento=(s.puntos/300.0)*100;
}
void ordenar(seleccion v[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(v[j].puntos<v[j+1].puntos||(v[j].puntos==v[j+1].puntos&&v[j].DG<v[j+1].DG)||(v[j].puntos==v[j+1].puntos&&v[j].DG==v[j+1].DG&&v[j].GF<v[j+1].GF)){
                seleccion aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;

            }
        }
    }
}
void mostrar(seleccion v[], int n){
    cout<<"Seleccion     "<<"PG  PE  PP  GF  GC  DG  PUNTOS  RENDIMIENTO"<<endl;
    for(int i=0;i<n;i++){
        cout<<"      "<<v[i].nombre<<"   "<<v[i].PG<<"  "<<v[i].PE<<"  "<<v[i].PP<<"  "<<v[i].GF<<"  "<<v[i].GC<<"  "<<v[i].DG<<"  "<<v[i].puntos<<"  "<<v[i].rendimiento<<endl;
    }
    cout<<endl;
    cout<<"GANADOR WIN WIN: "<<v[0].nombre<<"| PUNTAJE: "<<v[0].puntos<<"| DG: "<<v[0].DG<<"| RENDIMIENTO: "<<v[0].rendimiento<<"%"<<endl;
}
int main(){
    srand(time(0));
    seleccion selecciones[5]={
        {"PAIS_1"},{"PAIS_2"},{"PAIS_3"},{"PAIS_4"},{"PAIS_5"}
    };
    for( int i=0;i<5;i++ ){
        generarPartidos(selecciones[i]);
        generarGoles(selecciones[i]);
        calcularEstadistica(selecciones[i]);

    }
    ordenar(selecciones,5);
    mostrar(selecciones,5);

    return 0;
}