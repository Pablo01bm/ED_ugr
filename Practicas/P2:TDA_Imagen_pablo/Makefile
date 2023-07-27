main1: main1.o libimag.o
	g++	main1.o imagen.o imagenES.o -o main1_exe

main4: main4.o libimag.o
	g++	main1.o imagen.o imagenES.o -o main1_exe

main5: main5.o libimag.o
	g++	main1.o imagen.o imagenES.o	-o main1_exe

libimag.o: imagen.o imagenES.o
	ar rvs $@ $^ 

main1.o: main1.cpp
	g++ -g	-c	-o	$@ -I inc $<

main4.o: main4.cpp
	g++ -g	-c	-o	$@ -I inc $<

main5.o: main5.cpp
	g++ -g	-c	-o	$@ -I inc $<		

negativo: negativo.o imagenES.o
	g++ -g	-o	$@	$^

imagen.o: imagen.cpp imagen.h
	g++ -g	-c imagen.cpp -o imagen.o

imagenES.o:	imagenES.cpp	imagenES.h
	g++	-g	-c	-o	$@	-I	inc	$<

negativo.o:	negativo.cpp
	g++	-g	-c	-o	$@	-I	inc	$<

clean:
		echo Limpiando.
		-rm	*.o

rebuild:	clean main1 main4 main5

documentacion:
		echo Creando la documentacion.
		doxygen Doxyfile






