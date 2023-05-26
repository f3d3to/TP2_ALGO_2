#ifndef JUGADOR_H_
#define JUGADOR_H_

#include "Carta.h"
#include "Ficha.h"
#include "Lista.h"
#include <string>

class Jugador {
  friend class Ficha;

private:
  std::string nombreJugador;
  Ficha *ficha;
  int cantidadFichas;
  Lista<Carta> cartas;
  int contador_turnos; // Cuando suma un turno, resta uno al contador_bloqueado
                       // de cada ficha

public:
  /* Pre: Recibe una char que representara el simbolo de la ficha
   * Post: crea una ficha con el simbolo indicado y estado desbloqueado
   * */

  /*
   * Post: libera toda la memoria solicitada para la Jugador
   */
  ~Jugador();

  /* Pre: recibe nombre
   * Post: asigna el nombre
   * */
  void asignarNombre(std::string nombre);
};

#endif /* JUGADOR.H */