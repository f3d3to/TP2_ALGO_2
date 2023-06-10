#ifndef CARTA_H_
#define CARTA_H_
#include <string>

typedef enum {
    ATAQUE_QUIMICO,
    AVION_RADAR,
    BARCO_MISIL,
    REFUERZO,
    BOMBARDEO,
    ESPIONAJE
} funcion_t;

class Carta {
private:
    funcion_t funcion;

public:
    Carta(funcion_t funcion);
    funcion_t getFuncion();
    std::string getDescripcion();
};

#endif /* CARTA_H_ */
