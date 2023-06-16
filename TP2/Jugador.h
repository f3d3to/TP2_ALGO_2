#ifndef JUGADOR_H_
#define JUGADOR_H_
#include "Carta.h"
#include "Constantes.h"
#include "Ficha.h"
#include "Lista.h"
#include "Pila.h"
#include <string>

class Jugador {
  friend class Ficha;
private:
  std::string nombreJugador;
  Pila<Ficha *> *fichas;
  int cantidadSoldados;
  Lista<Carta *> *cartas;
  int contadorTurnos; // Cuando suma un turno, resta uno al contador_bloqueado
                      // de cada ficha
public:
  /* 
   *Pre: recibe un string, una ficha valida y un entero mayor a 0
   * Post: inicializar atributos, crea maso de carta en memoria
   */
  Jugador(std::string nombreJugador);
  /*
   * Pre :---
   * Post: libera toda la memoria de la instancia jugador.
   */
  ~Jugador();
  /*
   * Pre :exista una instancia de jugador previamente.
   * Post: devuelve el nombre del jugador.
   */
  std::string getNombre();
  /*
   * Pre :exista una instancia de jugador previamente.
   * Post: devuelve Ficha.
   */
  Ficha *getFicha();
  /*
   * Pre :exista una instancia de jugador previamente, recibe un TipoDeFicha.
   * Post: cambia el estadoDeFicha de una Ficha.
   */
  void setFicha(TipoDeFicha tipoDeFicha);
  /*
   * Pre :exista una instancia de jugador previamente.
   * Post: devuelve la cantidad de fichas.
   */
  int getCantidadFichas();
  /*
   * Pre :exista una instancia de jugador previamente, recibe una cantidad.
   * Post: cambia la cantidad de fichas.
   */
  void setCantidadFichas(int cantidad);
  /*
   * Pre :exista una instancia de jugador previamente, recibe una pila de fichas.
   * Post: cambia las fichas del la pila de fichas.
   */
  void setFichas(Pila<Ficha *> *nuevasFichas);
  /*
   * Pre :exista una instancia de jugador previamente.
   * Post: devuelve la pila de fichas
   */
  Pila<Ficha *> *getPilaFichas();
  /*
   * Pre :exista una instancia de jugador previamente.
   * Post: devuelve la lista de cartas
   */
  Lista<Carta *> *getCartas();
  /*
   * Pre :exista una instancia de jugador previamente.
   * Post: devuelve la ultima carta de la pila de cartas.
   */
  Carta *getUltimaCarta();
  /*
   * Pre :exista una instancia de jugador previamente.
   * Post: cambia las cartas de la lista de cartas.
   */
  void setCartas(Lista<Carta *> *nuevasCartas);
  /*
   * Pre :exista una instancia de jugador previamente.
   * Post: devuelve la cantidad de turnos.
   */
  int getTurnos();
  /*
   * Pre :exista una instancia de jugador previamente.
   * Post: cambia la cantidad de turnos.
   */
  void setTurnos(int nuevosTurnos);
};
#endif /* JUGADOR.H */