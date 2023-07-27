###############################################################
## Pablo Muñoz Castro 2º B3
##
## Makefile Rutas_Aereas
## Practica Final
###############################################################

HOME = .

BIN = $(HOME)/bin
DOC = $(HOME)/doc
DATOS = $(HOME)/datos
SRC = $(HOME)/src
OBJ = $(HOME)/obj
LIB = $(HOME)/lib
INCLUDE = $(HOME)/include


all : clean.all $(BIN)/rutas_aereas


## Ejecutable

$(BIN)/rutas_aereas : $(OBJ)/rutas_aereas.o $(OBJ)/imagen.o $(OBJ)/imagenES.o \
					$(OBJ)/AlmacenRutas.o $(OBJ)/Ruta.o $(OBJ)/Punto.o
	@echo
	@echo Creando ejecutable: rutas_aereas
	@echo
	g++ -o $(BIN)/rutas_aereas $(OBJ)/rutas_aereas.o $(OBJ)/imagen.o $(OBJ)/imagenES.o \
		$(OBJ)/AlmacenRutas.o $(OBJ)/Ruta.o $(OBJ)/Punto.o -std=c++11



## Archivo objeto principal

$(OBJ)/rutas_aereas.o : $(SRC)/rutas_aereas.cpp
	@echo
	@echo Generando archivo objeto: rutas_aereas.o
	@echo
	g++ -c -o $(OBJ)/rutas_aereas.o $(SRC)/rutas_aereas.cpp -I./include -std=c++11



## Archivos objeto adicionales

$(OBJ)/imagen.o : $(SRC)/imagen.cpp
	@echo
	@echo Generando archivo objeto: imagen.o
	@echo
	g++ -c -o $(OBJ)/imagen.o $(SRC)/imagen.cpp -I./include -std=c++11

$(OBJ)/imagenES.o : $(SRC)/imagenES.cpp
	@echo
	@echo Generando archivo objeto: imagenES.o
	@echo
	g++ -c -o $(OBJ)/imagenES.o $(SRC)/imagenES.cpp -I./include -std=c++11

$(OBJ)/AlmacenRutas.o : $(SRC)/AlmacenRutas.cpp
	@echo
	@echo Generando archivo objeto: AlmacenRutas.o
	@echo
	g++ -c -o $(OBJ)/AlmacenRutas.o $(SRC)/AlmacenRutas.cpp -I./include -std=c++11

$(OBJ)/Ruta.o : $(SRC)/Ruta.cpp
	@echo
	@echo Generando archivo objeto: Ruta.o
	@echo
	g++ -c -o $(OBJ)/Ruta.o $(SRC)/Ruta.cpp -I./include -std=c++11

$(OBJ)/Punto.o : $(SRC)/Punto.cpp
	@echo
	@echo Generando archivo objeto: Punto.o
	@echo
	g++ -c -o $(OBJ)/Punto.o $(SRC)/Punto.cpp -I./include -std=c++11



## Ordenes de limpieza

clean.obj :
	@echo
	@echo Eliminando objetos...
	@echo
	-rm $(OBJ)/*

clean.all : clean.obj
	@echo
	@echo Eliminando ejecutables...
	@echo
	-rm $(BIN)/*