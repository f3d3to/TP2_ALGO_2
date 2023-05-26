#include "Jugador.h"

std::string Jugador::obtenerNombre() {
    return nombreJugador;
}

void Jugador::asignarNombre(std::string nombre) {
    nombreJugador = nombre;
}

Ficha* Jugador::obtenerFicha() {
    return ficha;
}

void Jugador::asignarFicha(Ficha* nuevaFicha) {
    ficha = nuevaFicha;
}

int Jugador::obtenerCantidadFichas() {
    return cantidadFichas;
}

void Jugador::asignarCantidadFichas(int cantidad) {
    cantidadFichas = cantidad;
}

Lista<Carta> Jugador::obtenerCartas() {
    return cartas;
}

void Jugador::asignarCartas(Lista<Carta> nuevasCartas) {
    cartas = nuevasCartas;
}

int Jugador::obtenerTurnos() {
    return turnos;
}

void Jugador::asignarTurnos(int nuevosTurnos) {
    turnos = nuevosTurnos;
}
