#include<iostream>
#include<cstring>
using namespace std;
struct producto
{
    int codigo;
    char *nombre; //cadena dinamica
    double precio;
    int stock;
};
producto crearProducto(int codigo,const char* nombre,double precio,int stock){
    producto p;
    p.nombre = new char[strlen(nombre)+1];
    strcpy(p.nombre,nombre);
    p.codigo=codigo;
    p.precio=precio;
    p.stock=stock;

    return p;
}
producto* crearInventario(int n){
    producto* inventario=new producto[n];
    const char* nombre[]={"Teclado","Mouse","Monitor","laptop","Impresora"};
    double precios[]={10.5,21.0,31.5,42.0,52.5};
    for(int i=0;i<n;i++){
        inventario[i]=crearProducto(100+i,nombre[i%5],precios[i%5],(i+1)*5);
        
    }
    return inventario;
}
producto* buscarProducto(producto* inventario, int n, int codigoBuscado){
    for(int i=0;i<n;i++){
        if(inventario[i].codigo==codigoBuscado){
            return &inventario[i];
        }
    }
    return nullptr;
}
void liberarInventario(producto* inventario,int n){
    for(int i=0;i<n;i++){
        delete[] inventario[i].nombre;
    }
    delete[] inventario;
}
int main(){
    int n=5;
    producto* miInventario = crearInventario(n);
    cout<<"INVENTARIO"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Codigo: "<<miInventario[i].codigo<<"| Nombre: "<<miInventario[i].nombre<<"| Precio: "<<miInventario[i].precio<<"| Stock: "<<miInventario[i].stock<<endl;
    }
    int buscar = 102;
    cout<<"Buscando Producto con cod "<<buscar<<"..."<<endl;
    producto* encontrado=buscarProducto(miInventario,n,buscar);

    if(encontrado){
        cout<<"Producto encontrado: "<<encontrado->nombre<<"| Precio:"<<encontrado->precio<<endl;
    }else{
        cout<<"Producto no encontrado"<<endl;
    }

    liberarInventario(miInventario,n);
    
    return 0;
}