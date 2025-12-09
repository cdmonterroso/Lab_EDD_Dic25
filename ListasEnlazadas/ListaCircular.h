#include <cstdlib> //cabecera para usar el system;
#include <fstream> //Cabecera pra manejar archivos (leer y escribir)
#include <iostream>
using namespace std;
#include "Nodo.h"

class ListaCircular
{
private:
    /* data */
    Nodo *primero;
    Nodo *ultimo;
public:
    ListaCircular(/* args */);

    bool estaVacia(){
        return (primero == nullptr) && (ultimo == nullptr);
    }

    void insertarInicio(int dato){
        Nodo *nuevo = new Nodo(dato);
        if (ListaCircular::estaVacia())
        {
            nuevo->setSiguiente(nuevo); //El primer nodo se apunta a si mismo
            /* Como solo existe el nuevo nodo creado, este será el primero y el último */
            primero = ultimo = nuevo;
        }
        else{
            nuevo->setSiguiente(primero); //Se enlaza el nuevo nodo al primero
            ultimo->setSiguiente(nuevo); // Se enlaza el ultimo nodo al nuevo
            primero = nuevo; //Se verifica que el nodo creado sea el primero
        }
        
    }

    void insertarFinal(int dato){
        Nodo *nuevo = new Nodo(dato);
        if (ListaCircular::estaVacia())
        {
            /* code */
            nuevo->setSiguiente(nuevo);
            primero = ultimo = nuevo;
        }
        else{
            nuevo->setSiguiente(primero); //Se enlaza el nuevo al primero
            ultimo->setSiguiente(nuevo); //Se enlaza el último nodo al nuevo
            ultimo = nuevo;
        }
        
    }

    void eliminarInicio(){
        if (ListaCircular::estaVacia())
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
                ultimo->setSiguiente(segundo); //Se enlaza el ultimo nodo al segundo nodo
                delete primero;
                primero = segundo; //verifico que el segundo nodo pase a ser el primero
            }   
        }
    }

    void eliminarFinal(){
        if (ListaCircular::estaVacia())
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
                do
                {
                    if (temporal->getSiguiente()==ultimo) //Si el siguiente de temporal es el ultimo, entonces encontre al antepenultimo
                    {
                        delete ultimo;
                        temporal->setSiguiente(nullptr); //Se cambia el enlace, quitando la referencia del ultimo nodo
                        ultimo = temporal; //Se verfica que temporal sea el ultimo
                        break;
                    }
                    temporal = temporal->getSiguiente(); //Recorriendo la lista   
                }while (temporal != primero);
            }
        }
    }

    void visualizarLista(){
        if (ListaCircular::estaVacia())
        {
            cout << "La lista está vacía\n";
        }
        else{
            int nodoDato;
            Nodo *actual = primero;
            do
            {
                nodoDato = actual->getDato();
                cout << nodoDato << (actual->getSiguiente() != nullptr ? " -> " : "\n");
                actual = actual->getSiguiente();
            }while (actual != primero);
        } 
    }

    void generarReporte(){
        if (ListaCircular::estaVacia())
        {
            /* code */
        }else{
            ofstream archivo; //ofstream->escribir - ifstream->leer
            archivo.open("grafica_LC.dot", ios::out); //
            archivo << "digraph G { rankdir = LR; " << endl;

            int nodoDato;
            Nodo *actual = primero;
            do
            {
                nodoDato = actual->getDato();
                archivo << nodoDato;
                archivo << " -> ";
                actual = actual->getSiguiente();

                if (actual == primero)
                {
                    archivo << actual->getDato();
                }

            } while (actual != primero);
            
            archivo << "; }";
            archivo.close();
            system("dot -Tpng grafica_LC.dot -o grafica_LC.png");
            system("start grafica_LC.png");
        }
        
    }

    ~ListaCircular();
};

ListaCircular::ListaCircular(/* args */)
{
    primero = nullptr;
    ultimo = nullptr;
}

ListaCircular::~ListaCircular()
{
}
