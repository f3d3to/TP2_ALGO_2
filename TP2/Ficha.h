#ifndef FICHA_H_
#define FICHA_H_

#include "Constantes.h"

class Ficha{

private:
    char simbolo;
    EstadoFicha estado;

public:

    /* Pre: Recibe una char que representara el simbolo de la ficha
     * Post: crea una ficha con el simbolo indicado y estado desbloqueado
     * */
    Ficha(char simbolo);


    /* Pre: la fichaOriginal debe ser valida
     * Post: crea una ficha como copia de la ficha dada, y estado desbloqueado
     * */
    Ficha( Ficha * fichaOriginal);



    /*
     * Post: libera toda la memoria solicitada para la Ficha
     * */
    ~Ficha();


    /*
     * Post: devuelve el simbolo de la Ficha
     **/
    char getSimbolo();


    /*
     * Post: devuelve true si los simbolos de la Ficha recibida es igual al simbolo
     * y false si no lo son
     **/
    bool esIgual(Ficha * ficha2);


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



private:

    /*
     * Post:valida que el simbolo ingresado no sea '\0  o ' ' o lanza un excepcion en caso contrario.
     **/
    void validar(char simbolo);

};



#endif /* FICHA_H_ */