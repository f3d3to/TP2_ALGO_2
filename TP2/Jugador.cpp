#include "Jugador.h"
#include <iostream>

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
void Jugador::setFichas(Pila<Ficha *> *nuevasFichas) {
  // Limpia la pila de fichas existente
  while (!fichas->estaVacia()) {
    delete fichas->desapilar();
  }
  delete fichas;

  // Asigna la nueva pila de fichas
  fichas = nuevasFichas;
}
Ficha *Jugador::getFicha() {
  if (fichas->estaVacia()) {
    std::cout << "ESTA VACIA LA PILA" << std::endl;
  }
  return fichas->desapilar();
}
Lista<Carta *> *Jugador::getCartas() { return cartas; }

void Jugador::setCartas(Lista<Carta *> *nuevasCartas) {
  this->cartas = nuevasCartas;
}
int Jugador::getTurnos() { return contadorTurnos; }

void Jugador::setTurnos(int nuevosTurnos) {
  this->contadorTurnos = nuevosTurnos;
}

Pila<Ficha *> *Jugador::getPilaFichas() { return this->fichas; }