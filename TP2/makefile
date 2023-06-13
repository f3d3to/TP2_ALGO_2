CFLAGS=-g -pedantic -Wall
CC=g++

all: batalla_digitalv2 clear 

#Make Main

run: batalla_digitalv2
	./batalla_digitalv2

batalla_digitalv2: carta.o ficha.o casillero.o tablero.o jugador.o juego.o interfaz.o main.o easyBMP.o
	$(CC) $(CFLAGS) -o batalla_digitalv2 interfaz.o juego.o casillero.o tablero.o jugador.o carta.o ficha.o EasyBMP.o  main.o

#Make Obj

main.o: main.cpp 
	$(CC) $(CFLAGS) -o main.o  -c main.cpp

juego.o: Juego.cpp Juego.h
	$(CC) $(CFLAGS) -o juego.o  -c Juego.cpp

interfaz.o: Interfaz.cpp Interfaz.h
	$(CC) $(CFLAGS) -o interfaz.o  -c Interfaz.cpp

tablero.o: Tablero.cpp Tablero.h
	$(CC) $(CFLAGS) -o tablero.o  -c Tablero.cpp

casillero.o: Casillero.cpp Casillero.h
	$(CC) $(CFLAGS) -o casillero.o  -c Casillero.cpp

jugador.o: Jugador.cpp  Jugador.h
	$(CC) $(CFLAGS) -o jugador.o  -c Jugador.cpp

ficha.o: Ficha.cpp  Ficha.h
	$(CC) $(CFLAGS) -o ficha.o  -c Ficha.cpp

carta.o: Carta.cpp  Carta.h
	$(CC) $(CFLAGS) -o carta.o  -c Carta.cpp

easyBMP.o: 
	$(CC) $(CFLAGS) -o EasyBMP.o -c EasyBMP/EasyBMP.cpp 


#Make Clear

clear:
	rm *.o

install:
	cp batalla_digitalv2 ../batalla_digitalv2

leak_test:
	valgrind --leak-check=full ./batalla_digitalv2