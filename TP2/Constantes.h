#ifndef CONSTANTES_H_
#define CONSTANTES_H_

#include <string>

#define VACIO '.'

enum TipoDeFicha { NO_DEFINIDA, MINA, SOLDADO, ARMAMENTO, BARCO, AVION };

enum EstadoFicha { FICHA_DESBLOQUEADA, FICHA_BLOQUEADA };

enum EstadoCasillero {
  CASILLERO_BLOQUEADO,
  CASILLERO_DESBLOQUEADO,
  CASILLERO_ENVENENADO
};

enum TipoTerreno { TIERRA, AGUA, AIRE };

#endif /* CONSTANTES_H_ */
