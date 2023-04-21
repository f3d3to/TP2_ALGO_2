CXX=g++
CXXFLAGS=-Wall -pedantic -ansi -std=c++98 -g

# Compilar un solo archivo
compile:
	$(CXX) $(CXXFLAGS) $(ARCHIVO).cpp -o $(ARCHIVO).out

# Compilar todos los archivos .cpp en el directorio actual
compile-all:
	$(foreach file, $(wildcard *.cpp), \
		$(eval BASENAME := $(shell basename $(file) .cpp)) \
		$(CXX) $(CXXFLAGS) $(file) -o $(BASENAME).out;)

# Ejecutar un solo archivo
run:
	./$(ARCHIVO).out

# Ejecutar el archivo definido por defecto
run-default:
	./$(EJECUTABLE)

# Eliminar un solo archivo
clean-one:
	rm -f $(ARCHIVO).out

# Eliminar todos los archivos
clean-all:
	rm -f *.out

# Compilar y ejecutar un archivo específico
compile-run:
	$(CXX) $(CXXFLAGS) $(ARCHIVO).cpp -o $(ARCHIVO).out && ./$(ARCHIVO).out

# Compilar varios archivos
compile-several:
	$(CXX) $(CXXFLAGS) $(ARCHIVOS) -o $(EJECUTABLE).out

