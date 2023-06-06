#include "Jugador.h"
#include "Constantes.h"

Jugador::Jugador(std::string nombreJugador, int cantidadDeFichas) {
  this->nombreJugador = nombreJugador;
  this->fichas = new Lista<Ficha*>;
  this->cartas = new Lista<Carta*>;
  this->cantidadSoldados = cantidadDeSoldados;
  this->contadorTurnos = 0;
}

std::string Jugador::getNombre() { return nombreJugador; }

Ficha *Jugador::getFicha(TipoDeFicha tipoDeFicha, int numeroDeFicha) { 
  fichas->iniciarCursor();
  Ficha * fichaAux=NULL;
  while (*fichas->avanzarCursor()) {
    if(*fichas->obtenerCursor()->getTipoDeFicha() == tipoDeFicha && fichas->obtenerCursor()->getIdentificador() == numeroDeFicha)
      fichaAux=fichas->obtenerCursor();
  }
  
  return fichaAux; 
}

void Jugador::setFichas(Ficha *nuevaFicha);

int Jugador::getCantidadFichas() { return cantidadFichas; }

void Jugador::setCantidadFichas(int cantidad) { this->cantidadFichas = cantidad; }

Lista<Carta *>* Jugador::getCartas() { return cartas; }

void Jugador::setCartas(Lista<Carta*>* nuevasCartas) {this->cartas = nuevasCartas;}
int Jugador::getTurnos() { return contadorTurnos; }

void Jugador::setTurnos(int nuevosTurnos) {this->contadorTurnos = nuevosTurnos; }
