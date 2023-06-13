#ifndef FICHA_H_
#define FICHA_H_

#include "Constantes.h"

class Ficha {

private:
  EstadoFicha estado;
  TipoDeFicha tipoDeFicha;
  std::string identificadorDeJugador;

public:
  Ficha();
  /* Pre: Recibe un tipo, numero e identificador de jugador.
   Post: crea una ficha con el tipo indicado e idenficador. Su estado es
   desbloqueado.
   */
  Ficha(TipoDeFicha tipoDeFicha, std::string indetificadorDeJugador);
  Ficha(std::string identificadorDeJugador);
  Ficha &operator=(const Ficha &otraFicha);
  /* Pre: la fichaOriginal debe ser valida
   * Post: crea una ficha como copia de la ficha dada, y estado desbloqueado
   * */
  Ficha(Ficha *fichaOriginal);

  /*
   * Post: libera toda la memoria solicitada para la Ficha
   * */
  ~Ficha();

  /*
   * Post: devuelve el tipo de la Ficha
   **/
  TipoDeFicha getTipoDeFicha();

  /*
   * Post: setea el tipo de ficha
   **/
  void setTipoDeFicha(TipoDeFicha tipoDeFicha);

  /*
   * Post: devuelve true si los simbolos de la Ficha recibida es igual al
   *simbolo y false si no lo son
   **/
  bool esIgual(Ficha *ficha2);

  /*
   * Post: atributo estado cambia a bloqueado
   */
  void bloquear();

  /*
   * Post: atributo estado cambia a desbloqueado
   */
  void desbloquear();

  /*
   *Post: devuelve true si atributo estado == bloqueado
   */
  bool estaBloqueada();

  /*
   *pre: Exista un atributo ficha
   *post: devuelve el identificador de jugador de la ficha
   */
  std::string getIdentificadorDeJugador();

  /*
   *pre: Exista un atributo ficha
   *post: devuelve el numero de la ficha
   */
  int getNumeroDeFicha();
};

#endif /* FICHA_H_ */