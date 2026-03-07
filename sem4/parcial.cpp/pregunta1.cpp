#include<iostream>
using namespace std;
int costoMax(int *A,int n,int i){
    if(i==n){
        return 0;
    }
    int producto=1;
    int max=0;
    for(int j=i;j<n;j++){
        producto*=A[j];
        int costo=producto+costoMax(A,n,j+1);
        if(max<costo){
            max=costo;
        }
    }
    return max;
}
int main(){
    int A[]={1,2,3,4,5};
    int n=sizeof(A)/sizeof(A[0]);
    cout<<costoMax(A,n,0);
    //la b el valor que controla las recursivas es i que va desde 0 hasta ser igual a la cantidad de datos
    //pero en cada vez que saca el maximo recorre todos los casos posibles donde de todos ello saca el maximo 
    //empieza con una segmentacion de un elemento y ese se toma como mas y despues los comprar con todos los que tengan ese mismo incio
    //Despues va por la segmentacion de la primera parte de 2 elementos y saca un max cualquiera y otra vez compara 
    //hasta hasta llegar a q i==n;

    return 0;
}