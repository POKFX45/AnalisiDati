//Author F. Zarzaca 10 Nov 2016
//Debugged by G. Mandaglio 11 Nov 2016

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std; 

int main (){
float trovami;	


char file[100];
char file2[100];

cout<<"\n";
cout << "\033[1;3;32mQuesto programma legge i dati da un file, che siano stati messi a tabella e li ordina in modo crescente secondo la prima colonna\033[0m\n"<<endl;



cin.ignore();

cout<<"Scrivi il nome del file che vuoi leggere:"<<endl;
cin>>file2;

cout<<"Scrivi il nome del file su cui vuoi scrivere:"<<endl;
cin>>file;

bool ok;
cout<<"Vuoi vedere i dati ordinati?"<<endl;
cin>>ok;

ifstream leggimi(file2);
ofstream scrivo(file);
int numerodiletture=0;//quanto è lunga la colonna
while(!leggimi.eof()){//gli dico di leggermi il file (trovami)
	leggimi>>trovami;
	if(!leggimi.eof()){
		numerodiletture++;
	}
}			
leggimi.close();//lo chiudiamo

leggimi.open(file2);
double tabellina [numerodiletture/3][3];//creiamo la matrice [indice di riga][indice di colonna] 
for(int i=0; i<numerodiletture/3; i++){//numerodiletture=righe
  for(int j=0; j<3; j++){ //3 colonne
    leggimi>>tabellina[i][j];
    //cout<<tabellina[i][j]<<"  "; //modifico per rendere la stampa oridinata
  }
//cout<<endl;
}
leggimi.close();


double min=10000000; //DEVE ESSERE UN REALE 
int indicedelminimo =0;

double bicchierevuoto;

    for(int partenza=0; partenza<(numerodiletture/3-1); partenza++)
{
    min=10000000;  //è importantissimo mettere questa condizione
  for(int i=partenza; i<numerodiletture/3; i++){ 
  if(min>tabellina[i][0]){min=tabellina[i][0]; indicedelminimo=i;}
}


//prima colonna
bicchierevuoto=tabellina[indicedelminimo][0];
tabellina[indicedelminimo][0]=tabellina[partenza][0];
tabellina[partenza][0]=bicchierevuoto;
//seconda colonna
bicchierevuoto=tabellina[indicedelminimo][1];
tabellina[indicedelminimo][1]=tabellina[partenza][1];
tabellina[partenza][1]=bicchierevuoto;
//tenza colonna
bicchierevuoto=tabellina[indicedelminimo][2];
tabellina[indicedelminimo][2]=tabellina[partenza][2];
tabellina[partenza][2]=bicchierevuoto;
if(ok==1){
cout<<tabellina[partenza][0]<<"  "<<tabellina[partenza][1]<<"  "<<tabellina[partenza][2]<<endl;
}
scrivo<<tabellina[partenza][0]<<"  "<<tabellina[partenza][1]<<"  "<<tabellina[partenza][2]<<endl;
}

ifstream leggimi2(file);
leggimi.open(file);

if(leggimi.is_open()){
cout<<"\nIl file è stato scritto correttamente su "<<file<<endl;
}
leggimi.close();

return 0;
}

