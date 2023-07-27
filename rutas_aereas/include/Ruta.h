/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 /

/ 
 * File:   Ruta.h
 * Author: Antonio QH & Pablo
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

    Ruta();
    Ruta(string codigo);
    Ruta(const Ruta& orig);
    void aniadirPunto(const Punto &p);
   
   
    Punto getPuntoOrigen();
    Punto getPuntoDestino();
    string GetCodigo();


   friend istream& operator>> (istream &is, Ruta &leido);
   friend ostream& operator<< (ostream & os, Ruta & d);


};


 

#endif 
