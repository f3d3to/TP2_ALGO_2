#include "Juego.h"
#include "Constantes.h"
#include "Ficha.h"
#include "Jugador.h"
#include "Pila.h"
#include "Tablero.h"

Juego::Juego() {
  this->interfaz->mostrarPantallaInicial();
  this->cantidadTurnosJuego = 0;
  this->interfaz = new Interfaz();
  this->hayGanador = NULL;
  this->jugadorEnTurno = NULL;
  this->turno = 0;
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
  std::cout << "\033[1m\033[4mJuego configurado.\033[0m" << std::endl;
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

bool Juego::determinarGanador() {
  bool hayGanador;
  if (this->hayGanador != NULL) {
    hayGanador = true;
    this->interfaz->mostrarGanador(this->hayGanador->getNombre());
  } else {
    hayGanador = false;
  }
  return hayGanador;
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
    std::cout << "No hay jugadores disponibles." << std::endl;
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
      std::cout << "Ancho:  \t";
      std::cin >> ancho;

      std::cout << "Alto:   \t";
      std::cin >> alto;

      std::cout << "Profundo:  \t";
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
        Casillero *casillero = tablero->getCasillero(i, j, k);
        if (!casillero->estaVacio() &&
            casillero->getFicha()->getIdentificadorDeJugador() ==
                jugador->getNombre()) {
          contador++;
        }
      }
    }
  }
  return contador;
}

/*
 * Pre: el jugador elige una accion
 * Post: ejecuta la accion y actualiza el tablero
 */

/*
 *Pre tiene que asignar un soldado
 */
Jugador *Juego::validarSiHayGanador(Lista<Jugador *> *jugadores) {
  if (jugadores == NULL) {
    throw "La lista de jugadores esta vacia";
  }
  bool hayGanador = false;
  int cantidadGanadores = 0;
  Jugador *ganador = NULL;

  jugadores->iniciarCursor();
  while (jugadores->avanzarCursor()) {

    if (this->soldadosDeJugadorEnTablero(jugadores->obtenerCursor()) != 0) {
      cantidadGanadores++;
      ganador = jugadores->obtenerCursor();
    }
  }
  if (hayGanador && cantidadGanadores == 1) {
    return ganador;
  }
  return NULL;
}

/*
 * Pre: Recibe una coordenada
 * Post:
 */
void Juego::matarFicha(Casillero *casillero) {

  if (casillero == NULL) {
    throw "El casillero está vacío";
  }
  casillero->eliminarFicha();
}

void Juego::colocarArmamento(int x, int y, int z, Ficha *armamento) {
  Jugador *jugador = this->jugadorEnTurno;
  Casillero *casillero = this->tablero->getCasillero(x, y, z);
  Ficha *fichaEnCasillero = casillero->getFicha();

  try {
    if (fichaEnCasillero != NULL && casillero->obtenerTerreno() == TIERRA &&
        (fichaEnCasillero->getIdentificadorDeJugador() !=
             jugadorEnTurno->getNombre() ||
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

      } else {
        casillero->setFicha(armamento);
      }
    }
    std::cout << "Armamento colocado." << std::endl;

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
             jugadorEnTurno->getNombre() ||
         casillero->estaVacio()) &&
        !casillero->estaBloqueado()) {
      if (fichaEnCasillero->getTipoDeFicha() == MINA) {
        casillero->bloquear();
        this->matarFicha(casillero);
      } else {
        // fichaEnCasillero es un soldado o armemento
        casillero->bloquear();
        this->matarFicha(casillero);
        delete mina;
      }
    }
    std::cout << "Mina colocada." << std::endl;
  } catch (...) {
    this->interfaz->informarCasilleroNoDisponible();
  }
}
/*Pre: HAY QUE DESAPILAR LA PILA DE FICHAS Y CREAR EL SOLDADO ANTES DE LLAMAR
 * A ESTA FUNCION Post:verifica y coloca el soldado.
 */
void Juego::colocarSoldado(int x, int y, int z, Ficha *soldado) {
  Jugador *jugador = this->jugadorEnTurno;
  Casillero *casillero = this->tablero->getCasillero(x, y, z);
  Ficha *fichaEnCasillero = casillero->getFicha();

  try {
    // if (fichaEnCasillero != NULL &&
    //     (fichaEnCasillero->getIdentificadorDeJugador() !=
    //      jugadorEnTurno->getNombre()) &&
    //     !casillero->estaBloqueado()) {

    //   if (fichaEnCasillero->getTipoDeFicha() == SOLDADO) {
    //     this->matarFicha(casillero);
    //     delete soldado;

    //   } else if (fichaEnCasillero->getTipoDeFicha() == MINA) {
    //     casillero->bloquear();
    //     this->matarFicha(casillero);

    //   } else if (fichaEnCasillero->getTipoDeFicha() == ARMAMENTO) {
    //     casillero->bloquear();
    //     this->matarFicha(casillero);
    //     delete soldado;
    //   }
    // } else {
    casillero->setFicha(soldado);
    std::cout << "Soldado colocado." << std::endl;
    // }
  }

  catch (...) {
    this->interfaz->informarCasilleroNoDisponible();
  }
}

/* Pre: recibe una coordenada de origen y de destino.
  Post: mueve el soldado a un casillero adyacente
 */
void Juego::moverSoldado(int x1, int y1, int z1, int x2, int y2, int z2) {

  Jugador *jugador = this->jugadorEnTurno;
  Casillero *casilleroOrigen = this->tablero->getCasillero(x1, y1, z1);
  Casillero *casilleroDestino = this->tablero->getCasillero(x2, y2, z2);

  try {
    if (casilleroOrigen->getFicha()->getTipoDeFicha() == SOLDADO &&
        casilleroOrigen->getFicha()->getIdentificadorDeJugador() ==
            jugador->getNombre()) {
      if (casilleroDestino->esAdyacenteLineal(casilleroOrigen)) {
        this->colocarSoldado(x2, y2, z2, casilleroOrigen->getFicha());
        casilleroOrigen->setFicha(NULL);
      }
    }
    std::cout << "Soldado movido." << std::endl;

  } catch (...) {
    this->interfaz->ingresoInvalido();
  }
}

void Juego::moverArmamento(int x1, int y1, int z1, int x2, int y2, int z2) {

  Jugador *jugador = this->jugadorEnTurno;
  Casillero *casilleroOrigen = this->tablero->getCasillero(x1, y1, z1);
  Casillero *casilleroDestino = this->tablero->getCasillero(x2, y2, z2);

  try {
    if (casilleroOrigen->getFicha()->getTipoDeFicha() == ARMAMENTO &&
        casilleroOrigen->getFicha()->getIdentificadorDeJugador() ==
            jugador->getNombre()) {
      if (casilleroDestino->esAdyacenteLineal(casilleroOrigen)) {
        this->colocarArmamento(x2, y2, z2, casilleroOrigen->getFicha());
        casilleroOrigen->setFicha(NULL);
      }
    }
    std::cout << "Armaemento movido." << std::endl;

  } catch (...) {
    this->interfaz->ingresoInvalido();
  }
}

/* Pre:
  Post: Agrega una carta al mazo del jugador (lista)
 */

void Juego::sacarCartaDeMazo(Jugador *jugador) {

  try {
    if (!mazo->estaVacia()) {
      Carta *carta = mazo->desapilar();
      jugador->getCartas()->altaFinal(carta);
    }
  } catch (...) {
    this->interfaz->mazoSinCartas();
  }
  // } else {
  //   this->interfaz->mazoSinCartas();
  // }
  std::cout << "Ha sacado una carta del mazo." << std::endl;
}
void Juego::ataqueQuimico() {
  try {
    int x = 0, y = 0, z = 0;
    this->interfaz->pedirCoordenadas(x, y, z);
    Casillero *casilleroAux = this->tablero->getCasillero(x, y, z);
    // itera el tablero
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        for (int k = 0; k < 5; k++) {
          // Envenana los adyacentes
          casilleroAux->getAdyacente(i, j, k)->envenenar();
          // El origen de coordenadas
          if (i == 0 && j == 0 && k == 0) {
            casilleroAux->setContadorDeTurnos(10);
          } else if (i == 1 || j == 1 || k == 1) {
            casilleroAux->getAdyacente(i, j, k)->setContadorDeTurnos(8);
          } else if ((i == 2 || j == 2 || k == 2)) {
            casilleroAux->getAdyacente(i, j, k)->setContadorDeTurnos(6);
          } else if ((i == 3 || j == 3 || k == 3)) {
            casilleroAux->getAdyacente(i, j, k)->setContadorDeTurnos(4);
          } else if ((i == 4 || j == 4 || k == 4)) {
            casilleroAux->getAdyacente(i, j, k)->setContadorDeTurnos(2);
          }
        }
      }
    }
    std::cout << "Ha realizado un ataque químico." << std::endl;

  } catch (...) {
    this->interfaz->ingresoInvalido();
  }
}
void Juego::colocarAvion() {
  try {
    int x, y, z;
    this->interfaz->pedirCoordenadas(x, y, z);
    Casillero *casillero = this->tablero->getCasillero(x, y, z);
    Ficha *avion = casillero->getFicha();
    if (casillero->obtenerTerreno() == AIRE && casillero->estaVacio() &&
        !casillero->estaBloqueado()) {
      Ficha *avion = new Ficha(AVION, jugadorEnTurno->getNombre());
      casillero->setFicha(avion);
    }
    std::cout << "Ha colocado un avión." << std::endl;

  } catch (...) {
    this->interfaz->ingresoInvalido();
  }
}

void Juego::colocarBarco() {
  try {
    int x, y, z;
    // TODO: MOSTRAR MENSAJE DE DONDE DESEA COLOCAR BARCO.
    this->interfaz->pedirCoordenadas(x, y, z);
    Casillero *casillero = this->tablero->getCasillero(x, y, z);
    if (casillero->obtenerTerreno() == AGUA && casillero->estaVacio() &&
        !casillero->estaBloqueado()) {
      Ficha *barco = new Ficha(BARCO, jugadorEnTurno->getNombre());
      casillero->setFicha(barco);
      std::cout << "Se ha colocado un barco" << std::endl;
    }
  } catch (...) {
    this->interfaz->ingresoInvalido();
  }
}
void Juego::agregarTresMinas() {
  for (int i = 0; i < 3; i++) {
    try {
      int x = 0, y = 0, z = 0;
      this->interfaz->pedirCoordenadas(x, y, z);
      this->colocarMina(x, y, z);
    } catch (...) {
      this->interfaz->ingresoInvalido();
    }
  }
  std::cout << "Ha colocado las tres minas." << std::endl;
}

void Juego::identificarFichaEnCasillero() {

  try {
    int x = 0, y = 0, z = 0;

    this->interfaz->pedirCoordenadas(x, y, z);
    this->interfaz->mostrarFichaEnCasillero(tablero->getCasillero(x, y, z));

  } catch (...) {
    this->interfaz->ingresoInvalido();
  }
  std::cout << "La Ficha se ha descubierto." << std::endl;
}

void Juego::agregarSoldado() {
  try {
    int x = 0, y = 0, z = 0;

    this->interfaz->pedirCoordenadas(x, y, z);
    this->colocarSoldado(x, y, z,
                         new Ficha(SOLDADO, jugadorEnTurno->getNombre()));

  } catch (...) {
    this->interfaz->ingresoInvalido();
  }
  std::cout << "Ha llamado un refuerzo." << std::endl;
}

void Juego::ejecutarCarta(unsigned int indice) {
  switch (indice) {
  case ATAQUE_QUIMICO:
    this->ataqueQuimico();
  case AVION_RADAR:
    this->colocarAvion();
  case BARCO_MISIL:
    this->colocarBarco();
  case REFUERZO:
    this->agregarSoldado();
  case BOMBARDEO:
    this->agregarTresMinas();
  case ESPIONAJE:
    this->identificarFichaEnCasillero();
  default:
    throw "Numero de carta no valido";
  }
}

void Juego::usarCartaDeJugador(unsigned int posicionDeCarta) {
  // try {
  // Obtiene carta de jugador
  Carta *carta = this->jugadorEnTurno->getCartas()->obtener(posicionDeCarta);
  if (carta != NULL) {
    this->ejecutarCarta(carta->getFuncion());
    // Eliminar carta de jugador
    this->jugadorEnTurno->getCartas()->remover(posicionDeCarta);
  } else {
    this->interfaz->jugadorSinCartas();
  }
  std::cout << "Carta tirada." << std::endl;
}

void Juego::inicializarFichas() {
  // llevar a interfaz el mensaje
  std::cout << "\033[1;32mInicializando fichas...\033[0m" << std::endl;
  unsigned int contador = 0;
  // revisar logica por qué jugador 2 de 2 no puede iniciarlizar fichas.
  while (contador < this->jugadores->contarElementos()) {
    Jugador *jugador = this->jugadorEnTurno;
    this->interfaz->mostrarJugadorEnTurno(jugador->getNombre());
    int n = this->cantidadDeFichas;
    int cantidadSoldados = n * 0.75;   // 75% de las fichas
    int cantidadArmamentos = n * 0.25; // 25% de las fichas
    for (int i = 0; i < cantidadSoldados; i++) {
      int x = 0, y = 0, z = 0;
      Ficha *soldado = jugador->getFicha();
      std::cout << "Coloque un \033[1;33msoldado\033[0m";
      this->interfaz->pedirCoordenadas(x, y, z);
      while (this->tablero->getCasillero(x, y, z)->obtenerTerreno() == AGUA ||
             this->tablero->getCasillero(x, y, z)->obtenerTerreno() == AIRE) {
        this->interfaz->pedirCoordenadas(x, y, z);
      }
      this->colocarSoldado(x, y, z, soldado);
    }
    for (int in = 0; in < cantidadArmamentos; in++) {
      int x2 = 0, y2 = 0, z2 = 0;
      Ficha *armamento = jugador->getFicha();
      std::cout << "Coloque un \033[1;32marmamento\033[0m";
      this->interfaz->pedirCoordenadas(x2, y2, z2);
      this->colocarArmamento(x2, y2, z2, armamento);
    }
    contador++;
    this->cambiarDeJugadorActual();
    this->interfaz->limpiarPantalla();
  }
  std::cout << "\033[1;31mFichas inicializadas.\033[0m\n" << std::endl;
  this->interfaz->limpiarPantalla();
}

void Juego::bajarContadorCasilleros() {
  int *dim = this->tablero->getDimensiones();
  for (int k = 0; k < dim[2]; k++) {
    for (int j = 0; j < dim[1]; j++) {
      for (int i = 0; i < dim[1]; i++) {
        if (this->tablero->getCasillero(i, j, k)->getContadorDeturnos() > 0) {
          this->tablero->getCasillero(i, j, k)->bajarTurno();
        }
      }
    }
  }
}