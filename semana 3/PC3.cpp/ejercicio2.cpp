#include<iostream>
using namespace std;
int contarPalabrasConVocal(char *texto){
    int contador = 0;
    char *p = texto;

    while(*p != '\0'){
        if((*p=='a'||*p=='e'||*p=='i'||*p=='o'||*p=='u'||
            *p=='A'||*p=='E'||*p=='I'||*p=='O'||*p=='U') &&
           (p == texto || *(p-1) == ' ')){
            contador++;
        }
        p++;
    }
    return contador;
}
int main(){
    char texto[] = "HI Pitufos A e i";
    cout << "Palabras que inician con vocal: "<< contarPalabrasConVocal(texto) << endl;
    return 0;
}

