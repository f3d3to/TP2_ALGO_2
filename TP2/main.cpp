#include <iostream>
#include <string>

#include "Tablero.h"
#include "Carta.h"
#include "Interfaz.h"
#include "Constantes.h"


int main() {

    
    Interfaz* interfaz = new Interfaz();
    interfaz->mostrarPantallaInicial();

    unsigned int x = 3;
    unsigned int y = 3;
    unsigned int z = 3;

    Tablero* tablero = new Tablero(x, y, z);

    interfaz->mostrarControles(tablero);

    interfaz->mostrarTablero(tablero);




    return 0;
}