#include "Juego.h"
#include "Carta.h"
#include "Constantes.h"

Juego::Juego() {

  this->interfaz = new Interfaz();
  this->ganador = NULL;

  unsigned int cantidadJugadores = pedirCantidadJugadores();
  unsigned int cantidadFichas = pedirCantidadFichas();
  unsigned int cantidadCartas = pedirCantidadCartas();

  this->jugadores = new Lista<Jugador *>;
  // mostrar Siguiente jugador
  for (unsigned int i = 0; cantidadJugadores; i++) {
    std::string nombre = pedirNombre(i + 1);

    // Inicializa cada ficha (TDA Pila).
    Pila<Ficha> *fichas = new Pila<Ficha>;
    for (int j = 0; j < cantidadFichas; j++) {
      fichas->apilar(new Ficha(nombre));
    };

    Jugador *nuevoJugador = new Jugador(nombre);
    this->jugadores->altaFinal(nuevoJugador);
  }

  this->jugadorEnTurno = this->jugadores->obtener(1);

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
}

Juego::~Juego() {
  delete this->interfaz;
  delete this->ganador;

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
  if (this->ganador != NULL) {
    hayGanador = true;
    this->interfaz->mostrarGanador(this->ganador->getNombre());
  } else {
    hayGanador = false;
  }
  return hayGanador;
};

void Juego::cambiarDeJugadorActual() {
  this->jugadores->avanzarCursor();
  this->jugadorEnTurno = this->jugadores->obtenerCursor();
  this->interfaz->limpiarPantalla(); // Chequear
  this->interfaz->mostrarJugadorEnTurno(this->jugadorEnTurno->getNombre());
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
  for (unsigned int k = 0; k < tablero->getDimensiones()[2]; k++) {
    for (unsigned int j = 0; j < tablero->getDimensiones()[1]; j++) {
      for (unsigned int i = 0; i < tablero->getDimensiones()[0]; i++) {
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
};

void Juego::colocarFicha(int x, int y, int z, TipoDeFicha tipo) {

  Jugador *jugador = this->jugadorEnTurno;
  Casillero *casillero = this->tablero->getCasillero(x, y, z);
  Ficha *fichaEnCasillero = casillero->getFicha();
  Ficha *fichaAColocar = jugadorEnTurno->getFicha();

  if (casillero->obtenerTerreno()) {
    // mensaje
  }

  if (fichaEnCasillero->getIdentificadorDeJugador() ==
      jugadorEnTurno->getNombre()) {
    // es ficha del jugador
  }

  if (!casillero->estaBloqueado()) {
    if (fichaEnCasillero->getTipoDeFicha() == SOLDADO &&
        fichaAColocar->getTipoDeFicha() == SOLDADO) {
      this->matarFicha(casillero);
      delete fichaAColocar;

    } else if (fichaEnCasillero->getTipoDeFicha() == MINA) {
      casillero->bloquear();
      this->matarFicha(casillero);
      delete fichaAColocar;
    }
  } else if (fichaEnCasillero->getTipoDeFicha() == ARMAMENTO) {
    casillero->bloquear();
    this->matarFicha(casillero);
    delete fichaAColocar;
  }

  else if (fichaEnCasillero->getTipoDeFicha() == ARMAMENTO &&
           fichaAColocar->getTipoDeFicha() == SOLDADO) {
    this->matarFicha(casillero);
    delete fichaAColocar;
  }
}

void Juego::colocarMina(int x, int y, int z) {
  Jugador *jugador = this->jugadorEnTurno;
  Casillero *casillero = this->tablero->getCasillero(x, y, z);
  Ficha *fichaEnCasillero = casillero->getFicha();
  Ficha *mina = new Ficha(MINA, jugador->getNombre());
  try {
    if (casillero->obtenerTerreno() == TIERRA &&
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
  } catch (...) {
    this->interfaz->informarCasilleroNoDisponible();
  }
}
/*Pre: HAY QUE DESAPILAR LA PILA DE FICHAS Y CREAR EL SOLDADO ANTES DE LLAMAR A ESTA FUNCION
* Post:verifica y coloca el soldado.
*/
void Juego::colocarSoldado(int x, int y, int z , Ficha *soldado) {
  Jugador *jugador = this->jugadorEnTurno;
  Casillero *casillero = this->tablero->getCasillero(x, y, z);
  Ficha *fichaEnCasillero = casillero->getFicha();

  try {
    if (casillero->obtenerTerreno() == TIERRA &&
        (fichaEnCasillero->getIdentificadorDeJugador() !=
             jugadorEnTurno->getNombre() ||
         casillero->estaVacio()) &&
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

      } else {
        casillero->setFicha(soldado);
      }
    }
  } catch (...) {
    this->interfaz->informarCasilleroNoDisponible();
  }
};

/* Pre: recibe una coordenada de origen y de destino.
  Post: mueve el soldado a un casillero adyacente
 */
void Juego::moverSoldado(int x1, int y1, int z1, int x2, int y2, int z2) {

  Jugador *jugador = this->jugadorEnTurno;
  Casillero *casilleroOrigen = this->tablero->getCasillero(x1, y1, z1);
  Casillero *casilleroDestino = this->tablero->getCasillero(x2, y2, z2);

  try {
    if (casilleroOrigen->getFicha()->getTipoDeFicha() == SOLDADO &&
        casilleroOrigen->getFicha()->getIdentificadorDeJugador() == jugador->getNombre()) {
          if(casilleroDestino->esAdyacenteLineal(casilleroOrigen)){
            this->colocarSoldado(x2, y2, z2, casilleroOrigen->getFicha());
            casilleroOrigen->setFicha(NULL);
          }
    }
  } catch (...) {
    this->interfaz->ingresoInvalido(); 
  }

};

/* Pre: 
  Post: Agrega una carta al mazo del jugador (lista)
 */

void Juego::sacarCartaDeMazo(Jugador *jugador){
  
  try {
    if (!mazo->estaVacia()) {
      Carta *carta = mazo->desapilar();
      jugador->getCartas()->altaFinal(carta);
    }
  } catch (...) {
    this->interfaz->mazoSinCartas();
  }
  
};
void Juego::ejecutarCarta(unsigned int indice) {

  switch (indice) {
  case ATAQUE_QUIMICO:
      //this->ataqueQuimico();
  case AVION_RADAR:
      // this->


  case BARCO_MISIL:

  case REFUERZO:

  case BOMBARDEO:
    
  case ESPIONAJE:

  };
  
  throw "Numero de carta no valido";
}

void Juego::usarCartaDeJugador(funcion_t funcion, Jugador *jugador){
  this->interfaz->mostrarCartasJugador(jugador);
  this->interfaz->preguntarNroCarta();
  unsigned int numero = this->interfaz->pedirNroCarta();

  try {
    if(!jugador->getCartas()->estaVacia()){
    jugador->getCartas()->iniciarCursor();
    while(jugador->getCartas()->avanzarCursor()){
      if(jugador->getCartas()->obtenerCursor()->getFuncion()==funcion){
        Carta *cartaAux=jugador->getCartas()->obtenerCursor();
        this->ejecutarCarta(cartaAux->getFuncion());
        jugador->getCartas()->remover(numero);
      }
    }
  }
  } catch (...) {
    this->interfaz->mazoSinCartas();
  }
  
};

void Juego::jugarBatallaDigital() {
  /*
  Mientras el juego no esté terminado,
      - pide una accion al jugadorActual
      - ejecuta a accion --> varias cosas
      - muestra el mensaje de resultado de la accion
      - determinarGanador:
          - SI: mostrar gandor | finaliza el juego
          - NO: cambia de turno -->

  */
  this->interfaz->mostrarPantallaInicial();
  // TODO: mostrar ""
  while (!(this->ganador)) {
    /* Recorrer la lista de jugadores(cambiando el jugadorActual), y para cada
     jugador pedir la acciones, ejecutarlas y validar los movimientos, mostrando
     el estado del tablero para ese jugador.
     Hasta que se encuentre un ganador.
    */
    this->jugadores->iniciarCursor();

    // Recorre la lista
    while (!(this->ganador) && this->jugadores->avanzarCursor()) {

      Jugador *jugadorActual = jugadores->obtenerCursor();

      // Valida que no esté muerto
      if (jugadorActual->getCantidadFichas() != 0) {
        // mostrar tablero de jugador --->

        ////this->mostrarTableroJugador();
        // sacar carta
        this->sacarCarta();

        this->usarCarta();
        // chequear ganador
        // Colocar una mina en un casillero.
        // explotar o colocar en casillero.
        // preguntar soldado o armamento
        // mover soldado o armamento
        // validar movimiento

        this->moverFicha();

        this->ejecutarAtaque();
        // chequear ganador

        // jugar carta
        // realizar accion y mostrarla por pantalla
        // chequear ganador

        // chequear ganador
        // cambiar jugador

        // this->validarTurno();
      }
      // this->jugadorActual->sumarTurno();
      this->jugadores->obtenerCursor()->setTurnos(cantidadTurnosJuego++);
    }
    this->cantidadTurnosJuego++;
    // restarle a todos los casilleros que tengan "efectos" un turno.
  }
  /*
    mostrar mensaje de ganador

  */
}