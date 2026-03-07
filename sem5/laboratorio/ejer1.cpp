#include<iostream>
using namespace std;
struct estudiante{
    char nombre[20];
    int nota;
};
void mayor(estudiante *A, int N){
int mayor=0;
for(int i=0;i<N;i++){
if(mayor<A[i].nota){
  mayor=A[i].nota;
}
}

for(int i=0;i<N;i++){
  if(mayor==A[i].nota){

    cout<<"El estuduiante con mayor nota es: "<< A[i].nombre <<" con promedio: "<<mayor;
  }
}

}
int main(){
  int N;
  cout<<"Ingrese la cantidad de estudiantes"<<endl;
  cin>>N;
estudiante *A = new estudiante[N];
for(int i=0;i<N;i++){
  cout<<"Ingrese el nombre y nota del estudiante "<<i+1<<" : "<<endl;
  cin>>A[i].nombre;
  cin>>A[i].nota;
}
mayor(A,N);
delete[] A;
return 0;
}
