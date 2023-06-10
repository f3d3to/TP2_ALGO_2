#ifndef NODO_H_
#define NODO_H_

#ifndef NULL
#define NULL 0
#endif

template <class T> class Nodo {
private:
  T dato;
  Nodo<T> *siguiente;

public:
  /*
   * Post: Nodo inicializado con dato y siguiente nulo
   * */
  Nodo(T dato) {
    this->dato = dato;
    this->siguiente = NULL;
  }

  /*
   * Post: Devuelve el valor del dato
   */
  T getDato() { return this->dato; }

  /*
   * Post: Cambia el valor del dato por el recibido
   */
  void setDato(T nuevoDato) { this->dato = nuevoDato; }

  /*
   * Post: Devuelve el siguiente nodo
   */
  Nodo<T> *getSiguiente() { return this->siguiente; }

  /*
   * Post: Cambia el siguiente nodo por el recibido
   */
  void setSiguiente(Nodo<T> *nuevoSiguiente) {
    this->siguiente = nuevoSiguiente;
  }
};

#endif /* NODO_H_ */