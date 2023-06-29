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
  try {
    Juego *juego = new Juego();
    juego->jugarBatallaDigital();
    delete juego;
  } catch (...) {
    throw "Hay un error en el inicio del juego.";
  }
}
