#include <iostream>

class Rolladen{
private:
  const int MAX = 100;
  const int MIN = 0;

  int open ;

public:
  Rolladen(){
    this->open = this->MIN;
  }

  int GetOpen(){
    return open;
  }

  void Open(){
    this->open = this->MIN;
  }

  void Close(){
    this->open = this->MAX;
  }

  bool Move(int value){
    if(value <= this->MAX && value >= this->MIN){
      this->open = value;
      return true;
    }else{
      return false;
    }
  }

  void ConsoleStatus(){
    printf("Der Rolladen ist zu %i%% geschlossen.\n", this->open);
  }


};

int main(int argc, char const *argv[]) {
  Rolladen rl;

  rl.ConsoleStatus();

  rl.Open();

  rl.ConsoleStatus();

  rl.Close();

  rl.ConsoleStatus();

  rl.Move(10);

  rl.ConsoleStatus();

  rl.Move(80);

  rl.ConsoleStatus();

  rl.Move(1000);

  rl.ConsoleStatus();
  return 0;
}
