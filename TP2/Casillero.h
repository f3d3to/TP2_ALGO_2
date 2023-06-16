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
  int contadorDeTurno;
public:
  /*
   * pre: ---
   * Post: crea un Casillero con la Ficha vacia e inicializa
   * sus 26 casillerosAdyacentes
   */
  Casillero();
  /*
   * pre: recibe un tipo de dato del tipo Ficha
   * Post: crea un Casillero con la Ficha indicadas
   */
  Casillero(Ficha *ficha);

  /*
   * pre:---
   * Post: libera toda la memoria solicitada para el Casillero
   */
  ~Casillero();
  /*
   * Pre: recibe las coordenadas respecto del mismo casillero tomando como
   * referencia que el origen es la posicion del casillero.
   * Post: asigna el casillero recibido como adyacente en la posicion recibida
   * respecto del mismo casillero. Lanza una excepcion si las coordenadas son
   * inválidas
   */
  void asignarCasilleroAdyacente(int x, int y, int z,
                                 Casillero *casilleroAdyacente);
  /*
   * Pre: que exista la clase casillero previamente, recibe las coordenadas
   * respecto del mismo Casillero que se desea checkear.
   * Post: devuelve true si el Casillero tiene un Casilllero adyacente
   * existente ubicado en las coordenadas recibidas y false en caso de que no.
   */
  bool tieneAdyacente(unsigned int x, unsigned int y, unsigned int z);
  /*
   * pre : que exista la clase casillero previamente, recibe un tipo de dato
   * Casillero. Post: devuelve verdadero si el casillero pasado por parametro es
   * adyacente en linea con el casillero actual
   */
  bool esAdyacenteLineal(Casillero *);
  /* Pre : que exista la clase casillero previamente.
   * Post: devuelve la Ficha del Casillero
   */
  Ficha *getFicha();
  /*
   * pre: que exista la clase casillero previamente, Recibe un tipo de dato
   * Ficha. Post: establece la Ficha indicada en el Casillero.
   */
  void setFicha(Ficha *nuevaFicha);
  /*
   * Pre: que exista la clase casillero previamente  y this->ficha != NULL.
   * Post: Eliminar ficha en memoria.
   */
  void eliminarFicha();
  /*
   * Pre: que exista la clase casillero previamente ,recibe coordenadas i,j,k.
   * Post: devuelve el casillero adyacente que esta en la matriz de adyacentes.
   */
  Casillero *getAdyacente(unsigned int i, unsigned int j, unsigned int k);
  /*
   * pre: exista una instancia de casillero previamente.
   * post: devuelve el estado del casillero.
   */
  EstadoCasillero getEstado();
  /*
   * Pre: que exista la clase casillero previamente, recibe coordenadas i,j,k.
   * Post: devuelve un entero positivo que indica la cantidad de fichas iguales
   * respecto de la posicion recibida
   */
  unsigned int getLongitudFichasIguales(unsigned int i, unsigned int j,
                                        unsigned int k);
  /*
   * Pre: Exista una instancia de la clase casillero,recibe una casillero
   * valido. Post: devuelve verdadero si la ficha de ambos casilleros es igual.
   */
  bool tienenMismaFicha(Casillero *casilleroAdyacente);
  /*
   * Pre: Exista una instancia de la clase casillero.
   * Post: devuelve True si estado = bloqueado.
   */
  bool estaBloqueado();
  /*
   * Pre: Exista una instancia de la clase casillero.
   * Post: devuelve True si estado = envenenado.
   */
  bool estaEnvenenado();
  /*
   * Pre:  Exista una instancia de la clase casillero.
   * Post: cambia estado a bloqueado
   */
  void bloquear();
  /*
   * Pre:  Exista una instancia de la clase casillero.
   * Post: cambia estado a desbloqueado
   */
  void desbloquear();
  /*
   * pre:  Exista una instancia de la clase casillero.
   * Post: devuelve verdadero si el casillero no posee una ficha
   */
  bool estaVacio();
  /*
   * pre:  Exista una instancia de la clase casillero, reciba una variable int.
   * Post: cambia la cantidad de turnos en el casillero.
   */
  void setContadorDeTurnos(int turnos);
  /*
   * pre:  Exista una instancia de la clase casillero.
   * Post: devuelve el contador de turnos del casillero.
   */
  int getContadorDeturnos();
  /*
   * pre:  Exista una instancia de la clase casillero.
   * Post: baja en 1 el contador de turnos del casillero.
   */
  void bajarTurno();
  /*
   * pre:  Exista una instancia de la clase casillero.
   * Post: cambia el estado del casillero a ENVENENADO.
   */
  void envenenar();
  /*
   * pre:  Exista una instancia de la clase casillero.
   * Post: devuelve el tipo de terreno de el casillero.
   */

  TipoTerreno obtenerTerreno() const { return terreno; }
  /*
   * pre:  Exista una instancia de la clase casillero.
   * Post: asigna el tipo de terreno al casillero.
   */

  void asignarTerreno(TipoTerreno nuevoTerreno) { terreno = nuevoTerreno; }
};
#endif /* CASILLERO_H_ */