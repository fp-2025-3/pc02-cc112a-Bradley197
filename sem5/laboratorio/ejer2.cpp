#include<iostream>
#include<cmath>
using namespace std;
struct punto{
    int x;
    int y;
    int z;
};
double distancia(punto p1, punto p2){
    double suma = (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y) + (p1.z-p2.z)*(p1.z-p2.z);
    double resultado = sqrt(suma);
    return resultado;
}
int main(){
  punto p1;
  cout<<"Ingrese (x,y,z) del p1 : "<<endl;
  cin>>p1.x>>p1.y>>p1.z;
  punto p2;  
  cout<<"Ingrese (x,y,z) del p2 : "<<endl;
  cin>>p2.x>>p2.y>>p2.z;
  cout<<"LA DISTANCIA ENTRE ELLOS ES:  ";
  cout<<distancia(p1,p2);
  return 0;
}