#include<iostream>
using namespace std;
struct elemento{
    int grado;
    int coeficiente;
};
struct  polinomio
{
    elemento elm[3];
};
void suma(polinomio polinomio1,polinomio polinomio2,polinomio polinomio3, polinomio polSuma){
    
    for(int i=2;i>=0;i--){

                if(polinomio1.elm[i].grado==2){
                    polSuma.elm[2].grado=2;
                    polSuma.elm[2].coeficiente=polinomio1.elm[i].coeficiente+polinomio2.elm[i].coeficiente+polinomio3.elm[i].coeficiente;
                }
                if(polinomio1.elm[i].grado==1){
                    polSuma.elm[1].grado=1;
                    polSuma.elm[1].coeficiente=polinomio1.elm[i].coeficiente+polinomio2.elm[i].coeficiente+polinomio3.elm[i].coeficiente;
                }
                if(polinomio1.elm[i].grado==0){
                    polSuma.elm[0].grado=0;
                    polSuma.elm[0].coeficiente=polinomio1.elm[i].coeficiente+polinomio2.elm[i].coeficiente+polinomio3.elm[i].coeficiente;
                }


}

cout<<"La suma es: ";
for(int i=2;i>=0;i--){
    bool aña=true;
    if(i==0){
        aña=false;
    }
    cout<<polSuma.elm[i].coeficiente<<"x°"<<polSuma.elm[i].grado;
    if(aña==true){
        cout<<"+";
    }
}


}
void producto(polinomio polinomio1,polinomio polinomio2,polinomio polinomio3, polinomio polProducto){
    for(int i=2;i>=0;i--){
        for(int j=2;j>=0;j--){
            for(int k=2;k>=0;k--){

            }
        }
    }
};
int main(){
    polinomio polinomio1;
    polinomio1.elm[0].grado=0;
    polinomio1.elm[0].coeficiente=3;
    polinomio1.elm[1].grado=1;
    polinomio1.elm[1].coeficiente=0;
    polinomio1.elm[2].grado=2;
    polinomio1.elm[2].coeficiente=1;
    cout<<"polinomio 1:";
    for(int i=2;i>=0;i--){
        bool aña=true;
        if(i==0){
            aña=false;
        }
        cout<<polinomio1.elm[i].coeficiente<<"x°"<<polinomio1.elm[i].grado;
        if(aña==true){
            cout<<"+";
        }
    }
    cout<<endl;

    polinomio polinomio2;
    polinomio2.elm[0].grado=0;
    polinomio2.elm[0].coeficiente=5;
    polinomio2.elm[1].grado=1;
    polinomio2.elm[1].coeficiente=-4;
    polinomio2.elm[2].grado=2;
    polinomio2.elm[2].coeficiente=0;
    cout<<"polinomio 2:";
    for(int i=2;i>=0;i--){
        bool aña=true;
        if(i==0){
            aña=false;
        }
        cout<<polinomio2.elm[i].coeficiente<<"x°"<<polinomio2.elm[i].grado;
        if(aña==true){
            cout<<"+";
        }
    }

    cout<<endl;
    polinomio polinomio3;
    polinomio3.elm[0].grado=0;
    polinomio3.elm[0].coeficiente=1;
    polinomio3.elm[1].grado=1;
    polinomio3.elm[1].coeficiente=0;
    polinomio3.elm[2].grado=2;
    polinomio3.elm[2].coeficiente=3;
    cout<<"polinomio 3:";
    for(int i=2;i>=0;i--){
    bool aña=true;

        if(i==0){
            aña=false;
        }
        cout<<polinomio3.elm[i].coeficiente<<"x°"<<polinomio3.elm[i].grado;
        if(aña==true){
            cout<<"+";
        }
    }
    cout<<endl;
    polinomio polSuma;
    suma( polinomio1, polinomio2, polinomio3, polSuma);
    cout<<endl;
    polinomio polProducto;
    producto(polinomio1, polinomio2, polinomio3, polProducto);
    return 0;
}