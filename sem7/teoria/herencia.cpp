#include<iostream>
using namespace std;
class Libro {
    private:
        string titulo;
        string autor;
        int paginas;
    
        // void numeroCuenta();
    
    public:
        
        // constructor con parámetros
        Libro(string t, string a, int p):titulo(t), autor(a), paginas(p) {
            cout << "Se ejecuto el constructor con parámetros\n";
        };
    
        // Constructor por defecto
        Libro(){
            cout << "Contructor por defecto ";
        };
    
        // Destructor
        ~Libro(){
            cout << "Llamando al destructor\n";
        };
    
        // getter
        string getTitulo() const {  // buena práctica
            return titulo;
        }
    
        // setter
        void setTitulo(string t) {
            titulo = t;
        }
    
        void mostrarInfo() {
            cout << "Titulo: " << titulo <<", Autor: " << autor << ", Paginas: " << paginas <<endl; 
        }
    
    };
    class libroDigital : public Libro{//sintaxis para implementar HERENCIA
        private:s
        string formato;//PDF, EPUB

        public:
        //no se herdan constructores(debes declarar un nuevo constructor)//Redifiendo un nuevo constructor
        libroDigital(string t, string a, int p,string f):Libro(t,a,p),formato(f){}//Lista de inicializadores
        void mostrarInfoDigital(){
            mostrarInfo();
            cout<<"Formato digital "<<formato<<endl;
        }

    };
int main(){
    libroDigital Id("Cien años de soledad","Marquez",400,"PDF");
    Id.mostrarInfoDigital();
    return 0;
}