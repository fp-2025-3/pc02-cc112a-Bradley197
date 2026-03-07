#include<iostream>
#include<fstream>
using namespace std;
void escrbirFibonacciBinario(){
ofstream archiboBin("fibonacci.bin",ios::out|ios::binary);
if(!archiboBin){
    cout<<"error"<<endl;
    return;
}
int *elemento=new int[20];
elemento[0]=0;
elemento[1]=1;
for(int i=2;i<20;i++){
    elemento[i]=elemento[i-1]+elemento[i-2];
}
archiboBin.write((char*)elemento,sizeof(int)*20);
archiboBin.close();
delete[] elemento;
};
void leerFibonacciBinario(){
ifstream archiboLeer("fibonacci.bin",ios::in|ios::binary);
if(!archiboLeer){
    cout<<"nO SE PUEDE ABRIR"<<endl;
    return;
}
int valorLeer;
cout<<"El contenido es: "<<endl;
while(archiboLeer.read((char*)&valorLeer,sizeof(int))){
    cout<<valorLeer<<" ";
}
cout<<endl;
archiboLeer.close();
};
int main(){
    escrbirFibonacciBinario();
    leerFibonacciBinario();
    return 0;
}