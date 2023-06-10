#include "Jugador.h"

Jugador::Jugador(std::string nombreJugador) {
  this->nombreJugador = nombreJugador;
  this->fichas = new Pila<Ficha *>;
  this->cartas = new Lista<Carta *>;
  this->cantidadSoldados = 0;
  this->contadorTurnos = 0;
}

Jugador::~Jugador() {
  this->cartas->iniciarCursor();

  while (this->cartas->avanzarCursor()) {
    delete this->cartas->obtenerCursor();
  }
  while (!this->fichas->estaVacia()) {
    delete this->fichas->desapilar();
  }
  delete this->cartas;
  delete this->fichas;
}

std::string Jugador::getNombre() { return nombreJugador; }

Ficha *Jugador::getFicha() { return fichas->desapilar(); };

Lista<Carta *> *Jugador::getCartas() { return cartas; }

void Jugador::setCartas(Lista<Carta *> *nuevasCartas) {
  this->cartas = nuevasCartas;
}
int Jugador::getTurnos() { return contadorTurnos; }

void Jugador::setTurnos(int nuevosTurnos) {
  this->contadorTurnos = nuevosTurnos;
}

Pila<Ficha *> *Jugador::getFichas() { return this->fichas; }
