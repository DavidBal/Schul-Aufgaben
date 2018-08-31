#include <iostream>
using namespace std;

void Zahl(int zahl){
		int  myZahl = zahl + 1;
    printf("Abstieg: %i \n", myZahl);
		if (myZahl < 10){
			Zahl(myZahl);
		}
		printf("Aufstieg: %i \n", myZahl);
  }

  int main(){
    Zahl(0);
  }
