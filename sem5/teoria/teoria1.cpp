#include<iostream>
using namespace std;
struct estudiante{
    int codigo;
    double promedio;
};
estudiante* leerDatos(estudiante *A, int N){
    cout<<"INGRESE LOS ESTUDIANTES "<<endl;
for(int i=0;i<N;i++){
    cout<<"Estudiante "<<i+1<<endl;
    cout<<"Codigo: ";
    cin>>A[i].codigo;
    cout<<"Promedio: ";
    cin>>A[i].promedio;
}
return A;
}

void promedio10(estudiante *A, int N){
    cout<<"LOS ALUMN0S QUE APROVARON SON: "<<endl;
    for(int i=0;i<N;i++){
        if(A[i].promedio>=10){
            cout<<"Codigo : "<<A[i].codigo<<"       Promedio : "<<A[i].promedio;
        }
        cout<<endl;
    }
}
int main(){
    int N;
    cout<<"Ingrese la cantidad de estudiantes: "<<endl;
    cin>>N;

    estudiante *A = new estudiante[N];
    leerDatos(A,N);
    promedio10(A,N);

    delete[] A;
    return 0;
}