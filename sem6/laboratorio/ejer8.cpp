#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct Alumno{
    string apellidos;
    string nombres;
    int nota;
};
void intercambiar(Alumno* lista, int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            bool  debeIntercambiar = false;

            if(lista[j].apellidos>lista[j+1].apellidos){
                debeIntercambiar = true;
            }else if(lista[j].apellidos == lista[j+1].apellidos){
                if(lista[j].nombres>lista[j+1].nombres){
                    debeIntercambiar = true;

                }else if(lista[j].nombres==lista[j+1].nombres){
                    if(lista[j].nota>lista[j+1].nota){
                        debeIntercambiar=true;
                    }
                }
            }
            if(debeIntercambiar){
                Alumno aux=lista[j];
                lista[j]=lista[j+1];
                lista[j+1]=aux;
            }
        }
    }
}
int main(){
    ifstream archivoIn("entrada.csv");
    if (!archivoIn) {
        cout << "Error al abrir Entrada.csv" << endl;
        return 1;
    }
    string linea;
    int contador=0;
    while(getline(archivoIn,linea)){
        if(!linea.empty()){
            contador++;
        }
    }
    archivoIn.clear();
    archivoIn.seekg(0, ios::beg);
    Alumno* lista = new Alumno[contador];
    for(int i=0;i<contador;i++){
        getline(archivoIn,lista[i].apellidos,',');
        getline(archivoIn,lista[i].nombres,',');
        string notaStr;
        getline(archivoIn, notaStr);
        if(!notaStr.empty()){
            lista[i].nota = stoi(notaStr)+2;
        }

    }
    archivoIn.close();
    intercambiar(lista,contador);

    ofstream archivoOut("Salida.csv");
    for(int i=0;i<contador;i++){
        archivoOut << lista[i].apellidos <<","
        <<lista[i].nombres<<","
        <<lista[i].nota<<endl;
    }
    archivoOut.close();
    delete[] lista;
    return 0;
}