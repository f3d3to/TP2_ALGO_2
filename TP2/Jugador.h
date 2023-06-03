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
  Lista<Carta *> *cartas;
  int contador_turnos; // Cuando suma un turno, resta uno al contador_bloqueado
                       // de cada ficha
  
public:
  /* Pre: recibe un string, una ficha valida y un entero mayor a 0
   * Post: inicializar atributos, crea maso de carta en memoria
   * */
  Jugador(std::string nombreJugador, Ficha *ficha, int cantidadFichas);
  /*
   * Post: libera toda la memoria solicitada para la Jugador
   */
  ~Jugador();

  /* Pre: recibe nombre
   * Post: asigna el nombre
   * */

  std::string getNombre();
  Ficha * getFicha();
  void setFicha(Ficha *nuevaFicha);
  int getCantidadFichas();
  void setCantidadFichas(int cantidad);
  Lista<Carta*>* getCartas();
  Carta * getUltimaCarta();
  void setCartas(Lista<Carta*> *nuevasCartas);
  int getTurnos();
  void setTurnos(int nuevosTurnos);



};

#endif /* JUGADOR.H */