#include "guiatlf.cpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


int main(int argc, char * argv[]){
	//Comprobamos los parametos
	if (argc != 2){
		cout << "Introduzca el nombre del fichero"<<endl;
		return 0;
	}
	ifstream f(argv[1]);
	if (!f){
		cout << "Error al abrir el fichero "<< argv[1] << endl;
		return 0;
	}

Guia_Tlf g;
string nombre, telefono;

	f>>g;

 cout<<"La guia insertada "<<g<<endl;
 cin.clear();

 cout<<"Dime un nombre sobre el que quieres obtener el telefono"<<endl;
 string n;

 while (getline(cin,n)){
	   cout<<"Buscando "<<n<<"...."<<endl;
	   string tlf = g.getTelefono(n);
	   if (tlf==""){
		     cout<<"No existe ese nombre en la guia"<<endl;
	   }
	   else 
	    cout<<"El telefono es "<<tlf<<endl;
	   cout<<"[Ctrl+D]Dime un nombre sobre el que quieres obtener el telefono"<<endl;
 }	
 //Borrar contacto
 cin.clear();
 cout<<"Dime el nombre que quieres borrar"<<endl;
 
 
 while (getline(cin,n)){
	   g.borrar(n);
	   cout<<"Ahora la guia es:"<<endl;
	   cout<<g<<endl;
	   cout<<"Dime el nombre que quieres borrar"<<endl;
 }
 
 //Union y diferencia

 cin.clear();
 Guia_Tlf otraguia;
 string guia2;
 cout<<"Introduce otra guia"<<endl;

 getline(cin,guia2);
 ifstream f2(guia2);

 cin>>otraguia; cin.clear();
 Guia_Tlf un = g+otraguia;
 Guia_Tlf dif = (g-otraguia)+(otraguia-g);

 cout<<"La union de las dos guias: "<<endl <<un<<endl;
 
 cout<<"La diferencia de las dos guias:"<<endl <<dif<<endl;

 //Listar los contactos previos a un nombre dado
 
 cin.clear();  
 cout<<endl<<"Introduzca un nombre para establecer los previos"<<endl; 
 getline(cin,nombre);  
 telefono = g.getTelefono(nombre);  

 Guia_Tlf prev = g.previos(nombre,telefono);  
 cout<<endl<<"Los nombres previos al dado son: " << endl << prev << endl;

 //Insertar un contacto con su nombre y numero

 cin.clear();  
 cout << endl << "Introduce el nombre a insertar: " << endl;  
 while(getline(cin,nombre))
 {    
	cout << "Introduce el telefono de la persona que se va a insertar: " << endl;    
	getline(cin,telefono);
	while(telefono.size() != 9)
	{      
		cout << "El numero introducido no es correcto porque no es de 9 digitos, introduce un telefono con 9 digitos: " << endl;      
		getline(cin,telefono);    
	}
	g.insert(nombre,telefono);    
	cout<<"Ahora la guia es:"<<endl;    
	cout<<g<<endl;    
	cin.clear();    
	cout << "Introduce un nombre a insertar: " << endl;  
 }

 //Listar los contactos cuyo nombre empieze por una letra dada

 string laux;  
 char letra;  
 cin.clear();  
 cout << endl << "Introduce una letra para filtrar los contactos con ella: " << endl;
 
 while(getline(cin,laux))
 {    
	letra = laux[0];    
	Guia_Tlf inicial = g.buscarPorInicial(letra);    
	cout << "Los contactos que empieza por " << letra << " son: " << endl << inicial << endl;    
	cout << "Introduce una inicial para filtrar los contactos por esa inicial: " << endl;  

 }

// Listar los contactos cuyo telefono empiece por un numero dado

//string n;
int numero;
cin.clear();
cout << endl << "Introduce un numero para filtrar los contactos cuyo numero empieze por ese numero: " << endl;

while(getline(cin, n))
{
	numero = (int)n[0] - 48;    
	Guia_Tlf num = g.buscarPorNumero(numero);    
	cout << "Los contactos cuyo numero empieza por " << numero << " son: " << endl << num << endl;    
	cout << "Introduce un numero para filtrar los contactos cuyo numero empiece por ese numero: " << endl;

}

//Listar los contactos usando iteradores 

cout<<endl<<"Listando la guia con iteradores:"<<endl;  
Guia_Tlf::iterator it;  
for (it=g.begin(); it!=g.end(); ++it)  
	cout<<*it<<endl;


}	//FIN

