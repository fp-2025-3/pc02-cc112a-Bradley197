#include<iostream>
#include<fstream>
using namespace std;
float totalVentas(){
    ifstream lectura("ventas.txt");
    float total=0;
    float venta;
    if(!lectura){
        cout<<"El archivo no abre"<<endl;
        return 0;
    }
    while(lectura>>venta){
        total+=venta;
    }
    lectura.close();
    return total;
}
float promedio(float total,const int Dias){
    int prom=total/Dias;
    return prom;
}
float mayorCompra(){
    ifstream lectura("ventas.txt");
    float mayor=0;
    float venta;
    if(!lectura){
        cout<<"El archivo no se abre :"<<endl;
        return 0;
    }
    while(lectura>>venta){
        if(mayor<venta){
            mayor=venta;
        }
    }
    return mayor;
}
float menorCompra(){
    ifstream lectura("ventas.txt");
    float menor=100000;
    float venta;
    if(!lectura){
        cout<<"El archivo no se abre :"<<endl;
        return 0;
    }
    while(lectura>>venta){
        if(menor>venta){
            menor=venta;
        }
    }
    return menor;
}
int main(){
    ofstream archivo("ventas.txt",ios::app);
    if(!archivo){
        cout<<"Error al abrir l archivo";
        return 1;
    }
    const int Dias=7;
    float venta;
    for(int i=0;i<=Dias;i++){
        cout<<"Ingrese la venta del dia "<<i<<" :";
        cin>>venta;
        archivo<<venta<<endl;
   }
   cout<<"____________________________"<<endl;
   cout<<"RESUMEN"<<endl;
   float tot=totalVentas();
   cout<<"El total de la semana es : "<<tot<<endl;
   cout<<"El promedio de la semana es :"<<promedio(tot,Dias)<<endl;
   cout<<"La mayor compra fue :"<<mayorCompra()<<endl;
   cout<<"La menor compra fue :"<<menorCompra()<<endl;

    return 0;
}