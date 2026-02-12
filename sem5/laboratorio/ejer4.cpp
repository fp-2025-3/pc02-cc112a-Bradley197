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
int * producto(int N1,int *polinomio1,int N2,int *polinomio2,int grado,int *polinomioM){
for(int i=grado;i>=0;i--){//grado nuevo polinomio
    int anterior=0;
    for(int j=N1;j>=0;j--){
        for(int k=N2;k>=0;k--){
            if(i==j+k){
                anterior=anterior+polinomio1[j]*polinomio2[k];
            }
        }
    }
    polinomioM[i]=anterior;
}
return polinomioM;
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
    int grado=N1+N2;
    int *polinomioM=new int[grado+1];
    producto(N1,polinomio1,N2,polinomio2,grado,polinomioM);
    imprecion(grado,polinomioM);

    delete[] polinomio1;
    delete[] polinomio2;
    delete[] polinomio3;
    delete[] polinomioM;
    return 0;
}