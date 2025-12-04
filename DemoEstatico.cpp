#include <iostream>
using namespace std;
#include "Estatico.h"

int main(){
    Estatico d1; //Declaración estatica, el objeto se almacena en el stack
    Estatico *d2 = new Estatico(); //Declaración dinamica, el objeto se almacena en el heap

    cout << d1.valor << endl; //Variable "valor" está almacenada en el stack
    cout << d2->valor << endl; //Variable valor está almacenada en el heap
    cout << Estatico::cuenta << endl; //Esta variable está almacenada en el segmento Dato

    if (true)
    {
        Estatico d3(88);
        Estatico *d4 = new Estatico(89);
        cout << "\nObjeto estatico: " << Estatico::cuenta << endl;
        cout << d3.valor << endl;
        delete d4;
    }

    cout << "\nObjeto estatico: " << Estatico::cuenta << endl;
    

    return 0;
}