#include<iostream>
using namespace std;
void agregarDuplicar(int *codigos,double* promedios, int *i,int *n){
//agregar
cout<<"Ingrese los codigos: "<<endl;
cin>>codigos[*i];
(*i)++;
if(*i==*n){
    int numero = 2*(*n);
    int *nuevosCodigos = new int[numero];
    double *nuevosPromedios = new double[numero];
    for(int j=0;j<*n;j++){
        nuevosCodigos[j] = codigos[j];
        nuevosPromedios[j] = promedios[j];
    }

    *n=numero;

}

}
void rellenarPromedios(double *promedios, int n){//la cantidad de personas
    cout<<"Ingrese los promedios: "<<endl;
    for(int i=0;i<n;i++){
        cout<<"Ingrese el promedio del numero "<<i+1<<" :"<<endl;
        cin>>promedios[i];
    }
}


void eliminarRedimencionar(int *&codigos, double *&promedios, int *n){
    int j=0;
    for(int i=0;i<*n;i++){
        if(*(promedios+i)>=10){
            j++;
        }
    }
    //la nueva cantidad de elemetos que quedan es j;
    int *newCod = new int[j];
    double *newPromedios = new double[j];

    int k=0;
    for(int i=0;i<*n;i++){
        if(promedios[i]>=10){
            newCod[k]=codigos[i];
            newPromedios[k]=promedios[i];
            k++;
        }

    }
    delete[] codigos;
    delete[] promedios;

    codigos = newCod;
    promedios= newPromedios;
    *n=j;

}
int main(){
    int n=10;
    int i=0;
    int *codigos = new int[n];
    double *promedios = new double[n];
    for(int k=0;k<3;k++){
        agregarDuplicar(codigos,promedios,&i,&n);
        cout<<"Ingrese los promedios: "<<endl;
        cin>>promedios[i-1];
    }
    eliminarRedimencionar(codigos,promedios,&i);
    for(int k=0;k<i;k++){
        cout<<"Codigo: "<<codigos[k]<<"Promedio: "<<promedios[k]<<endl;

    }
    delete[] codigos;
    delete[] promedios;

    return 0;
}