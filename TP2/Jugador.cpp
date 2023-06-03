#include "Jugador.h"

Jugador::Jugador(Jugador *jugador) {
  this->simbolo = ficha->getSimbolo();
  this->estado = FICHA_DESBLOQUEADA;
}

std::string Jugador::getNombre() { return nombreJugador; }

Ficha *Jugador::getFicha() { return ficha; }

void Jugador::setFicha(Ficha *nuevaFicha) { this->ficha = nuevaFicha;}

int Jugador::getCantidadFichas() { return cantidadFichas; }

void Jugador::setCantidadFichas(int cantidad) { this->cantidadFichas = cantidad; }

Lista<Carta *>* Jugador::getCartas() { return cartas; }

void Jugador::setCartas(Lista<Carta*>* nuevasCartas) {this->cartas = nuevasCartas;}
int Jugador::getTurnos() { return contador_turnos; }

void Jugador::setTurnos(int nuevosTurnos) {this->contador_turnos = nuevosTurnos; }
