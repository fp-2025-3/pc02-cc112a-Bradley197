#include<iostream>
using namespace std;
int main(){
    class Sensor{
        private:
        string id;
        double* posicion;
        public:
        Sensor(string id, double x, double y){
            this->id = id;
            posicion = new double[2];
            
        }
    }
    return 0;
}