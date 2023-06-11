#ifndef JUEGO_H_
#define JUEGO_H_

#include "Carta.h"
#include "Cola.h"
#include "Constantes.h"
#include "Ficha.h"
#include "Interfaz.h"
#include "Jugador.h"
#include "Tablero.h"
#include <iostream>
#include <string>

typedef enum { ENCURSO, FINALIZADO } Estado;
class Juego {

private:
  Lista<Jugador *> *jugadores;
  Pila<Carta *> *mazo;
  Jugador *jugadorEnTurno;
  Jugador *hayGanador;
  Tablero *tablero;
  Interfaz *interfaz;
  unsigned int cantidadMaximaCartas;
  unsigned int cantidadTurnosJuego;
  Estado estadoActual;
  int turno;

public:
  Juego();

  ~Juego();

  std::string pedirNombre(int jugadorNumero);
  void cambiarDeJugadorActual();

  /*Pre:
  Post: cambia el turno
  */
  void cambiarDeTurno();

  /* Post: valida si ganador no es NULL */
  bool determinarGanador();

  /* Post: muestra el estado del juego */
  void mostrarEstadoDeTurno();

  /* Post: ejecuta la accion del jugador */
  void ejecutarAtaque();
  /* Pre:Exista una clase juego previamente.
     Post:inicia la logica del juego batalla digital.
  */
  void jugarBatallaDigital();
  Ficha *agregarSoldado(TipoDeFicha tipo);
  Jugador *validarSiHayGanador(Lista<Jugador *> *jugadores);
  void matarFicha(Casillero *casillero);
  void colocarFicha(int x, int y, int z, TipoDeFicha tipo);
  void colocarMina(int x, int y, int z);
  void colocarSoldado(int x, int y, int z, Ficha *soldado);
  void moverSoldado(int x1, int y1, int z1, int x2, int y2, int z2);
  void sacarCartaDeMazo(Jugador *jugador);
  void usarCartaDeJugador(Jugador *jugador);
  unsigned int pedirNroCarta(Jugador *jugador);
  void ataqueQuimico();
  void colocarAvion();
  void colocarBarco();
  void agregarTresMinas();
  void agregarSoldado();
  void identificarFichaEnCasillero();

private:
  unsigned int soldadosDeJugadorEnTablero(Jugador *jugador);
  std::string pedirNombr(int jugadorNumero);
  unsigned int pedirCantidadJugadores();
  unsigned int pedirCantidadFichas();
  void pedirDimensionesJuego(int, int, unsigned int *dimensiones);
  unsigned int pedirCantidadCartas();
  funcion_t getFuncionalidad(unsigned int indice);
  Ficha *ponerFicha(Jugador *jugador, TipoDeFicha tipo);
  void ejecutarCarta(unsigned int indice);
};

#endif /* JUEGO_H_ */