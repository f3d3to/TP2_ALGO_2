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


class Juego{


private:
	Lista < Jugador * > * jugadores;
    Cola < Carta * > * mazo;
    Jugador * jugadorEnTurno;
    Jugador * jugadorAnterior;
    Jugador * ganador;
    Tablero * tablero;
    Interfaz * interfaz;
    unsigned int cantidadMaximaCartas;

public:

    Juego();

    ~Juego();

    std::string pedirNombre(int jugadorNumero);
    void cambiarTurno();

    /* Post: valida si ganador no es NULL */
    bool determinarGanador();

    /* Post: muestra el estado del juego */
    void mostrarEstadoDeTurno();

    /* Post: ejecuta la accion del jugador */
    void moverSoldado();
    void ejecutarAtaque();

private:
    std::string pedirNombr(int jugadorNumero);
    unsigned int pedirCantidadJugadores();
    unsigned int pedirCantidadFichas();
    void pedirDimensionesJuego(int,int,unsigned int * dimensiones);
    unsigned int pedirCantidadCartasPorJugador() ;
    funcion_t getFuncionalidad(unsigned int indice);




};








#endif /* JUEGO_H_ */