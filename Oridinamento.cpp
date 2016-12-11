////////////////////////////ORDINAMENTO////////////////////////

#include <iostream>
#include <fstream>

using namespace std;

int main (){

//Variabili
float dato, min=10000000, bicchierevuoto;
char file[100], file2[100];
bool ok;
int nletture=0, ncolonne, nrighe, indicedelminimo=0;                          //Settaggio del minimo a un numero molto grande, in teoria, per essere precisi, si dovrebbe cercare il massimo e porlo uguale al minimo

//Titolo
cout<<"\n";
cout << "\033[1;3;32mQuesto programma legge i dati da un file, che siano stati messi a tabella e li ordina in modo crescente secondo la prima colonna\033[0m\nPremi Invio per andare avanti\n";

cin.ignore();               //Il programma si arresta fin quando non viene premuto invio

cout<<"Scrivi il nome del file che vuoi leggere:"<<endl;
cin>>file2;

cout<<"Scrivi il nome del file su cui vuoi scrivere: (Se non esiste verrà creato)"<<endl;
cin>>file;

cout<<"Vuoi vedere i dati ordinati? (Si=1; No=0)"<<endl;
cin>>ok;

ifstream leggimi(file2);
ofstream scrivo(file);

while(!leggimi.eof()){
	leggimi>>dato;

	if(!leggimi.eof()){
		nletture++;
	}
}

leggimi.close();
leggimi.open(file2);

cout<<"Quante colonne ci sono nel file?\n";
cin>>ncolonne;

nletture=nrighe;
double tabellina [nrighe/ncolonne][ncolonne];                //creiamo la matrice [indice di riga][indice di colonna]

for(int i=0; i<nrighe/3; i++){
  for(int j=0; j<3; j++){                                    //3 colonne
    leggimi>>tabellina[i][j];
  }
}

leggimi.close();

///////////ORDINAMENTO/////////////////////////////
///////////SE CI SONO PI COLONNE///////////////////
///////////ORDINA SOLO LA PRIMA////////////////////
///////////DA COMPLETARE///////////////////////////

for(int partenza=0; partenza<(nrighe/3-1); partenza++){
    min=10000000;

    for(int i=partenza; i<nrighe/3; i++){
        if(min>tabellina[i][0]){
        min=tabellina[i][0];
        indicedelminimo=i;
        }
    }

    for (int k=0; k<3; k++){                    //prima colonna
    bicchierevuoto=tabellina[indicedelminimo][k];
    tabellina[indicedelminimo][k]=tabellina[partenza][k];
    tabellina[partenza][k]=bicchierevuoto;
    }

    if(ok==1){
        cout<<tabellina[partenza][0]<<"  "<<tabellina[partenza][1]<<"  "<<tabellina[partenza][2]<<endl; //Scrittura dei numeri ordinati sul terminale
    }
    scrivo<<tabellina[partenza][0]<<"  "<<tabellina[partenza][1]<<"  "<<tabellina[partenza][2]<<endl; //Scrittura sul file
}

ifstream leggimi2(file);
leggimi2.open(file);

if(leggimi2.is_open()){
cout<<"\033[1;3;32m\nIl file è stato scritto correttamente su \033[0m"<<file<<endl;

}

else{
    cout<<"\033[1;3;32mRiprovaci\033[0m"<<endl;
}
leggimi2.close();

return 0;
}

