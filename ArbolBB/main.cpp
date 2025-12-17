#include <iostream>>
using namespace std;
#include "Arbol.h";

int main(){

    Arbol miArbol;
    miArbol.insertar(30);
    miArbol.insertar(33);
    miArbol.insertar(40);
    miArbol.insertar(32);
    miArbol.insertar(34);
    miArbol.insertar(20);
    miArbol.insertar(10);
    miArbol.insertar(37);
    miArbol.insertar(24);

    //miArbol.buscar(37);
    cout << "PREORDEN\n";
    miArbol.Recorrido();
}