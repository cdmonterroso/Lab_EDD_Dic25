#include <iostream>
using namespace std;
#include "../ListasEnlazadas/ListaSimple.h";

class TablaHash
{
private:
    /* data */
    int tamTabla;
    int numElementos;
    ListaSimple *tabla;
public:
    TablaHash(/* args */);
    int Clave(int valor){
        int i = (int)(valor % tamTabla);
        cout << "Llave asingada: " << i << endl;
        return i;
    }
    void insertar(int valor){
        int indice = Clave(valor); //Obteniendo la clave
        tabla[indice].insertarFinal(valor); //Insertando en la clave correspondiente
    }
    void imprimirTabla(){
        for (int i = 0; i < tamTabla; i++)
        {
            cout << "[" << i << "] -> ";
            tabla[i].visualizarLista();
        }
        
    }
    ~TablaHash();
};

TablaHash::TablaHash(/* args */)
{
    tamTabla = 11;
    tabla = new ListaSimple[tamTabla];
    for (int i = 0; i < tamTabla; i++)
    {
        cout << tabla->estaVacia() << endl;
    }
    numElementos = 0;
}

TablaHash::~TablaHash()
{
}
