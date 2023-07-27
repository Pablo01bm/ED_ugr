/**
  * @file Pilamax.cpp
  * @brief Implementaci�n del TDA Pila
  *
  */

#include <cassert>

 #include <Pilamax.h>  //El codigo ya se incluye en pila.h

/* _________________________________________________________________________ */

template <class T>
Pilamax<T>::Pilamax(const Pilamax<T> & otra){
  if (otra.primera!=0){            //Si la pila original no est� vac�a
    Celda *p = otra.primera;       //Copio el puntero al primer nodo
    Celda *nueva;
    primera = 
    nueva = new Celda(p->elemento,0); //Creamos el primer nodo
    p = p->siguiente;                 //Avanzamos el puntero
    while (p!=0){                                  //Mientras queden elementos
      nueva->siguiente = new Celda(p->elemento,0); //Creamos un nuevo nodo
      nueva = nueva->siguiente;                    //Avanzamos los punteros
      p = p->siguiente;
    }
  }
  else                              //Si la pila original est� vac�a
    primera = 0;
  num_elem = otra.num_elem;     //En cualquier caso, copiamos num_elem
}

/* _________________________________________________________________________ */

template <class T>
Pilamax<T>::~Pilamax(){
  Celda *aux;
  while (primera!=0){              //Mientras la pila no est� vac�a,
    aux = primera;                 //Copiamos el puntero al tope de la pila
    primera = primera->siguiente;  //Avanzamos primera
    delete aux;                    //Borramos el nodo de la lista
  }
}

/* _________________________________________________________________________ */

template <class T>
Pilamax<T>& Pilamax<T>::operator=(const Pilamax<T> & otra){
  Celda * p;
  
  if (this!=&otra){    //Comprobaci�n de rigor. Si son diferentes objetos
    while (primera!=0){    //Borramos la lista de nodos de la pila *this
      p = primera;
      primera = primera->siguiente;
      delete p;
    }
    if (otra.primera!=0){        //Si la otra pila tiene elementos
      p = otra.primera;          //Copiamos el puntero al primero nodo
      Celda *nueva;
      primera = nueva = new Celda(p->elemento,0);//Reservamos el primer nodo
      p = p->siguiente;                             //Avanzamos el puntero
      while (p!=0){                                 //Mientras queden elementos
        nueva->siguiente = new Celda(p->elemento,0); //Creamos un nuevo nodo
        nueva = nueva->siguiente;                   //Avanzamos nueva (auxiliar)
        p = p->siguiente;                           //Avanzamos el puntero
      }
    }
    num_elem=otra.num_elem;      //En cualquier caso, copiamos num_elem
  }
  return *this; //Devolvemos el objeto para permitir el encadenamiento (a=b=c)
}

/*_________________________________________________________________________ */

template <class T>
void Pilamax<T>::poner(const T & elem){
  Elemento elemento(elem);
  primera = new Celda(elem,primera); //Creamos un nuevo nodo en el tope
  int max;

  if(num_elem>0){
    if(elem>=primera->siguiente->elemento.maximo)
      max=elem;
    else
      max = primera->siguiente->elemento.maximo;
    primera->elemento.maximo=max;
  } else {
    primera->elemento.maximo=primera->elemento.elem;
  }
  num_elem++;                        //Actualizamos num_elem
}

/* _________________________________________________________________________ */

template <class T>
void Pilamax<T>::quitar(){
  assert(primera!=0);           //Si la pila no tiene elementos, abortar
  Celda *p = primera;           //Copiamos el puntero al tope
  primera = primera->siguiente; //Actualizamos primera
  delete p;                     //Borramos el nodo que ocupaba el tope
  num_elem--;                   //Actualizamos num_elem
}
