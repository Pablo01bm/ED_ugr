#include "Ruta.h"
#include "Punto.h"
#include <vector>

using namespace std;

Ruta::iterator Ruta::begin(){
    return ruta.begin();
}

Ruta::iterator Ruta::end(){
    return ruta.end();
}

Ruta::const_iterator Ruta::end() const {
    return ruta.cend();
}

Ruta::const_iterator Ruta::begin() const {
    return ruta.cbegin();
}




Ruta::Ruta() {
    codigo="";
}

Ruta::Ruta(string codigo){
    this->codigo=codigo;
}



Ruta::Ruta(const Ruta& orig) {

    this->ruta.clear();
    
        for( int i=0 ; i < orig.ruta.size() ; i++){
            ruta.push_back(orig.ruta[i]);
        }
    
    this->codigo=orig.codigo;
    
}

void Ruta::aniadirPunto(const Punto &p){

   // Ruta::iterator it;
   // *it=p;
    ruta.push_back(p);

}


Punto Ruta::getPuntoOrigen(){
    Ruta::iterator it;
    *it=ruta.front();
    return *it;
}

Punto Ruta::getPuntoDestino(){
    Ruta::iterator it;
    *it=ruta.back();
    return *it;
}

string Ruta::GetCodigo(){
    return codigo;
}

istream& operator>> (istream &is, Ruta &leido){
    Ruta rlocal;
    string s, n;
    bool tope=false;
    int i=0;
	//leemos el comentario
    Punto P;

        is >> s;
        is >> n;
        leido.numeroPuntos=stoi(n);
        
	    while (is>>P && !tope){
		    leido.ruta.push_back(P);
            i++;
            if (i == leido.numeroPuntos-1)
                tope=true;
            
	    }
        leido.codigo=s;
	

      
	    return is;

        
        

}


ostream& operator<< (ostream & os,  Ruta & d){

   os << d.GetCodigo() << d.numeroPuntos ;

   for ( int i=0; i < d.numeroPuntos ; i++){
       os << d.ruta[i];
   }

   return os;

}

