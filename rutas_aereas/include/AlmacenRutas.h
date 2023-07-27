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
    
    AlmacenRutas();
    AlmacenRutas(const AlmacenRutas& orig);
    void aniadirRuta(const Ruta &p);
   
    Ruta GetRuta(string codigo);



    friend istream& operator>> (istream &flujo, AlmacenRutas &leido);
    friend ostream& operator<< (ostream & os,  AlmacenRutas & d);


};

   



#endif
