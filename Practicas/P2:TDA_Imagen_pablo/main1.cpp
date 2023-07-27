#include <iostream>
#include <cstring>
#include <cstdlib>

#include "imagenES.h"
#include "imagen.h"

using namespace std;

//-------------------------------------------------------
//REALIZADO POR: Pablo Borrego Megias Grupo: A3 practicas de ED
//-------------------------------------------------------

//______________________________________________________________________________
//Ejercicio 1

Imagen ejer_1(int min,  int max, const Imagen &imag){

Imagen img(imag.num_filas(), imag.num_columnas());
int pixel;
  for (int i=0; i<imag.num_filas(); i++){
    for(int j=0; j<imag.num_columnas(); j++){
      if (imag.valor_pixel(i,j) <= min || imag.valor_pixel(i,j)>=max){
        
        img.asigna_pixel(i,j, 255);
        
      }else{
        img.asigna_pixel(i,j, imag.valor_pixel(i,j));
        
      }
    }
  }
  
  return img;

};

int main (int argc, char *argv[]){

     char *origen, *destino; // nombres de los ficheros

  unsigned char *image;
  int nf, nc, npixeles; // Num. de filas y columnas de las imagenes
  Imagen imag;


  // Comprobar validez de la llamada
  if (argc != 3){
    cerr << "Error: Numero incorrecto de parametros.\n";
    cerr << "Uso: negativo <FichImagenOriginal> <FichImagenDestino>\n";
    exit (1);
  }

  origen  = argv[1];
  destino = argv[2];

  cout << endl;
  cout << "Fichero origen: " << origen << endl;
  cout << "Fichero resultado: " << destino << endl;




  if (LeerTipoImagen(origen)==IMG_PPM){
    cerr << "ha introducido ppm "<< endl;
    exit (1);
  }



  // Leer la imagen del fichero de entrada
  image = LeerImagenPGM (origen, nf, nc);
  if (!image){
    cerr << "Error: No pudo leerse la imagen." << endl;
    cerr << "Terminando la ejecucion del programa." << endl;
    exit (1);
  }
  int min, max;
  imag.leer_imagen(image, nf, nc);
  cout << "Introduzca el minimo: "<< endl;
  cin >> min;
  cout << "Introduzca el maxima: "<< endl;
  cin >> max;

  imag=ejer_1(min, max, imag);

  // Mostrar los parametros calculados por LeerImagenPGM()
  cout << endl;
  cout << "Dimensiones de " << origen << ":" << endl;
  
  cout << "   Imagen   = " << nf  << " filas x " << nc << " columnas " << endl;

  
  
  cout << "Creamos la imagen del archivo: "<< origen << endl;
  
  cout << "La imagen tiene: " << nf << " filas y "<< nc << " columnas. " << endl;
  
  unsigned char *v= imag.escribir_imagen(nf, nc);

  cout << "Escribiendo imagen en el fichero: "<< destino<<endl;
  EscribirImagenPGM(destino, v, nf, nc);


  // Liberar la imagen
  delete [] image;
  delete[] v;

  return (0);





}

