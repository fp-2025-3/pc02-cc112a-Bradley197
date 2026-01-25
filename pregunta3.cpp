#include <iostream>
using namespace std;

const int F = 4;
const int C = 5;

bool esPico(int matriz[10][10], int i, int j, int filas, int columnas) {
    int actual = *(*(matriz + i) + j); 
    
    bool mayorIgual = true;
    bool estrictamenteMayor = false;

    int di[] = {-1, 1, 0, 0};
    int dj[] = {0, 0, -1, 1};

    for (int k = 0; k < 4; k++) {
        int ni = i + di[k];
        int nj = j + dj[k];

        if (ni >= 0 && ni < filas && nj >= 0 && nj < columnas) {
            int vecino = *(*(matriz + ni) + nj); 
            
            if (actual < vecino) mayorIgual = false;
            if (actual > vecino) estrictamenteMayor = true;
        }
    }
    return mayorIgual && estrictamenteMayor;
}

void recorrerMatriz(int matriz[10][10], int filas, int columnas) {
    cout << "Elementos pico:" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (esPico(matriz, i, j, filas, columnas)) {
                cout << "Pico en (" << i << "," << j << ") : " << *(*(matriz + i) + j) << endl;
            }
        }
    }
}

int main() {

    int matriz[10][10] = {
        {3, 3, 3, 3, 3},
        {3, 4, 4, 2, 3},
        {3, 4, 5, 4, 3},
        {3, 3, 3, 3, 3}
    };

    recorrerMatriz(matriz, F, C);

    return 0;
}