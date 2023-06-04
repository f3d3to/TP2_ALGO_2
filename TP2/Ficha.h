#ifndef FICHA_H_
#define FICHA_H_

#include "Constantes.h"

class Ficha {

private:
  EstadoFicha estado;
  TipoDeFicha tipoDeFicha;
  int identificador;

public:
  /* Pre: Recibe una char que representara el simbolo de la ficha.
   Tambien recibe un identificador de tipo entero.
   Post: crea una ficha con el tipo indicado e idenficador. Su estado es desbloqueado.
   */
  Ficha(TipoDeFicha tipoDeFicha,int identificador);

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

//private:
  
};

#endif /* FICHA_H_ */