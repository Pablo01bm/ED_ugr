#include <iostream>
#include <cstring>
#include <cstdlib>

#include "imagenES.h"
#include "imagen.h" 
#include<cmath>
using namespace std;

//-------------------------------------------------------
//REALIZADO POR: Pablo Borrego Megias Grupo: A3 practicas de ED
//-------------------------------------------------------

//____________________________________________________________
//Ejercicio 4, ICONO
Imagen ej4(int num_filas, int num_cols, const Imagen &original){

  int n_filas_orig;
  int n_cols_orig;
  int valorpixeles;
  double media1,media2;
  int cont=0;
  double pixel, propor_f, propor_c;

  n_filas_orig=original.num_filas();
  n_cols_orig=original.num_columnas();

    media1=n_filas_orig/num_filas;
    media2=n_cols_orig/num_cols;

  propor_f=round(media1);
  propor_c=round(media2);  

  Imagen icono=Imagen(num_filas, num_cols);

  for (int i=0; i<n_filas_orig; i++){
    for(int j=0; j<n_cols_orig; j++){
      valorpixeles+=original.valor_pixel(i, j);
      cont++;
      cout << "PROPOR: "<< propor_c<<"   CONTADOR: "<< cont<<endl;
      if(cont==propor_c){
        cout << "Valor del pixel: "<< round(valorpixeles/propor_c)<<endl;  
        icono.asigna_pixel(round(i/propor_f), round(j/propor_c), round(valorpixeles/propor_c));
        cont=0;
        valorpixeles=0;
      }
    }
  }

return icono;

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
  cout << "Introduzca el numero de filas: "<< endl;
  cin >> min;
  cout << "Introduzca el numero de columnas: "<< endl;
  cin >> max;

  imag=ej4(min, max, imag);

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

