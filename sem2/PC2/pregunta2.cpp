#include <iostream>
using namespace std;

// Complete la funcion de busqueda

int* buscar(
    int* inicio,                 // Estos dos primeros parametros
    int* fin,                    // delimitan el rango de busqueda a [inicio, fin)
    bool (*equivale)(int, int),  // equivale es una funcion que determina cuando dos enteros se condideran equivalentes
    int clave                    // clave es el valor a buscar segun el criterio indicado
) {
    // Complete aqui
    for(int *ptr=inicio;ptr<fin;ptr++){
        if(equivale(*ptr,clave)){
            return ptr;
        }
    }
   return nullptr;
};

// Implemente aqui los Criterios de equivalencia
bool igual(int a,int b){
    if(a==b){
        return true;
    }else{
        return false;
    }
}
bool mismaParidad(int a, int b) {
    if (a < 0 || b < 0) {
        return false;
    }

    if (a % 2 == b % 2) {
        return true;
    } else {
        return false;
    }
}
bool divideA(int a, int b){
    if (a == 0) return false; 
    return (b % a == 0);
}
bool mismaCantidadDigitos(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    int cantA = 0;
    if (a == 0) cantA = 1;
    while (a > 0) {
        a /= 10;
        cantA++;
    }
    int cantB = 0;
    if (b == 0) cantB = 1;
    while (b > 0) {
        b /= 10;
        cantB++;
    }
    return cantA == cantB;
}
bool mismoResiduo(int a,int b){
    int residuoA=a%5;
    int residuoB=b%5;
    if(residuoA==residuoB){
        return true;
    }else{
        return false;
    }
}
// y si es necesario algunas funciones adicionales para reproducir el ejemplo de salida



int main() {
    int A[] = { -1, 21, 2, -2, 8, 13, 25 };
    int* inicio = A;
    int* fin = A + 7;

    int clave = 13;

    // Imprima el arreglo

    // Llame a la funcion buscar para cada criterio implementado
    cout << "Arreglo: "<<endl;
    for(int* p = inicio; p < fin; p++) cout << *p << " ";
    cout << "Clave: " << clave << endl;

    int* res; 
    res = buscar(inicio, fin, igual, clave);
    if(res) cout << "Igualdad exacta: encontrado valor: " << *res << " Pos: " << res << endl;

    res = buscar(inicio, fin, mismaParidad, clave);
    if(res) cout << "Misma paridad: encontrado valor: " << *res << " Pos: " << res << endl;

    res = buscar(inicio, fin, divideA, clave);
    if(res) cout << "Divide a: encontrado valor: " << *res << " Pos: " << res << endl;

    res = buscar(inicio, fin, mismaCantidadDigitos, clave);
    if(res) cout << "Misma cantidad de digitos: encontrado valor: " << *res << " Pos: " << res << endl;

    res = buscar(inicio, fin, mismoResiduo, clave);
    if(res) cout << "Mismo residuo modulo 5: encontrado valor: " << *res << " Pos: " << res << endl;
 

    return 0;
}