#include "Carta.h"
#include "Cola.h"
#include "Constantes.h"
#include "Interfaz.h"
#include "Juego.h"
#include "Jugador.h"
#include "Tablero.h"
#include <iostream>
#include <string>

int main() {
  Juego *juego = new Juego();
  juego->jugarBatallaDigital();

  delete juego;
  return 0;
}
