#include<iostream>
#include<fstream>
using namespace std;
struct punto{
    double x,y;
};

int main(){
    ifstream archivoIn("laguna.txt");
    ofstream archivoOut("area.txt");
    if(!archivoIn||!archivoOut){
        cout<<"no se puede abrir"<<endl;
        return 1;
    }
    int nt,nv;
    archivoIn>>nt;
    archivoIn>>nv;

    punto* vertice=new punto[nv];
    for(int i=0;i<nv;i++){
        archivoIn>>vertice[i].x>>vertice[i].y;
    }

    double areaTotal=0;
    for(int i=0;i<nt;i++){
        int v1,v2,v3;
        archivoIn>>v1>>v2>>v3;
        punto p1=vertice[v1-1];
        punto p2=vertice[v2-1];
        punto p3=vertice[v3-1];

        double resultadoFormula = ((p1.x*(p2.y-p3.y))+p2.x*(p3.y-p1.y)+p3.x*(p1.y-p2.y));

        if(resultadoFormula<0){
            resultadoFormula=-resultadoFormula;
        }
        double areaTriangulo=resultadoFormula/2.0;
        areaTotal+=areaTriangulo;

    }
    archivoOut<<"Area "<<areaTotal<<endl;
    cout<<"Se acabo"<<endl;
    archivoIn.close();
    archivoOut.close();
    delete[] vertice;

    return 0;
}