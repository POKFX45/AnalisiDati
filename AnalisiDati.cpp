#include <iostream> //librearia di cout e cin
#include <fstream> //libreria per ifstream e ofstream
#include <cmath> //libreria per la potenza, e altre funzioni matematiche


using namespace std; //serve a non usare std:: ogni volta 


int main(){

ifstream leggimi;

float dato,media,sigma;
float somm=0;
int ndati=0;
bool a;
float sq=0;


char file[100]; //il nome del file non potrà essere più lungo di 100 caratteri

top://serve a far tornare qua il programma in caso di errore

cout<<"\nInserisci il nome del file che vuoi aprire\n";
cin>>file;

leggimi.open(file); //apre il file

if(leggimi.is_open()){//controlla se il file è aperto

cout<<"\nVuoi far apparire a schermo tutti i valori del file? (1=si/0=no)"<<endl;
cin>>a;

//legge e conta quanti numeri ci sono nel file

while(!leggimi.eof()){
leggimi>>dato;
if(!leggimi.eof()){
ndati++; //ogni volta che legge un dato aumenta ndati di 1
if(a==true){
cout<<dato<<endl;}

//fa la sommatoria
somm=somm+dato;
}
}

cout<<"\nNel file ci sono "<<ndati<<" numeri"<<endl;
cout<<"La somma di tutti numeri è uguale a "<<somm<<endl;

//calcolo della media
media=somm/ndati;
cout<<"\nIl valore medio è "<<media<<endl;


leggimi.close();
//chiude e riapre il file in modo da riportarsi all'inizio
leggimi.open(file);

float misure[ndati]; //vettore lungo per quanti sono i dati nel file

//calcolo dello scarto quadratico medio, formula riscritta come algoritmo
for (int j=0; j<ndati; j++){
leggimi>>misure[j];

sq=sq+pow(misure[j]-media,2);
}


sigma=pow(sq/ndati,0.5);
leggimi.close();

cout<<"Lo scarto quadratico medio equivale a "<<sigma<<endl;


float min, max;

//inizializzazione dei valori di min e max al valore di misure[0]
min=misure[0];
max=misure[0];
int k;
//qui cerca qual'è il più grande e il più piccolo valore all'interno del file
for(k=0; k<=ndati; k++){
if(min>misure[k])   {min=misure[k]; /* prova cont=k;*/};
if(max<misure[k])   max=misure[k];

};

/* prova cout<<"Contatore "<<cont<<endl;
cout<<"prova vettore 127005"<<misure[127005]<<endl; */

cout<<"\nIl valore minimo trovato è "<<min<<endl;
cout<<"Il valore massimo trovato è "<<max<<endl;




//Ordinamento dei valori, 

int me, indicemin,start, t;
start=0;
float min2,zero;
bool lovoglio;

cout<<"\nVuoi vedere i dati in modo ordinato? (si=1/no=0)\n\n";
cin>>lovoglio;
if(lovoglio==1){

cout<<"\nOrdinamento dei valori\n";
for(start=0; start<=ndati; start++){
min2=max;
indicemin=start;
for(me=start; me<=ndati; me++){
if(min2>misure[me])   {min2=misure[me]; /*cout<<"me    =   "<<me<<endl;*/ indicemin=me; };
     }

//cout<<"misure posto 0   "<<misure[zero]<<endl;//cout<<"varia    "<<varia[0]<<endl;
zero=misure[indicemin];
misure[indicemin]=misure[start];
misure[start]=zero;


cout<<misure[start]<<"; ";
//cout<<"sstart= "<<start<<endl;
//cout<<"prova n"<<zero<<"   "<<misure[zero]<<endl;

};

}


//Inizio calcoli istogramma
float intervallino;
int nbin;

cout<<"\nIn quanti intervalli vuoi divisa la distanza (max-min)?\n";
cin>>nbin;

int bin[nbin];

//inizializza il valore di ogni elemento del vettore a 0
for(int phi=0; phi<nbin; phi++)
bin[phi]=0;

//calcolo della lunghezza di ogni intervallo
intervallino=(max-min)/float(nbin);
cout<<"\nIl tuo intervallo è lungo "<<intervallino<<"\n\n";

//inserimento di ogni valore nel suo intervallo
for(int lol=0; lol<ndati; lol++){

for(int phi=0; phi<nbin; phi++)
if(misure[lol]>min+phi*intervallino && misure[lol]<min+(phi+1)*intervallino)bin[phi]++;

}

bool si, si2;

cout<<"Per vedere quanti punti cadono in ogni intervallo inserisci 1:\n";
cin>>si;
if(si==true){
for(int phi=0; phi<nbin; phi++){
cout<<"Nell'intervallo "<<phi<<" cadono "<<bin[phi]<<" punti"<<endl;}

//aggiornamento istogramma prof
cout<<"\n\nSono l'aggiornamento del prof\n\n"<<endl;
for (int i =0 ;i<nbin;i++)
cout<<min+intervallino/2+i*intervallino<<" "<<bin[i]<<endl;

//fine programma
cout<<"\nIl programma è finito :)\nSe vuoi ricominciare inserisci 1\n";
cin>>si2;
if(si2==true){goto top;}

}
else {cout<<"\nIl programma è finito :)\nSe vuoi ricominciare inserisci 1, se no 0\n";
cin>>si2;
if(si2==true){goto top;}
}
}

//nel caso il file non si fosse aperto esegue questo comando e torna all'inizio
else {cout<<"\nIl file che cerchi non esiste\n";
goto top;}


return 0;


}
