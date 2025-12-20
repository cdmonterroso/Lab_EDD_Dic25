#include <iostream>
using namespace std;
#include "TablaHash.h"

int main(){
    TablaHash miTabla;
    miTabla.insertar(99);
    miTabla.insertar(35);
    miTabla.insertar(15);
    miTabla.insertar(90);
    miTabla.insertar(88);
    miTabla.insertar(77);
    miTabla.insertar(64);
    miTabla.insertar(41);
    miTabla.insertar(19);
    miTabla.insertar(98);
    miTabla.insertar(48);
    miTabla.insertar(71);
    miTabla.insertar(22);
    miTabla.insertar(10);
    miTabla.insertar(57);
    miTabla.insertar(1);
    miTabla.imprimirTabla();

    return 0;
}