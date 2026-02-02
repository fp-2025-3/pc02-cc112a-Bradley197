#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
void transformarNumeros(char* texto, int * num){
    char *token =strtok(texto,",");
    int i=0;
    while(token!=NULL){
        num[i++] = atoi(token);
        token = strtok(NULL,",");
    }
}
void buscarSuma(int *texto,int n, int k){
    //todo esto esta hecho en un arreglo de enteros y sin comas;
    int *p1 = texto;
    int *p2 = texto + n-1; 
//en este caso n es 4 numero de elementos -1;
//Suma de valores entre el primero con el ultimo y el ultimo con uno anterior 
while(p1 < p2){
    int suma = *p1 + *p2;
    if(suma==k){
        cout<<"Existe 2 numero con suma: "<<k<<endl;
        break;
    }
    else if(suma<k){
        p1++;
    }else{
        p2--;
    }
}
cout<<"No esxiste un numero con suma: "<<k<<endl;
}
int main(){
    char texto[]= "1 , 2 , 4 , 7 , 11" ;
    int k;
    cout<<"Ingrese el numero : "<<endl;
    cin>>k;
    int numero[20];
    int n=0;
    transformarNumeros(texto,numero);
    while(numero[n]!=0){
        n++;

    }
    buscarSuma(numero,n,k);
    
    // 13: lo primero es agarrar el mayo suma con el minimo y con el otro y ver a que lado se acerca mas
    //12, 18 vemos que esta mas cerca al lado izquiero entonces el puntero al indice izquierdo tiene que subir y dice 11+2  encontrado
    ////haciendo lo mismo para 11; 
    //en caso sea la suma menor o igual baja del mayor a uno antes y


    //suma con el menor suma con el mayor
    
    return 0;
}