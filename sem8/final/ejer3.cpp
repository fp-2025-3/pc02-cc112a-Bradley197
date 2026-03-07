#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
struct Proyecto {
    int id;
    char titulo[40];
    double presupuesto;
    int duracionMeses;
};
int contarRegistros(fstream& archivo){
    archivo.seekg(0,ios::end);
    return archivo.tellg()/sizeof(Proyecto);
}
void abrirArchivo(fstream& archivo){
    archivo.open("proyectos.dat",ios::binary|ios::in|ios::out);
    if(!archivo){
        archivo.open("proyectos.dat",ios::binary|ios::out);
        archivo.close();
        archivo.open("proyectos.dat",ios::binary|ios::in|ios::out);
    }
}

bool existeId(fstream& archivo, int id){
    int total = contarRegistros(archivo);
    Proyecto temp;
    for(int i=0;i<total;i++){
        archivo.seekg(i*sizeof(Proyecto), ios::beg);
        archivo.read((char*)&temp, sizeof(Proyecto));
        if(temp.id == id){
            return true;
        }
    }
    return false;
}

void crearArchivo(int N){
    fstream archivo;
    abrirArchivo(archivo);
    for(int i=0;i<N;i++){
        Proyecto p;
        cout<<endl<<"Proyecto"<<(i+1)<<" :"<<endl;
        cout<<"ID: "<<endl;
        cin>>p.id;
        if(existeId(archivo, p.id)){
            cout<<"Ya existe un archivo con este id"<<endl;
            i--;
            continue;
        }
        cout<<"Titulo: "<<endl;
        cin>>p.titulo;
        cout<<"Presupuesto: "<<endl;
        cin>>p.presupuesto;
        cout<<"Duracion meses: "<<endl;
        cin>>p.duracionMeses;

        int total=contarRegistros(archivo);

        int pos=total;
        Proyecto temp;
        for(int j=0;j<total;j++){
            archivo.seekg(j*sizeof(Proyecto), ios::beg);
            archivo.read((char*)&temp, sizeof(Proyecto));
            if(p.presupuesto>temp.presupuesto){
                pos = j;
                break;
            }
        }
        for(int j=total;j>pos;j--){
            archivo.seekg((j-1)*sizeof(Proyecto), ios::beg);
            archivo.read((char*)&temp, sizeof(Proyecto));
            archivo.seekp(j*sizeof(Proyecto), ios::beg);
            archivo.write((char*)&temp, sizeof(Proyecto));
        }
        archivo.seekp(pos*sizeof(Proyecto), ios::beg);
        archivo.write((char*)&p, sizeof(Proyecto));

    }
    archivo.close();
}

void insertarProyecto(){
    fstream archivo;
    abrirArchivo(archivo);
    Proyecto p;
    cout<<"ID: "<<endl;
    cin>>p.id;
    if(existeId(archivo,p.id)){
        cout<<"Ya existe uno"<<endl;
        archivo.close();
        return;
    }
    cout<<"Titulo :"<<endl;
    cin>>p.titulo;
    cout<<"Presupuesto: "<<endl;
    cin>>p.presupuesto;
    cout<<"Duracion meses: "<<endl;
    cin>>p.duracionMeses;
    int total = contarRegistros(archivo);
    int pos=total;
    Proyecto temp;
    for(int j=0;j<total;j++){
        archivo.seekg(j*sizeof(Proyecto), ios::beg);
        archivo.read((char*)&temp, sizeof(Proyecto));
        if(p.presupuesto > temp.presupuesto){
            pos=j;
            break;
        }
    }
    for(int j=total;j>pos;j--){
        archivo.seekg((j-1)*sizeof(Proyecto),ios::beg);
        archivo.read((char*)&temp, sizeof(Proyecto));
        archivo.seekp(j*sizeof(Proyecto), ios::beg);
        archivo.write((char*)&temp, sizeof(Proyecto));
    }
    archivo.seekp(pos*sizeof(Proyecto), ios::beg);
    archivo.write((char*)&p, sizeof(Proyecto));

    archivo.close();
    cout<<"Producto insertado"<<endl;
}
void mostrarProyectos(){
    fstream archivo;
    abrirArchivo(archivo);
    int total=contarRegistros(archivo);
    if(total==0){
        cout<<"No hay proyectos"<<endl;
        archivo.close();
        return;
    }
    Proyecto p;
    archivo.seekg(0,ios::beg);
    while(archivo.read((char*)&p, sizeof(Proyecto))){
        cout<<"ID: "<<p.id<<endl;
        cout<<"Titulo: "<<p.titulo<<endl;
        cout<<"Presupuesto: "<<p.presupuesto<<endl;
        cout<<"Duracion meses: "<<p.duracionMeses<<endl;
    }
    archivo.close();
}

int main(){
    int opcion;
    do{
        cout<<"SISTEMA DE PROYECTOS"<<endl;
        cout<<"1.Crear archivos con N proyectos"<<endl;
        cout<<"2.Insertar nuevio proyecto"<<endl;
        cout<<"3.Mostrar todos los proyectos"<<endl;
        cout<<"0.salir"<<endl;
        cout<<"Ingrese opcion"<<endl;
        cin>>opcion;
        if(opcion==1){
            int n;
            cout<<"Cuantos proyectos? "<<endl;
            cin>>n;
                crearArchivo(n);
        }else if(opcion==2){
            insertarProyecto();
        }else if(opcion==3){
            mostrarProyectos();
        }
    }while(opcion!=0);
    
    return 0;
}