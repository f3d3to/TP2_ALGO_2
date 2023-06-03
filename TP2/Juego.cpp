#include "Juego.h"

Juego::Juego(){

    this->interfaz = new Interfaz();
    this->ganador = NULL;
    this->jugadorAnterior = NULL;

    unsigned int cantidadJugadores = pedirCantidadJugadores();
    unsigned int cantidadFichas = pedirCantidadFichas();

    this->jugadores = new Lista < Jugador * >;

    for(unsigned int i=0; cantidadJugadores; i++){
        std::string nombre = pedirNombre(i+1);
        Ficha * ficha = new Ficha ("aca va que armamento va ver logica" + i);
        Jugador *nuevoJugador = new Jugador(nombre,ficha,cantidadFichas);
        this->jugadores->altaFinal(nuevoJugador);
    }

    this->jugadorEnTurno = this->jugadores->obtener(1);

    unsigned int * dimensiones = new unsigned int[3];
    pedirDimensionesJuego(cantidadJugadores,cantidadFichas,dimensiones);
    this->tablero = new Tablero(dimensiones[0],dimensiones[1],dimensiones[2]);
    delete[] dimensiones;

    this->cantidadMaximaCartas = pedirCantidadCartasPorJugador();

    this->mazo = new Cola < Carta * >;

    for (unsigned int i = 0; i < cantidadJugadores*cantidadMaximaCartas*2; i++) {
        funcion_t funcionalidad = getFuncionalidad(i % 6);
        Carta * nuevaCarta = new Carta(funcionalidad);
        this->mazo->push(nuevaCarta);
    }
    


}


bool Juego::determinarGanador(){
    bool hayGanador;
    if (this->ganador != NULL){
        hayGanador = true;
        this->interfaz->mostrarGanador(this->ganador->getNombre());
    }
    else{
        hayGanador = false;
    }
    return hayGanador;

};


void Juego::cambiarTurno(){
    this->jugadores->avanzarCursor();
    this->jugadorEnTurno = this->jugadores->obtenerCursor();
    this->interfaz->limpiarPantalla(); // Chequear
    this->interfaz->mostrarJugadorEnTurno(this->jugadorEnTurno->getNombre());
}

//FUNCIONES DE ENTRADA DE DATOS//

unsigned int Juego::pedirCantidadJugadores() {

	int cantidadJugadores = 0;
	bool cantidadValida = false;

    while ( !cantidadValida ) {

    	this->interfaz->pedirCantidadJugadores();
        try {
            std::cin >> cantidadJugadores;
            if (cantidadJugadores < 2){
                throw "Error Menos de 2 jugadores";
            }
            cantidadValida = true;
        } catch (...) {
            this->interfaz->ingresoInvalido();
        }
    }

    return (unsigned int) cantidadJugadores;
}

unsigned int Juego::pedirCantidadFichas() {

    int cantidadFichas = 0;
    bool cantidadValida = false;

    while (!cantidadValida) {
        this->interfaz->pedirCantidadFichas();
        try {
            std::cin >> cantidadFichas;
            if (cantidadFichas < 1){
                throw "Error menos de 1 ficha";
            }
            cantidadValida = true;
        } catch (...) { //En caso de que ingrese un valor inválido se le indica al usuario que lo que ingreso es inválido
            this->interfaz->ingresoInvalido();
        }
    }

    return (unsigned int) cantidadFichas;
}

std::string Juego::pedirNombre(int jugadorNumero) {
    std::string nombre;
    bool nombreValido = false;

    while ( !nombreValido ) {
        this->interfaz->pedirNombre(jugadorNumero);
        try {
            std::cin >> nombre;
            if (nombre.length() > 10) {
                throw("Nombre demasiado largo.");
            }
            nombreValido = true;
        } catch (...) {
            this->interfaz->ingresoInvalido();
        }
    }
    return nombre;
}

void Juego::pedirDimensionesJuego(int cantidadJugadores,int cantidadFichas,unsigned int * dimensiones){
    int ancho,alto,profundo;
    bool diemensionesValidas = false;

    while(!diemensionesValidas){
        this->interfaz->pedirDimensiones();
        try{
            std::cout<<"Ancho:  \t";
            std::cin>>ancho;

            std::cout<<"Alto:   \t";
            std::cin>>alto;

            std::cout<<"Profundo:  \t";
            std::cin>>profundo;

            if(ancho < 1 || alto < 1 || profundo < 1 ||
            ancho*alto*profundo < cantidadJugadores*cantidadFichas+cantidadJugadores){
                throw "Dimesiones de juego invalidas o tablero demasiado chico.";
            }
            diemensionesValidas = true;
        }
        catch(...){
            this->interfaz->tableroChico();
        }
    }

    dimensiones[0] = ancho;
    dimensiones[1] = alto;
    dimensiones[2] = profundo;

}

unsigned int Juego::pedirCantidadCartasPorJugador() {

    int cantidadCartas;
    bool cantidad_valida = false;

    while ( !cantidad_valida ) {

        this->interfaz->pedirCantidadCartas();
        try {
            std::cin>>cantidadCartas;
            if ( cantidadCartas < 1 ) {
                throw("Cada jugador debe tener al menos una carta.");
            }
            cantidad_valida = true;
        } catch (...) {
            this->interfaz->ingresoInvalido();
        }
    }

    return (unsigned int)cantidadCartas;
}

funcion_t Juego::getFuncionalidad(unsigned int indice){
    
    switch (indice) {
		case ATAQUE_QUIMICO:
			return ATAQUE_QUIMICO;    
		case AVION_RADAR:
			return AVION_RADAR;  
		case BARCO:
			return BARCO;  
		case REFUERZOS:
			return REFUERZOS;  
		case ESCUDO:
			return ESCUDO;  
		case MASCARA_ANTIGAS:
			return MASCARA_ANTIGAS;  
    };

    throw "Numero de carta no valido";
}



    