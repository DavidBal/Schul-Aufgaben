#include <iostream>
using namespace std;

template <class T>
class Element{
private:
  T value;
  Element<T>* next;
  Element<T>* prev;
public:
  Element (T value){
    this->value = value;
    this->next = NULL;
    this->prev = NULL;
  }

  Element (T value, Element<T>* next): Element(value){
    this->next = next;
  }

  Element (T value, Element<T>* next, Element<T>* prev): Element(value, prev){
    this->prev = prev;
  }


};

template <class T>
class List{
private:
  Element<T>* first;
  Element<T>* last;

public:
  List (){
    this->first = NULL;
    this->last = NULL;
  }

  void Add(T newElement){
    if (this->last == NULL && this->first == NULL)
    {
      new Element<>();
    }else if(this->last == NULL || this->next == NULL){

    }
  }

};

int main(){

}
