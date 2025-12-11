#include <iostream>
#include <string.h>
using namespace std;

class Nodo
{
private:
    /* data */
    string dato;
    int fila, columna;
    Nodo *anterior;
    Nodo *siguiente;
    Nodo *arriba;
    Nodo *abajo;
public:
    Nodo(string dato){
        this->dato = dato;
        anterior = siguiente = arriba = abajo = nullptr;
    }
    Nodo(string dato, int fila, int columna){
        this->dato = dato;
        this->fila = fila;
        this->columna = columna;
        anterior = siguiente = arriba = abajo = nullptr;
    }
    string getDato(){
        return this->dato;
    }
    void setDato(string dato){
        this->dato = dato;
    }
    int getFila(){
        return this->fila;
    }
    void setFila(int fila){
        this->fila = fila;
    }
    int getColumna(){
        return this->columna;
    }
    void setColumna(int columna){
        this->columna = columna;
    }

    Nodo* getAnterior(){
        return this->anterior;
    }
    void setAnterior(Nodo *anterior){
        this->anterior = anterior;
    }
    Nodo *getSiguiente(){
        return this->siguiente;
    }
    void setSiguiente(Nodo *siguiente){
        this->siguiente = siguiente;
    }
    Nodo* getArriba(){
        return this->arriba;
    }
    void setArriba(Nodo *arriba){
        this->arriba = arriba;
    }
    Nodo* getAbajo(){
        return this->abajo;
    }
    void setAbajo(Nodo *abajo){
        this->abajo = abajo;
    }
    ~Nodo();
};

Nodo::~Nodo()
{
}
