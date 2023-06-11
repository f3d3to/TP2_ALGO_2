#ifndef INTERFAZ_H_
#define INTERFAZ_H_

#include "Carta.h"
#include "Jugador.h"
#include "Lista.h"
#include "Tablero.h"
#include "iostream"

using namespace std;

class Interfaz {
public:
  /*
   * Post: muestra por pantalla el menu principal del juego mostrando el titulo
   * del mismo y dando bienvenida al usuario
   */
  void mostrarPantallaInicial();

  /*
   * Post: muestra en pantalla el simbolo de la ficha recibida sin dar
   * salto de línea al final
   */
  void mostrarFicha(Ficha *);

  /*
   * Pre: recibe un string con el nombre del Jugador que ha ganado el juego
   * Post: muestra un mensaje por pantalla indicando el nombre del ganador
   */
  void mostrarGanador(std::string);

  /*
   * Pre: Recibe un tablero valido
   * Post: muestra por pantalla el la disposicion del tablero especificando
   *        el ancho alto y profundo para orientar al ususario
   */
  void mostrarControles(Tablero *);

  /*
   * Pre: recibe el estado actual del tablero
   * Post: muestra por pantalla las Fichas de los casilleros del tablero
   * recibido imprimiendo tantos planos como profundidad tenga el tablero
   * recibido. Por ejemplo si el tablero tiene una profundidad de 2 niveles
   * (z=2) se mostrara por pantalla 2 planos xy pertenecientes a cada nivel de
   * profundidad
   */
  void mostrarTablero(Tablero *);

  /*Pre: Recibe un tablero y un jugador
   * Post: Muestra por pantalla el tablero del jugador.
   */
  void mostrarTableroDeJugador(Tablero *, Jugador *);
  /*
   * Pre: recibe el número de jugador al que corresponde el nombre
   * Post: pide por pantalla el nombre al jugador indicando su número
   * ejemplo: Jugador 1: Tomás, Jugador 2: Miguel, ett
   */
  void pedirNombre(int);

  /*
   * Post: pide por pantalla la cantidad de Jugadores que tendra el Juego
   */
  void pedirCantidadJugadores();

  /*
   * Post: pide por pantalla la cantidad de Fichas que tendra cada Jugador
   */
  void pedirCantidadFichas();

  /*
   * Post: pide por pantalla cada una de las dimensiones del tablero
   */
  void pedirDimensiones();

  /*
   * Post: imprime un mensaje de error indicando al usuario que el tablero debe
   * ser mas grande
   */
  void tableroChico();

  /*
   * Post: pide por pantalla cual sera la cantidad maxima de cartas que tendra
   * cada jugador
   */
  void pedirCantidadCartas();

  /*
   * Post: pide por pantalla la posicion de la ficha a bloquear
   */
  void pedirPosicionFichaABloquear();

  /*
   * Post: imprime un mensaje de error indicando al usuario que la posicion
   * ingresada es invalida
   */
  void informarNoHayFicha();

  /*
   * Post: pide por pantalla la posicion del casillero a bloquear
   */
  void pedirPosicionCasilleroABloquear();

  /*
   * Post: indica por pantalla que se ingreso un valor invalido
   */
  void ingresoInvalido();

  /*
   * Post: muestra un mensaje en pantalla pidiendo al jugador que introduzca
   * las 3 coordenadas del tablero donde desea ubicar su ficha
   */
  void pedirCoordPonerFicha();

  /*
   *Post: imprime un mensaje de error indicando al usuario que el casillero
   *pedido no esta disponible
   */
  void informarCasilleroNoDisponible();

  /*
   * Post: pide por pantalla la posicion de la ficha que se desea mover
   */
  void pedirCoordOrigenMoverFicha();

  /*
   * Post: pide por pantalla la posicion de destino de la ficha que se desea
   * mover
   */
  void pedirCoordDestinoMoverFicha();

  /*
   * Post: imprime un mensaje preguntado al usuario si quiere utilizar alguna de
   * sus cartas
   */
  void preguntarUsarCarta();

  /*
   * Post: imprime un mensaje preguntado al usuario que numero de carta quier
   * utilizar
   */
  void preguntarNroCarta();

  /*
   * Pre: recibe un string nombreJugador valido y un char simbolo valido
   * Post: indica al jugador "nombreJugador" que debe poner una ficha cuyo
   * simbolo en pantalla es "simbolo"
   */
  void tocaPonerFicha(std::string, char, int, std::string);

  /*
   * Pre: recibe un string nombreJugador valido y un char simbolo valido
   * Post: indica al jugador "nombreJugador" que debe mober una ficha cuyo
   * simbolo en pantalla es "simbolo"
   */
  void tocaMoverFicha(std::string, char, std::string);

  /*
   * Pre: Recibe una lista de cartas valida y un string nombreJugador valido
   * Post: muestra por pantalla las "cartas" disponibles del jugador
   * "nombreJugador"
   */
  /*
  void mostrarCartasJugador(std::string, Lista<Carta*> *);
*/
  /*
   * Post: imprime un mensaje de error indicando al usuario que no posee la
   * carta elegida
   */
  void jugadorNoTieneCartaElegida();

  /*
   * Post: imprime por pantalla un mensaje indicando al usuario que el mismo no
   * posee cartas en su mano
   */
  void jugadorSinCartas();

  /* Post: Limpia la interfaz de juego */
  void limpiarPantalla();

  /*Post: imprime por pantalla el nombre del jugador*/
  void mostrarJugadorEnTurno(std::string nombreJugador);
  /*
   * Post: imprime un mensaje confirmando el movimiento realizado
   */
  void informarMovimientoDeFicha();

  void mostrarCartasJugador(Jugador *jugador);

  void mazoSinCartas();

  void mostrarFichaEnCasillero(Casillero *casillero);

  void pedirCoordenadas(int &x, int &y, int &z);

  unsigned int pedirNroCarta(Jugador *jugador);
};

#endif /* INTERFAZ_H_ */