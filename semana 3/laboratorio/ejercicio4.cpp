#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void genMatriz(int matriz[9][9]){
    for(int (*p)[9]=matriz;p<matriz+9;p++){
        int i=1;
        for(int *columna=*p;columna<*p+9;columna++){
            *columna=i++;
        }
        for(int j=0;j<9;j++){
            int k=rand()%9;
            swap(*(*p+j),*(*p+k));
        }
    }
}
void imprimirMatriz(int (*p)[9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<*(*(p+i)+j)<<" ";
        }
        cout<<endl;
    }
}
//ahora buscar el valor del elemento 
int encontrarElemento(int (*p)[9],int fila,int columna){
    return *(*(p+fila)+columna);
}
//mover todas las matrices de forma de que en esa columa este ese numero que buscabamos
//void matrizMovida(int (*p)[9],int fila,int columna){
    //primero encontrar sus elementos y si es positiva la resta avanzar sino retroceder
    
//}
int main(){
srand(time(0));
int matriz[9][9];
genMatriz(matriz);
imprimirMatriz(matriz);
int fila;
int columna;
cout<<"Ingrese fila inicial(1-9): "<<endl;
cin>>fila;
fila=fila-1;
cout<<"Ingrese columna inicial:(1-9) "<<endl;
cin>>columna;
columna=columna-1;
cout<<"El elemento es: "<<endl;
int elemento = encontrarElemento(matriz,fila,columna);
cout<<elemento<<endl;
return 0;
}