#ifndef JUGADOR_H_
#define JUGADOR_H_

#include <string>
#include "Ficha.h"
#include "Carta.h"
#include "Lista.h"

class Jugador {
friend class Ficha;

private:

    std::string nombreJugador;
    Ficha * ficha;
    int cantidadFichas;
    Lista<Carta > cartas;
    int turnos;

public:
    
};

#endif /* JUGADOR.H */