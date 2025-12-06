#include <iostream>
using namespace std;
//#include "ListaSimple.h"
#include "ListaDoble.h"

int main()
{
    /*ListaSimple miLista;
    miLista.insertarInicio(10);
    miLista.insertarFinal(15);
    miLista.insertarInicio(5);
    miLista.insertarFinal(20);
    miLista.visualizarLista();*/
    cout << endl;

    ListaDoble miListaDoble;
    miListaDoble.insertarInicio(200);
    miListaDoble.insertarInicio(150);
    miListaDoble.insertarInicio(100);
    miListaDoble.insertarInicio(250);
    miListaDoble.visualizarLista();
    return 0;
}

