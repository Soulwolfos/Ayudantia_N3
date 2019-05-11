CXX = mpic++
CXXFLAGS = -g3 -Wall
MKDIR = mkdir -p


LIBS = -lm -lmpi

directorios: 
	$(MKDIR) build dist
	
main.o: directorios main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o build/main.o

Funciones.o: directorios Funciones.cpp Funciones.h
	$(CXX) $(CXXFLAGS) -c Funciones.cpp -o build/Funciones.o

all: clean main.o Funciones.o
	$(CXX) $(CXXFLAGS) -o dist/programa build/main.o build/Funciones.o
	rm -fr build

clean:
	rm -fr *.o a.out programa dist build

.DEFAULT_GOAL := all