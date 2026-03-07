#include<iostream>
using namespace std;

void subMatriz(int i1, int j1, int i2, int j2, int A[4][5], int res[10][10]) {
    int filas = i2 - i1 + 1;
    int columnas = j2 - j1 + 1;

    if (filas <= 0 || columnas <= 0) return;

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            // A[i][j] con punteros es *(*(A + i) + j)
            *(*(res + i) + j) = *(*(A + i1 + i) + j1 + j);
        }
    }
}

int sumaMatriz(int filas, int columnas, int M[10][10]) {
    int suma = 0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            suma += *(*(M + i) + j);
        }
    }
    return suma;
}

void matrixMax(int A[4][5]) {
    int sumaMAX = -999999;
    int bi1, bj1, bi2, bj2;
    int temp[10][10]; 

    for (int i1 = 0; i1 < 4; i1++) {
        for (int j1 = 0; j1 < 5; j1++) {
            for (int i2 = i1; i2 < 4; i2++) {
                for (int j2 = j1; j2 < 5; j2++) {
                    
                    subMatriz(i1, j1, i2, j2, A, temp);
                    int f = i2 - i1 + 1;
                    int c = j2 - j1 + 1;
                    int sumaActual = sumaMatriz(f, c, temp);

                    if (sumaActual > sumaMAX) {
                        sumaMAX = sumaActual;
                        bi1 = i1; bj1 = j1;
                        bi2 = i2; bj2 = j2;
                    }
                }
            }
        }
    }
    cout<<"Suma Maxima: "<<sumaMAX<< endl;
    cout<<"Coordenadas: ("<<bi1<<"," <<bj1<< ") a ("<<bi2<<","<<bj2<<")"<< endl;
}

int main() {
    int A[4][5] = {
        {-2, 1, -3, 4, -1},
        { 2, 3, -2, 1, -5},
        {-1, 4,  2, -3, 2},
        { 1,-2,  3,  4, -1}
    };

    matrixMax(A);
    return 0;
}