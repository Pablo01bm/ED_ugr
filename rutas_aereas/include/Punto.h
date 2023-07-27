

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

    
    
    Punto();
    Punto(double x, double y);
    Punto(const Punto &p);
    void setPunto(double x, double y);
    void setPuntox(double x);
    void setPuntoy(double y);
    Punto getPunto();
    double GetLongitud();
    double GetLatitud();
    string mostrarPunto();

    Punto & operator=(const Punto &p);
    bool operator==(const Punto &p)const ;

   friend istream& operator>> (istream & is, Punto &leido);
   friend ostream& operator<< (ostream & os, const Punto & d);

};


  



#endif 
