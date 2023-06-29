#include "Juego.h"
#include "Carta.h"
#include "Casillero.h"
#include "Constantes.h"
#include "Ficha.h"
#include "Jugador.h"
#include "Lista.h"
#include "Pila.h"
#include "Tablero.h"
#include <csignal>
#include <iostream>
#include <string>
#include <unistd.h>

Juego::Juego() {
  this->interfaz->mostrarPantallaInicial();
  this->cantidadTurnosJuego = 0;
  this->interfaz = new Interfaz();
  this->hayGanador = NULL;
  this->estadoActual = ENCURSO;
  this->jugadorEnTurno = NULL;
  this->turno = 0;
  this->interfaz->mostrarInstruccion("I");
  unsigned int cantidadJugadores = pedirCantidadJugadores();
  unsigned int cantidadFichas = pedirCantidadFichas();
  unsigned int cantidadCartas = pedirCantidadCartas();

  this->cantidadDeFichas = cantidadFichas;

  this->jugadores = new Lista<Jugador *>;
  // mostrar Siguiente jugador
  for (unsigned int i = 0; i < cantidadJugadores; i++) {
    std::string nombre = pedirNombre(i + 1);
    Pila<Ficha *> *fichas = new Pila<Ficha *>;
    for (unsigned int j = 0; j < cantidadFichas; j++) {
      Ficha *ficha = new Ficha(nombre);
      fichas->apilar(ficha);
    }

    Jugador *nuevoJugador = new Jugador(nombre);
    nuevoJugador->setFichas(fichas); // Actualiza la pila de fichas del jugador
    this->jugadores->altaFinal(nuevoJugador);
  }

  // Setea jugador en turno.
  this->jugadores->iniciarCursor();
  this->jugadores->avanzarCursor();
  this->jugadorEnTurno = this->jugadores->obtenerCursor();

  unsigned int *dimensiones = new unsigned int[3];
  pedirDimensionesJuego(cantidadJugadores, cantidadFichas, dimensiones);
  this->tablero = new Tablero(dimensiones[0], dimensiones[1], dimensiones[2]);
  delete[] dimensiones;

  // Inicializa mazo de cartas (TDA Pila).
  this->mazo = new Pila<Carta *>;
  for (unsigned int i = 0; i < cantidadCartas; i++) {
    funcion_t funcionalidad = getFuncionalidad(i % 6);

    Carta *nuevaCarta = new Carta(funcionalidad);

    this->mazo->apilar(nuevaCarta);
  }
  this->interfaz->mostrarInstruccion("J");
}

Juego::~Juego() {
  delete this->interfaz;
  delete this->hayGanador;

  delete this->jugadorEnTurno;
  delete this->jugadores;

  delete this->tablero;

  while (!this->mazo->estaVacia()) {
    delete this->mazo->desapilar();
  }

  delete this->mazo;
}

void Juego::cambiarDeJugadorActual() {
  bool cursorAvanzado = this->jugadores->avanzarCursor();

  if (cursorAvanzado) {
    this->jugadorEnTurno = this->jugadores->obtenerCursor();

  } else {
    this->jugadores
        ->iniciarCursor(); // Reiniciar el cursor al principio de la lista

    if (this->jugadores->avanzarCursor()) {
      this->jugadorEnTurno = this->jugadores->obtenerCursor();
    } else {
      // La lista está vacía, no hay jugadores
      this->jugadorEnTurno = NULL;
    }
  }
  if (this->jugadorEnTurno != NULL) {
    this->interfaz->mostrarJugadorEnTurno(this->jugadorEnTurno->getNombre());
  } else {
  }
}

// FUNCIONES DE ENTRADA DE DATOS//
unsigned int Juego::pedirCantidadJugadores() {

  int cantidadJugadores = 0;
  bool cantidadValida = false;

  while (!cantidadValida) {

    this->interfaz->pedirCantidadJugadores();
    try {
      std::cin >> cantidadJugadores;
      if (cantidadJugadores < 2) {
        throw "Error Menos de 2 jugadores";
      }
      cantidadValida = true;
    } catch (...) {
      this->interfaz->ingresoInvalido();
    }
  }

  return (unsigned int)cantidadJugadores;
}

unsigned int Juego::pedirCantidadFichas() {

  int cantidadFichas = 0;
  bool cantidadValida = false;

  while (!cantidadValida) {
    this->interfaz->pedirCantidadFichas();
    try {
      std::cin >> cantidadFichas;
      if (cantidadFichas < 4) {
        throw "Error menos de 4 fichas";
      }
      cantidadValida = true;
    } catch (...) { // En caso de que ingrese un valor inválido se le indica al
                    // usuario que lo que ingreso es inválido
      this->interfaz->ingresoInvalido();
    }
  }

  return (unsigned int)cantidadFichas;
}

std::string Juego::pedirNombre(int jugadorNumero) {
  std::string nombre;
  bool nombreValido = false;

  while (!nombreValido) {
    this->interfaz->pedirNombre(jugadorNumero);
    try {
      std::cin >> nombre;
      if (nombre.length() > 10) {
        throw("Nombre demasiado largo.");
      }
      nombreValido = true;
    } catch (...) {
      this->interfaz->ingresoInvalido();
    }
  }
  return nombre;
}

void Juego::pedirDimensionesJuego(int cantidadJugadores, int cantidadFichas,
                                  unsigned int *dimensiones) {
  int ancho, alto, profundo;
  bool diemensionesValidas = false;

  while (!diemensionesValidas) {
    this->interfaz->pedirDimensiones();
    try {
      std::cout << "\033[1;35mAncho:\033[0m  \t";
      std::cin >> ancho;

      std::cout << "\033[1;35mAlto:\033[0m   \t";
      std::cin >> alto;

      std::cout << "\033[1;35mProfundo:\033[0m  \t";
      std::cin >> profundo;

      if (ancho < 1 || alto < 1 || profundo < 1 ||
          ancho * alto * profundo <
              cantidadJugadores * cantidadFichas + cantidadJugadores) {
        throw "Dimesiones de juego invalidas o tablero demasiado chico.";
      }
      diemensionesValidas = true;
    } catch (...) {
      this->interfaz->tableroChico();
    }
  }

  dimensiones[0] = ancho;
  dimensiones[1] = alto;
  dimensiones[2] = profundo;
}

unsigned int Juego::pedirCantidadCartas() {

  int cantidadCartas;
  bool cantidad_valida = false;

  while (!cantidad_valida) {
    this->interfaz->pedirCantidadCartas();
    try {
      std::cin >> cantidadCartas;
      if (cantidadCartas < 6) {
        throw("La cantiadad mínima de cartas es 6.");
      }
      cantidad_valida = true;
    } catch (...) {
      this->interfaz->ingresoInvalido();
    }
  }
  return (unsigned int)cantidadCartas;
}

funcion_t Juego::getFuncionalidad(unsigned int indice) {

  switch (indice) {
  case ATAQUE_QUIMICO:
    return ATAQUE_QUIMICO;
  case AVION_RADAR:
    return AVION_RADAR;
  case BARCO_MISIL:
    return BARCO_MISIL;
  case REFUERZO:
    return REFUERZO;
  case BOMBARDEO:
    return BOMBARDEO;
  case ESPIONAJE:
    return ESPIONAJE;
  };

  throw "Numero de carta no valido";
}

unsigned int Juego::soldadosDeJugadorEnTablero(Jugador *jugador) {

  unsigned int contador = 0;
  for (int k = 0; k < tablero->getDimensiones()[2]; k++) {
    for (int j = 0; j < tablero->getDimensiones()[1]; j++) {
      for (int i = 0; i < tablero->getDimensiones()[0]; i++) {
        Ficha *fichaEnCasillero = tablero->getCasillero(i, j, k)->getFicha();
        if (fichaEnCasillero != NULL &&
            fichaEnCasillero->getIdentificadorDeJugador() ==
                jugador->getNombre() &&
            fichaEnCasillero->getTipoDeFicha() == SOLDADO) {
          contador++;
        }
      }
    }
  }
  return contador;
}
void Juego::mostrarResultadosPartida() {
  if (estaEmpatado) {
    this->interfaz->mostrarEmpate();
  }
  if (hayGanador) {
    this->interfaz->mostrarGanador(this->hayGanador->getNombre());
  }
  this->interfaz->sobrescribirArchivoBMP();
  this->interfaz->mostrarFinDelJuego();
}

void Juego::validarSiHayGanador(Lista<Jugador *> *jugadores) {
  Lista<Jugador *> *jugadoresAux = new Lista<Jugador *>;
  jugadoresAux->agregar(*jugadores);
  if (jugadores == NULL) {
    throw "La lista de jugadores está vacía";
  }

  int cantidadGanadores = 0;
  unsigned int cantidadPerdedores = 0;
  Jugador *ganador = NULL;

  jugadoresAux->iniciarCursor();
  while (jugadoresAux->avanzarCursor()) {
    Jugador *jugador = jugadoresAux->obtenerCursor();
    if (this->soldadosDeJugadorEnTablero(jugador) > 0) {
      cantidadGanadores++;
      ganador = jugador;
    } else if (this->soldadosDeJugadorEnTablero(jugador) == 0) {
      cantidadPerdedores++;
    }
  }

  if (cantidadGanadores == 1) {
    this->hayGanador = ganador;
    this->estadoActual = FINALIZADO;
  } else if (cantidadGanadores == 0 &&
             cantidadPerdedores == jugadoresAux->contarElementos()) {
    this->estaEmpatado = true;
    this->estadoActual = FINALIZADO;
  }
  delete jugadoresAux;
}

void Juego::matarFicha(Casillero *casillero) {

  if (casillero == NULL) {
    throw "El casillero está vacío";
  }
  TipoDeFicha tipo = casillero->getFicha()->getTipoDeFicha();

  this->interfaz->mostrarFichaEliminada(tipo);
  casillero->eliminarFicha();
}

void Juego::colocarArmamento(int x, int y, int z, Ficha *armamento) {
  Jugador *jugador = this->jugadorEnTurno;
  Casillero *casillero = this->tablero->getCasillero(x, y, z);
  Ficha *fichaEnCasillero = casillero->getFicha();

  try {
    if (fichaEnCasillero != NULL && casillero->obtenerTerreno() == TIERRA &&
        (fichaEnCasillero->getIdentificadorDeJugador() !=
             jugador->getNombre() ||
         casillero->estaVacio()) &&
        !casillero->estaBloqueado()) {

      if (fichaEnCasillero->getTipoDeFicha() == SOLDADO) {
        this->matarFicha(casillero);
        delete armamento;

      } else if (fichaEnCasillero->getTipoDeFicha() == MINA) {
        casillero->bloquear();
        this->matarFicha(casillero);

      } else if (fichaEnCasillero->getTipoDeFicha() == ARMAMENTO) {
        casillero->bloquear();
        this->matarFicha(casillero);
        delete armamento;
      }
    } else {
      armamento->setTipoDeFicha(ARMAMENTO);
      casillero->setFicha(armamento);
      this->interfaz->mostrarFichaColocada("R");
    }

  } catch (...) {
    this->interfaz->informarCasilleroNoDisponible();
  }
}

void Juego::colocarMina(int x, int y, int z) {
  Jugador *jugador = this->jugadorEnTurno;
  Casillero *casillero = this->tablero->getCasillero(x, y, z);
  Ficha *fichaEnCasillero = casillero->getFicha();
  Ficha *mina = new Ficha(MINA, jugador->getNombre());
  try {
    if (fichaEnCasillero != NULL && casillero->obtenerTerreno() == TIERRA &&
        (fichaEnCasillero->getIdentificadorDeJugador() !=
             jugador->getNombre() ||
         casillero->estaVacio()) &&
        !casillero->estaBloqueado()) {
      if (fichaEnCasillero->getTipoDeFicha() == MINA) {
        casillero->bloquear();
        this->matarFicha(casillero);
        casillero->setContadorDeTurnos(5);
        delete mina;
      } else {
        // fichaEnCasillero es un soldado o armemento
        casillero->bloquear();
        this->interfaz->mostrarMinaExplosion();
        this->matarFicha(casillero);
        casillero->setContadorDeTurnos(5);
        delete mina;
      }

    } else {
      casillero->setFicha(mina);
      this->interfaz->mostrarFichaColocada("M");
    }
  } catch (...) {
    this->interfaz->informarCasilleroNoDisponible();
  }
}

void Juego::lanzarMisil(int x, int y, int z) {
  Casillero *casillero = this->tablero->getCasillero(x, y, z);
  Ficha *fichaEnCasillero = casillero->getFicha();

  try {
    if (fichaEnCasillero != NULL &&
        (fichaEnCasillero->getTipoDeFicha() == SOLDADO ||
         fichaEnCasillero->getTipoDeFicha() == ARMAMENTO)) {
      this->matarFicha(casillero);
      casillero->setContadorDeTurnos(3);
      this->interfaz->mostrarFichaColocada("C");
    }
  } catch (...) {
    this->interfaz->informarCasilleroNoDisponible();
  }
}

void Juego::colocarSoldado(int x, int y, int z, Ficha *soldado) {
  Jugador *jugador = this->jugadorEnTurno;
  Casillero *casillero = this->tablero->getCasillero(x, y, z);
  Ficha *fichaEnCasillero = casillero->getFicha();

  try {
    if (fichaEnCasillero != NULL &&
        (fichaEnCasillero->getIdentificadorDeJugador() !=
         jugador->getNombre()) &&
        !casillero->estaBloqueado()) {

      if (fichaEnCasillero->getTipoDeFicha() == SOLDADO) {
        this->matarFicha(casillero);
        delete soldado;
      } else if (fichaEnCasillero->getTipoDeFicha() == MINA) {
        casillero->bloquear();
        this->matarFicha(casillero);
      } else if (fichaEnCasillero->getTipoDeFicha() == ARMAMENTO) {
        casillero->bloquear();
        this->matarFicha(casillero);
        delete soldado;
      }
    } else {
      soldado->setTipoDeFicha(SOLDADO);
      casillero->setFicha(soldado);
      this->interfaz->mostrarFichaColocada("S");
    }
  }

  catch (...) {
    this->interfaz->informarCasilleroNoDisponible();
  }
}

void Juego::moverSoldado() {
  int x1, y1, z1, x2, y2, z2;
  bool seleccionOrigen = false;
  bool seleccionDestino = false;
  Casillero *casilleroOrigen = NULL;

  while (!seleccionOrigen) {
    this->interfaz->mostrarMensajesCoordenadas("IS");
    this->interfaz->pedirCoordenadas(x1, y1, z1, this->tablero);
    Jugador *jugador = this->jugadorEnTurno;
    casilleroOrigen = this->tablero->getCasillero(x1, y1, z1);

    if (casilleroOrigen->getFicha() != NULL &&
        casilleroOrigen->getFicha()->getTipoDeFicha() == SOLDADO &&
        casilleroOrigen->getFicha()->getIdentificadorDeJugador() ==
            jugador->getNombre()) {
      seleccionOrigen = true;
    } else {
      this->interfaz->mostrarMensajesCoordenadas("NS");
    }
  }

  while (!seleccionDestino) {
    this->interfaz->mostrarMensajesCoordenadas("DS");
    this->interfaz->pedirCoordenadas(x2, y2, z2, this->tablero);

    Casillero *casilleroDestino = this->tablero->getCasillero(x2, y2, z2);
    if (casilleroDestino->esAdyacenteLineal(casilleroOrigen)) {
      this->colocarSoldado(x2, y2, z2, casilleroOrigen->getFicha());
      casilleroOrigen->setFicha(NULL);
      this->interfaz->mostrarAccionesRealizadas("S");
      seleccionDestino = true;
    } else {
      this->interfaz->mostrarMensajesCoordenadas("LS");
    }
  }
}

void Juego::moverArmamento() {
  int x1, y1, z1, x2, y2, z2;
  bool seleccionOrigen = false;
  bool seleccionDestino = false;
  Casillero *casilleroOrigen = NULL;

  while (!seleccionOrigen) {
    this->interfaz->mostrarMensajesCoordenadas("IA");
    this->interfaz->pedirCoordenadas(x1, y1, z1, this->tablero);
    Jugador *jugador = this->jugadorEnTurno;
    casilleroOrigen = this->tablero->getCasillero(x1, y1, z1);

    if (casilleroOrigen->getFicha() != NULL &&
        casilleroOrigen->getFicha()->getTipoDeFicha() == ARMAMENTO &&
        casilleroOrigen->getFicha()->getIdentificadorDeJugador() ==
            jugador->getNombre()) {
      seleccionOrigen = true;
    } else {
      this->interfaz->mostrarMensajesCoordenadas("NA");
    }
  }

  while (!seleccionDestino) {
    this->interfaz->mostrarMensajesCoordenadas("DA");
    this->interfaz->pedirCoordenadas(x2, y2, z2, this->tablero);

    Casillero *casilleroDestino = this->tablero->getCasillero(x2, y2, z2);
    if (casilleroDestino->esAdyacenteLineal(casilleroOrigen)) {
      this->colocarArmamento(x2, y2, z2, casilleroOrigen->getFicha());
      casilleroOrigen->setFicha(NULL);
      this->interfaz->mostrarAccionesRealizadas("A");
      seleccionDestino = true;
    } else {
      this->interfaz->mostrarMensajesCoordenadas("LA");
    }
  }
}

void Juego::sacarCartaDeMazo(Jugador *jugador) {

  try {
    if (!mazo->estaVacia()) {
      Carta *carta = mazo->desapilar();
      jugador->getCartas()->altaFinal(carta);
    }
  } catch (...) {
    this->interfaz->mazoSinCartas();
  }
  this->interfaz->mostrarAccionesRealizadas("C");
}

void Juego::ataqueQuimico() {
  try {
    int x = 0, y = 0, z = 0;
    this->interfaz->pedirCoordenadas(x, y, z, this->tablero);
    // itera el tablero
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        for (int k = 0; k < 5; k++) {
          // Envenana los adyacentes
          Casillero *casilleroAux =
              this->tablero->getCasillero(x - i, y - j, z - k);
          casilleroAux->envenenar();
          // El origen de coordenadas

          if (i == 0 && j == 0 && k == 0) {
            casilleroAux->setContadorDeTurnos(10);
          } else if (i == 1 || j == 1 || k == 1) {
            casilleroAux->setContadorDeTurnos(8);
          } else if ((i == 2 || j == 2 || k == 2)) {
            casilleroAux->setContadorDeTurnos(6);
          } else if ((i == 3 || j == 3 || k == 3)) {
            casilleroAux->setContadorDeTurnos(4);
          } else if ((i == 4 || j == 4 || k == 4)) {
            casilleroAux->setContadorDeTurnos(2);
          }
        }
      }
    }
    this->interfaz->mostrarAccionesRealizadas("Q");
  } catch (...) {
    this->interfaz->ingresoInvalido();
  }
}

void Juego::colocarAvion() {
  try {
    int x = 0, y = 0, z = 0;
    this->interfaz->mostrarInstruccion("A");
    bool coordenadaValida = false;
    while (!coordenadaValida) {
      this->interfaz->pedirCoordenadas(x, y, z, this->tablero);
      Casillero *casillero = this->tablero->getCasillero(x, y, z);
      Ficha *fichaEnCasillero = casillero->getFicha();
      if (fichaEnCasillero == NULL && casillero->obtenerTerreno() == AIRE &&
          !casillero->estaBloqueado()) {
        Jugador *jugador = this->jugadorEnTurno;
        Ficha *avion = new Ficha(AVION, jugador->getNombre());
        casillero->setFicha(avion);
        this->interfaz->mostrarFichaColocada("A");
        coordenadaValida = true;
      } else {
        this->interfaz->mostrarMsjErrorCoordenadas("CV");
      }
    }
  } catch (...) {
    this->interfaz->mostrarMsjErrorCoordenadas("-A");
  }
}

void Juego::colocarBarco() {
  try {
    int x = 0, y = 0, z = 0;
    this->interfaz->mostrarInstruccion("B");
    bool coordenadaValida = false;
    while (!coordenadaValida) {
      this->interfaz->pedirCoordenadas(x, y, z, this->tablero);
      Casillero *casillero = this->tablero->getCasillero(x, y, z);
      Ficha *fichaEnCasillero = casillero->getFicha();
      if (fichaEnCasillero == NULL && casillero->obtenerTerreno() == AGUA &&
          !casillero->estaBloqueado()) {
        Jugador *jugador = this->jugadorEnTurno;
        Ficha *barco = new Ficha(BARCO, jugador->getNombre());
        casillero->setFicha(barco);
        this->interfaz->mostrarFichaColocada("B");
        coordenadaValida = true;
      } else {
        this->interfaz->mostrarMsjErrorCoordenadas("CO");
      }
    }
  } catch (...) {
    this->interfaz->mostrarMsjErrorCoordenadas("-B");
  }
}

void Juego::agregarTresMinas() {
  this->interfaz->mostrarInstruccion("T");
  for (int i = 0; i < 3; i++) {
    try {
      int x = 0, y = 0, z = 0;
      this->interfaz->pedirCoordenadas(x, y, z, this->tablero);
      this->colocarMina(x, y, z);
    } catch (...) {
      this->interfaz->ingresoInvalido();
    }
  }
  this->interfaz->mostrarFichaColocada("T");
}

void Juego::identificarFichaEnCasillero() {
  this->interfaz->mostrarInstruccion("W");
  int x = 0, y = 0, z = 0;

  this->interfaz->pedirCoordenadas(x, y, z, this->tablero);
  if (this->tablero->getCasillero(x, y, z)->getFicha() != NULL) {
    this->interfaz->mostrarFichaEnCasillero(
        this->tablero->getCasillero(x, y, z));
  }
  this->interfaz->mostrarAccionesRealizadas("M");
}

void Juego::agregarSoldado() {
  this->interfaz->mostrarInstruccion("L");
  this->interfaz->mostrarInstruccion("S");
  try {
    int x = 0, y = 0, z = 0;

    this->interfaz->pedirCoordenadas(x, y, z, this->tablero);
    this->colocarSoldado(x, y, z,
                         new Ficha(SOLDADO, jugadorEnTurno->getNombre()));

  } catch (...) {
    this->interfaz->ingresoInvalido();
  }
  this->interfaz->mostrarFichaColocada("L");
}

void Juego::ejecutarCarta(unsigned int indice) {
  switch (indice) {
  case ATAQUE_QUIMICO:
    this->ataqueQuimico();
    break;
  case AVION_RADAR:
    this->colocarAvion();
    break;
  case BARCO_MISIL:
    this->colocarBarco();
    break;
  case REFUERZO:
    this->agregarSoldado();
    break;
  case BOMBARDEO:
    this->agregarTresMinas();
    break;
  case ESPIONAJE:
    this->identificarFichaEnCasillero();
    break;
  default:
    throw "Numero de carta no valido";
    break;
  }
}

void Juego::usarCartaDeJugador(unsigned int posicionDeCarta) {
  Carta *carta = this->jugadorEnTurno->getCartas()->obtener(posicionDeCarta);
  if (carta != NULL) {
    this->ejecutarCarta(carta->getFuncion());
    // Eliminar carta de jugador
    this->jugadorEnTurno->getCartas()->remover(posicionDeCarta);
  } else {
    this->interfaz->jugadorSinCartas();
  }
  this->interfaz->mostrarAccionesRealizadas("T");
}

void Juego::inicializarFichas() {
  this->interfaz->mostrarIniciarFichas();
  unsigned int contador = 0;
  while (contador < this->jugadores->contarElementos()) {
    Jugador *jugador = this->jugadorEnTurno;
    this->interfaz->mostrarJugadorEnTurno(jugador->getNombre());
    int n = this->cantidadDeFichas;
    int cantidadSoldados = n * 0.75;   //
    int cantidadArmamentos = n * 0.25; // 25% de las fichas
    for (int i = 0; i < cantidadSoldados; i++) {
      int x = 0, y = 0, z = 0;
      Ficha *soldado = jugador->getFicha();
      this->interfaz->mostrarInstruccion("S");
      this->interfaz->pedirCoordenadas(x, y, z, this->tablero);
      while (this->tablero->getCasillero(x, y, z)->obtenerTerreno() == AGUA ||
             this->tablero->getCasillero(x, y, z)->obtenerTerreno() == AIRE) {
        this->interfaz->pedirCoordenadas(x, y, z, this->tablero);
      }
      this->colocarSoldado(x, y, z, soldado);
    }
    for (int in = 0; in < cantidadArmamentos; in++) {
      int x2 = 0, y2 = 0, z2 = 0;
      Ficha *armamento = jugador->getFicha();
      this->interfaz->mostrarInstruccion("R");
      this->interfaz->pedirCoordenadas(x2, y2, z2, this->tablero);
      this->colocarArmamento(x2, y2, z2, armamento);
    }
    contador++;
    this->cambiarDeJugadorActual();
    this->interfaz->limpiarPantalla();
  }
  this->interfaz->mostrarFichasInicializadas();
  this->interfaz->mostrarColoresFichas();
  this->interfaz->limpiarPantalla();
}

void Juego::bajarContadorCasilleros() {
  int *dim = this->tablero->getDimensiones();
  for (int k = 0; k < dim[2]; k++) {
    for (int j = 0; j < dim[1]; j++) {
      for (int i = 0; i < dim[0]; i++) {
        if (this->tablero->getCasillero(i, j, k)->getContadorDeturnos() > 0) {
          this->tablero->getCasillero(i, j, k)->bajarTurno();
        }
      }
    }
  }
}

bool Juego::hayBarco(Jugador *jugador) {
  int *dim = this->tablero->getDimensiones();
  for (int k = 0; k < dim[2]; k++) {
    for (int j = 0; j < dim[1]; j++) {
      for (int i = 0; i < dim[0]; i++) {

        Ficha *fichaAux = this->tablero->getCasillero(i, j, k)->getFicha();
        if ((fichaAux != NULL) && (fichaAux->getTipoDeFicha() == BARCO) &&
            (fichaAux->getIdentificadorDeJugador() == jugador->getNombre())) {
          return true;
        }
      }
    }
  }
  return false;
}

/* Chequear */
void Juego::ejecutarRadar(Jugador *jugador) {
  int *dim = this->tablero->getDimensiones();
  for (int k = 0; k < dim[2]; k++) {
    for (int j = 0; j < dim[1]; j++) {
      for (int i = 0; i < dim[0]; i++) {

        Ficha *fichaAux = this->tablero->getCasillero(i, j, k)->getFicha();
        if ((fichaAux != NULL) && (fichaAux->getTipoDeFicha() == AVION) &&
            (fichaAux->getIdentificadorDeJugador() == jugador->getNombre())) {
          for (int z = k - 3; z < dim[2] - k; z++) {
            for (int y = 0; y < 3; y++) {
              for (int x = 0; x < 3; x++) {
                Casillero *casillero =
                    this->tablero->getCasillero(i - x, j - y, z);
                if (casillero->getFicha() != NULL &&
                    casillero->getFicha()->getIdentificadorDeJugador() ==
                        jugador->getNombre()) {

                  this->interfaz->mostrarMina(i, j, k);
                }
              }
            }
          }
        }
      }
    }
  }
}

void Juego::jugarBatallaDigital() {
  this->interfaz->limpiarPantalla();
  this->inicializarFichas();
  this->interfaz->mostrarBatallaIniciada();
  while (this->estadoActual != FINALIZADO) {
    this->interfaz->sobrescribirArchivoBMP();
    int x0 = 0, y0 = 0, z0 = 0, x1 = 0, y1 = 0, z1 = 0;
    this->sacarCartaDeMazo(this->jugadorEnTurno);
    // Obtiene el nro de la carta y la ejecuta
    this->interfaz->mostrarCartasJugador(this->jugadorEnTurno);
    this->interfaz->pedirUsarCarta();
    char opcionCarta;
    std::cin >> opcionCarta;
    if (opcionCarta == 'S' || opcionCarta == 's') {
      unsigned int nroCarta =
          this->interfaz->pedirNroCarta(this->jugadorEnTurno);
      this->usarCartaDeJugador(nroCarta);
    }

    this->interfaz->mostrarInstruccion("X");
    this->interfaz->pedirCoordenadas(x1, y1, z1, this->tablero);
    this->colocarMina(x1, y1, z1);

    this->interfaz->indicarMoverSolado();
    char opcionSoldado;
    std::cin >> opcionSoldado;
    if (opcionSoldado == 'S' || opcionSoldado == 's') {
      this->moverSoldado();
    }

    this->interfaz->indicarMoverArmamento();
    char opcionArmamento;
    std::cin >> opcionArmamento;
    if (opcionArmamento == 'S' || opcionArmamento == 's') {
      this->moverArmamento();
    }
    if (this->hayBarco(this->jugadorEnTurno)) {
      this->interfaz->mostrarInstruccion("M");
      this->interfaz->pedirCoordenadas(x0, y0, z0, this->tablero);
      this->lanzarMisil(x0, y0, z0);
    }
    this->ejecutarRadar(this->jugadorEnTurno);

    this->interfaz->mostrarTableroDeJugadorBitMap(this->tablero,
                                                  this->jugadorEnTurno);

    this->interfaz->limpiarPantalla();
    this->cambiarDeJugadorActual();
    this->validarSiHayGanador(this->jugadores);
    this->turno++;
  }
  this->mostrarResultadosPartida();
}
