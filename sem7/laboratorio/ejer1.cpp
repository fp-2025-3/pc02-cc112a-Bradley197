#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream file1,file2;
    file1.open("entradas/archivo1.txt");
    file2.open("entradas/archivo2.txt");
    if(!file1||!file2){
        cout<<"No se abre error"<<endl;
        return 1;
    }
    ofstream file3("output/mezcla1.txt",ios::app);
    if(!file3){
        cout<<"No se abre error"<<endl;
        return 1;
    }
    int elemento1;
    int elemento2;
    file1>>elemento1;
    file2>>elemento2;
    while(elemento1!=-1&&elemento2!=-1){
        if(elemento1<elemento2){
            file3<<elemento1<<endl;
            file1>>elemento1;
        }else if(elemento1>elemento2){
            file3<<elemento2<<endl;
            file2>>elemento2;
        }else{
            file3<<elemento1<<endl;
            file3<<elemento2<<endl;
            file1>>elemento1;
            file2>>elemento2;                        
        }
    }
    if(elemento1==-1){
    while(elemento2!=-1){
            //imprimir elemento2
            file3<<elemento2<<endl;
            file2>>elemento2; 
    }
}

if(elemento2==-1){
    while(elemento1!=-1){
            //imprimir elemento2
            file3<<elemento1<<endl;
            file1>>elemento1;
    }
}
    return 0;
}