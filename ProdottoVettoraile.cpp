///////////////////////////PRODOTTO VETTORIALE///////////////////////////

#include <iostream>

using namespace std;

float vettore1[3]={4,5,6};
float vettore2[3]={9,5,9};
float vettore3[3]={45,32,7};
float prodv=0;

int main () {

for (int i=0; i<3; i++){
	prodv= prodv + vettore1[i]*vettore2[i];
}

cout<<somma<<endl;

return 0;
}
