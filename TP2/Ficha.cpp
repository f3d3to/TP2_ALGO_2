#include "Ficha.h"
#include "Constantes.h"
#include <string>

Ficha::Ficha() {
  this->tipoDeFicha = NO_DEFINIDA;
  this->identificadorDeJugador = " ";
  this->estado = FICHA_DESBLOQUEADA;
}
Ficha::Ficha(TipoDeFicha tipoDeFicha, std::string identificadorDeJugador) {
  this->tipoDeFicha = tipoDeFicha;
  this->identificadorDeJugador = identificadorDeJugador;
  this->estado = FICHA_DESBLOQUEADA;
}

Ficha::Ficha(std::string identificadorDeJugador) {
  this->tipoDeFicha = NO_DEFINIDA;
  this->identificadorDeJugador = identificadorDeJugador;
  this->estado = FICHA_DESBLOQUEADA;
}

Ficha &Ficha::operator=(const Ficha &otraFicha) {
  if (this == &otraFicha) {
    return *this; // Evita la asignación a sí mismo
  }

  // Copia los atributos de la otra ficha
  estado = otraFicha.estado;
  tipoDeFicha = otraFicha.tipoDeFicha;
  identificadorDeJugador = otraFicha.identificadorDeJugador;

  return *this;
}

Ficha::~Ficha() {}

Ficha::Ficha(Ficha *ficha) {
  this->tipoDeFicha = ficha->getTipoDeFicha();
  this->identificadorDeJugador = ficha->getIdentificadorDeJugador();
  this->estado = FICHA_DESBLOQUEADA;
}

void Ficha::setTipoDeFicha(TipoDeFicha tipoDeFicha) {
  this->tipoDeFicha = tipoDeFicha;
}

TipoDeFicha Ficha::getTipoDeFicha() { return this->tipoDeFicha; }

bool Ficha::esIgual(Ficha *ficha2) {
  try {
    return (this->getIdentificadorDeJugador() ==
            ficha2->getIdentificadorDeJugador());
  } catch (...) {
    // si los punteros son nulos salta la excepcion
    return false;
  }
}

bool Ficha::estaBloqueada() { return (this->estado == FICHA_BLOQUEADA); }

void Ficha::bloquear() { this->estado = FICHA_BLOQUEADA; }

void Ficha::desbloquear() { this->estado = FICHA_DESBLOQUEADA; }

std::string Ficha::getIdentificadorDeJugador() {
  return this->identificadorDeJugador;
}
