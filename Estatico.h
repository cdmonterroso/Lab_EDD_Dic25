#include <iostream>
using namespace std;

class Estatico
{
private:
    int datos;
public:
    static int cuenta;
    int valor;

    Estatico(/* args */){
       datos = 0;
       valor = 10;
       cuenta++; 
    };

    Estatico(int x){
        datos = x;
        valor = x;
        cuenta++;
    }

    ~Estatico(){
        cuenta--;
    };
};

int Estatico::cuenta = 0;
//Operador de resolución de ambito ::