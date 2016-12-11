//////////////////////PUNTATORI//////////////////////

#include <iostream>
#include <fstream>

using namespace std; 

int main() {

double vettore[10]={1,2.34,3.68,67.1,4.34,5,6,7,9.65,7.8};

double* indice; 			//Creazione di un double a puntatore di nome "indice"
indice=vettore;				//Indice sarà uguale al vettore

cout<<*indice+3<<endl; 		//Stampa a schermo il numero all'indice 1 sommandogli 3

cout<<*(indice+3)<<endl; 	//Stampa il numero del vettore all'indice 1+3

return 0;
}
