#include "Interfaz.h"
#include "Casillero.h"
#include "Constantes.h"
#include "EasyBMP/EasyBMP.h"
#include "Jugador.h"
#include "Nodo.h"
#include "Tablero.h"
#include <iostream>

void Interfaz::mostrarPantallaInicial() {
  std::cout << "\n\n\033[1;36m================================================="
               "==============="
               "==============================\n\n";
  std::cout << "\033[1;36m\n\t\t\t\t BATALLA DIGITAL V2.0      \033[0m"
            << std::endl;
  std::cout
      << "\n\t\033[1mBienvenido a BATALLA DIGITAL 2.0, una versión alternativa"
         " de la BATALLA DIGITAL convencional \n\tcon un tablero en 3 "
         "dimensiones"
         " y varios jugadores y cartas para jugar!\033[0m"
      << std::endl;
  std::cout << "\n\033[1mProyecto desarrollado por alumnos de FIUBA:\033[0m"
            << std::endl;
  std::cout
      << "\nAmddy Zambrano, Agustín Allelo, Pablo Mokorel, Federico Neuman"
      << std::endl;
  std::cout << "\n\n\033[1;36m================================================="
               "==============="
               "==============================\n\n";

  this->limpiarPantalla();
}

void Interfaz::mostrarControles(Tablero *t) {
  int dim[3];
  dim[0] = t->getDimensiones()[0];
  dim[1] = t->getDimensiones()[1];
  dim[2] = t->getDimensiones()[2];

  cout << "\n\n································································"
          "·";
  cout << "······························\n\n";

  std::cout << "#DISPOSICION DEL TABLERO:\n\n";
  for (int k = 1; k < dim[2] + 1; ++k) {
    for (int f = 0; f < k - 1; ++f) {
      std::cout << "\t";
    }
    std::cout << "Profundo:" << k << "\n";
    for (int f = 0; f < k; ++f) {
      std::cout << "\t";
    }
    std::cout << "     ancho:";
    for (int f = 1; f < dim[0] + 1; ++f) {
      std::cout << " " << f << "   ";
    }
    std::cout << "\n";
    for (int j = 1; j < dim[1] + 1; ++j) {
      for (int f = 0; f < k; ++f) {
        std::cout << "\t";
      }
      std::cout << "alto:" << j << "    ";

      for (int i = 1; i < dim[0] + 1; ++i) {
        try {
          char simbolo = t->getCasillero(i - 1, j - 1, k - 1)
                             ->getFicha()
                             ->getTipoDeFicha();
          std::cout << "  " << simbolo << "  ";
        } catch (...) {
          std::cout << "  "
                    << "-"
                    << "  ";
        }
      }
      std::cout << "\n";
    }
    std::cout << "\n\n";
  }
  std::cout << "\n#COORDENADAS\n";
  std::cout
      << "\nLas coordenadas que ingrese deben estar entre los rangos:  \n";
  std::cout << "\n\t Ancho:\t\t1 - " << dim[0];
  std::cout << "\n\t Alto:\t\t1 - " << dim[1];
  std::cout << "\n\t Profundo:\t1 - " << dim[2];

  cout << "\n\n································································"
          "·";
  cout << "······························\n\n";
}
void Interfaz::mostrarBatallaIniciada() {
  std::cout
      << "\033[1;36m\033[4mBatalla iniciada, el juego ha comenzado!\033[0m\n"
      << std::endl;
}

void Interfaz::mostrarFicha(Ficha *ficha) {
  if (ficha == NULL) {
    cout << '-';
  }
  if (ficha->getTipoDeFicha() == MINA) {
    cout << 'M';
  }
  if (ficha->getTipoDeFicha() == AVION) {
    cout << '>';
  }
  if (ficha->getTipoDeFicha() == BARCO) {
    cout << 'B';
  }
  if (ficha->getTipoDeFicha() == SOLDADO) {
    cout << 'S';
  }
  if (ficha->getTipoDeFicha() == ARMAMENTO) {
    cout << 'A';
  }
}
void Interfaz::mostrarFinDelJuego() {
  std::cout << "\033[1;31m\033[4mFin del juego, gracias por jugar!\033[0m\n"
            << std::endl;
}

void Interfaz::mostrarGanador(std::string nombreGanador) {
  cout << "\n\n================================================================"
          "=";
  cout << "==============================\n\n";
  std::cout << "\n\tEl ganador del juego es: \n\n\t\t" << nombreGanador
            << std::endl;
  cout << "\n\n================================================================"
          "=";
  cout << "==============================\n\n";
}

void Interfaz::pedirNombre(int jugadorNumero) {
  std::cout << "\nJugador " << jugadorNumero
            << " - Ingrese su nombre (max 10 caracteres): ";
}

void Interfaz::pedirCantidadJugadores() {
  std::cout << "\nIngrese la cantidad de jugadores con la que desea "
               "jugar (2 o "
               "mas): ";
}

void Interfaz::pedirCantidadFichas() {
  std::cout << "\nIngrese la cantidad de fichas que tendra cada "
               "jugador (4 o mas): ";
}

void Interfaz::pedirDimensiones() {
  std::cout << "\nIngrese las dimensiones del tablero (ancho, alto, "
               "profundo): "
            << std::endl;
}

void Interfaz::tableroChico() {
  std::cout << "\nEl tablero debe ser mas grande." << std::endl;
}

void Interfaz::pedirCantidadCartas() {
  std::cout << "\nIngrese la cantidad maxima de cartas que podra tener en la "
               "mano cada jugador al mismo tiempo (minimo 6): ";
}
void Interfaz::pedirUsarCarta() {
  std::cout << "Desea usar una carta? S/N" << std::endl;
}

void Interfaz::pedirPosicionFichaABloquear() {
  std::cout << "\nIngrese la posicion en el tablero de la ficha a bloquear: "
            << std::endl;
}

void Interfaz::informarNoHayFicha() {
  std::cout << "\nNo hay una ficha en la posicion del tablero ingresada."
            << std::endl;
}

void Interfaz::pedirPosicionCasilleroABloquear() {
  std::cout << "\nIngrese la posicion en el tablero del casillero a "
               "bloquear: "
            << std::endl;
}
void Interfaz::indicarColocarMina() {
  std::cout << "Coloque una \033[1;31mmina\033[0m";
}

void Interfaz::indicarMoverSolado() {
  std::cout << "Desea mover un soldado? S/N" << std::endl;
}

void Interfaz::indicarMoverArmamento() {
  std::cout << "Desea mover un armamento? S/N" << std::endl;
}

void Interfaz::pedirCoordPonerFicha() {
  std::cout << "\nIngrese la posicion en el tablero donde desea "
               "colocar su ficha: "
            << std::endl;
}

void Interfaz::informarCasilleroNoDisponible() {
  std::cout << "\nEl casillero elegido no esta disponible" << std::endl;
}

void Interfaz::informarMovimientoDeFicha() {
  std::cout << "\n La ficha se ha movido con éxito." << std::endl;
}

void Interfaz::pedirCoordOrigenMoverFicha() {
  std::cout << "\nIngrese la posicion en el tablero de la ficha que "
               "desea mover: "
            << std::endl;
}

void Interfaz::pedirCoordDestinoMoverFicha() {
  std::cout << "\nIngrese la posicion en el tablero a donde desea mover la "
               "ficha elegida: "
            << std::endl;
}

void Interfaz::preguntarUsarCarta() {
  std::cout << "\nQuieres utilizar una carta? (S/N): ";
}

void Interfaz::preguntarNroCarta() {
  std::cout << "\nCual carta quieres usar?: ";
}

void Interfaz::tocaPonerFicha(std::string nombreJugador, char simbolo,
                              int cantidadFichas, std::string color) {
  std::cout << "\nJugador: " << nombreJugador
            << " te toca poner una ficha, tenes " << cantidadFichas
            << " (usas la " << simbolo << "  -  Color: " << color << ")."
            << std::endl;
}

void Interfaz::tocaMoverFicha(std::string nombreJugador, char simbolo,
                              std::string color) {
  std::cout << "\nJugador: " << nombreJugador
            << " te toca mover una ficha (usas la " << simbolo
            << "  -  Color: " << color << ")." << std::endl;
}

void Interfaz::mostrarCartasJugador(Jugador *jugador) {
  unsigned int contador = 0;
  std::cout << "\n Jugador: '" << jugador->getNombre() << "', tus cartas son: ";
  Lista<Carta *> *cartas = jugador->getCartas();
  cartas->iniciarCursor();
  while (cartas->avanzarCursor()) {
    contador++;
    Carta *carta = cartas->obtenerCursor();
    std::cout << "\n\t * " << contador << " : " << carta->getDescripcion()
              << "\n";
  }
}

void Interfaz::jugadorNoTieneCartaElegida() {
  std::cout << "\nNo tienes la carta que elegiste usar." << std::endl;
}

void Interfaz::jugadorSinCartas() {
  std::cout << "\nNo tienes cartas para usar." << std::endl;
}

void Interfaz::mazoSinCartas() {
  std::cout << "\nEl mazo no tiene mas cartas." << std::endl;
}

void Interfaz::ingresoInvalido() {
  std::cout << "\nEl valor ingresado es invalido, vuelva a intentar"
            << std::endl;
}

void Interfaz::mostrarJugadorEnTurno(std::string nombreDeJugador) {
  std::cout << "\nEs el turno del jugador: " << nombreDeJugador << "."
            << std::endl;
}

void Interfaz::limpiarPantalla() {
  std::cout << "\033[1mPresione Enter para iniciar...\033[0m" << std::endl;
  std::cin.ignore(); // Limpiar el búfer de entrada
  std::cin.get();    // Esperar a que se ingrese una tecla

  std::cout << "\033[H\033[2J\033[3J"; // CARACTER PARA LIMPIAR LA PANTALLA
}

void Interfaz::mostrarFichaEnCasillero(Casillero *casillero) {

  std::cout << " ";
  this->mostrarFicha(casillero->getFicha());
  std::cout << "";
}
void Interfaz::pedirCoordenadas(int &x, int &y, int &z, Tablero *tablero) {

  bool coordenadasValidas = false;

  std::cout << "\nIngrese las coordenas del casillero (ancho, alto, "
               "profundo): "
            << std::endl;

  while (!coordenadasValidas) {
    int *dimesiones = tablero->getDimensiones();
    std::cin >> x;
    std::cin >> y;
    std::cin >> z;

    if (x < 1 || y < 1 || z < 1 || x > dimesiones[0] || y > dimesiones[1] ||
        z > dimesiones[2]) {
      std::cout << "Coordenadas inválidas. Intente nuevamente." << std::endl;
      coordenadasValidas = false;
    } else {
      coordenadasValidas = true;
    }
  }
  x--;
  y--;
  z--;
}

unsigned int Interfaz::pedirNroCarta(Jugador *jugador) {
  unsigned int posicionDeCarta;
  bool cartaValida = false;

  while (!cartaValida) {
    this->preguntarNroCarta();
    std::cin >> posicionDeCarta;

    if (posicionDeCarta < 1 ||
        posicionDeCarta > jugador->getCartas()->contarElementos()) {
      this->ingresoInvalido();
    } else {
      cartaValida = true;
    }
  }

  return posicionDeCarta;
}

void pintarCasillero(BMP &image, int xStart, int yStart, int xEnd, int yEnd,
                     int red, int green, int blue) {
  for (int x = xStart; x <= xEnd; ++x) {
    for (int y = yStart; y <= yEnd; ++y) {
      if (x == xStart || x == xEnd || y == yStart || y == yEnd) {
        // Dibujar contorno negro
        image(x, y)->Red = 0;
        image(x, y)->Green = 0;
        image(x, y)->Blue = 0;
      } else {
        // Pintar el interior del casillero
        image(x, y)->Red = red;
        image(x, y)->Green = green;
        image(x, y)->Blue = blue;
      }
    }
  }
}

void pintarFicha(BMP &image, int xStart, int yStart, int xEnd, int yEnd,
                 int fichaRed, int fichaGreen, int fichaBlue) {
  int centerX = (xStart + xEnd) / 2;
  int centerY = (yStart + yEnd) / 2;
  int radius = (xEnd - xStart) / 2 - 2;

  for (int x = xStart; x <= xEnd; ++x) {
    for (int y = yStart; y <= yEnd; ++y) {
      int dx = x - centerX;
      int dy = y - centerY;
      if (dx * dx + dy * dy <= radius * radius) {
        // Pintar dentro del círculo
        image(x, y)->Red = fichaRed;
        image(x, y)->Green = fichaGreen;
        image(x, y)->Blue = fichaBlue;
      } else if (dx * dx + dy * dy >= (radius - 2) * (radius - 2) &&
                 dx * dx + dy * dy <= radius * radius) {
        // Pintar contorno del círculo en color blanco
        image(x, y)->Red = 255;
        image(x, y)->Green = 255;
        image(x, y)->Blue = 255;
      }
    }
  }
}

void asignarColor(TipoTerreno terreno, EstadoCasillero estado, int &red,
                  int &green, int &blue) {
  switch (terreno) {
  case AGUA:
    red = (estado == CASILLERO_ENVENENADO) ? 85 : 0;
    green = (estado == CASILLERO_BLOQUEADO) ? 85 : 100;
    blue = (estado == CASILLERO_BLOQUEADO) ? 85 : 235;
    break;
  case TIERRA:
    red = (estado == CASILLERO_BLOQUEADO) ? 128 : 102;
    green = (estado == CASILLERO_ENVENENADO) ? 255 : 51;
    blue = (estado == CASILLERO_ENVENENADO) ? 0 : 0;
    break;
  case AIRE:
    red = (estado == CASILLERO_BLOQUEADO) ? 209 : 0;
    green = (estado == CASILLERO_ENVENENADO) ? 235 : 191;
    blue = (estado == CASILLERO_ENVENENADO) ? 247 : 255;
    break;
  }
}

// Función para asignar el color de la ficha
void asignarColorFicha(Ficha *ficha, int &red, int &green, int &blue) {
  if (ficha == NULL) {
    red = 255;
    green = 255;
    blue = 255; // Gris (por defecto)
  } else {
    switch (ficha->getTipoDeFicha()) {
    case NO_DEFINIDA:
      red = 255;
      green = 255;
      blue = 255;
      break;
    case MINA:
      red = 0;
      green = 255;
      blue = 95; // Verde brillante
      break;
    case SOLDADO:
      red = 255;
      green = 255;
      blue = 0; // Amarillo brillante
      break;
    case ARMAMENTO:
      red = 255;
      green = 0;
      blue = 255; // Magenta
      break;
    case BARCO:
      red = 255;
      green = 165;
      blue = 0; // Naranja
      break;
    case AVION:
      red = 128;
      green = 128;
      blue = 128; // Gris
      break;
    }
  }
}

void pintarFondoNegro(BMP &image) {
  // Pintar fondo negro
  for (int x = 0; x < image.TellWidth(); ++x) {
    for (int y = 0; y < image.TellHeight(); ++y) {
      image(x, y)->Red = 255;
      image(x, y)->Green = 255;
      image(x, y)->Blue = 255;
    }
  }
}
void Interfaz::mostrarTableroDeJugadorBitMap(Tablero* tablero, Jugador* jugador) {
  int dim[3];
  dim[0] = tablero->getDimensiones()[0];
  dim[1] = tablero->getDimensiones()[1];
  dim[2] = tablero->getDimensiones()[2];

  int nivelesPorFila = 3;  // Cantidad de capas por cada fila de niveles
  int pixelSize = 60;      // Tamaño de píxel para cada casillero (aumentado)
  int layerGap = 20;       // Espacio entre capas (aumentado)
  BMP image;
  image.SetSize(dim[0] * pixelSize * nivelesPorFila + (nivelesPorFila - 1) * layerGap + 50,
                dim[1] * pixelSize * ((dim[2] + nivelesPorFila - 1) / nivelesPorFila) +
                    ((dim[2] + nivelesPorFila - 1) / nivelesPorFila - 1) * layerGap + 50);
  image.SetBitDepth(24);
  pintarFondoNegro(image);

  for (int k = 0; k < dim[2]; ++k) {
    int nivelActual = k / nivelesPorFila;     // Nivel actual en la fila de niveles
    int nivelOffset = k % nivelesPorFila;     // Desplazamiento en la fila de niveles

    for (int j = 0; j < dim[1]; ++j) {
      for (int i = 0; i < dim[0]; ++i) {
        Casillero* casillero = tablero->getCasillero(i, j, k);
        Ficha* ficha = casillero->getFicha();

        int xStart = (nivelActual * dim[0] + i) * pixelSize + nivelActual * layerGap + 25;
        int yStart = (j + nivelOffset * dim[1]) * pixelSize + nivelOffset * layerGap + 25;
        int xEnd = (nivelActual * dim[0] + i + 1) * pixelSize + nivelActual * layerGap + 25;
        int yEnd = (j + 1 + nivelOffset * dim[1]) * pixelSize + nivelOffset * layerGap + 25;

        EstadoCasillero estadoCasillero = casillero->getEstado();
        TipoTerreno terreno = casillero->obtenerTerreno();
        int red, green, blue;
        asignarColor(terreno, estadoCasillero, red, green, blue);
        pintarCasillero(image, xStart, yStart, xEnd, yEnd, red, green, blue);
        if (ficha != NULL && ficha->getIdentificadorDeJugador() == jugador->getNombre()) {
          int fichaRed, fichaGreen, fichaBlue;
          asignarColorFicha(ficha, fichaRed, fichaGreen, fichaBlue);
          pintarFicha(image, xStart, yStart, xEnd, yEnd, fichaRed, fichaGreen, fichaBlue);
        }
      }
    }
  }

  std::cout << "Guardando tablero." << std::endl;
  image.WriteToFile("tablero.bmp");
  std::cout << "Tablero impreso." << std::endl;
}
