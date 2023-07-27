/**
 * @file : guiatlf.h
 * @brief: TDA guia de telefonos
 * */
 

#ifndef _GUIA_TLF_H
#define _GUIA_TLF_H
#include <map>
#include <iostream>
#include <string>
using namespace std;

istream & operator>>(istream &is,pair<string,string> &d){
	  
	  getline(is,d.first,'\t');
	  getline(is,d.second);
	  return is;
}	  

ostream & operator<<(ostream &os,const pair<const string,string> &d)
{
	 os<<d.first<<'\t'<<d.second<<endl;  
	 return os;
}

/**
 * @brief TDA Guia_tlf
 * 
 * @author Pablo Borrego
 * @date Diciembre 2020
**/
class Guia_Tlf{
	  private:
		    map<string,string> datos; //si admites que haya nombres repetidos tendr�as que usar un
					     //multimap
					     
	  public:
		    //Guia_Tlf(){}
		    //Guia_Tlf(const Guia_Tlf & gt);
		    //~Guia_Tlf(){}
		    //Guia_Tlf & operator=(const Guia_Tlf & gt);
		    /**
		      @brief Acceso a un elemento
		      @param nombre: nombre del elemento  elemento acceder
		      @return devuelve el valor asociado a un nombre, es decir el teléfono
		    */
		    string & operator[](const string &nombre) {
			      return datos[nombre];
		    }
		    
		    
		    string  getTelefono(const string & nombre);
			   
		     
		    /**
		     @brief Insert un nuevo telefono 
		     @param nombre: nombre clave del nuevo telefono
		     @param tlf: numero de telefono
		     @return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf o false en caso contrario
		    */
		    pair<map<string,string>::iterator,bool>  insert(string nombre, string tlf);
		    
		    /**
		     @brief Insert un nuevo telefono 
		     @param p: pair con el nombre y el telefono asociado
		     
		     @return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf o false en caso contrario
		    */
		    pair<map<string,string>::iterator,bool>  insert(pair<string,string> p);  
		    
		    
		    /**
		      @brief Borrar un telefono
		      @param nombre: nombre que se quiere borrar
		      @note: en caso de que fuese un multimap borraria todos con ese nombre
		    */
		    void borrar(const string &nombre);
		    
		    /**
		      @brief Borrar un telefono
		      @param nombre: nombre que se quiere borrar y telefono asociado
		      @note: esta funcion nos permite borrar solamente aquel que coincida en nombre y tlf
		    */
		    //con map siempre hay uno con multimap puede existir mas de uno
		    void borrar(const string &nombre,const string &tlf);


		    /**
		      @brief  Numero de telefonos 
		      @return el numero de telefonos asociados
		     */
		    int size()const{
			      return datos.size();
		    }	      
		    /**
		      @brief Contabiliza cuantos telefonos tenemos asociados a un nombre
		      @param nombre: nombre sobre el que queremos consultar
		      @return numero de telefonos asociados a un nombre
		      
		     */
		    //al ser un map debe de ser 0 o 1. Si fuese un multimap podr�amos tener mas de uno
		    unsigned int contabiliza(const string &nombre){
			      return datos.count(nombre);
		    }
		    
		    /**
		      @brief Limpia la guia
		     */
		    void clear(){
			      datos.clear();
		    }	      
		    /**
		      @brief Union de guias de telefonos
		      @param g: guia que se une
		      @return: una nueva guia resultado de unir el objeto al que apunta this y g
		    */
		    Guia_Tlf operator+(const Guia_Tlf & g){
			Guia_Tlf aux(*this);
			map<string,string>::const_iterator it;
			for (it=g.datos.begin();it!=g.datos.end();++it){
			   aux.insert(it->first,it->second);
			}	  
			return aux;
			
		    }	   
		    	      
		    /**
		      @brief Diferencia de guias de telefonos
		      @param g: guia que se une
		      @return: una nueva guia resultado de la diferencia del objeto al que apunta this y g
		    */
		    Guia_Tlf operator-(const Guia_Tlf & g){
			Guia_Tlf aux(*this);
			map<string,string>::const_iterator it;
			for (it=g.datos.begin();it!=g.datos.end();++it){
			   aux.borrar(it->first,it->second);
			}	  
			return aux;
			
		    }
		    
		    /**
		      @brief Escritura de la guia de telefonos
		      @param os: flujo de salida. Es MODIFICADO
		      @param g: guia de telefonos que se escribe
		      @return el flujo de salida
		     */ 
		      
		    
		    friend ostream & operator<<(ostream & os, Guia_Tlf & g){
			      map<string,string>::iterator it;
			      for (it=g.datos.begin(); it!=g.datos.end();++it){
					os<<it->first<<"\t"<<it->second<<endl;
			      }
			      return os;
		    }
		    

			/**
			 * @brief Obtiene una guia de telefonos con los nombres previos a uno dado
			 * @param nombre: nombre que delimita
			 * @param tlf : telefono asociado
			 * @return nueva guia
			 **/
			Guia_Tlf previos(const string &nombre, const string &tlf);
			 



		    /**
		      @brief Lectura de  la guia de telefonos
		      @param is: flujo de entrada. ES MODIFICADO
		      @param g: guia de telefonos. ES MODIFICADO
		      @return el flujo de entrada
		    */
		    
		    friend istream & operator>>(istream & is, Guia_Tlf & g){
			      pair<string,string> p;
			      Guia_Tlf aux;
			      
			      while (is>>p){
				  aux.insert(p);
			      }
			      g=aux;
			      return is;
		    }

			/**
			 * @brief Busca los contactoss que empiezan por la letra dada
			 * @param letra: la letra 
			 * @return Devuelve una guia con los contactos que empiezan por dicha letra
			 * 
			 **/

			Guia_Tlf buscarPorInicial(char letra);
		    
			/**
			 * @brief Busca contactos que empiecen por el numero dado
			 * @param numero: El numero por el que buscar 
			 * @return Devuelve una guia que contenga los numeros que empiezan por el dado
			 **/ 
			
			Guia_Tlf buscarPorNumero(int numero);
			      
			/**
			 * @brief Obtiene la primera letra de un nombre dado
			 * @param nombre: primer componente del pair de map
			 * @return Devuelve un char que contiene la primera letra de un nombre dado
			 **/ 	  
		    
			char obtenerInicial(const string &nombre){
				return (char)toupper(nombre[0]);
			}

			/**
			 * @brief Obtiene el primer digito de un numero dado
			 * @param numero: segunda componente del pair del map
			 * @return Devuelve un char del primer digito del numero dado
			 **/ 

			int obtenerPrimerDigito(const string &numero){
				char num = (char)(numero[0]);
				return ((int)num -48);
			}

			/**
			 * @brief Clase iteradora de la guia
			 **/ 
			class iterator{
				private:
					map<string,string>::iterator it;
				public:
				iterator & operator++(){
				    ++it;    
				}    
				iterator & operator--(){     
					--it;    
				}    
				pair<const string,string> &operator *(){     
					return *it;    
				}    
				bool operator ==(const iterator &i){     
					return i.it==it;    
				}    
				bool operator !=(const iterator &i){     
					return i.it!=it;    
				}    
				friend class Guia_Tlf;    
			};	


			/**
			 * @brief Inicializa un iterador al comienzo de la guia
			 **/ 
			iterator begin(){
				iterator i;
				i.it=datos.begin();
				return i;
			}

			/**
			 * @brief Inicializa un iterador al final de la guia 
			 **/ 
			iterator end(){
				iterator i;
				i.it=datos.end();
				return i;

			}




};

#endif

