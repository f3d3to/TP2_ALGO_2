#ifndef CASILLERO_H_
#define CASILLERO_H_

#include "Constantes.h"
#include "Ficha.h"

class Casillero {
private:
  Ficha *ficha;
  Casillero ****casillerosAdyacentes;
  EstadoCasillero estado;
  TipoTerreno terreno;

public:
  /*
   * Post: crea un Casillero con la Ficha vacia e inicializa
   * sus 27 casillerosAdyacentes
   */
  Casillero();

  /*
   * Post: crea un Casillero con la Ficha indicadas
   */
  Casillero(Ficha *ficha);

  /*
   * Post: libera toda la memoria solicitada para el Casillero
   */
  ~Casillero();

  /*
   * Pre: recibe las coordenadas respecto del mismo casillero tomando como
   * referencia que el origen es la posicion del casillero. Post: asigna el
   * casillero recibido como adyacente en la posicion recibida respecto del
   * mismo casillero. Lanza una excepcion si las coordenadas son inválidas
   */
  void asignarCasilleroAdyacente(int x, int y, int z,
                                 Casillero *casilleroAdyacente);

  /*
   * Pre: recibe las coordenadas respecto del mismo Casillero que se desea
   * checkear Post: devuelve true si el Casillero tiene un Casilllero adyacente
   * existente ubicado en las coordenadas recibidas y false en caso de que no
   */
  bool tieneAdyacente(unsigned int x, unsigned int y, unsigned int z);

  /*
   * Post: devuelve verdadero si el casillero pasado por parametro es adyacente
   *        en linea con el casillero actual
   */
  bool esAdyacenteLineal(Casillero *);

  /* Pre: Recibe una casillero valido
   * Post: devuelve la Ficha del Casillero
   */
  Ficha *getFicha();

  /*
   * Post: establece la Ficha indicada en el Casillero
   */
  void setFicha(Ficha *nuevaFicha);

  /*
   * Pre: this->ficha != NULL
   * Post: Eliminar ficha en memoria
   */
  void eliminarFicha();

  /*
   * Pre: recibe coordenadas i,j,k entre 0 y 2
   * Post: devuelve el casillero adyacente que esta en la matriz de adyacentes
   */
  Casillero *getAdyacente(unsigned int i, unsigned int j, unsigned int k);

  /*
   * Pre: recibe coordenadas i,j,k entre 0 y 2
   * Post: devuelve un entero positivo que indica la cantidad de fichas iguales
   * respecto de la posicion recibida
   */
  unsigned int getLongitudFichasIguales(unsigned int i, unsigned int j,
                                        unsigned int k);

  /*
   * Pre: Recibe una casillero valido
   * Post: devuelve verdadero si la ficha de ambos casilleros es igual
   */
  bool tienenMismaFicha(Casillero *casilleroAdyacente);

  /*
   * Pre: -
   * Post: devuelve True si estado = bloqueado
   */
  bool estaBloqueado();

  /*
   * Pre: -
   * Post: cambia estado a bloqueado
   */
  void bloquear();

  /*
   * Pre: -
   * Post: cambia estado a desbloqueado
   */
  void desbloquear();

  /*
   *Post: devuelve verdadero si el casillero no posee una ficha
   */
  bool estaVacio();

  TipoTerreno obtenerTerreno() const { return terreno; }

  void asignarTerreno(TipoTerreno nuevoTerreno) { terreno = nuevoTerreno; }
};

#endif /* CASILLERO_H_ */