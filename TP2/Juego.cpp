#include "Juego.h"

Juego::Juego(){

    this->interfaz = new Interfaz();
    this->ganador = NULL;

    unsigned int cantidadJugadores = pedirCantidadJugadores();
    unsigned int cantidadFichas = pedirCantidadFichas();

    this->jugadores = new Lista < Jugador * >;
    
    for(unsigned int i=0; cantidadJugadores; i++){
        std::string nombre = pedirNombre(i+1);

      // Ficha * ficha = new Ficha (ficha->getSimbolo()+ i); //VER COMO HACER PARA CREAR DISTINTOS TIPOS DE ARMAMENTOS
        Jugador *nuevoJugador = new Jugador(nombre, );
        // nuevoJugador-> = new Lista < Jugador * >;
        
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

Juego::~Juego() {
    
    delete this->tablero;

    this->jugadores->iniciarCursor();
    while( this->jugadores->avanzarCursor() ) {
        delete this->jugadores->obtenerCursor();
    }
    delete this->jugadores;

    while( ! this->mazo->estaVacia() ) {
        delete this->mazo->pop();
    }
    delete this->mazo;

    delete this->interfaz;
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

// void Juego::ValidacionAvanzarDeTurno(){
//     for (int i; i< this->jugadores->contarElementos(); i++){
//         jugadores->obtener(i);
        
//         cambiarDeJugador();
//     }

//     cambiarDeTurno()

// }
void Juego::cambiarDeJugadorActual( ){
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
            if (cantidadFichas < 4){
                throw "Error menos de 4 ficha";
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

void Juego::moverSoldado(){
    int x,y,z, x1, y1, z1;
    this->interfaz->pedirCoordOrigenMoverFicha();

    // Pide coordenadas origen hasta las ingrese correctamente
    std::cin >>x;
    std::cin >>y;
    std::cin >>z;
    // Valida coordenadas
    
    if(!(this->tablero->existeCasillero(x, y, z))){
        
    // Validar que la casilla contenga una ficha, sea un soldado, que pertenezca al jugador y que la casilla no esté inactiva
        throw "La posicion indicada no existe";
    }

    // Seleccionar la ficha 
    Ficha *fichaOrigen = this->tablero->getCasillero(x,y,z)->getFicha();

    // Pide coordenadas de destino hasta las ingrese correctamente 
    this->interfaz->pedirCoordDestinoMoverFicha();
    std::cin >>x1;
    std::cin >>y1;
    std::cin >>z1;

    if(!(this->tablero->existeCasillero(x1, y1, z1))){   
    // Validar que la casilla contenga una ficha, sea un soldado, que pertenezca al jugador y que la casilla no esté inactiva
        throw "La posicion indicada no existe";
    }

    // Valida que la casilla no este inactiva, que no haya una Ficha enemiga, ni del jugador
    // Mueve la ficha
    Ficha *fichaDestino = this->tablero->getCasillero(x1,y1,z1)->getFicha();

    // Swap ficha
    if ((!fichaDestino->estaBloqueada()) && fichaDestino!=NULL){
        // Swap la ficha
        this->tablero->getCasillero(x1,y1,z1)->setFicha(fichaOrigen);
        // Elimina la fichaOrigen
        this->tablero->getCasillero(x,y,z)->quitarFicha();
        // Mensaje de ficha ha sido movida con éxito
        this->interfaz->informarMovimientoDeFicha();
    }
   
}


void Juego::jugarBatallaDigital(){
    /*
    Mientras el juego no esté terminado,
        - pide una accion al jugadorActual
        - ejecuta a accion --> varias cosas
        - muestra el mensaje de resultado de la accion
        - determinarGanador:
            - SI: mostrar gandor | finaliza el juego
            - NO: cambia de turno -->

    */
    this->interfaz->mostrarPantallaInicial();
    // TODO: mostrar ""
    while(!(this->ganador)){
        /* Recorrer la lista de jugadores(cambiando el jugadorActual), y para cada jugador
         pedir la acciones, ejecutarlas y validar los movimientos, mostrando
         el estado del tablero para ese jugador.
         Hasta que se encuentre un ganador.
        */
        this->jugadores->iniciarCursor();
        
        
        // Recorre la lista 
        while(!(this->ganador) && this->jugadores->avanzarCursor()){

            Jugador * jugadorActual= jugadores->obtenerCursor();

            // Valida que no esté muerto
            if(jugadorActual->getCantidadFichas() != 0){
                // mostrar tablero de jugador --->
                
                ////this->mostrarTableroJugador();
                // sacar carta
                this->sacarCarta();
                
                this->usarCarta();
                // chequear ganador
                // Colocar una mina en un casillero.
                    // explotar o colocar en casillero.
                // preguntar soldado o armamento
                //mover soldado o armamento
                // validar movimiento 

                this->moverFicha();

                this->ejecutarAtaque();
                // chequear ganador
                
                // jugar carta
                    // realizar accion y mostrarla por pantalla 
                    // chequear ganador
                
                // chequear ganador
                // cambiar jugador 
                
                // this->validarTurno();
                
            }
            // this->jugadorActual->sumarTurno();
            this->jugadores->obtenerCursor()->setTurnos(cantidadTurnosJuego++);
        }
      this->cantidadTurnosJuego ++;
      // restarle a todos los casilleros que tengan "efectos" un turno.
    }
    /*
      mostrar mensaje de ganador 

    */
}
