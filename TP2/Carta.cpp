#include "Carta.h"

std::string funcionalidades[6] = {
    "Contamina 125 casilleros por 10 turnos en el centro, 8 turnos el siguiente radio y asi",
    "Detecta minas en cada turno",
    "Si esta en el agua, puede disparar un misil una vez por turno",
    "Se incorpora un soldado",
    "El jugador puede proteger una zona de 10 casilleros por 5 turnos",
    "Protege a 125 casilleros por 10 turnos del ataque quimico"};

Carta::Carta(funcion_t funcion) { this->funcion = funcion; }

funcion_t Carta::getFuncion() { return this->funcion; }

std::string Carta::getDescripcion() { return funcionalidades[this->funcion]; }