#include<iostream>
#include<cstring>
using namespace std;
    struct Item
    {
        char *descripcion; //arrgelo dinamico 
        int cantidad;
        double precioUnitario;
    };
    struct Pedido
    {
        int numeroPedido;
        char* nombreCliente;  //memoria dinamica
        Item* items;  //arreglo dinamico de items
        int cantidadItems;
    };
    Item crearItem(const char* descripcion,int cantidad, double precio){
        Item item;
        item.descripcion = new char[strlen(descripcion)+1];
        strcpy(item.descripcion,descripcion);
        item.cantidad = cantidad;
        item.precioUnitario=precio;
        return item;
    }

    Pedido *crearPedido(int numero, const char* cliente, int cantidadItems){
        Pedido *M=new Pedido;
        M->numeroPedido = numero;
        M->cantidadItems = cantidadItems;

        M->nombreCliente =new char[strlen(cliente)+1];
        strcpy(M->nombreCliente,cliente);
        
        M->items = new Item[cantidadItems];

        return M;

    }

    double calcularTotal(const Pedido* p){
        //Sumatoria de la cantidad por el precio unitario
        double Total=0;
        for(int i=0;i<p->cantidadItems;i++){
            Total=Total+((p->items[i].cantidad)*(p->items[i].precioUnitario));
        }
        return Total;
    }

    Item* itemMasCaro(Pedido *p){
        if(p->cantidadItems==0){
            return nullptr;
        }
        int indice=0;
        for(int i=1;i<p->cantidadItems;i++){
            if(p->items[i].precioUnitario > p->items[indice].precioUnitario){
                indice=i;
            }
        }
        return &p->items[indice];
    }

    void liberarPedido(Pedido *p){
        for(int i=0;i<p->cantidadItems;i++){
            delete [] p->items[i].descripcion ;
        }
        delete[] p->items;

        delete[] p->nombreCliente;

        delete p;
    }

int main(){
    Pedido *p= crearPedido(101,"Carlos Perez",3);
    p->items[0]=crearItem("Laptop",1,100);
    p->items[1]=crearItem("Mouse",2,200);
    p->items[2]=crearItem("Teclado",3,300);

    cout<<"Pedido N°:"<<p->numeroPedido<<endl;
    cout<<"Cliente: "<<p->nombreCliente<<endl;
    cout<<"Items: "<<endl;
    for(int i=0;i<p->cantidadItems;i++){
        cout<<"_ "<<p->items[i].descripcion<<"| cant: "<<p->items[i].cantidad<<" | Precio: "<<p->items[i].precioUnitario<<endl;
    }
    liberarPedido(p);

    
    
    return 0;
}