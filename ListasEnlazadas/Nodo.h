#include <iostream>
using namespace std;

class Nodo
{
private:
    /* data */
    int dato;
    Nodo *anterior;
    Nodo *siguiente; 
public:
    Nodo(int dato);

    Nodo* getAnterior(){
        return this->anterior;
    }

    void setAnterior(Nodo *anterior){
        this->anterior = anterior;
    }

    Nodo *getSiguiente(){
        return this->siguiente;
    };
    
    void setSiguiente(Nodo *siguiente){
        this->siguiente = siguiente;
    }

    int getDato(){
        return this->dato;
    }

    void setDato(int dato){
        this->dato = dato;
    }

    ~Nodo();
};

Nodo::Nodo(int dato)
{
    this->dato = dato;
    this->anterior = nullptr;
    this->siguiente = nullptr;
}

Nodo::~Nodo()
{

}
