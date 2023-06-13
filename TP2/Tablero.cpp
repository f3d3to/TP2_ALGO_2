#include "Tablero.h"

Tablero::Tablero(unsigned int x, unsigned int y, unsigned int z) {
  this->dimensiones[0] = x;
  this->dimensiones[1] = y;
  this->dimensiones[2] = z;

  this->casilleros = new Lista<Lista<Lista<Casillero *> *> *>();

  for (unsigned int k = 0; k < z; k++) {
    Lista<Lista<Casillero *> *> *fila = new Lista<Lista<Casillero *> *>();

    for (unsigned int j = 0; j < y; j++) {
      Lista<Casillero *> *columna = new Lista<Casillero *>();

      for (unsigned int i = 0; i < x; i++) {
        Casillero *casillero = new Casillero();

        if (k < 5) {
          // Los niveles del 1 al 5 tienen casilleros de tierra y agua
          // intercalados
          if ((i + j + k) % 3 != 0) {
            casillero->asignarTerreno(TIERRA);
          } else {
            casillero->asignarTerreno(AGUA);
          }
        } else {
          // Los niveles superiores representan el aire
          casillero->asignarTerreno(AIRE);
        }

        columna->altaFinal(casillero);
      }

      fila->altaFinal(columna);
    }

    this->casilleros->altaFinal(fila);
  }

  for (unsigned int i = 0; i < x; i++) {
    for (unsigned int j = 0; j < y; j++) {
      for (unsigned int k = 0; k < z; k++) {
        Casillero *casillero = this->getCasillero(i, j, k);

        for (int l = -1; l < 2; l++) {
          for (int m = -1; m < 2; m++) {
            for (int n = -1; n < 2; n++) {
              if (this->existeCasillero(i + l, j + m, k + n)) {
                Casillero *casilleroAdyacente =
                    this->getCasillero(i + l, j + m, k + n);
                casillero->asignarCasilleroAdyacente(l, m, n,
                                                     casilleroAdyacente);
              } else {
                casillero->asignarCasilleroAdyacente(l, m, n, NULL);
              }
            }
          }
        }
      }
    }
  }
}

Tablero::~Tablero() {

  for (int k = 0; k < this->dimensiones[2]; k++) {
    for (int j = 0; j < this->dimensiones[1]; j++) {
      for (int i = 0; i < this->dimensiones[0]; i++) {
        delete this->getCasillero(i, j, k);
      }
      delete this->casilleros->obtener(k + 1)->obtener(j + 1);
    }
    delete this->casilleros->obtener(k + 1);
  }
  delete this->casilleros;
}

int *Tablero::getDimensiones() { return this->dimensiones; }

bool Tablero::existeCasillero(int x, int y, int z) {
  return (x >= 0 && x < this->getDimensiones()[0] && y >= 0 &&
          y < this->getDimensiones()[1] && z >= 0 &&
          z < this->getDimensiones()[2]);
}

Casillero *Tablero::getCasillero(unsigned int x, unsigned int y,
                                 unsigned int z) {

  return this->casilleros->obtener(z + 1)->obtener(y + 1)->obtener(x + 1);
}
