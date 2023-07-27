/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 /

/ 
 * File:   Ruta.h
 * Author: Antonio QH & Pablo Borrego
 *
 * Created on 3 de enero de 2021, 12:25
 */

#ifndef RUTA_H
#define RUTA_H

#include <Punto.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;



class Ruta {
private:

    vector<Punto> ruta;
    string codigo;
    int numeroPuntos;

public:



    typedef vector<Punto>::iterator iterator;
    typedef vector<Punto>::const_iterator const_iterator;
    Ruta::const_iterator begin() const;
    Ruta::const_iterator end() const;
    Ruta::iterator begin();
    Ruta::iterator end();

/** 
*   @brief  Constructor por defecto de la clase ruta
*
**/
    Ruta();


/** 
*   @brief  Constructor con codigo
*   @param 1 El codigo de la ruta
**/
    Ruta(string codigo);

/** 
*   @brief  Constructor de copia
*   @param 1 La ruta a copiar
**/    
    Ruta(const Ruta& orig);

/** 
*   @brief  Funcion para añadir punto a la ruta actual
*   @param 1 El punto a añadir
**/    
    void aniadirPunto(const Punto &p);
   
/** 
*   @brief  Consultor del primer punto de la ruta
*   
**/
    Punto getPuntoOrigen();
/** 
*   @brief  Consultor del último punto de la ruta
*   
**/
    Punto getPuntoDestino();
/** 
*   @brief  Consultor del código de la ruta
*   
**/
    string GetCodigo();

/** 
*   @brief  Operador sobrecargado >> de la clase ruta
*   
**/
   friend istream& operator>> (istream &is, Ruta &leido);
/** 
*   @brief  Operador sobrecargado << de la clase ruta
*   
**/
   friend ostream& operator<< (ostream & os, Ruta & d);


};


 

#endif 
