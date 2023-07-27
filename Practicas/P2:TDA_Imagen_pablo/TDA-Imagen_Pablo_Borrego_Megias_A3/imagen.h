/****************************************************************************************/
// Fichero: imagen.h
// Fichero de cabecera asociado a la biblioteca libimg.a.
// Implementacion del TDA imagen (imagen digital en niveles de gris).
/****************************************************************************/

#ifndef IMAGEN
#define IMAGEN

typedef unsigned char byte;  // tipo base de cada pixel

 class Imagen{
     private:
     // Definición de los tipos para manejar imagenes digitales. Es solo un ejemplo de lo que// podría ser esta parte privada.

        int filas;     // Número de filas de la imagen
        int cols;      // Número de columnas de la imagen
        byte **img;    // La imagen en si: una matriz dinamica 2D de bytes

     public:
     
     Imagen();

     Imagen(int filas, int cols, byte **imag);

     Imagen & operator=(const Imagen & imag);

     Imagen(int filas, int cols);

     ~Imagen();

     int num_filas()const;

     int num_columnas()const;

     void asigna_pixel(int fila, int col, byte valor);

     byte valor_pixel(int fila, int col) const;

     void leer_imagen(unsigned char * c, int nfilas, int ncolumns);

     unsigned char * escribir_imagen(int &nfilas, int &ncolumns);
     
     void reservar(int filas, int cols);

     void liberar();

     double valor_min();

     double valor_max();

     
 };


#endif
