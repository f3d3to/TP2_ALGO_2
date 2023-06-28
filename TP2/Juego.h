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
  bool estaEmpatado;
  unsigned int cantidadDeFichas;
  int turno;

public:
  /*
   * pre: ---
   * post: crea una instancia de juego.
   */
  Juego();

  /*
   * pre: exista una instancia de juego
   * post: destruyo la instancia de juego liberando memoria.
   */
  ~Juego();

  /*
   * pre: exista una instancia de juego y reciba el numero de jugador
   * en el juego.
   * post: devuelve el nombre ddel jugador.
   */
  std::string pedirNombre(int jugadorNumero);
  void mostrarResultadosPartida();

  /*
   * pre: exista una instancia de juego.
   * post: cambia el jugadorEnTurno y mueve el cursor de la lista de jugadores.
   */
  void cambiarDeJugadorActual();

  /*
   * pre: exista una instancia de juego.
   * post: aumenta el contador de turno en 1.
   */
  void cambiarDeTurno();

  /*
   * Pre:Exista una clase juego previamente. recibe la lista de jugadores.
   * Post: comprueba si solo una de los jugadores tiene soldado, y de ser
   * verdadero devuelve al jugador ganador.
   */
  void validarSiHayGanador(Lista<Jugador *> *jugadores);

  /*
   * pre: exista una instancia de juego y reciba un casillero.
   * post: si el casillero no esta vacio elimina a la ficha en ese casillero.
   */
  void matarFicha(Casillero *casillero);

  /*
   * pre: exista una instancia de juego, recibe las coordenadas x,y,z y una
   * Ficha. post: coloca una ficha del tipo armamento en las coordenadas x,y,z.
   */
  void colocarArmamento(int x, int y, int z, Ficha *soldado);

  /*
   * pre: exista una instancia de juego, recibe las coordenadas x,y,z y una
   * Ficha.
   * post: coloca una ficha del tipo mina en las coordenadas x,y,z.
   */
  void colocarMina(int x, int y, int z);

  /*
   * pre: exista una instancia de juego, recibe las coordenadas x,y,z.
   * post: lanza un misil en la posicion x,y,z eliminando si hay soldados o
   * armamento.
   */
  void lanzarMisil(int x, int y, int z);

  /*
   * pre: exista una instancia de juego, recibe las coordenadas x,y,z y una
   * Ficha. post: coloca una ficha del tipo soldado en las coordenadas
   * x,y,z.
   */
  void colocarSoldado(int x, int y, int z, Ficha *soldado);

  /*
   * pre: exista una instancia de juego, recibe las coordenadas
   * x1,y1,z1,x2,y2,z2. post: si es una ficha del tipo soldado lo mueve desde la
   * posicion incial x1,y1,z1 a la posicion final x2,y2,z2.
   */
  void moverSoldado();

  /*
   * pre: exista una instancia de juego, recibe las coordenadas
   * x1,y1,z1,x2,y2,z2. post: si es una ficha del tipo armamento lo mueve desde
   * la posicion incial x1,y1,z1 a la posicion final x2,y2,z2.
   */
  void moverArmamento();

  /*
   * pre: exista una instancia de juego, recibe un jugador.
   * post: saca una carta del mazo y la agrega a la lista de cartas del jugador.
   */
  void sacarCartaDeMazo(Jugador *jugador);

  /*
   * pre: exista una instancia de juego, recibe un numero de carta.
   * post: dependiendo del numero de carta indicada, busca en la lista de cartas
   * del jugador y aplica la funcion de esa carta.
   */
  void usarCartaDeJugador(unsigned int posicionDeCarta);

  /*
   * pre: exista una instancia de juego, recibe un jugador.
   * post: devuelve un el numero de carta a usar por el jugador.
   */
  unsigned int pedirNroCarta(Jugador *jugador);

  /*
   * pre: exista una instancia de juego
   * post: aplica la funcion de la carta ataque quimico.
   */
  void ataqueQuimico();

  /*
   * pre: exista una instancia de juego
   * post: aplica la funcion de la carta avion radar.
   */
  void colocarAvion();

  /*
   * pre: exista una instancia de juego
   * post: aplica la funcion de la carta barco misil.
   */
  void colocarBarco();

  /*
   * pre: exista una instancia de juego
   * post: aplica la funcion la carta bormbardeo.
   */
  void agregarTresMinas();

  /*
   * pre: exista una instancia de juego
   * post: aplica la funcion de la carta Refuerzos
   */
  void agregarSoldado();

  /*
   * pre: exista una instancia de juego
   * post: aplica la funcion de la carta espionaje.
   */
  void identificarFichaEnCasillero();

  /*
   * pre: exista una instancia de juego
   * post: baja el contador de turnos en el casillero.
   */
  void bajarContadorCasilleros();

  /*
   * pre: exista una instancia de juego
   * post: Inicializa el tablero colocando las fichas en los casilleros
   * correspondientes.
   */
  void inicializarFichas();

  /*
   * pre: exista una instancia de juego, recibe un jugador.
   * post: duelve la cantidad de soldados que hay en el tablero de ese jugador.
   */
  unsigned int soldadosDeJugadorEnTablero(Jugador *jugador);

  /*
   * pre: exista una instancia de juego
   * post: devuelve la cantidad de jugadores que van a haber en el juego.
   */
  unsigned int pedirCantidadJugadores();

  /*
   * pre: exista una instancia de juego
   * post: devuelve la cantidad de fichas a usar en el juego.
   */
  unsigned int pedirCantidadFichas();

  /*
   * pre: exista una instancia de juego, recibe la cantidad de jugadores, fichas
   * y las dimensiones del tablero
   * post: pide por pantalla la cantidad de jugadores,fichas y la dimension del
   * tablero.
   */
  void pedirDimensionesJuego(int cantidadJugadores, int cantidadFichas,
                             unsigned int *dimensiones);

  /*
   * pre: exista una instancia de juego
   * post: devuelve la cantidad de cartas a usar en el juego.
   */
  unsigned int pedirCantidadCartas();

  /*
   * pre: exista una instancia de juego, pide un indice.
   * post: devuelve el tipo de funcion de la carta dependiendo del indice.
   */
  funcion_t getFuncionalidad(unsigned int indice);

  /*
   * pre: exista una instancia de juego, recibe un jugador y un tipo de ficha.
   * post: devuelve una Ficha con indentidad de ese jugador y el tipoDeFicha
   * seleccionado.
   */
  Ficha *ponerFicha(Jugador *jugador, TipoDeFicha tipo);

  /*
   * pre: exista una instancia de juego, recibe un indice.
   * post: dependiendo del indice seleccionado hace uno de la funcionalidad
   * de esa carta.
   */
  void ejecutarCarta(unsigned int indice);

  /*
   * pre: exista una instancia de juego, recibe un jugador.
   * post: devuelve true o false si encuentra un barco del jugador.
   */
  bool hayBarco(Jugador *jugador);

  /*
   * pre: exista una instancia de juego, recibe un jugador.
   * post: devuelve true o false si encuentra un avion del jugador.
   */
  bool hayAvion(Jugador *jugador);

  /*
   * pre: exista una instancia de juego.
   * post: ejecuta el radar del avion.
   */
  void ejecutarRadar(Jugador *jugador);

  /*
   * pre: exista una instancia de juego.
   * post: desarrolla toda la logica del juego batalla digital.
   */
  void jugarBatallaDigital();
};

#endif /* JUEGO_H_ */