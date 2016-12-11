#include <iostream> 		//librearia di cout e cin
#include <fstream> 			//libreria per ifstream e ofstream
#include <cmath> 			//libreria per la potenza, e altre funzioni matematiche


using namespace std; 		//serve a non usare std:: ogni volta


int main(){

//Variabili
ifstream leggimi;
float dato,media,sigma, somm=0, sq=0;
int ndati=0;
bool a;
char file[100]; 			//il nome del file non potrà essere più lungo di 100 caratteri

top:						//serve a far tornare qua il programma in caso di errore

cout<<"\nInserisci il nome del file che vuoi aprire\n";
cin>>file;

leggimi.open(file); 		            //apre il file

if(leggimi.is_open()){		            //controlla se il file è aperto, se è aperto restituisce true

cout<<"\nVuoi far apparire a schermo tutti i valori del file? (1=si/0=no)"<<endl;
cin>>a;

                                        //lettura e conteggio dei numeri sul file
    while(!leggimi.eof()){
        leggimi>>dato;				    //variabile su viene caricato il dato
        if(!leggimi.eof()){
            ndati++; 					//contatore
            if(a==true){
            cout<<dato<<endl;
            }
        somm=somm+dato;                 //Sommatoria
        }
    }
leggimi.close();                        //Chiusura del file

media=somm/ndati;                       //calcolo della media

cout<<"\nNel file ci sono "<<ndati<<" numeri"<<endl;
cout<<"La somma di tutti numeri è uguale a "<<somm<<endl;
cout<<"\nIl valore medio è "<<media<<endl;

leggimi.open(file);                     //Riapertura del file

float misure[ndati]; 		            //vettore lungo per quanti sono i dati nel file

for (int j=0; j<ndati; j++){
    leggimi>>misure[j];                 //Carimento dei dati nel vettore
    sq=sq+pow(misure[j]-media,2);       //Calcolo di?
}

sigma=pow(sq/ndati,0.5);                //Calcolo della deviazione standard

leggimi.close();                        //Chiusura del file

cout<<"Lo scarto quadratico medio equivale a "<<sigma<<endl;

///////////////////////////////////////FINE PRIMA PARTE DEL PROGRAMMA////////////////////////////////////////

///////////////////////////////////////RICERCA DEL MINIMO E DEL MASSIMO//////////////////////////////////////

float min, max;

min=misure[0];                             //inizializzazione dei valori di min e max al valore di misure[0]
max=misure[0];

int k;                                      //Definizione del contatore fuori dal ciclo per (?)

for(k=0; k<=ndati; k++){                    //Ricerca del minimo e del massimo
    if(min>misure[k]){
        min=misure[k];
        /* prova cont=k;*/
    };
    if(max<misure[k]){
        max=misure[k];
    };
};

cout<<"\nIl valore minimo trovato è "<<min<<endl;
cout<<"Il valore massimo trovato è "<<max<<endl;

///////////////////////////////////////////FINE SECONDA PARTE///////////////////////////////////////

///////////////////////////////////////////ORDINAMENTO DEI VALORI///////////////////////////////////


int me, indicemin,start=0, t, cambio;
float min2, max2, zero;


cout<<"\nVuoi vedere i dati in modo ordinato?\n[0] In modo crescente\n[1] In modo descrescente\n[Qualsiasi altro numero]No\n";
cin>>cambio;

switch(cambio){
case 0:                                         //Ordinamento decrescente

cout<<"\nOrdinamento dei valori in modo decrescente\n";
for(start=0; start<=ndati; start++){

    min2=max;
    indicemin=start;

    for(me=start; me<=ndati; me++){
        if(min2>misure[me]){
            min2=misure[me];
            indicemin=me;
            };
     }

    if (min2!=misure[start]){                     //Swap dei valori per ordinarli
        zero=misure[indicemin];
        misure[indicemin]=misure[start];
        misure[start]=zero;
    }

cout<<misure[start]<<"; ";

};
break;

case 1:                                            //Ordinamento crescente

cout<<"\nOrdinamento dei valori\n";
for(start=0; start<=ndati; start++){

    max2=min;
    indicemin=start;

    for(me=start; me<=ndati; me++){
        if(max2<misure[me]){
            max2=misure[me];
            indicemin=me;
            };
     }

    if (min2 != misure[start]){
        zero=misure[indicemin];
        misure[indicemin]=misure[start];
        misure[start]=zero;
    }

cout<<misure[start]<<"; ";
};

break;

default:
cout<<"  "<<endl;
break;
}

//////////////////////////////////////FINE TERZA PARTE//////////////////////////////////

//////////////////////////////////////ISTOGRAMMA////////////////////////////////////////

float intervallino;
int nbin;

cout<<"\nIn quanti intervalli vuoi divisa la distanza (max-min)?\n";
cin>>nbin;

int bin[nbin];

for(int phi=0; phi<nbin; phi++){                  //inizializza il valore di ogni elemento del vettore a 0
    bin[phi]=0;
}

intervallino=(max-min)/float(nbin);                 //calcolo della lunghezza di ogni intervallo
cout<<"\nIl tuo intervallo è lungo "<<intervallino<<"\n\n";


for(int i=0; i<ndati; i++){                   //inserimento di ogni valore nel suo intervallo

    for(int phi=0; phi<nbin; phi++){
        if(misure[i]>min+phi*intervallino && misure[i]<min+(phi+1)*intervallino){
            bin[phi]++;
        }
    }

}

bool si, si2;

cout<<"Vuoi vedere quanti punti cadono in ogni intervallo? (Si=1/No=0)\n";
cin>>si;

if(si==true){
    for(int phi=0; phi<nbin; phi++){
    cout<<"Nell'intervallo "<<phi<<" cadono "<<bin[phi]<<" punti"<<endl;}

//Aggiornamento istogramma prof
    bool ok;

    cout<<"\nVuoi vedere l'aggiornamento del prof? (si=1/no=0)\n";
    cin>>ok;

    if(ok==1){
        cout<<"\n\nSono l'aggiornamento del prof\n\n"<<endl;
        for (int i =0 ;i<nbin;i++)
        cout<<min+intervallino/2+i*intervallino<<" "<<bin[i]<<endl;

                                                                            //fine programma
        cout<<"\nIl programma è finito :)\nSe vuoi ricominciare inserisci 1\n";
        cin>>si2;
        if(si2==true){goto top;}

        }
        else {
            cout<<"\nIl programma è finito :)\nSe vuoi ricominciare inserisci 1, se no 0\n";
            cin>>si2;
            if(si2==true){
                goto top;
                }
        }
}

}                                                           //Parentesi graffa dell'if iniziale che controlla se il file è aperto

else {
    cout<<"\nIl file che cerchi non esiste\n";            //nel caso il file non si fosse aperto esegue questo comando e torna all'inizio
    goto top;
}


return 0;


}
