#include <iostream>
using namespace std;
#include "Nodo.h"

class ListaSimple
{
private:
    /* data */
    //NECSITAMOS UNA REFERENCIA DEL PRIMER Y ULTIMO NODO DE LA LISTA
    Nodo *primero;
    Nodo *ultimo;
public:
    ListaSimple(/* args */);

    bool estaVacia(){
        return ((primero == nullptr) && (ultimo == nullptr));
    }

    void insertarInicio(int dato){
        Nodo *nuevo = new Nodo(dato);
        if (ListaSimple::estaVacia())
        {
            /* Como solo existe el nuevo nodo creado, este será el primero y el último */
            primero = ultimo = nuevo;
        }
        else{
            nuevo->setSiguiente(primero); //Se enlaza el nuevo nodo al primero
            primero = nuevo; //Se verifica que el nodo creado sea el primero
        }
        
    }

    void insertarFinal(int dato){
        Nodo *nuevo = new Nodo(dato);
        if (ListaSimple::estaVacia())
        {
            /* code */
            primero = ultimo = nuevo;
        }
        else{
            ultimo->setSiguiente(nuevo); //Se enlaza el último nodo al nuevo
            ultimo = nuevo;
        }
        
    }

    void eliminarInicio(){
        if (ListaSimple::estaVacia())
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
                delete primero;
                primero = segundo; //Verifoco que el segundo nodo pase a ser el primero
            }
            
        }
    }

    void eliminarFinal(){
        if (ListaSimple::estaVacia())
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
                while (temporal != nullptr)
                {
                    if (temporal->getSiguiente()==ultimo) //Si el siguiente de temporal es el ultimo, entonces encontre al antepenultimo
                    {
                        delete ultimo;
                        temporal->setSiguiente(nullptr); //Se cambia el enlace, quitando la referencia del ultimo nodo
                        ultimo = temporal; //Se verfica que temporal sea el ultimo
                    }
                    temporal = temporal->getSiguiente(); //Recorriendo la lista   
                }
            }
        }
        
    }

    void visualizarLista(){
        if (ListaSimple::estaVacia())
        {
            cout << "La lista está vacía\n";
        }
        else{
            int nodoDato;
            Nodo *actual = primero;
            while (actual != nullptr)
            {
                nodoDato = actual->getDato();
                cout << nodoDato << (actual->getSiguiente() != nullptr ? " -> " : "\n");
                actual = actual->getSiguiente();
            }
            
        }
        
    }

    ~ListaSimple();
};

ListaSimple::ListaSimple(/* args */)
{
    primero = nullptr;
    ultimo = nullptr;
}

ListaSimple::~ListaSimple()
{
}
