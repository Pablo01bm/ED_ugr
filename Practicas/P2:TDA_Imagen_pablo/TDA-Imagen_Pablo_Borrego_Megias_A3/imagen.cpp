#include <fstream>
#include <string>
#include <iostream>
#include "imagen.h"

typedef unsigned char byte;

using namespace std;

//-------------------------------------------------------
//REALIZADO POR: Pablo Borrego Megias Grupo: A3 practicas de ED
//-------------------------------------------------------
/*
* @author: Pablo Borrego Megias
*
*
 */


Imagen::Imagen(){
    filas=0;
    cols=0;
    img=nullptr;
}

Imagen::Imagen(int filas, int cols ){
    this->filas=filas;
    this->cols=cols;
    reservar(filas, cols);
   
}
 Imagen & Imagen::operator=(const Imagen & imag){
    filas=imag.filas;
    cols=imag.cols;
    if (this != &imag){
        liberar();
        reservar(filas, cols);

         for ( int i=0; i< filas; i++){
             for(int j=0; j< cols; j++){
                img[i][j]=imag.valor_pixel(i,j);
             }
         }
             
    }
}

void Imagen::liberar(){
    if(img != nullptr){
        delete[] img[0];
        delete[] img;
    }
}

void Imagen::reservar(int f, int c){
    if(f>=0 && c>=0){
        this->filas=f;
        this->cols=c;
        img=new unsigned char*[f];
        img[0]=new unsigned char[f*c];

        for (int i=1; i<f ; i++){
            img[i]=img[i-1]+cols;
        } 
        for (int i=0; i<f; i++){
            for(int j=0; j<c; j++){
                img[i][j]=0;
            }
        }

    }
}

Imagen::~Imagen(){
    this->filas=0;
    this->cols=0;
    liberar();
}

int Imagen::num_filas()const{
   return filas;
}

int Imagen::num_columnas()const{
    return cols;
}

void Imagen::asigna_pixel(int fila, int col, byte valor){
    if(0<=fila && fila<filas && 0<=col && col<cols && 0<=valor && valor <=255){
        img[fila][col]=valor;
    }
}

byte Imagen::valor_pixel(int fila, int col) const{
if( fila < num_filas() &&  fila >= 0 && col < num_columnas() && col >= 0 )
    return img[fila][col];
}

void Imagen::leer_imagen(unsigned char * c, int nfilas, int ncolumns){
   
    liberar();
    reservar(nfilas, ncolumns);
    
    for (int i=0; i<nfilas; i++){
        for (int j=0; j<ncolumns; j++){
            img[i][j]=c[i*ncolumns+j];
        }
    }
}

unsigned char * Imagen::escribir_imagen(int &nfilas, int &ncolumns){
    unsigned char * c=new unsigned char[(this->filas)*(this->cols)];
    nfilas=this->filas;
    ncolumns=this->cols;
    int pixel;
    for (int i=0; i<nfilas; i++){
        for (int j=0; j<ncolumns; j++){
            c[(i*ncolumns)+j]=this->valor_pixel(i, j) ;
            
        }
    }

    return c;
}

double Imagen::valor_min(){
    int valor_actual=0, valor_min=img[0][0];

        for (int i=0; i< filas;i++){
            for(int j=0; j<cols; j++){
                valor_actual=img[i][j];
                
                if(valor_actual<valor_min){
                    valor_min=valor_actual;
                }
                
                
            }
        }
        cout << "VALOR MINIMO: "<< valor_min<< endl;
        return valor_min;
}
double Imagen::valor_max(){
    int valor_max=img[0][0],valor_actual=0;

        for (int i=0; i< filas;i++){
            for(int j=0; j<cols; j++){
                valor_actual=img[i][j];
                if(valor_actual>valor_max){
                    valor_max=valor_actual;
                }
            }
        }
        cout << "VALOR: "<< valor_max<< endl;
    return valor_max;    
}