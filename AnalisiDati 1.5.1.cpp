#include <iostream>     //librearia di cout e cin
#include <fstream>      //libreria per ifstream e ofstream
#include <cmath>        //libreria per la potenza, e altre funzioni matematiche


using namespace std;    //serve a non usare std:: ogni volta 


int main()
{

 ifstream leggimi;

 float dato,media,sigma;
 float somm=0;
 int ndati=0;
 bool a;
 float sq=0;


 char file[100];         //il nome del file non potrà essere più lungo di 100 caratteri

 top:                    //serve a far tornare qua il programma in caso di errore

 cout<<"\nInserisci il nome del file che vuoi aprire\n";
 cin>>file;

 leggimi.open(file);     //apre il file

 if(leggimi.is_open()){  //controlla se il file è aperto e quindi procede, se non è aperto si blocca e passa all'else che c'è a fine codice

  cout<<"\nVuoi far apparire a schermo tutti i valori del file? (1=si/0=no)"<<endl;
  cin>>a;

//In questa parte legge e conta quanti numeri ci sono nel file

  while(!leggimi.eof())
  {
       
   leggimi>>dato;
       
   if(!leggimi.eof())
   {
    ndati++;            //ogni volta che legge un dato aumenta ndati di 1
    if(a==true)         //if che serve a stampare tutti i dati
     {
     cout<<dato<<endl;
     }

                    
    somm=somm+dato;     //Qui fa la sommatoria di tutti i dati
   }
  }

  cout<<"\nNel file ci sono "<<ndati<<" numeri"<<endl;
  cout<<"La somma di tutti numeri è uguale a "<<somm<<endl;

//In questa parte il programma calcola la media dei valori
  media=somm/ndati;
  cout<<"\nIl valore medio è "<<media<<endl;


  leggimi.close();
  leggimi.open(file);   //chiude e riapre il file in modo da riportarsi all'inizio

  float misure[ndati];  //vettore lungo per quanti sono i dati nel file

//Questa parte calcola lo scarto quadratico medio
  for (int j=0; j<ndati; j++)
  {
   leggimi>>misure[j];

   sq=sq+pow(misure[j]-media,2);
  }

  sigma=pow(sq/ndati,0.5);
  leggimi.close();

  cout<<"Lo scarto quadratico medio equivale a "<<sigma<<endl;


  float min, max; 
  int k;
  min=misure[0];       //inizializzazione del valore min al valore di misure[0]
  max=misure[0];       //inizializzazione del valore min al valore di misure[0]
 
//In questa parte cerca il minimo e il massimoa assoluto
  for(k=0; k<=ndati; k++)
  {
   if(min>misure[k])   {min=misure[k]; /* prova cont=k;*/};
   if(max<misure[k])   max=misure[k];

  }

  cout<<"\nIl valore minimo trovato è "<<min<<endl;
  cout<<"Il valore massimo trovato è "<<max<<endl;

//In questa parte ordina i valori 

  int me, indicemin,start, t, cambio;
  float min2,zero;
  start=0;
      
  cout<<"\nVuoi vedere i dati in modo ordinato? (crescente=1/descrescente=0/no=qualsiasi altro numero)\n\n";
  cin>>cambio;

  switch(cambio)     //Serve a decidere quale ordinamento fare (crescente/decrescente)
  {
   case 0:

//Ordinamento in ordine crescente
   cout<<"\nOrdinamento dei valori\n";
            
   for(start=0; start<=ndati; start++)
   {
    min2=max;
    indicemin=start;
        
    for(me=start; me<=ndati; me++)
    {
     if(min2>misure[me])
     {
      min2=misure[me]; indicemin=me; 
     }
    }
  
     if (min2 != misure[start])
     {
     //Qui avviene la magia
     zero=misure[indicemin];
     misure[indicemin]=misure[start];
     misure[start]=zero;
    }

    cout<<misure[start]<<"; ";
   }

   break;
            
//Ordinamento dei valori in modo decrescente
    case 1:
     int max2;

     cout<<"\nOrdinamento dei valori\n";
     for(start=0; start<=ndati; start++)
     {
      max2=min;
      indicemin=start;
          
      for(me=start; me<=ndati; me++)
      {
           if(max2<misure[me])
      {
           max2=misure[me]; 
           indicemin=me; 
      }
      }



      if (min2 != misure[start])
      {
      zero=misure[indicemin];
      misure[indicemin]=misure[start];
      misure[start]=zero;
      }

     cout<<misure[start]<<"; ";

     };
   break;
   default: 
   break;
}

//Questa parte serve per creare un istogramma
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
  for(int lol=0; lol<ndati; lol++)
  {
  for(int phi=0; phi<nbin; phi++)
       if(misure[lol]>min+phi*intervallino && misure[lol]<min+(phi+1)*intervallino)
            bin[phi]++;

  }

  bool si, si2;

  cout<<"Vuoi vedere quanti punti cadono in ogni intervallo? (si=1/no=0)\n";
  cin>>si;
  if(si==true){
  for(int phi=0; phi<nbin; phi++){
  cout<<"Nell'intervallo "<<phi<<" cadono "<<bin[phi]<<" punti"<<endl;}

  //aggiornamento istogramma prof
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
  if(si2==true){
       goto top;
  }

}
else {
     cout<<"\nIl programma è finito :)\nSe vuoi ricominciare inserisci 1, se no 0\n";
     cin>>si2;
     if(si2==true){
          goto top;
     }
}
}
}

     //nel caso il file non si fosse aperto esegue questo comando e torna all'inizio
else {
     cout<<"\nIl file che cerchi non esiste\n";
     goto top;
}


return 0;


}
