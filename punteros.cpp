#include <iostream>
using namespace std;

int main(){
    
    int num = 7;
    int n;
    int *puntero;
    cout << puntero << endl;
    puntero = &num;
    

    cout << num << endl;
    cout << &num << endl;
    cout << puntero << endl;    //imprimiendo la dirección de memoria de nun
    cout << *puntero << endl;   //imprimiendo el valor apuntado por el puntero
    cout << &puntero << endl;   //imprimiendo la dirección de memoria del propio puntero

    num = 10;
    cout << *puntero << endl;
    *puntero = 20;
    cout << num << endl;

    return 0;
}