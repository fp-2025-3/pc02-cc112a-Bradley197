#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
struct partidos{
    int PG;
    int PE;
    int PP;
    int puntajeTotal;
    double rendimiento;
};
struct goles{
    int GF;
    int GC;
    int DG=GF-GC;
};
struct seleccion{
    char nombre[10];
    partidos ptj;
    goles GT;


};
void puntosRepartidos(partidos partidosTotales1){
    partidosTotales1.PG=rand()%100+1;
    if(partidosTotales1.PG!=100){
        partidosTotales1.PE=(rand()%(100-partidosTotales1.PG))+1;
        while(partidosTotales1.PG+partidosTotales1.PE>100){
            partidosTotales1.PE=(rand()%(100-partidosTotales1.PG))+1;
        }
        partidosTotales1.PP=100-partidosTotales1.PG-partidosTotales1.PE;
    }
    if(partidosTotales1.PG==100){
        partidosTotales1.PE=0;
        partidosTotales1.PP=0;
    }
    cout<<"PG: "<<partidosTotales1.PG<<endl;
    cout<<"PP: "<<partidosTotales1.PP<<endl;
    cout<<"PE: "<<partidosTotales1.PE<<endl;
    partidosTotales1.puntajeTotal=3*partidosTotales1.PG+partidosTotales1.PP;
    cout<<"El puntaje total es: "<<partidosTotales1.puntajeTotal<<endl;
    partidosTotales1.rendimiento=partidosTotales1.puntajeTotal/300;
    cout<<"El rendimiento es: "<<partidosTotales1.rendimiento<<".42"<<endl;
    
}
int puntosa(partidos partidosTotales1, int a){
    partidosTotales1.PG=rand()%100+1;
    if(partidosTotales1.PG!=100){
        partidosTotales1.PE=(rand()%(100-partidosTotales1.PG))+1;
        while(partidosTotales1.PG+partidosTotales1.PE>100){
            partidosTotales1.PE=(rand()%(100-partidosTotales1.PG))+1;
        }
        partidosTotales1.PP=100-partidosTotales1.PG-partidosTotales1.PE;
    }
    if(partidosTotales1.PG==100){
        partidosTotales1.PE=0;
        partidosTotales1.PP=0;
    }
    a=partidosTotales1.PG;
    return a;

}
int puntosb(partidos partidosTotales1, int b){
    partidosTotales1.PG=rand()%100+1;
    if(partidosTotales1.PG!=100){
        partidosTotales1.PE=(rand()%(100-partidosTotales1.PG))+1;
        while(partidosTotales1.PG+partidosTotales1.PE>100){
            partidosTotales1.PE=(rand()%(100-partidosTotales1.PG))+1;
        }
        partidosTotales1.PP=100-partidosTotales1.PG-partidosTotales1.PE;
    }
    if(partidosTotales1.PG==100){
        partidosTotales1.PE=0;
        partidosTotales1.PP=0;
    }
    b=partidosTotales1.PP;
    return b;

}
int puntosc(partidos partidosTotales1, int c){
    partidosTotales1.PG=rand()%100+1;
    if(partidosTotales1.PG!=100){
        partidosTotales1.PE=(rand()%(100-partidosTotales1.PG))+1;
        while(partidosTotales1.PG+partidosTotales1.PE>100){
            partidosTotales1.PE=(rand()%(100-partidosTotales1.PG))+1;
        }
        partidosTotales1.PP=100-partidosTotales1.PG-partidosTotales1.PE;
    }
    if(partidosTotales1.PG==100){
        partidosTotales1.PE=0;
        partidosTotales1.PP=0;
    }
    c=partidosTotales1.PE;
    return c;

}

void cantGOles(partidos partidosTotales1, goles golesTotales1,int PG,int PP,int PE){
    golesTotales1.GF=0;
    golesTotales1.GC=0;
        for(int k=0;k<PG;k++){
            int goles1=rand()%5+1;
            int goles2=rand()%5+1;
            if(goles1>goles2){
             golesTotales1.GF=golesTotales1.GF+goles1;
             golesTotales1.GC=golesTotales1.GC+goles2;
             
            }
         
        }
        for(int m=0;m<PE;m++){
            int goles1=rand()%5+1;
            int goles2=rand()%5+1;
            if(goles1==goles2){
             golesTotales1.GF=golesTotales1.GF+goles1;
             golesTotales1.GC=golesTotales1.GC+goles2;
             
            }
         
        }
        for(int n=0;n<PP;n++){
            int goles1=rand()%5+1;
            int goles2=rand()%5+1;
            if(goles1<goles2){
             golesTotales1.GF=golesTotales1.GF+goles1;
             golesTotales1.GC=golesTotales1.GC+goles2;
             
            }
          
        }
    
    cout<<"La cantidad de goles a favor son: "<<golesTotales1.GF<<endl;

    cout<<"La cantidad de goles en contra son: "<<golesTotales1.GC<<endl;

    cout<<"La diferencia de goles es: "<<golesTotales1.GF-golesTotales1.GC;



}
int main(){
    srand(time(0));
    cout<<"SELECCION 1"<<endl;
    partidos partidosTotales1;
    //ya tengo los poartidos reopartidos
    puntosRepartidos(partidosTotales1);
    //ahora goles;
    goles golesTotales1;
    int m;
    int a=puntosa(partidosTotales1,m);
    int n;
    int b=puntosb(partidosTotales1,n);
    int p;
    int c=puntosc(partidosTotales1,p);
    cantGOles(partidosTotales1,golesTotales1,a,b,c);

    cout<<"SELECCION 2"<<endl;
    cout<<"SELECCION 3"<<endl;
    cout<<"SELECCION 4"<<endl;
    cout<<"SELECCION 5"<<endl;

    return 0;
}