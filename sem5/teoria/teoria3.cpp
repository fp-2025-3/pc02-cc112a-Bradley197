#include<iostream>
using namespace std;
struct producto{
    int codigo;
    double precio;
    producto *p;
};
int main(){
    int N;
    cout<<"Ingrese la cantidad de productos que ingresara: "<<endl;
    cin>>N;

    producto *A =new producto[N];
    for(int i=0;i<N;i++){
        cout<<"Ingrese el producto "<<i+1<<" (codigo,precio) :";
        cin>>A[i].codigo>>A[i].precio;
    }
    //amacenarlos en una lista simple
    producto *lista =new producto[N];
    for(int i=0;i<N;i++){
        lista[i].p=&A[i];
    }
    //ahora meter cafa producto dentro de lista
    cout<<"LOS PRODUCTOS SON :  "<<endl;
    cout<<"CODIGO        PRECIO"<<endl;
    for(int i=0;i<N;i++){
        cout<<lista[i].p->codigo<<"                "<<lista[i].p->precio<<endl;
    }
    delete[] A;
    delete[] lista;
    return 0;
}