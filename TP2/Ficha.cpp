#include "Ficha.h"
#include "Constantes.h"
#include <string>

Ficha::Ficha(TipoDeFicha tipoDeFicha, int identificador){
    this->tipoDeFicha = tipoDeFicha;
    this->identificador = identificador;
    this->estado = FICHA_DESBLOQUEADA;

}


Ficha::Ficha(Ficha* ficha) {
    this->tipoDeFicha = ficha->getTipoDeFicha();
    this->identificador = ficha->getIdentificador();
    this->estado = FICHA_DESBLOQUEADA;
}


Ficha::~Ficha() {

}


TipoDeFicha Ficha::getTipoDeFicha() {
    return this->tipoDeFicha;
}

bool Ficha::esIgual(Ficha * ficha2){
    try {
        return (this->identificador == ficha2->identificador);
    } catch (...) {
        //si los punteros son nulos salta la excepcion
        return false;
    }
}


bool Ficha::estaBloqueada() {

    return (this->estado == FICHA_BLOQUEADA);
}


void Ficha::bloquear() {

    this->estado = FICHA_BLOQUEADA;
}


void Ficha::desbloquear() {

    this->estado = FICHA_DESBLOQUEADA;
}


