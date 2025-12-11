#include <iostream>
using namespace std;
#include "Nodo.h";

class Matriz
{
private:
    /* data */
public:
    Nodo* root;
    Matriz(/* args */){
        root = new Nodo("Root", -1, -1); //-1 y -1 para encabezdo root
    };
    bool estaVacia(){

    }
    void insertar(string dato, int fila, int columna){
        Nodo* nodoDato = new Nodo(dato, fila, columna); //Mando el dato y, la fila y la columna
        Nodo* nodoFila; 
        Nodo* nodoColumna;

        nodoFila = buscarFila(fila, root); //Si existe me devuelve el nodo cabecera, si no existe devuelve nullptr
        nodoColumna = buscarColumna(columna, root); //Si existe me devuelve el nodo cabecera, si no existe devuelve nullptr

        if (nodoFila == nullptr && nodoColumna == nullptr) //caso 1
        {
            nodoFila = crearFila(fila);
            nodoColumna = crearColumna(columna);
        }
        else if (nodoFila != nullptr && nodoColumna == nullptr) //caso 2
        {
            nodoColumna = crearColumna(columna);
        }
        else if(nodoFila == nullptr && nodoColumna != nullptr) //caso 3
        {
            nodoFila = crearFila(fila);
        }
        
        //insertando nodoDato en la cabecera fila
        Nodo* auxFila = nodoFila;
        while (auxFila != nullptr)
        {
            if (auxFila->getSiguiente() == nullptr) //Encontre el último nodo (puede ser la misma cabecera fila)
            {
                //Hacemos los enlaces correspondientes (horizontal)
                auxFila->setSiguiente(nodoDato);
                nodoDato->setAnterior(auxFila);
                break;
            }
            auxFila = auxFila->getSiguiente();
        }

        //Insertando nodoDato en la cabecera columna
        Nodo* auxColumna = nodoColumna;
        while (auxColumna != nullptr)
        {
            if (auxColumna->getAbajo() == nullptr) //Encontre el último nodo (puede ser la misma cabecer columna)
            {
                auxColumna->setAbajo(nodoDato);
                nodoDato->setArriba(auxColumna);
                break;
            }
            auxColumna = auxColumna->getAbajo();            
        } 
    }


    Nodo* crearFila(int fila){ //EMPRESAS
        Nodo *f = new Nodo("fila", fila, -1);
        Nodo* aux = root;
        while (aux->getAbajo() != nullptr)
        {
            /* code */
            aux = aux->getAbajo();
        }
        aux->setAbajo(f);
        f->setArriba(aux);
        return f;
    }

    Nodo* crearColumna(int columna){ //DEPARTAMENTOS
        Nodo* c = new Nodo("columna", -1, columna);
        Nodo* aux = root;
        while (aux->getSiguiente() != nullptr)
        {
            /* code */
            aux = aux->getSiguiente();
        }
        aux->setSiguiente(c);
        c->setAnterior(aux);
        return c;
    } 

    Nodo* buscarFila(int fila, Nodo* inicio){
        Nodo* aux = inicio; //Nodo inicio puede ser igual a root;
        while (aux != nullptr)
        {
            /* code */
            if (aux->getFila() == fila)
            {
                /* code */
                return aux; //Si encontramos la cabecera, la retorna
            }
            aux = aux->getAbajo();
        }
        return nullptr; //si no la encuentra, quiere decir que no existe y devuelve nullptr
    }

    Nodo* buscarColumna(int columna, Nodo* inicio){
        Nodo* aux = inicio;
        while (aux != nullptr)
        {
            /* code */
            if (aux->getColumna() == columna)
            {
                /* code */
                return aux;
            }
            aux = aux->getSiguiente();
        }
        return nullptr;
    }

    ~Matriz();
};

Matriz::~Matriz()
{
}
