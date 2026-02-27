#include<iostream>
#include<fstream>
using namespace std;
struct Venta {
    int idVenta;
    int idVendedor;
    int idProducto;
    int cantidad;
    double precioUnitario;
};
int main(){ 
    ofstream file1("reporte.txt");
    ifstream file("ventasss.dat",ios::binary);
    if(!file1||!file){
        cout<<"El archivo no se abre"<<endl;
        return 1;
    }
    int totalElementos=0;
    double monto=0;
    int idVendedor;
    int totalVendidoVendedor;
    int idProducto;
    int totalProductos;
    int nv=0;
    int np=0;
    int idSospechoso;
    Venta venta;
    while(file.read((char*)&venta,sizeof(Venta))){
        totalElementos++;
        monto+=(venta.cantidad)*(venta.precioUnitario); 
    }
    int *productos = new int[totalElementos];
    int *vendedores = new int[totalElementos];

    file.seekg(0, ios::beg);
    //cuantos vendedores hay
    for(int i=0;i<totalElementos;i++){
        for(int j=0;j<nv;j++){
            bool Existe = false;
            if(vendedores[j]==venta.idVendedor){
                Existe = true;
                break;
            }else{
                vendedores[nv++]=venta.idVendedor;
            }
        }
        for(int j=0;j<np;j++){
            bool Existe=false;
            if(productos[j]==venta.idProducto){
                Existe=true;
                break;
            }else{
                productos[np++]=venta.idProducto;
            }
        }
    }
    for(int i=0;i<totalElementos;i++){
        for(int j=0;j<nv;j++){
            if(vendedores[j]==venta.idVendedor){
                totalVendidoVendedor+=(venta.cantidad)*(venta.precioUnitario);
            }
        }
        for(int j=0;j<np;j++){
            if(productos[j]==venta.idProducto){
                totalProductos++;
            }
        }
    }
    
    file1<<"---REPORTE GENERAL DE VENTAS---"<<endl;
    file1<<"Total de registros: "<<totalElementos<<endl;
    file1<<"MONTO TOTAL VENDIDO: "<<endl;
    file1<<monto<<endl<<endl;
    file1<<"-------------------"<<endl;
    file1<<"VENDEDOR CON MAYOR RECAUDACIÓN:"<<endl;
    file1<<"ID Vendedor: "<<idVendedor<<endl;
    file1<<"Total vendido: "<<totalVendidoVendedor<<endl<<endl;
    file1<<"-------------------"<<endl;
    file1<<"PRODUCTO MÁS VENDIDO: "<<endl;
    file1<<"ID Producto: "<<idProducto<<endl;
    file1<<"Total unidades: "<<totalProductos<<endl<<endl;
    file1<<"-----------------------"<<endl;
    file1<<"VENTAS SOSPECHOSAS: "<<endl;
    file1<<"sospechoso "<<idSospechoso<<endl;

    return 0;
}