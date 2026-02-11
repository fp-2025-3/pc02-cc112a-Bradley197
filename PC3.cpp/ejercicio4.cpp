#include<iostream>
using namespace std;
int guardarDireccion(char *texto, char **indice){
    int n=0;
    char *p=texto;
    while(*p != '\0'){
        if(*p != ' '&&(p==texto || *(p-1)==' ')){
            *(indice+n)=p;
            n++;
        }
        p++;
    }
    return n;
}

int comparar(const char *a, const char *b){
    while(*a != ' '&&*a != '\0' &&*b !=' '&&*b!='\0'){
        if(*a != *b){
            return *a -*b;
        }
        a++;
        b++;
    }

    if((*a==' '||*a=='\0')&&(*b==' '||*b=='\0')){
        return 0;
    }
    if((*a==' '||*a=='\0')){
        return -1;
    }
    return 1;
}

void ordenaIndice(char** indice, int n){
    for(int i=0;i<n;i++){
        for(int j=1+i;j<n;j++){
            if(comparar(indice[i], indice[j]) > 0){
             swap(indice[i], indice[j]);
         }

        }
    }
}
void imprimir(char* texto, char** indice, int n){
    for(int i=0;i<n;i++){
        char *p=indice[i];

        while(*p!=' '&&*p!='\0'){
            cout<<*p;
            p++;
        }
        cout<<"   (posicion "<<indice[i]-texto<<")"<<endl;
    }
}
int main(){
    char texto[]="los punteros no se copian se referencian y se ordenan";
    char *indice[20];
    int n=guardarDireccion(texto,indice);
    ordenaIndice(indice,n);
    imprimir(texto,indice,n);
    return 0;
}