#include "Interfaz.h"


void Interfaz::mostrarPantallaInicial() {
	cout << "\n\n=================================================================";
	cout << "==============================\n\n";
    cout << "\n\t\t\t\t BATALLA DIGITAL V2.0      " << endl;
    cout << "\n\tBienvenido a BATALLA DIGITAL 2.0, una version alternativa"
            " de la BATALLA DIGITAL convencional \n\tcon un tablero en 3 dimensiones"
            " y varios jugadores y cartas para jugar!" << endl;
    cout << "\nProyecto desarrollado por alumnos de FIUBA" << endl;
	cout << "\n\n=================================================================";
	cout << "==============================\n\n";
}


void Interfaz::mostrarControles( Tablero * t ) {
    int dim[3];
    dim[0] = t->getDimensiones()[0];
    dim[1] = t->getDimensiones()[1];
    dim[2] = t->getDimensiones()[2];

	cout << "\n\n·································································";
	cout << "······························\n\n";

    std::cout<<"#DISPOSICION DEL TABLERO:\n\n";
    for ( int k=1; k < dim[2]+1; ++k ) {
		for ( int f=0; f < k-1; ++f ) {
			std::cout<<"\t";
		}
        std::cout<<"Profundo:"<<k<<"\n";
		for ( int f=0; f < k; ++f ) {
			std::cout<<"\t";
		}
		std::cout<<"     ancho:";
		for ( int f=1; f < dim[0]+1; ++f ) {
			std::cout<<" "<<f<<"   ";
		}
		std::cout<<"\n";
        for ( int j=1; j < dim[1]+1; ++j ) {
    		for ( int f=0; f < k; ++f ) {
    			std::cout<<"\t";
    		}
            std::cout<<"alto:"<<j<<"    ";

            for ( int i=1; i < dim[0]+1; ++i ) {
            	try {
            		char simbolo = t->getCasillero(i-1, j-1, k-1)->getFicha()->getTipoDeFicha();
                    std::cout<<"  "<<simbolo<<"  ";
                }
                catch (...) {
                    std::cout<<"  "<<"-"<<"  ";
                }
            }
            std::cout<<"\n";
        }
        std::cout<<"\n\n";
    }
    std::cout<<"\n#COORDENADAS\n";
    std::cout<<"\nLas coordenadas que ingrese deben estar entre los rangos:  \n";
    std::cout<<"\n\t Ancho:\t\t1 - "<<dim[0];
    std::cout<<"\n\t Alto:\t\t1 - "<<dim[1];
    std::cout<<"\n\t Profundo:\t1 - "<<dim[2];

	cout << "\n\n·································································";
	cout << "······························\n\n";

}


void Interfaz::mostrarFicha(Ficha * ficha) {

    if (ficha->getTipoDeFicha() == MINA){
        cout << 'M' ;
    }
    if (ficha->getTipoDeFicha() == BARCO){
        cout << 'B' ;
    }
    if (ficha->getTipoDeFicha() == SOLDADO){
        cout << 'S' ;
    }
    if (ficha->getTipoDeFicha() == ARMAMENTO){
        cout << 'A' ;
    }
    
}


void Interfaz::mostrarGanador(std::string nombreGanador) {
	cout << "\n\n=================================================================";
	cout << "==============================\n\n";
    std::cout << "\n\tEl ganador del juego es: \n\n\t\t" << nombreGanador<<std::endl;
	cout << "\n\n=================================================================";
	cout << "==============================\n\n";

}

void mostrarTableroDeJugador(Tablero *tablero, Jugador *jugador){
    int dim[3];
    dim[0] = tablero->getDimensiones()[0];
    dim[1] = tablero->getDimensiones()[1];
    dim[2] = tablero->getDimensiones()[2];

    std::cout<<"\n\n";
    for ( int f=0; f < dim[2]+2; ++f ) {
		for (int g=0; g < dim[0]; ++g) {
			cout << "**";
		}
    }
    std::cout<<"\n\n";

    std::cout<<"TABLERO: " <<  jugador->getNombre() <<std::endl;
    for ( int k=0; k < dim[2]; ++k ) {

        for ( int j=0; j < dim[1]; ++j ) {
    		for ( int f=0; f < k+2; ++f ) {
    			for ( int m=0; m < dim[0]*2-1; ++m ) {
    				std::cout<<" ";
    			}
    		}

            for ( int i=0; i < dim[0]; ++i ) {
            	try {
            		Ficha* ficha = tablero->getCasillero(i, j, k)->getFicha();
                    if (ficha->getIdentificadorDeJugador() == jugador->getNombre() && ficha->getTipoDeFicha() == MINA ){
                        std::cout<<" M ";
                    }
                    else if (ficha->getIdentificadorDeJugador() == jugador->getNombre() && ficha->getTipoDeFicha() == SOLDADO){
                        std::cout<<" S ";
                    }
                    else if (ficha->getIdentificadorDeJugador() == jugador->getNombre() && ficha->getTipoDeFicha() == ARMAMENTO){
                        std::cout<<" A ";
                    }
                     else if (ficha->getIdentificadorDeJugador() == jugador->getNombre() && ficha->getTipoDeFicha() == BARCO){
                        std::cout<<" B ";
                    }
                    
                }
                catch (...) {
                    std::cout<<" "<<"-";
                }
            }

            std::cout<<"\n";
        }
    }
    std::cout<<"\n\n";
    for ( int f=0; f < dim[2]+2; ++f ) {
		for (int g=0; g < dim[0]; ++g) {
			cout << "**";
		}
    }
    std::cout<<"\n\n";

}



void Interfaz::mostrarTablero(Tablero * t) {

    int dim[3];
    dim[0] = t->getDimensiones()[0];
    dim[1] = t->getDimensiones()[1];
    dim[2] = t->getDimensiones()[2];

    std::cout<<"\n\n";
    for ( int f=0; f < dim[2]+2; ++f ) {
		for (int g=0; g < dim[0]; ++g) {
			cout << "**";
		}
    }
    std::cout<<"\n\n";

    std::cout<<"TABLERO:\n";
    for ( int k=0; k < dim[2]; ++k ) {

        for ( int j=0; j < dim[1]; ++j ) {
    		for ( int f=0; f < k+2; ++f ) {
    			for ( int m=0; m < dim[0]*2-1; ++m ) {
    				std::cout<<" ";
    			}
    		}

            for ( int i=0; i < dim[0]; ++i ) {
            	try {
                    std::cout<< " " ;
                    this->mostrarFicha(t->getCasillero(i, j, k)->getFicha());
                    std::cout<< "";
                }
                catch (...) {
                    std::cout<<" "<<"-";
                }
            }

            std::cout<<"\n";
        }
    }
    std::cout<<"\n\n";
    for ( int f=0; f < dim[2]+2; ++f ) {
		for (int g=0; g < dim[0]; ++g) {
			cout << "**";
		}
    }
    std::cout<<"\n\n";
}


void Interfaz::pedirNombre(int jugadorNumero) {
    std::cout << "\nJugador " << jugadorNumero << " - Ingrese su nombre (max 10 caracteres): ";
}


void Interfaz::pedirCantidadJugadores() {
    std::cout << "\nIngrese la cantidad de jugadores con la que desea jugar (2 o mas): ";
}


void Interfaz::pedirCantidadFichas() {
    std::cout << "\nIngrese la cantidad de fichas que tendra cada jugador (4 o mas): ";
}


void Interfaz::pedirDimensiones() {
    std::cout << "\nIngrese las dimensiones del tablero (ancho, alto, profundo): " << std::endl;
}


void Interfaz::tableroChico() {
	std::cout << "\nEl tablero debe ser mas grande." << std::endl;
}


void Interfaz::pedirCantidadCartas() {
    std::cout << "\nIngrese la cantidad maxima de cartas que podra tener en la mano cada jugador al mismo tiempo (minimo 1): ";
}


void Interfaz::pedirPosicionFichaABloquear() {
    std::cout << "\nIngrese la posicion en el tablero de la ficha a bloquear: " << std::endl;
}


void Interfaz::informarNoHayFicha() {
    std::cout << "\nNo hay una ficha en la posicion del tablero ingresada." << std::endl;
}


void Interfaz::pedirPosicionCasilleroABloquear() {
    std::cout << "\nIngrese la posicion en el tablero del casillero a bloquear: " << std::endl;
}


void Interfaz::pedirCoordPonerFicha() {
    std::cout << "\nIngrese la posicion en el tablero donde desea colocar su ficha: " << std::endl;
}


void Interfaz::informarCasilleroNoDisponible() {
    std::cout << "\nEl casillero elegido no esta disponible" << std::endl;
}

void Interfaz::informarMovimientoDeFicha(){
    std::cout << "\n La ficha se ha movido con éxito." << std::endl;
}

void Interfaz::pedirCoordOrigenMoverFicha() {
    std::cout << "\nIngrese la posicion en el tablero de la ficha que desea mover: " << std::endl;
}


void Interfaz::pedirCoordDestinoMoverFicha() {
    std::cout << "\nIngrese la posicion en el tablero a donde desea mover la ficha elegida: " << std::endl;
}


void Interfaz::preguntarUsarCarta() {
    std::cout << "\nQuieres utilizar una carta? (S/N): " ;
}


void Interfaz::preguntarNroCarta() {
    std::cout << "\nCual carta quieres usar? (1 a 6): " ;
}


void Interfaz::tocaPonerFicha(std::string nombreJugador, char simbolo, int cantidadFichas, std::string color) {
    std::cout   << "\nJugador: "<< nombreJugador<<" te toca poner una ficha, tenes "
                <<cantidadFichas<<" (usas la "<<simbolo<<"  -  Color: "<<color<<")." << std::endl;
}


void Interfaz::tocaMoverFicha(std::string nombreJugador, char simbolo, std::string color) {
    std::cout   << "\nJugador: "<< nombreJugador<<" te toca mover una ficha (usas la "
                <<simbolo<<"  -  Color: "<<color<<")." << std::endl;
}


void Interfaz::mostrarCartasJugador(Jugador *jugador){

    std::cout << "\n"<<jugador->getNombre()<<" tus cartas son: ";
    Lista<Carta *> *cartas = jugador->getCartas();
    cartas->iniciarCursor();
    while ( cartas->avanzarCursor() ) {
        Carta * carta = cartas->obtenerCursor();
        std::cout << "\n\t" <<carta->getDescripcion() << "\n";
    }
}


void Interfaz::jugadorNoTieneCartaElegida() {
	std::cout << "\nNo tienes la carta que elegiste usar." << std::endl;
}


void Interfaz::jugadorSinCartas() {
    std::cout << "\nNo tienes cartas para usar." << std::endl;
}


void Interfaz::ingresoInvalido() {
    std::cout << "\nEl valor ingresado es invalido, vuelva a intentar" << std::endl;
}

void Interfaz::mostrarJugadorEnTurno(std::string nombreDeJugador){
    std::cout << "\nEs el turno del jugador" << nombreDeJugador <<"."<< std::endl;
}

void Interfaz::limpiarPantalla() {
    std::cout << "\033[H\033[2J\033[3J"; // CARACTER PARA LIMPIAR LA PANTALLA
}

