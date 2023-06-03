#ifndef COLA_H_
#define COLA_H_


#include "Nodo.h"

template<class T>
class Cola {

private:
    Nodo <T> * inicio;
    Nodo <T> * final;
    unsigned int tamanio;

public:

    /*
     * Pre: -
     * Post: inicializa atributos en NULL y cero
     */
    Cola();


    /*
     * Pre: -
     * Post: hace delete de cada nodo de la cola
     */
    ~Cola();


    /*
     * Pre: Recibe un elemento de tipo T
     * Post: crea Nodo en el heap y agrega al final (cambia inicio, final y tamanio)
     */
    void push( T );


    /*
     * Pre: La cola no esta vacia
     * Post: saca el primer elemento de la cola y lo devuelve
     *          (lanza error si la cola esta vacia)
     */
    T pop();


    /*
     * Pre: -
     * Post: devuelve True si tamanio=0
     */
    bool estaVacia();

};


template<class T>
Cola<T>::Cola() {
    this->inicio = NULL;
    this->final = NULL;
    this->tamanio = 0;
}


template<class T>
Cola<T>::~Cola() {

    while ( !(this->estaVacia()) ){
        this->pop();
    }
}


template<class T>
void Cola<T>::push(T dato) {

    Nodo<T> * nuevoNodo = new Nodo<T>(dato);

    if ( !this->inicio ) {
        this->inicio = nuevoNodo;
        this->final = this->inicio;
    }
    else {
        this->final->setSiguiente(nuevoNodo);
        this->final = nuevoNodo;
    }

    ++(this->tamanio);
}


template<class T>
T Cola<T>::pop() {

    if ( !(this->inicio) ) {
        throw ("Cola vacia. No se puede obtener elemento");
    }

    T datoaBorrar = this->inicio->getDato();
    Nodo<T> * nodoaBorrar = this->inicio;
    this->inicio = this->inicio->getSiguiente();
    delete nodoaBorrar;
    --(this->tamanio);

    return  datoaBorrar;
}


template<class T>
bool Cola<T>::estaVacia() {

    return ( this->tamanio == 0 );
}



#endif /* COLA_H_ */