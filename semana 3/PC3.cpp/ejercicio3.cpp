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
            swap((*p)[j], (*p)[k]);

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
void rotarFila(int fila[9], int desplazamiento) {
    int aux[9];

    for (int i = 0; i < 9; i++) {
        aux[(i + desplazamiento + 9) % 9] = fila[i];
    }

    for (int i = 0; i < 9; i++) {
        fila[i] = aux[i];
    }
}

void recorrer(int matriz[9][9], int elemento, int columnaObjetivo) {
    for (int i = 0; i < 9; i++) {
        int columnaActual = -1;

        for (int j = 0; j < 9; j++) {
            if (matriz[i][j] == elemento) {
                columnaActual = j;
                break;
            }
        }

        if (columnaActual != -1) {
            int desplazamiento = columnaObjetivo - columnaActual;
            rotarFila(matriz[i], desplazamiento);
        }
    }
}


int main(){
srand(time(0));
int matriz[9][9];
genMatriz(matriz);
imprimirMatriz(matriz);

int fila, columna;
cout << "Ingrese fila inicial(1-9): "<< endl;
cin >> fila;
fila = fila - 1;

cout << "Ingrese columna inicial:(1-9) "<< endl;
cin >> columna;
columna = columna - 1;

int elemento = encontrarElemento(matriz,fila,columna);
cout << "El elemento es: " << elemento << endl;
recorrer(matriz, elemento, columna);
cout << "\nMatriz movida:\n";
imprimirMatriz(matriz);

return 0;
}
