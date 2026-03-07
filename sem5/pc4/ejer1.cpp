#include<iostream>
using namespace std;
struct elemento{
    int grado;
    int coeficiente;
};
struct  polinomio
{
    elemento* elem;
    int gradoMax;
};
void suma(polinomio polinomio1,polinomio polinomio2,polinomio polinomio3, polinomio &polSuma){
    
    for(int i=2;i>=0;i--){

                if(polinomio1.elem[i].grado==2){
                    polSuma.elem[2].grado=2;
                    polSuma.elem[2].coeficiente=polinomio1.elem[i].coeficiente+polinomio2.elem  [i].coeficiente+polinomio3.elem  [i].coeficiente;
                }
                if(polinomio1.elem  [i].grado==1){
                    polSuma.elem  [1].grado=1;
                    polSuma.elem  [1].coeficiente=polinomio1.elem  [i].coeficiente+polinomio2.elem  [i].coeficiente+polinomio3.elem  [i].coeficiente;
                }
                if(polinomio1.elem  [i].grado==0){
                    polSuma.elem  [0].grado=0;
                    polSuma.elem  [0].coeficiente=polinomio1.elem  [i].coeficiente+polinomio2.elem  [i].coeficiente+polinomio3.elem  [i].coeficiente;
                }


}

cout<<"La suma es: ";
for(int i=2;i>=0;i--){
    bool aña=true;
    if(i==0){
        aña=false;
    }
    cout<<polSuma.elem  [i].coeficiente<<"x°"<<polSuma.elem  [i].grado;
    if(aña==true){
        cout<<"+";
    }
}


}
void producto(polinomio polinomio1,polinomio polinomio2,polinomio polinomio3, polinomio &polProducto){
    for(int i=0;i<=polProducto.gradoMax;i++){
        polProducto.elem[i].grado=i;
        polProducto.elem[i].coeficiente=0;
   }
    int sumaMayorGrado=polinomio1.elem  [2].grado+polinomio2.elem  [2].grado+polinomio3.elem  [2].grado;
    for(int m=sumaMayorGrado;m>=0;m--){
        for(int i=2;i>=0;i--){
          for(int j=2;j>=0;j--){
            for(int k=2;k>=0;k--){
                if(polProducto.elem[m].grado==polinomio1.elem  [i].grado+polinomio2.elem  [j].grado+polinomio3.elem  [k].grado){
                    polProducto.elem[m].coeficiente+=polinomio1.elem[i].coeficiente*polinomio2.elem[j].coeficiente*polinomio3.elem  [k].coeficiente;
                }
            }
        }
    }
    }
    cout<<"El producto es: "<<endl;
    bool may=true;
    for(int m=sumaMayorGrado;m>=0;m--){
        if(m==0){
            may=false;
        }
        if(polProducto.elem[m].coeficiente==0){
            cout<<"";
        }else if (polProducto.elem[m].grado==0){
            cout<<polProducto.elem[m].coeficiente;
        }
        else{
            cout<<polProducto.elem[m].coeficiente<<"x°"<<polProducto.elem[m].grado;
        }
        if(may==true){
            cout<<"+";
        }
    }
    
};
int main(){
    polinomio polinomio1;
    polinomio1.gradoMax=2;
    polinomio1.elem=new elemento[polinomio1.gradoMax+1];
    polinomio1.elem  [0].grado=0;
    polinomio1.elem  [0].coeficiente=3;
    polinomio1.elem  [1].grado=1;
    polinomio1.elem  [1].coeficiente=0;
    polinomio1.elem  [2].grado=2;
    polinomio1.elem  [2].coeficiente=1;
    cout<<"polinomio 1:";
    bool aña=true;
    for(int i=2;i>=0;i--){
        if(i==0){
            aña=false;
        }
        if(polinomio1.elem[i].coeficiente==0){
            cout<<"";
        }else if(polinomio1.elem[i].grado==0){
            cout<<polinomio1.elem[i].coeficiente;
        }else{
             cout<<polinomio1.elem [i].coeficiente<<"x°"<<polinomio1.elem  [i].grado;
        }
        if(aña==true){
            cout<<"+";
        }
    }
    cout<<endl;

    polinomio polinomio2;
    polinomio2.gradoMax=2;
    polinomio2.elem=new elemento[polinomio2.gradoMax+1];
    polinomio2.elem  [0].grado=0;
    polinomio2.elem  [0].coeficiente=5;
    polinomio2.elem  [1].grado=1;
    polinomio2.elem  [1].coeficiente=-4;
    polinomio2.elem  [2].grado=2;
    polinomio2.elem  [2].coeficiente=0;
    cout<<"polinomio 2:";
    for(int i=2;i>=0;i--){
        if(i==0){
            aña=false;
        }
        if(polinomio2.elem[i].coeficiente==0){
            cout<<"";
        }else if(polinomio2.elem[i].grado==0){
            cout<<polinomio2.elem[i].coeficiente;
        }else{
             cout<<polinomio2.elem[i].coeficiente<<"x°"<<polinomio2.elem[i].grado;
        }
        if(aña==true){
            cout<<"+";
        }
    }

    cout<<endl;
    polinomio polinomio3;
    polinomio3.gradoMax=2;
    polinomio3.elem=new elemento[polinomio3.gradoMax+1];
    polinomio3.elem  [0].grado=0;
    polinomio3.elem  [0].coeficiente=1;
    polinomio3.elem  [1].grado=1;
    polinomio3.elem  [1].coeficiente=0;
    polinomio3.elem  [2].grado=2;
    polinomio3.elem  [2].coeficiente=3;
    cout<<"polinomio 3:";
    for(int i=2;i>=0;i--){
        if(i==0){
            aña=false;
        }
        if(polinomio3.elem[i].coeficiente==0){
            cout<<"";
        }else if(polinomio3.elem[i].grado==0){
            cout<<polinomio3.elem[i].coeficiente;
        }else{
             cout<<polinomio3.elem [i].coeficiente<<"x°"<<polinomio3.elem  [i].grado;
        }
        if(aña==true){
            cout<<"+";
        }
    }
    cout<<endl;
    polinomio polSuma;
    polSuma.gradoMax=2;
    polSuma.elem=new elemento[polSuma.gradoMax+1];
    suma( polinomio1, polinomio2, polinomio3, polSuma);
    cout<<endl;
    polinomio polProducto;
    polProducto.gradoMax=polinomio1.gradoMax+polinomio2.gradoMax+polinomio3.gradoMax;
    polProducto.elem=new elemento[polProducto.gradoMax+1];
    producto(polinomio1, polinomio2, polinomio3, polProducto);
    delete[] polinomio1.elem;
    delete[] polinomio2.elem;
    delete[] polinomio3.elem;
    delete[] polSuma.elem;
    delete[] polProducto.elem;
    return 0;
}