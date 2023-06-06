#ifndef JUGADOR_H_
#define JUGADOR_H_

#include "Carta.h"
#include "Constantes.h"
#include "Ficha.h"
#include "Lista.h"
#include <string>

class Jugador {
  friend class Ficha;

private:
  std::string nombreJugador;
  Lista<Ficha*>* ficha;
  int cantidadSoldados;
  Lista<Carta *> *cartas;
  int contadorTurnos; // Cuando suma un turno, resta uno al contador_bloqueado
                       // de cada ficha
  
public:
  /* Pre: recibe un string, una ficha valida y un entero mayor a 0
   * Post: inicializar atributos, crea maso de carta en memoria
   * */
  Jugador(std::string nombreJugador, int cantidadDeFichas);
  /*
   * Post: libera toda la memoria solicitada*/
  ~Jugador();

  std::string getNombre();
  Ficha * getFicha(TipoDeFicha tipoDeFicha);
  void setFicha(Ficha *nuevaFicha);

  int getCantidadFichas();
  void setCantidadFichas(int cantidad);

  Lista<Carta*>* getCartas();
  Carta * getUltimaCarta();
  void setCartas(Lista<Carta*> *nuevasCartas);
  int getTurnos();
  void setTurnos(int nuevosTurnos);
  
};

#endif /* JUGADOR.H */