#include<iostream>
using namespace std;
int *polinomio(int N,int *polinomiox){
    for(int i=N;i>=0;i--){
        cout<<"Ingrese el coeficiente de x°"<<i<<" :";
        cin>>polinomiox[i];
    }
    return polinomiox;
};
void imprecion(int N,int *polinomiox){
    for(int i=N;i>0;i--){
        cout<<polinomiox[i]<<"x°"<<i<<"+";
    }
    cout<<polinomiox[0];

};

int * suma(int N1,int *polinomio1,int N2,int *polinomio2,int mayor,int menor,int *polinomio3){
    bool lado=true;
    if(N1<N2){
        lado =true;
    }else{
        lado=false;
    }
    for(int i=mayor;i>=0;i--){
        //aca sumarlos
        if(menor==i){
            //aca suma
            polinomio3[i]=polinomio1[i]+polinomio2[i];
            menor--;
        }else{
            if(lado==true){
                polinomio3[i]=polinomio2[i];
            }
            if(lado==false){
                polinomio3[i]=polinomio1[i];
            }
        }
    }
    return polinomio3;
};
void producto(int N1,int *polinomio1,int N2,int *polinomio2){

};


int main(){
    int N1,N2;
    cout<<"Ingrese el grado del primer polinomio: ";
    cin>>N1;
    int *polinomio1=new int[N1+1];
    polinomio(N1,polinomio1);


    cout<<"Ingrese el grado del segundo polinomio: ";
    cin>>N2;
    int *polinomio2=new int[N2+1];
    polinomio(N2,polinomio2);

    cout<<"Pimer polinomio : ";
    imprecion(N1,polinomio1);
    cout<<endl;
    cout<<"Segundo polinomio : ";
    imprecion(N1,polinomio1);
    cout<<endl;
    cout<<"La suma de los polinomios es: ";
    int mayor;
    int menor;
    if(N1<N2){
        mayor=N2;
        menor=N1;
    }else{
        mayor=N1;
        menor=N2;
    }
    int *polinomio3=new int[mayor+1];
    suma(N1,polinomio1,N2,polinomio2,mayor,menor,polinomio3);
    imprecion(mayor,polinomio3);
    cout<<endl;
    cout<<"El producto de los polinomios es: ";
    //producto(N1,polinomio1,N2,polinomio2);

    //aca falta su delete
    return 0;
}