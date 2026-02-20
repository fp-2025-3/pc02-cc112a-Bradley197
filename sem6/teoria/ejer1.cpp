#include<iostream>
#include<fstream>
using namespace std;
struct estudiante{
    int codigo;
    char nombre[50];
    float promedio;
};
void guardarTexto(estudiante* arr, int n){
    ofstream archivo("notas.txt");
    for(int i=0;i<n;i++){
        archivo<<arr[i].codigo<<" "
        <<arr[i].nombre<<" "
        <<arr[i].promedio<<endl;
    }
    archivo.close();
}
int main(){
    int n;
    cout<<"Ingrese la cantidad de estudiantes: "<<endl;
    cin>>n;
    estudiante *arr=new estudiante[n];
    for(int i=0;i<n;i++){
        cout<<"Ingrese estudiante numero "<<i+1<<" :"<<endl;
        cin>>arr[i].codigo>>arr[i].nombre>>arr[i].promedio;
    }
    guardarTexto(arr,n);
    delete[] arr;
    return 0;
}