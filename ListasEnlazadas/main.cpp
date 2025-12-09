#include <iostream>
using namespace std;
//#include "ListaSimple.h"
//#include "ListaDoble.h"
#include "ListaCircular.h"

int main()
{
    /*ListaSimple miLista;
    miLista.insertarInicio(10);
    miLista.insertarFinal(15);
    miLista.insertarInicio(5);
    miLista.insertarFinal(20);
    miLista.visualizarLista();*/
    cout << endl;

    /*ListaDoble miListaDoble;
    miListaDoble.insertarInicio(200);
    miListaDoble.insertarInicio(150);
    miListaDoble.insertarInicio(100);
    miListaDoble.insertarInicio(250);
    miListaDoble.visualizarLista();*/

    ListaCircular miListaCircular;
    miListaCircular.insertarInicio(100);
    miListaCircular.insertarFinal(200);
    miListaCircular.insertarFinal(300);
    miListaCircular.insertarFinal(400);
    miListaCircular.visualizarLista();
    cout << endl;
    miListaCircular.eliminarInicio();
    miListaCircular.eliminarFinal();
    miListaCircular.insertarInicio(50);
    miListaCircular.insertarFinal(500);
    miListaCircular.visualizarLista();
    miListaCircular.generarReporte();

    return 0;
}

