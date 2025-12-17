#include <fstream>
#include <iostream>
using namespace std;
#include "Nodo.h"

class Arbol
{
private:
    /* data */
    Nodo* raiz;
    ofstream archivo;
    int nodoDato;
public:
    int recorrido = 0;
    Arbol(/* args */);
    
    bool estaVacio(){
        return (raiz == nullptr);
    }

    Nodo* getRaiz(){
        return this->raiz;
    }

    void insertar(int dato){
        raiz = insertarNodo(dato, raiz);
    }

    Nodo* insertarNodo(int dato, Nodo* nodoPtr){
        if(nodoPtr == nullptr){
            Nodo* nuevo = new Nodo(dato);
            nodoPtr = nuevo;
        }
        else if (dato < nodoPtr->getDato()){
            nodoPtr->setIzq(insertarNodo(dato, nodoPtr->getIzq()));
        }
        else if(dato > nodoPtr->getDato()){
            nodoPtr->setDer(insertarNodo(dato,nodoPtr->getDer()));
        }
        else {
            cout << "Nodo duplicado\n";
        }

        return nodoPtr;
    }

    void buscar(int dato){
        cout << "Recorriddo del nodo encontrado: "<< buscarNodo(dato, raiz) << ", " << recorrido << endl;
    }

    int buscarNodo(int dato, Nodo* nodoPtr){
        if (nodoPtr == nullptr)
        {
            return 0;
            cout << "Nodo no encontrado\n";
        }
        else if (dato == nodoPtr->getDato()){
            recorrido++;
            return nodoPtr->getDato();
        }
        else if (dato < nodoPtr->getDato()){
            recorrido++;
            return buscarNodo(dato, nodoPtr->getIzq());
        }
        else if (dato > nodoPtr->getDato()){
            recorrido++;
            return buscarNodo(dato, nodoPtr->getDer());
        }
    }

    void Recorrido(){
        Recorrido(raiz);
    }

    void Recorrido(Nodo* nodoPtr){
        if (nodoPtr != nullptr)
        {
            //PREORDEN
            /*cout << nodoPtr->getDato() << ", ";
            Recorrido(nodoPtr->getIzq());
            Recorrido(nodoPtr->getDer());*/

            //INORDEN
            Recorrido(nodoPtr->getIzq());
            cout << nodoPtr->getDato() << ", ";
            Recorrido(nodoPtr->getDer());

        }
    }

    void generarReporte(){
        if (estaVacio())
        {
            cout << "El árbol está vacío\n"; 
        }
        else{
            archivo.open("grafica_arbol.dot", ios::out);
            archivo << "digraph G { " << endl;

            imprimirNodos(raiz);

            archivo << " }";
            archivo.close();
            system("dot -Tpng grafica_arbol.dot -o grafica_arbol.png");
            system("start grafica_arbol.png");

        }
    }

    void imprimirNodos(Nodo* nodoPtr){
        if (nodoPtr == nullptr)
        {
            return;
        }
        if (nodoPtr->getIzq() != nullptr)
        {
            nodoDato = nodoPtr->getDato();
            archivo << nodoDato; archivo << "->";
            nodoDato = nodoPtr->getIzq()->getDato();
            archivo << nodoDato; archivo << ";";

        }
        imprimirNodos(nodoPtr->getIzq());
        
        if (nodoPtr->getDer() != nullptr)
        {
            nodoDato = nodoPtr->getDato();
            archivo << nodoDato; archivo << "->";
            nodoDato = nodoPtr->getDer()->getDato();
            archivo << nodoDato; archivo << ";";
        }
        
        imprimirNodos(nodoPtr->getDer());
        
    }


    ~Arbol();
};

Arbol::Arbol(/* args */)
{
    this->raiz = nullptr;
}

Arbol::~Arbol()
{
}
