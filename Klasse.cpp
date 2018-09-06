#include <iostream>

class Elevator {
private:
  int aktuelleEtage;
  int maxEtage;
  int minEtage;
public:
  Elevator(int minEtage,int maxEtage){
    if(minEtage > maxEtage)
    {
      throw "Der min Wert muss kleienr als der max Wert sein";
    }
    this->maxEtage = maxEtage;
    this->minEtage = minEtage;
  }

  void init(int minEtage, int maxEtage){
    this->maxEtage = maxEtage;
    this->minEtage = minEtage;
  }

  int GetAktuelleEtage(){
    return aktuelleEtage;
  }

  void Move(int destination){
    if(destination < this->minEtage){
      printf("Das Ziel muss größer als die MinEtage(%i)\n", this->minEtage);
    }else if(destination > this->maxEtage){
      printf("Das Ziel muss kleiner als die maxEtage(%i)\n", this->maxEtage);
    }else{
      aktuelleEtage = destination;
      printf("Sie haben die %i Etage erreicht.\n", this->aktuelleEtage);
    }
  }
};

int main(int argc, char const *argv[]) {
  try{
    Elevator* ele = new Elevator(0, -1);

    //printf("aktuelleEtage: %i\n", ele->GetAktuelleEtage());
    ele->Move(10);
    //printf("aktuelleEtage: %i\n", ele->GetAktuelleEtage());
    ele->Move(100);
    ele->Move(-1);
    //printf("aktuelleEtage: %i\n", ele->GetAktuelleEtage());
    ele->Move(2);
    ele->Move(0);
    ele->Move(9);
    delete ele;
    return 0;
  }catch(char const* s){
    printf("%s\n", s);
  }
}
