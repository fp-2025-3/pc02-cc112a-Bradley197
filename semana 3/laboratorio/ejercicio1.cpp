//strtok
#include<iostream>
#include<cstdlib>
using namespace std;
int separar_palabras(char* texto, char* palabras[]){
char *p=texto;
int i=0;
while(*p!='\0'){
    if(p==texto && *p!=' '){
        palabras[i]=p;
        i++;
    }
    else if(p > texto &&*p!=' '&&*(p-1)==' '){
        palabras[i]=p;
        i++;
    }
    p++;
}
return i;
};
int longitud_palabra(const char* p){
    int contador=0;
    while(*p!=' '&&*p!='\0'){
        p++;
        contador++;
    }
    return contador;
};
void clasificar(char* palabras[], int n,
                char* cortas[], int& nc,
                char* largas[], int& nl){
                    nc=0;
                    nl=0;
                    for(int i=0;i<n;i++){
                        if(longitud_palabra(palabras[i])<=3){
                           cortas[nc]=palabras[i];
                           nc++;   
                        }
                        if(longitud_palabra(palabras[i])>3){
                           largas[nl]=palabras[i];
                           nl++;  
                        }
                    }
                };
int comparar_palabras(const char* a, const char* b){
    while(*a!='\0'&&*b!='\0'&&*a!=' '&&*b!=' '&&*a == *b){
        a++;
        b++;
    }
    char c1 = *a;
    char c2 = *b;

    if (c1 == ' '){
      c1 = '\0';
    };
    if (c2 == ' '){
       c2 = '\0'; 
    };

    return (c1 - c2);
}
void ordenar(char* v[], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(comparar_palabras(v[j],v[j+1])>0){
                swap(v[j],v[j+1]);
            }
        }
    }
};
void imprimir_grupo(const char* titulo, char* v[], int n){
    cout<<titulo<<endl;
    for(int i=0;i<n;i++){
        char* p = v[i];
        while(*p!='\0'&&*p!=' '){
            cout<<*p;
            p++;
        }
        cout<<endl;
    }
};
int main(){

char texto[300]="Hi my name is raul";
char* palabras[60];
char* cortas[60];
char* largas[60];
int nc=0,nl=0;

int n= separar_palabras(texto,palabras);
clasificar(palabras,n,cortas,nc,largas,nl);
ordenar(cortas,nc);
ordenar(largas,nl);
imprimir_grupo("Palabras cortas: ",cortas,nc);
imprimir_grupo("Palabras largas: ",largas,nl);
    return 0;
}