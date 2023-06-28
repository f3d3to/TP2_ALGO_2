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
  /* Pre: x, y, z deben ser valores válidos
     Post: muestra la mina en las coordenadas (x, y, z)
  */
  void mostrarMina(int x, int y, int z);
  /* Pre:
     Post:
  */
  void mostrarMinaExplosion();
  /* Pre:
     Post:
  */
  void mostrarFichaEliminada(TipoDeFicha);
  /* Pre:
     Post:
  */
  void mostrarEmpate();

  /* Pre: ficha debe ser una cadena de caracteres válida
     Post: muestra un mensaje dependiendo qué ficha fue colocada
  */
  void mostrarFichaColocada(const std::string &ficha);

  /* Pre: instruccion debe ser una cadena de caracteres válida
     Post: muestra la instrucción en pantalla
  */
  void mostrarInstruccion(const std::string &instruccion);

  /* Pre: accion debe ser una cadena de caracteres válida
     Post: muestra un mensaje de error relacionado con las coordenadas en
     pantalla
  */
  void mostrarMsjErrorCoordenadas(const std::string &accion);

  /* Pre: accion debe ser una cadena de caracteres válida
     Post: muestra las acciones realizadas en pantalla
  */
  void mostrarAccionesRealizadas(const std::string &accion);

  /* Pre: accion debe ser una cadena de caracteres válida
     Post: muestra los mensajes relacionados con las coordenadas en pantalla
  */
  void mostrarMensajesCoordenadas(const std::string &accion);

  /* Pre: -
     Post: muestra los colores de las fichas en pantalla
  */
  void mostrarColoresFichas();

  /* Pre: -
     Post: muestra el inicio de las fichas en pantalla
  */
  void mostrarIniciarFichas();

  /* Pre: -
     Post: muestra las fichas inicializadas en pantalla
  */
  void mostrarFichasInicializadas();
  /*
   * Pre: ---
   * Post: muestra por pantalla el menu principal del juego mostrando el titulo
   * del mismo y dando bienvenida al usuario
   */
  void mostrarPantallaInicial();

  /*
   * Pre: ---
   * Post: Muestra por pantalla que el juego ha iniciado.
   */
  void mostrarBatallaIniciada();

  /*
   * Pre:----
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

  /*
   * Pre: Recibe un tablero y un jugador
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
   * Pre: ---
   * Post: pide por pantalla la cantidad de Jugadores que tendra el Juego
   */
  void pedirCantidadJugadores();

  /*
   * Pre: ---
   * Post: pide por pantalla la cantidad de Fichas que tendra cada Jugador
   */
  void pedirCantidadFichas();

  /*
   * Pre: ---
   * Post: pide por pantalla cada una de las dimensiones del tablero
   */
  void pedirDimensiones();

  /*
   * Pre: ---
   * Post: imprime un mensaje de error indicando al usuario que el tablero
   * debe ser mas grande
   */
  void tableroChico();

  /*
   * Pre: ---
   * Post: pide por pantalla cual sera la cantidad maxima de cartas que tendra
   * cada jugador
   */
  void pedirCantidadCartas();

  /*
   * Pre: ---
   * Post: imprime un mensaje para ver si usa o no carta en el turno.
   */
  void pedirUsarCarta();

  /*
   * Pre: ---
   * Post: imprime un mensaje para indicar que debe colocar una mina.
   */
  void indicarColocarMina();

  /*
   * Pre: ---
   * Post: imprime un mensaje para indicar que debe mover un soldado.
   */
  void indicarMoverSolado();

  /*
   * Pre: ---
   * Post: imprime un mensaje para indicar que debe mover un armamento.
   */
  void indicarMoverArmamento();

  /*
   * Pre: ---
   * Post: imprimer un mensaje que indica en fin del juego.
   */
  void mostrarFinDelJuego();

  /*
   * Pre: Recibe un tablero y un jugador
   * Post: imprime el tablero mediante bitmap, monstrando solo las fichas del
   * jugador ingresado.
   */
  void mostrarTableroDeJugadorBitMap(Tablero *tablero, Jugador *jugador);

  /*
   * Pre: ---
   * Post: pide por pantalla la posicion de la ficha a bloquear
   */
  void pedirPosicionFichaABloquear();

  /*
   * Pre: ---
   * Post: imprime un mensaje de error indicando al usuario que la posicion
   * ingresada es invalida
   */
  void informarNoHayFicha();

  /*
   * Pre: ---
   * Post: pide por pantalla la posicion del casillero a bloquear
   */
  void pedirPosicionCasilleroABloquear();

  /*
   * Pre: ---
   * Post: indica por pantalla que se ingreso un valor invalido
   */
  void ingresoInvalido();

  /*
   * Pre: ---
   * Post: muestra un mensaje en pantalla pidiendo al jugador que introduzca
   * las 3 coordenadas del tablero donde desea ubicar su ficha
   */
  void pedirCoordPonerFicha();

  /*
   * Pre: ---
   *Post: imprime un mensaje de error indicando al usuario que el casillero
   *pedido no esta disponible
   */
  void informarCasilleroNoDisponible();

  /*
   * Pre: ---
   * Post: pide por pantalla la posicion de la ficha que se desea mover
   */
  void pedirCoordOrigenMoverFicha();

  /*
   * Pre: ---
   * Post: pide por pantalla la posicion de destino de la ficha que se desea
   * mover
   */
  void pedirCoordDestinoMoverFicha();

  /*
   * Pre: ---
   * Post: imprime un mensaje preguntado al usuario si quiere utilizar alguna
   * de sus cartas
   */
  void preguntarUsarCarta();

  /*
   * Pre: ---
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
   * Pre: ---
   * Post: imprime un mensaje de error indicando al usuario que no posee la
   * carta elegida
   */
  void jugadorNoTieneCartaElegida();

  /*
   * Pre: ---
   * Post: imprime por pantalla un mensaje indicando al usuario que el mismo
   * no posee cartas en su mano
   */
  void jugadorSinCartas();

  /*
   * Pre: ---
   * Post: Limpia la interfaz de juego
   */
  void limpiarPantalla();

  /*
   * Pre: ---
   * Post: imprime por pantalla el nombre del jugador
   */
  void mostrarJugadorEnTurno(std::string nombreJugador);

  /*
   * Pre: ---
   * Post: imprime un mensaje confirmando el movimiento realizado
   */
  void informarMovimientoDeFicha();

  /*
   * Pre: Recibe un jugador.
   * Post: Imprime un mensaje mostrando las cartas del jugador.
   */
  void mostrarCartasJugador(Jugador *jugador);

  /*
   * Pre: ---
   * Post: imprime un mensaje de que el jugador no tiene cartas.
   */
  void mazoSinCartas();

  /*
   * Pre: ---
   * Post: imprime mostrando la ficha en el casillero.
   */
  void mostrarFichaEnCasillero(Casillero *casillero);

  /*
   * Pre: recibe las coordenadas x,y,z.
   * Post: imprime un mensaje pidiendo una posicion y las almacena en x,y,z.
   */
  void pedirCoordenadas(int &x, int &y, int &z, Tablero *tablero);

  /*
   * Pre: Recibe un jugador.
   * Post:imprime un mensaje pidiendo la carta a usar del jugador y
   * devuelve el numero de la carta a usar.
   */
  unsigned int pedirNroCarta(Jugador *jugador);

  void sobrescribirArchivoBMP();
};

#endif /* INTERFAZ_H_ */