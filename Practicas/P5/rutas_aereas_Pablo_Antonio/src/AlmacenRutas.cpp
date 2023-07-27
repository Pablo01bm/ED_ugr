#include "Ruta.h"
#include "Punto.h"
#include "AlmacenRutas.h"
#include <vector>



using namespace std;

AlmacenRutas::AlmacenRutas() {
    
}

AlmacenRutas::AlmacenRutas(const AlmacenRutas& orig) {

    this->rutas.clear();

        for(int i=0; i<orig.rutas.size() ; i++){
            rutas.push_back(orig.rutas[i]);
        }
    
    
}

void AlmacenRutas::aniadirRuta(const Ruta &p){
    rutas.push_back(p);

}

Ruta AlmacenRutas::GetRuta(string codigo){
    
bool encontrado=false;
Ruta ruta;


    for ( int i = 0; i < rutas.size() || !encontrado; i++){
        if (rutas[i].GetCodigo() == codigo  ){
            encontrado=true;
            ruta=rutas[i];
        }    
    }

    return ruta;

}

/*
istream & operator>>(istream & is, AlmacenRutas & R){
    
    Ruta rutaAct;
    string s;

    cout << "HOLAALAK;LAKLFJOAHFIANHFIANEIF"<<endl;

    if (is.peek() == '#'){
        string a;
        getline(is, a);
    }
    cout << "He leido el #"<< endl;
  
    while (is >> s){
        is >> rutaAct;
        R.rutas.push_back(rutaAct);
    }

    

    return is;

}
*/
istream &operator>>(istream &is, AlmacenRutas &R){
    bool tope=false;
    AlmacenRutas rlocal;

    //leemos el comentario
    if (is.peek() == '#'){
        string a;
        getline(is, a);
    }
    Ruta P;
    while (is >> P && !tope){
        
        rlocal.rutas.push_back(P);
        if (rlocal.rutas.size()==4)
            tope=true;
    }
    R = rlocal;
    return is;
}

ostream& operator<< (ostream & os,  AlmacenRutas & d){

    for (int i = 0; i < d.rutas.size(); i++){
        os << d.rutas.at(i);
    }

    return os;

}