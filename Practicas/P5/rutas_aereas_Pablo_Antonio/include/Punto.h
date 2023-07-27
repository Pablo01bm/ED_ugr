
#include <string>
#include <vector>

#ifndef PUNTO_H
#define PUNTO_H

using namespace std;

class Punto{

private:
    double x;
    double y;

public:

/**
  * @brief Constructor sin parametros 
  */    
    Punto();

/**
  * @brief Constructor con puntos 
  *
  * @param x valor x
  * @param y valor y
  */
    Punto(double x, double y);

/**
  * @brief Constructor de copia
  */
    Punto(const Punto &p);

/**
  * @brief cambia los valores x e y
  *
  * @param x valor x
  * @param y valor y
  * @return void
  */
    void setPunto(double x, double y);

/**
  * @brief cambia los valores x 
  *
  * @param x valor x
  * @return void
  */
    void setPuntox(double x);

/**
  * @brief cambia los valores y
  *
  * @param x valor y
  * @return void
  */
    void setPuntoy(double y);

/**
  * @brief Obtener el punto
  *
  * @return Devuelve el punto
  *
  * @see Punto
  */
    Punto getPunto();

/**
  * @brief Devuelve la longitud
  * 
  * @return double de la longitud
  */
    double GetLongitud();

/**
  * @brief Devuelve la latitud
  * 
  * @return double de la latitud
  */
    double GetLatitud();

/**
  * @brief Nos muestra como string el punto
  * 
  * @return Devuelve un string con el punto, perfecto para hacer cout
  *
  * @see string
  */
    string mostrarPunto();

/**
  * @brief Operador = de la clase punto
  *
  * @see Punto
  */
    Punto & operator=(const Punto &p);

/**
  * @brief Operador == de la clase punto
  *
  * @see Punto
  */
    bool operator==(const Punto &p)const ;

/**
  * @brief Operador >> de la clase punto
  *
  * 
  */
   friend istream& operator>> (istream & is, Punto &leido);

/**
  * @brief Operador << de la clase punto
  *
  * 
  */
   friend ostream& operator<< (ostream & os, const Punto & d);

};


  



#endif 