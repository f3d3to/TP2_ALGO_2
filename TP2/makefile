CXXFLAGS=-std=c++98
CFLAGS=-g -pedantic -Wall -ansi -fPIE
CC=g++

all: batalla_digitalv2 clear

#Make Main

batalla_digitalv2: main.o ficha.o casillero.o  tablero.o interfaz.o carta.o jugador.o juego.o 
	$(CC) $(CFLAGS) $(CXXFLAGS) -o batalladigitalv2 main.o ficha.o casillero.o tablero.o interfaz.o carta.o jugador.o juego.o

#Make Obj

main.o: main.cpp 
	$(CC) $(CFLAGS) -o main.o  -c main.cpp

interfaz.o: Interfaz.cpp Interfaz.h
	$(CC) $(CFLAGS) -o interfaz.o  -c Interfaz.cpp

tablero.o: Tablero.cpp Tablero.h
	$(CC) $(CFLAGS) -o tablero.o  -c Tablero.cpp

casillero.o: Casillero.cpp Casillero.h
	$(CC) $(CFLAGS) -o casillero.o  -c Casillero.cpp

ficha.o: Ficha.cpp  Ficha.h
	$(CC) $(CFLAGS) -o ficha.o  -c Ficha.cpp

carta.o: Carta.cpp  Carta.h 
	$(CC) $(CFLAGS) -o carta.o  -c Carta.cpp

jugador.o: Jugador.cpp  Jugador.h 
	$(CC) $(CFLAGS) -o jugador.o  -c Jugador.cpp

juego.o: Juego.cpp  Juego.h 
	$(CC) $(CFLAGS) -o juego.o  -c Juego.cpp


#Make Clear

clear:
	rm *.o

leak_test:
	valgrind --leak-check=full ./batalladigitalv2