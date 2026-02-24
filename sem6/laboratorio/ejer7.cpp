#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
struct punto{
    double x;
    double y;
};
#ifndef M_PI
#define M_PI 3.14259265358979323846
#endif
punto rotar(punto p, double rad){
    punto resultado;
    resultado.x=cos(rad)* p.x - sin(rad)* p.y;
    resultado.y=sin(rad)* p.x + cos(rad)* p.y;
    return resultado;
}
void guardar(){
    ifstream archivo("poligono1.txt");
    ofstream archivoOut("poligono2.txt");
    if(!archivo||!archivoOut){
        cout<<"NO SE ABRE"<<endl;
        return;
    }
    int nv;
    archivo>>nv;
    punto *p = new punto[nv];
    for(int i=0;i<nv;i++){
        archivo>>p[i].x>>p[i].y;
    }
    double angulo;
    cout<<"Ingrese el angulo"<<endl;
    cin>>angulo;
    double rad= angulo*M_PI/180.0;
    archivoOut<<nv<<endl;
    for(int i=0;i<nv;i++){
        punto p_nuevo=rotar(p[i],rad);
        archivoOut<< p_nuevo.x<<"  "<<p_nuevo.y<<endl;
    }
    cout<<"Ya esta rotado"<<endl;
    delete[] p;
    archivo.close();
    archivoOut.close();
};
int main(){
    guardar();
    return 0;
}