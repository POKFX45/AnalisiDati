///////////////////////////////SEMPLICE LETTURA DA UN FILE////////////////////

#include <iostream> 			
#include <fstream>				//Libreria per ifstream e ofstream

using namespace std;

int main () {

ifstream leggimi;				//Funzione per leggere dai file
leggimi.open("");			 	//Inserire tra le virgolette il nome del file con l'estensione, 
								//ed eventualmente anche il percorso
								
float dato; 					//Variabile su cui verrà caricato il dato letto

for (int i=0; i<10; i++){

	leggimi>>dato;				
	cout<<dato<<endl;			

}

leggimi.close();				//Chiude il file aperto

return 0;
}
