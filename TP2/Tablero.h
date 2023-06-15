#ifndef TABLERO_H_
#define TABLERO_H_


#include "Lista.h"
#include "Casillero.h"
#include "Ficha.h"

class Tablero{
private:
    Lista<Lista<Lista<Casillero *> *> *> * casilleros;
    int dimensiones[3];

public:
    /*
     * Pre: recibe las longitudes de las tres dimensiones con las que se desea crear el tablero
     * Post: inicializa un tablero de x ancho, y alto, z profundidad de casilleros vacios y
     * asigna sus respectivos casilleros adyacentes
     */
    Tablero(unsigned int x, unsigned int y, unsigned int z);

    /*
     * pre: ---
     * Post: libera la memoria solicitada para la creacion del tablero
     */
    ~Tablero();

    /*
     * pre: ---
     * Post: devuelve un puntero a las dimensiones del Tablero
     */
    int * getDimensiones();

    /*
     * Pre: recibe las coordenadas x,y,z del Casillero que se desea verificar
     * Post: devuelve true si existe un Casillero en el Tablero ubicado en las
     * coordenadas recibidas, devuelve false si no existe y lanza una excepcion
     * si las coordenadas son inválidas
     * quito el unsigned int porque chequea numeros negativos
     */
    bool existeCasillero(int x, int y, int z);

    /*
     * Pre: recibe las coordenadas x,y,z del casillero que se desea obtener
     * Post: devuelve el casillero que se encuentra en la coordenada recibida
     */
    Casillero * getCasillero(unsigned int x, unsigned int y, unsigned int z);

};



#endif /* TABLERO_H_ */