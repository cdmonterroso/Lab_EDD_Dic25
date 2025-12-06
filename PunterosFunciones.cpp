#include <iostream>
using namespace std;

//PASO POR VALOR Y POR REFERENCIA

/*Paso por valor*/
/*void funcion(int y){
    y = 100;
    cout << "variable duplicada dentro de la función: " << y << endl;
}*/

/*Paso por referencia*/
void funcion(int* y){
    *y = 100;
    cout << "misma variable pasada por referencia: " << *y << endl;
}

int main()
{
    /* code */
    int x = 0;
    cout <<  x <<endl;
    //funcion(x); //Pasamos el valor de x, no pasamos la dirección de memoria
    funcion(&x); //Pasamos la referencia de x, sí pasamos la dirección de memoria
    cout << x << endl;
    return 0;
}
