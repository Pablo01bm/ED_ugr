#include "Diccionario.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){

  if (argc!=2){
      cout<<"Dime el nombre del fichero con el diccionario"<<endl;
      return 0;
   }


   ifstream f (argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }
   
   Diccionario mi_diccionario;
   f>>mi_diccionario; //Cargamos en memoria el diccionario
   //Usamos un iterador para recorrer los terminos del diccionario e imprimirlos
   Diccionario::const_iterator it; 
   for(it = mi_diccionario.begin(); it != mi_diccionario.end(); ++it){
     cout << (*it) << endl;
   }
   
   Diccionario reducido;
   //FUNCIONALIDADES
   
   cout << "SE MUESTRAN LAS DEFINICIONES ASOCIADAS A LA PALABRA AARON:" << endl;
   mi_diccionario.getDefiniciones("aaron");
   
   
   cout << "SE MUESTRA UN DICCIONARIO EN EL INTERVALO [a,a]: " << endl;
   reducido=mi_diccionario.Intervalo('a','a');
   for(it = reducido.begin(); it != reducido.end(); ++it){
     cout << (*it) << endl;
   }
   
  
   cout << "DICCIONARIO DE TERMINOS ASOCIADOS A COLOR: " << endl;
   reducido= mi_diccionario.FiltroClave("color");
   cout << reducido;
   
   cout << "RECUENTO:" << endl;
   mi_diccionario.Recuento();

}
