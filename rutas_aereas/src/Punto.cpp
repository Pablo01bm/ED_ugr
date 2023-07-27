/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 /

/ 
 * File:   Punto.cpp
 * Author: Antonio QH
 * 
 * Created on 3 de enero de 2021, 12:07
 */

#include "Punto.h"
#include <string>
#include <iostream>
using namespace std;

Punto::Punto() {
    x = 0;
    y = 0;
}

Punto::Punto(const Punto &orig) {
    x = orig.x;
    y = orig.y;
}


Punto::Punto(double x, double y){
    this->x = x;
    this->y = y;
}


void Punto::setPunto(double x, double y){
    this->x = x;
    this->y = y;
}


void Punto::setPuntox(double x){
        this->x = x;
}
 
 
void Punto::setPuntoy(double y){
        this->y = y;
}

Punto Punto::getPunto(){
    return *this;
}

double Punto::GetLongitud(){
    return y;
}

double Punto::GetLatitud(){
    return x;
}

string Punto::mostrarPunto(){
    string s;
    string xc = std::to_string(x);
    string yc = std::to_string(y);


    s = "(" + xc + "," + yc + ")";
    return s;
}

Punto &Punto::operator=(const Punto &p){
        this->x = p.x;
        this->y = p.y;

    return *this;
}

bool Punto::operator==(const Punto &p) const {

    return (this->y==p.y && this->x==p.x);

}

istream& operator>> (istream &is, Punto &leido){
    string parentesis, parentesis2, coma;
    string x1, y1;
    
    is >> parentesis ;
    
    is >> x1 >> coma >> y1 >> parentesis2; 

    leido.setPuntox(stod(x1));
    leido.setPuntoy(stod(y1));
    
  

    return is;

}
ostream& operator<< (ostream & os,  const Punto & d){

        Punto aux=d;

    os << aux.mostrarPunto();

    return os;

}