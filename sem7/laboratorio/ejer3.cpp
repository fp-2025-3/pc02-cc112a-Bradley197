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
    ofstream file1("output/reporte.txt");
    ifstream file("entradas/ventas.dat",ios::binary);
    if(!file1||!file){
        cout<<"El archivo no se abre"<<endl;
        return 1;
    }
    int totalElementos;
    file.read((char*)&totalElementos,sizeof(int));//esto de aca para poder leer lo que esta en binario
    double monto=0;

    double totalVendidoVendedorMayor=0;
    double totalProductosMayor=0;
    int idVendedorMayor=0;
    int idProductoMayor=0;
    
    int cantidadVendedores=1;
    //int *vendedores=new int;
    int cantidadProductos=1;
    //int *productos=new int;

    Venta venta;
    file.read((char*)&venta,sizeof(Venta));
    int primerVendedor=venta.idVendedor;
    int primerProducto=venta.idProducto;
    //hallar el vendedor con mayo recaudacion

    for(int i=0;i<200;i++){
        monto+=(venta.cantidad)*(venta.precioUnitario);    
        //para saber que vendedor vendio mas debo saber cuantos vendedores tengo y guardarlos depues suma el total de todo lo que vendieron 

        //necesito saber cuantos id de productos hay y depues guardarlos despues rellenar cada uno de ellos para ver que cantidad tienen y imprimir el mayor

        file.read((char*)&venta,sizeof(Venta));
        //cantidad de vendedores:
        if(primerVendedor!=venta.idVendedor){
            primerVendedor=venta.idVendedor;
            cantidadVendedores++;
        }



        //cantidad de productos:
        if(primerProducto!=venta.idProducto){
            primerProducto=venta.idProducto;
            cantidadProductos++;
        }

    }
    //Volver a recorrer y guardar cada que son diferentes
    file.seekg(sizeof(int), ios::beg);
    int *vendedores=new int[cantidadVendedores];
    int *productos=new int[cantidadProductos];

    primerVendedor=venta.idVendedor;
    vendedores[0]=primerVendedor;
    primerProducto=venta.idProducto;
    productos[0]=primerProducto;
    for(int i=0;i<200;i++){
        for(int j=1;j<cantidadVendedores;j++){
        if(primerVendedor!=venta.idVendedor){
            primerVendedor=venta.idVendedor;
            vendedores[j]=primerVendedor;            
        }            
        }



        //cantidad de productos:
        for(int m=1;m<cantidadProductos;m++){
        if(primerProducto!=venta.idProducto){
            primerProducto=venta.idProducto;
            productos[m]=primerProducto;
        }  
        }
      
    }

    file.seekg(sizeof(int), ios::beg);
    int *totalVendedor = new int[cantidadVendedores]{0};
    int *totalProductos = new int[cantidadProductos]{0};


    for(int i=0;i<200;i++){
        for(int j=0;j<cantidadVendedores;j++){
            if(vendedores[j]==venta.idVendedor){
                totalVendedor[j]+=(venta.cantidad * venta.precioUnitario);
            }
        }
        //comparar su totalvendedor
        for(int k=0;k<cantidadVendedores;k++){
            if(totalVendidoVendedorMayor<totalVendedor[k]){
                totalVendidoVendedorMayor=totalVendedor[k];
                idVendedorMayor=vendedores[k];
            }
        }
        
        
        for(int j=0;j<cantidadProductos;j++){
            if(productos[j]==venta.idProducto){
                totalProductos[j]+=(venta.cantidad * venta.precioUnitario);
            }
        }
        for(int k=0;k<cantidadProductos;k++){
            if(totalProductosMayor<totalProductos[k]){
                totalProductosMayor=totalProductos[k];
                idProductoMayor=productos[k];
            }


    }
}
    file1<<"---REPORTE GENERAL DE VENTAS---"<<endl;
    file1<<"Total de registros: "<<totalElementos<<endl;
    file1<<"MONTO TOTAL VENDIDO: "<<monto<<endl<<endl;
    file1<<"-------------------"<<endl;
    file1<<"VENDEDOR CON MAYOR RECAUDACIÓN:"<<endl;
    file1<<"ID Vendedor: "<<idVendedorMayor<<endl;
    file1<<"Total vendido: "<<totalVendidoVendedorMayor<<endl<<endl;
    file1<<"-------------------"<<endl;
    file1<<"PRODUCTO MÁS VENDIDO: "<<endl;
    file1<<"ID Producto: "<<idProductoMayor<<endl;
    file1<<"Total unidades: "<<totalProductosMayor<<endl;

    delete[] vendedores;
    delete[] totalVendedor;

    delete[] productos;
    delete[] totalProductos;
    return 0;
}