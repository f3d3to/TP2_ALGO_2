#include "Carta.h"

std::string funcionalidades[6] = {
    "Contamina 125 casilleros por 10 turnos en el centro, 8 turnos el siguiente radio y asi",
    "Detecta minas en cada turno",
    "Si esta en el agua, puede disparar un misil una vez por turno",
    "Se incorpora un soldado",
    "Puede tirar 3 minas por el turno en el que se usa",
    "Permite seleccionar una ficha e identificar si es de un enemigo"};

Carta::Carta(funcion_t funcion) { this->funcion = funcion; }

funcion_t Carta::getFuncion() { return this->funcion; }

std::string Carta::getDescripcion() { return funcionalidades[this->funcion]; }