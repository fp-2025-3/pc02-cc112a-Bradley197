#include<iostream>
#include<string>
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
    int idVendedor=0;
    int idProducto=0;
    int nv=0;
    int np=0;
    Venta venta;
    while(file.read((char*)&venta,sizeof(Venta))){
        totalElementos++;
        monto+=(venta.cantidad)*(venta.precioUnitario); 
    }
    int *productos = new int[totalElementos];
    int *vendedores = new int[totalElementos];
    file.clear();
    file.seekg(0, ios::beg);
    //cuantos vendedores hay
    for(int i=0;i<totalElementos;i++){
        file.read((char*)&venta,sizeof(Venta));
        bool ExisteV = false;
        for(int j=0;j<nv;j++){
            if(vendedores[j]==venta.idVendedor){
                ExisteV = true;
                break;
            }
        }
        if(!ExisteV){
                vendedores[nv++]=venta.idVendedor;
            }
        bool ExisteP=false;
        for(int j=0;j<np;j++){
            if(productos[j]==venta.idProducto){
                ExisteP=true;
                break;
            }
        }
        if(!ExisteP){
                productos[np++]=venta.idProducto;
        }
    }

    file.clear();
    file.seekg(0, ios::beg);
    double *totalVendidoVendedors=new double[nv]{};
    int *totalProductos=new int[np]{};
    for(int i=0;i<totalElementos;i++){
        file.read((char*)&venta,sizeof(Venta));
        for(int j=0;j<nv;j++){
            if(vendedores[j]==venta.idVendedor){
                totalVendidoVendedors[j]+=(venta.cantidad)*(venta.precioUnitario);
                
                
            }
        }
        for(int j=0;j<np;j++){
            if(productos[j]==venta.idProducto){
                totalProductos[j]+=venta.cantidad;
            }
        }
    }
    double maxMonto=-1;
    int maxProductos=-1;
    for(int i=0;i<nv;i++){
        if(totalVendidoVendedors[i]>maxMonto){
            maxMonto=totalVendidoVendedors[i];
            idVendedor=vendedores[i];
        }
    }
    for(int i=0;i<np;i++){
        if(totalProductos[i]>maxProductos){
            maxProductos=totalProductos[i];
            idProducto=productos[i];
        }
    }

    
    file1<<"---REPORTE GENERAL DE VENTAS---"<<endl;
    file1<<"Total de registros: "<<totalElementos<<endl;
    file1<<"MONTO TOTAL VENDIDO: "<<endl;
    file1<<monto<<endl<<endl;
    file1<<"-------------------"<<endl;
    file1<<"VENDEDOR CON MAYOR RECAUDACIÓN:"<<endl;
    file1<<"ID Vendedor: "<<idVendedor<<endl;
    file1<<"Total vendido: "<<maxMonto<<endl<<endl;
    file1<<"-------------------"<<endl;
    file1<<"PRODUCTO MÁS VENDIDO: "<<endl;
    file1<<"ID Producto: "<<idProducto<<endl;
    file1<<"Total unidades: "<<maxProductos<<endl<<endl;
    file1<<"-----------------------"<<endl;

    file.clear();
    file.seekg(0, ios::beg);
    string listaSospechosos="";
    for(int i=0;i<totalElementos;i++){
        file.read((char*)&venta,sizeof(Venta));
        if(venta.cantidad>100){
            listaSospechosos += to_string(venta.idVenta) + "\t | ID Vendedor: "+
            to_string(venta.idVendedor) + "\t | ID Producto: "+to_string(venta.idProducto)
            + "\t | Cantidad: "+ to_string(venta.cantidad)+"\n";
        }
    }
    file1<<"VENTAS SOSPECHOSAS: "<<endl;
    file1<<"ID Venta: "<<endl;
    file1<<listaSospechosos;
    delete[] productos;
    delete[] vendedores;
    delete[] totalProductos;
    delete[] totalVendidoVendedors;
    return 0;
}