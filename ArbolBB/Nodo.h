class Nodo
{
private:
    /* data */
    int dato;
    Nodo* izq; //Hijo o subarbol izquierdo
    Nodo* der; //Hijo o subarbol derecho
public:
    Nodo(int dato){
        this->dato = dato;
        this->izq = nullptr;
        this->der = nullptr;
    }

    void setDato(int dato){
        this->dato = dato;
    }

    int getDato(){
        return this->dato;
    }

    void setIzq(Nodo* izq){
        this->izq = izq;
    }

    Nodo* getIzq(){
        return this->izq;
    }

    void setDer(Nodo* der){
        this->der = der;
    }

    Nodo* getDer(){
        return this->der;
    }

    ~Nodo();
};

Nodo::~Nodo()
{
}
