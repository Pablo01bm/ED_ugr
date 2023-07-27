/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 /

/ 
 * File:   Ruta.h
 * Author: Antonio QH
 *
 * Created on 3 de enero de 2021, 12:25
 */

#ifndef ALMACENRUTA_H
#define ALMACENRUTA_H


#include <Ruta.h>
#include <vector>


using namespace std;

class AlmacenRutas {
private:

    vector<Ruta> rutas;
    string codigo;

public:

/**
  * @brief constructor de AlmacenRutas
  *  
  */
    AlmacenRutas();


/**
  * @brief constructor de copia
  * 
  */
    AlmacenRutas(const AlmacenRutas& orig);


/**
  * @brief añade una ruta al almacen de rutas
  *
  * @param p 
  *  
  * @return void
  */
    void aniadirRuta(const Ruta &p);


/**
  * @brief cambia los valores x e y
  *
  * @param codigo codigo de la ruta
  * @return devuelve la ruta con el codigo proporcionado
  */   
    Ruta GetRuta(string codigo);


/**
  * @brief operador >> de la clase AlmacenRutas
  * 
  */
    friend istream& operator>> (istream &flujo, AlmacenRutas &leido);


/**
  * @brief operador << de la clase AlmacenRuta
  * 
  */
    friend ostream& operator<< (ostream & os,  AlmacenRutas & d);


};

   



#endif