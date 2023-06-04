#include <iostream>
#include <string>

// #include "Tablero.h"
// #include "Carta.h"
// #include "Interfaz.h"
// #include "Constantes.h"
#include "Juego.h"


int main() {
    Juego juego = Juego();
    juego.jugarBatallaDigital();
    return 0;
}

// Interfaz* interfaz = new Interfaz();
// interfaz->mostrarPantallaInicial();

// unsigned int x = 3;
// unsigned int y = 3;
// unsigned int z = 3;

// Tablero* tablero = new Tablero(x, y, z);

// interfaz->mostrarControles(tablero);
// interfaz->mostrarTablero(tablero);

// Carta* carta1 = new Carta(ATAQUE_QUIMICO);
// Carta* carta2 = new Carta(AVION_RADAR);
// Carta* carta3 = new Carta(BARCO);
// Carta* carta4 = new Carta(REFUERZOS);
// Carta* carta5 = new Carta(ESCUDO);
// Carta* carta6 = new Carta(MASCARA_ANTIGAS);


// cout << carta1->getDescripcion() ;
// cout << carta2->getDescripcion() ;
// cout << carta3->getDescripcion() ;
// cout << carta4->getDescripcion() ;
// cout << carta5->getDescripcion() ;
// cout << carta6->getDescripcion() ;
