#include <iostream>
using namespace std;

int factorialIterativo(int n){
    int resultado = 1;
    for (int i = 2; i <= n ; i++)
    {
        cout << "i" << i << endl;
        resultado = resultado * i;
    }
    return resultado;
}

int factorialRecursivo(int n){
    if (n <= 1)
    {
        return 1;
    }else{
        return n * factorialRecursivo(n-1);
    }
}

/*
0! = 1;
1! = 1
2! = 2 * 1!;
3! = 3 * 2!;
4! = 4 * 3!;
n! = n * (n-1)!
*/

int main()
{
    //cout << "Funcion factorial: " << factorialIterativo(5) << endl;
    cout << "Funcion factorial: " << factorialRecursivo(3) << endl;
    return 0;
}

