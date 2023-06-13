#include "Carta.h"
#include "Cola.h"
#include "Constantes.h"
#include "EasyBMP/EasyBMP.h"
#include "Interfaz.h"
#include "Juego.h"
#include "Jugador.h"
#include "Tablero.h"
#include <iostream>
#include <string>

int main() {
  Juego *juego = new Juego();
  juego->interfaz->limpiarPantalla();
  juego->inicializarFichas();
  while (juego->estadoActual != FINALIZADO) {
    juego->interfaz->mostrarBatallaIniciada();
    int x0 = 0, y0 = 0, z0 = 0, x1 = 0, y1 = 0, z1 = 0;
    juego->sacarCartaDeMazo(juego->jugadorEnTurno);

    // Obtiene el nro de la carta y la ejecuta
    juego->interfaz->mostrarCartasJugador(juego->jugadorEnTurno);
    juego->interfaz->pedirUsarCarta();
    char opcionCarta;
    std::cin >> opcionCarta;
    if (opcionCarta == 'S' || opcionCarta == 's') {
      unsigned int nroCarta =
          juego->interfaz->pedirNroCarta(juego->jugadorEnTurno);
      juego->usarCartaDeJugador(nroCarta);
    }

    juego->interfaz->indicarColocarMina();
    juego->interfaz->pedirCoordenadas(x1, y1, z1);
    juego->colocarMina(x1, y1, z1);

    juego->interfaz->indicarMoverSolado();
    char opcionSoldado;
    std::cin >> opcionSoldado;
    if (opcionSoldado == 'S' || opcionSoldado == 's') {
      juego->interfaz->pedirCoordenadas(x0, y0, z0);
      juego->interfaz->pedirCoordenadas(x1, y1, z1);
      juego->moverSoldado(x0, y0, z0, x1, y1, z1);
    }

    juego->interfaz->indicarMoverArmamento();
    char opcionArmamento;
    std::cin >> opcionArmamento;
    if (opcionArmamento == 'S' || opcionArmamento == 's') {
      juego->interfaz->pedirCoordenadas(x0, y0, z0);
      juego->interfaz->pedirCoordenadas(x1, y1, z1);
      juego->moverArmamento(x0, y0, z0, x1, y1, z1);
    }

    juego->interfaz->mostrarTableroDeJugadorBitMap(juego->tablero,
                                                   juego->jugadorEnTurno);
    std::cout << "Seleccione enter para avanzar de turno." << std::endl;
    juego->interfaz->limpiarPantalla();

    juego->cambiarDeJugadorActual();

    juego->turno++;
    juego->hayGanador = juego->validarSiHayGanador(juego->jugadores);
    juego->estadoActual = juego->determinarGanador() ? FINALIZADO : ENCURSO;
  }
  juego->interfaz->mostrarGanador(juego->hayGanador->getNombre());
  juego->interfaz->mostrarFinDelJuego();
  delete juego;
  return 0;
}
