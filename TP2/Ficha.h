#ifndef FICHA_H_
#define FICHA_H_
#include "Constantes.h"

class Ficha {
private:

  EstadoFicha estado;
  TipoDeFicha tipoDeFicha;
  std::string identificadorDeJugador;
public:
  /*
   * pre:---
   * post: crea una instancia del tipo ficha.
   */
  Ficha();
  /* 
   * Pre: Recibe un tipo, numero e identificador de jugador.
   * Post: crea una ficha con el tipo indicado e idenficador. Su estado es
   * desbloqueado.
   */
  Ficha(TipoDeFicha tipoDeFicha, std::string indetificadorDeJugador);
  /*
   * pre:Recibe un identificador de jugador.
   * post: crea una instancia del tipo ficha.
   */
  Ficha(std::string identificadorDeJugador);
  /*
   * pre:Recibe una ficha.
   * post: duelve una instancia de ese tipo ficha.
   */
  Ficha &operator=(const Ficha &otraFicha);
  /* 
   * Pre: la fichaOriginal debe ser valida
   * Post: crea una ficha como copia de la ficha dada, y estado desbloqueado.
   */
  Ficha(Ficha *fichaOriginal);
  /*
   * pre: ---
   * Post: libera toda la memoria solicitada para la Ficha 
   */
  ~Ficha();
  /*
   * pre: Exista una instancia del tipo Ficha.
   * Post: devuelve el tipo de la Ficha
   */
  TipoDeFicha getTipoDeFicha();
  /*
   * pre: Exista una instancia del tipo Ficha y reciba el tipo de ficha.
   * Post: setea el tipo de ficha
   */
  void setTipoDeFicha(TipoDeFicha tipoDeFicha);
  /*
   * pre: Exista una instancia del tipo Ficha y reciba una Ficha.
   * Post: devuelve true si los simbolos de la Ficha recibida es igual al
   * simbolo y false si no lo son
   */
  bool esIgual(Ficha *ficha2);
  /*
   * Pre: Exista una instancia del tipo Ficha.
   * Post: atributo estado cambia a bloqueado
   */
  void bloquear();
  /*
   * Pre: Exista una instancia del tipo Ficha.
   * Post: atributo estado cambia a desbloqueado
   */
  void desbloquear();
  /*
   * Pre: Exista una instancia del tipo Ficha.
   * Post: devuelve true si atributo estado == bloqueado
   */
  bool estaBloqueada();
  /*
   * Pre: Exista una instancia del tipo Ficha.
   * post: devuelve el identificador de jugador de la ficha
   */
  std::string getIdentificadorDeJugador();
  /*
   * Pre: Exista una instancia del tipo Ficha.
   * post: devuelve el numero de la ficha
   */
  int getNumeroDeFicha();
};

#endif /* FICHA_H_ */