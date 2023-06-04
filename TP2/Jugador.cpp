#include "Jugador.h"
#include "Constantes.h"

Jugador::Jugador(std::string nombreJugador, int cantidadDeFichas) {
  this->nombreJugador = nombreJugador;
  this->soldados = new Lista<Ficha*>;
  this->barcos = new Lista<Ficha*>;
  this->armamentos = new Lista<Ficha*>;
  this->minas = new Lista<Ficha*>;
  
  this->cartas = new Lista<Carta*>;
  this->cantidadFichas= cantidadDeFichas;
  this->contadorTurnos=0;

}

std::string Jugador::getNombre() { return nombreJugador; }

Ficha *Jugador::getFicha(TipoDeFicha tipoDeFicha) { 
  Lista<Ficha*> mina,
  // Lista<Ficha*> mina = new Ficha[cantidadMiNAS]();,

  *fichas->iniciarCursor();

  while (*fichas->avanzarCursor()) {
    if(*fichas->obtenerCursor()->getTipoDeFicha() == tipoDeFicha)
      fichas->iniciarCursor();
      fichas->obtenerCursor(); 
  }
  
  
  return ficha; 
}

void Jugador::setFicha(Ficha *nuevaFicha) { this->ficha = nuevaFicha;}

int Jugador::getCantidadFichas() { return cantidadFichas; }

void Jugador::setCantidadFichas(int cantidad) { this->cantidadFichas = cantidad; }

Lista<Carta *>* Jugador::getCartas() { return cartas; }

void Jugador::setCartas(Lista<Carta*>* nuevasCartas) {this->cartas = nuevasCartas;}
int Jugador::getTurnos() { return contadorTurnos; }

void Jugador::setTurnos(int nuevosTurnos) {this->contadorTurnos = nuevosTurnos; }
