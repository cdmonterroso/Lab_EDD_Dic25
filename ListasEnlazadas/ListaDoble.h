#include <iostream>
using namespace std;
#include "Nodo.h"

class ListaDoble
{
private:
    /* data */
    //NECSITAMOS UNA REFERENCIA DEL PRIMER Y ULTIMO NODO DE LA LISTA
    Nodo *primero;
    Nodo *ultimo;
public:
    ListaDoble(/* args */);

    bool estaVacia(){
        return ((primero == nullptr) && (ultimo == nullptr));
    }

    void insertarInicio(int dato){
        Nodo *nuevo = new Nodo(dato);
        if (ListaDoble::estaVacia())
        {
            /* Como solo existe el nuevo nodo creado, este será el primero y el último */
            primero = ultimo = nuevo;
        }
        else{
            primero->setAnterior(nuevo); //Se enlaza el primer nodo al nuevo
            nuevo->setSiguiente(primero); //Se enlaza el nuevo nodo al primero
            primero = nuevo; //Se verifica que el nodo creado sea el primero
        }
        
    }

    void insertarFinal(int dato){
        Nodo *nuevo = new Nodo(dato);
        if (ListaDoble::estaVacia())
        {
            /* code */
            primero = ultimo = nuevo;
        }
        else{
            ultimo->setSiguiente(nuevo); //Se enlaza el último nodo al nuevo
            nuevo->setAnterior(ultimo); //Se enlaza el nuevo nodo al último
            ultimo = nuevo; //Se verifica que el nodo creado sea el último
        }
        
    }

    void eliminarInicio(){
        if (ListaDoble::estaVacia())
        {
            cout << "La lista está vacía" << endl;
        }
        else{
            if (primero == ultimo) //Si primero y ultimo son iguales, solo hay un elemento en la lista
            {
                delete primero;
                primero = ultimo = nullptr; //Se eliminar las referencias
            }
            else{
                Nodo *segundo = primero->getSiguiente(); //Guardo la referencia del segundo nodo de la lista
                segundo->setAnterior(nullptr);
                delete primero;
                primero = segundo; //Verifico que el segundo nodo pase a ser el primero
            }
            
        }
    }

    void eliminarFinal(){
        if (ListaDoble::estaVacia())
        {
            cout << "La lista está vacía" << endl;
        }
        else{
            Nodo *temporal = primero;
            if (primero == ultimo)
            {
                delete primero;
                primero = ultimo = nullptr; //Se eliminar las referencias
            }
            else{
                Nodo *antepenultimo = (ultimo->getAnterior()); //Guardo la referencia del antepenultimo
                delete ultimo;
                antepenultimo->setSiguiente(nullptr);
                ultimo = antepenultimo; //Verifico que el antepenultimo nodo pase a ser el último
            }
        }
        
    }

    void visualizarLista(){
        if (ListaDoble::estaVacia())
        {
            cout << "La lista está vacía\n";
        }
        else{
            int nodoDato;
            Nodo* actual = primero;
            while (actual != nullptr)
            {
                nodoDato = actual->getDato();
                cout << nodoDato << endl;
                actual = actual->getSiguiente();
            }
            
        }
        
    }

    ~ListaDoble();
};

ListaDoble::ListaDoble(/* args */)
{
    primero = nullptr;
    ultimo = nullptr;
}

ListaDoble::~ListaDoble()
{
}
