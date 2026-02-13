#include<iostream>
using namespace std;
int main(){
    struct Item
    {
        char *descripcion;
        int cantidad;
        double precioUnitario;
    };
    struct Pedido
    {
        int numeroPedido;
        char* nombreCliente;
        Item* imtes;
        int cantidadItems;
    };
    
    
    return 0;
}