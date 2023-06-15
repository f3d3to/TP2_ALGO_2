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
    /*
     *pre: recibe un tipo de dato funcion_t.
     *post: crea una instancia de la clase carta, esta debe recibir un tipo funcion_t valido.
     */
    Carta(funcion_t funcion);

    /*
     *pre: que exista previamente una instancia de la clase carta.
     *post: devuelve un tipo funcion_t que indica el tipo de carta que es.
     */
    funcion_t getFuncion();

    /*
     *pre: que exista previamente una instancia de la clase carta.
     *post: duelve una descripcion de la funcion de la carta.
     */
    std::string getDescripcion();
};

#endif /* CARTA_H_ */
