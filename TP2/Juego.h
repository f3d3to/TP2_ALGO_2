#ifndef JUEGO_H_
#define JUEGO_H_

#include <iostream>
#include <string>

#include "Tablero.h"
#include "Jugador.h"
#include "Carta.h"
#include "Cola.h"
#include "Interfaz.h"
#include "Constantes.h"

typedef enum {ENCURSO, FINALIZADO} Estado;
class Juego{

private:
	Lista < Jugador * > * jugadores;
    Cola < Carta * > * mazo;
    Jugador * jugadorEnTurno;
    Jugador * ganador;
    Tablero * tablero;
    Interfaz * interfaz;
    unsigned int cantidadMaximaCartas;
    Estado estadoActual;

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
    void moverSoldado();
    void ejecutarAtaque();
    /* Pre:Exista una clase juego previamente.
       Post:inicia la logica del juego batalla digital.
    */
    void jugarBatallaDigital();


private:
    std::string pedirNombr(int jugadorNumero);
    unsigned int pedirCantidadJugadores();
    unsigned int pedirCantidadFichas();
    void pedirDimensionesJuego(int,int,unsigned int * dimensiones);
    unsigned int pedirCantidadCartasPorJugador() ;
    funcion_t getFuncionalidad(unsigned int indice);
};








#endif /* JUEGO_H_ */