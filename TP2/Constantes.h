#ifndef CONSTANTES_H_
#define CONSTANTES_H_


#include <string>


#define VACIO '.' // tira error si hay espacio ' '


enum EstadoFicha {
    FICHA_DESBLOQUEADA,
    FICHA_BLOQUEADA
};


enum EstadoCasillero {
    CASILLERO_BLOQUEADO,
    CASILLERO_DESBLOQUEADO
};

enum  TipoCasillero {
    TIERRA,
    AGUA,
    AIRE
};





#endif /* CONSTANTES_H_ */