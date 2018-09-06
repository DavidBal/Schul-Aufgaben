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

int Fakultaet(int zahl){
  if(zahl <= 1 ){
    return 1;
  }else{
    return zahl * Fakultaet(zahl-1);
  }
}

  int main(){
    Zahl(0);

    printf(" %i\n", Fakultaet(5));
  }
