#include<iostream>
using namespace std;
class Libro{
    private:
    string titulo;
    string autor;
    int paginas;

    void numeroCuenta();//funcion en privado

    public:
    //constructor con parametros
    Libro(string t, string a, int p):titulo(t),autor(a),paginas(p) {};//se inicializo con : ... es buena practica

    //getter
    string getTitulo()const{//el const es buena ṕractica ya que solo va a obtener los datos
        //cout<<"se ejecuto el constructor"<<endl;
        return titulo;
    }//no cambia ningun valor de esos datos es como si estubiera leendo, devuelve


    //setter (establece valores)
    void setTitulo(string t){
        titulo = t;
    }//puede inicializar puede alterar


    void mostrarInfo(){
        cout<<"Titulo: "<<titulo<<", Autor: "<<autor<<", Paginas: "<<paginas;
    }

};
int main(){
    //crear instancias, crer vcariables de ese tipo o crear objetos
    Libro libro1("El principito","Antoine",100);//invoca al constructor, probar poniendo algo en el constructor "se ejecuto el constructor"
    Libro libro2("Don quijote","cervantes",800);

    //cada objeto tiene su porpio estado(valores que tiene cada dato)
    libro1.mostrarInfo();
    libro2.mostrarInfo();

    //si cambiamos el titulo de principito de libro1
    libro1.setTitulo("El principito - Nueva Edicion");
    cout<<"Despues de cambiar el titulo"<<endl;
    libro1.mostrarInfo();
    libro2.mostrarInfo();
    return 0;
}