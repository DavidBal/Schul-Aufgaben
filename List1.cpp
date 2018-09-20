/**
 * -----------------------------------------------------------------------------
 * Autor: David Bal.
 * Datum: 31.08.2018
 * -----------------------------------------------------------------------------
 * Aufgabe 1  - Durchschnittsberechnung mit Ausgabe der Werte ueber dem Durchschnitt und variabler Werteanzahl.
 * Aufgabe 3a - Ausgabe vorwaerts(procedure, iterativ; lokaler Startpointer, ganze Liste)
 * Aufgabe 3b - Ausgabe rückwaerts(procedure, iterativ; lokaler Startpointer, ganze Liste)
 * Aufgabe 4a - Ausgabe vorwaerts(procedure, rekusiv, ganze Liste);
 * Aufgabe 4b - Ausgabe rückwaerts(procedure, rekusiv, ganze Liste);
 * Aufgabe 6a - Pointer ** Eingabe(procedure, iterativ);  Unterprogramm frei(procedure, iterativ)
 * Aufgabe 6b - Refrence *& Eingabe(procedure, iterativ);  Unterprogramm frei(procedure, iterativ)
 * Aufgabe 7a - Unterprogramm AusgabeListe mit Adressen (procedure, rekusiv)
 * Aufgabe 7b - Unterprogramm frei(procedure, rekursiv);
 * TODO Aufgabe 5, 7
**/

#include <iostream>
using namespace std;

struct ListElement {
  int value;
  struct ListElement* next;
};

struct ListElement* AddElementToList(struct ListElement* first, int value);
void ShowAllValuesInListIterativ(struct ListElement* first);
void ShowAllValuesInListIterativStartBack(struct ListElement* first);
void ClearList(struct ListElement** first);
int  GetListAverageValue(struct ListElement* first);
struct ListElement* FillListWithNumbers(struct ListElement* first,int count);
void ShowListValueRekursiv(struct ListElement* item, bool forward, int position=0);
void ShowAllValuesBiggerThenValue(struct ListElement* first, int value);
void AddElementToListRefernce(struct ListElement*& first, int value);
void AddElementToListPointer(struct ListElement** first, int value);
void ClearListRefrence(struct ListElement*& first);
void FreeListRekursiv(struct ListElement** pointer );

int main()
{
  struct ListElement* first = NULL;
  int menue = 0;
  do{
    std::cout << "Welche Funktion wollen Sie ausführen?" << endl;
    std::cout << "1 - item hinzufügen (5 a)" << endl;
    std::cout << "2 - Füge 10 Elemente in die Liste" << endl;

    std::cout << "3 - Durchschnitt (Aufgabe 1)" << endl;


    std::cout << "4 - Liste ausgeben Vorwärts Iterativ (Aufgabe 3 a)" << endl;
    std::cout << "5 - Liste ausgeben Rückwärts Iterativ (Aufgabe 3 b)" << endl;

    std::cout << "6 - Liste ausgeben Vorwärts Rekursiv (Aufgabe 4 a, 7 a)" << endl;
    std::cout << "7 - Liste ausgeben Rückwärts Rekursiv (Aufgabe 4 b)" << endl;

    std::cout << "8 - Element hinzufügen Pointer (Aufgabe 6 a)" << '\n';
    std::cout << "9 - Element hinzufügen Refrence (Aufgabe 6 b)" << '\n';

    std::cout << "10 - Liste leeren (5 b)" << endl;
    std::cout << "11 - Liste leeren Recursiv (7 b)" << '\n';
    std::cout << "0 - Beenden (Die Liste wird freigeben)" << endl;
    cin >> menue;
    int value = 0;
    int average = 0;
    switch ( menue) {
      case 0:
        break;
      case 1:
          printf("Bitte einen Wert eingeben: ");
          cin >> value;
          first = AddElementToList(first, value);
          break;
      case 2:
          first = FillListWithNumbers(first,10);
          break;

      case 3:
          average = GetListAverageValue(first);
          printf("Durchschnitt: %i\n", average);

          ShowAllValuesBiggerThenValue(first, average);
          break;

      case 4:
          ShowAllValuesInListIterativ(first);
          break;
      case 5:
          ShowAllValuesInListIterativStartBack(first);
          break;

      case 6:
          ShowListValueRekursiv(first, true);
          break;
      case 7:
          ShowListValueRekursiv(first, false);
          break;

      case 8:
          printf("Bitte einen Wert eingeben: ");
          cin >> value;
          AddElementToListPointer(&first, value);
          break;
      case 9:
        printf("Bitte einen Wert eingeben: ");
        cin >> value;
        AddElementToListRefernce(first, value);
        break;
      case 10:
        ClearList(&first);
        break;
      case 11:
        FreeListRekursiv(&first);
        break;
      default:
        menue = 10000;
        break;
    }
  } while(menue != 0);
  ClearList(&first);
}

struct ListElement* AddElementToList(struct ListElement* first, int value)
{
  //1. Create a new Element
  struct ListElement* tmp = NULL;
  tmp = (struct ListElement*) malloc (sizeof(struct ListElement));

  if(tmp != NULL){
    tmp->value = value;
    //3. set next
    tmp->next = first;
    //4. set first pointer to new item
    first = tmp;
  }
  tmp = NULL;
  return first;
}

void ShowAllValuesInListIterativ(struct ListElement* first)
{
  printf("Listen Inhalt: \n");
  struct ListElement* tmp = first;
  int counter = 0;
  while(tmp != NULL){
    printf("Pos:%i | Value:%i\n", counter, tmp->value);

    tmp = tmp->next;
    counter++;
  }
  tmp = NULL;
}

void ShowAllValuesBiggerThenValue(struct ListElement* first, int value)
{
  printf("Listen Inhalt: \n");
  struct ListElement* tmp = first;
  int counter = 0;
  while(tmp != NULL){
    if(tmp->value < value)
    {
      printf("Pos:%i | Value:%i\n", counter, tmp->value);
    }
    tmp = tmp->next;
    counter++;
  }
  tmp = NULL;
}

void ShowAllValuesInListIterativStartBack(struct ListElement* first)
{
  int count = 0;
  struct ListElement* tmp = first;
  if(tmp != NULL){
    while ( tmp->next != NULL) {
      count += 1;
      tmp = tmp->next;
    }

    for(int i = 0; i<=count; i++)
    {
      tmp = first;
      for(int h = 0; h < (count-i); h++)
      {
        tmp = tmp->next;
      }
      printf("Pos:%i | Value:%i\n", count-i, tmp->value);
    }
  }
}

int GetListAverageValue(struct ListElement* first)
{
  struct ListElement* tmp = first;
  int counter = 0;
  int value = 0;
  std::cout << "Test" << '\n';
  while(tmp != NULL)
  {
    value += tmp->value;
    counter += 1;
    tmp = tmp->next;
  }
  if(counter > 0)
  {
    return (value / counter);
  } else {
    return 0;
  }
}

void ClearList(struct ListElement** first)
{
  struct ListElement* tmp= *first;
  while(tmp != NULL){
    *first = tmp->next;
    free(tmp);
    tmp = *first;
  }
  tmp = NULL;
}

void ClearListRefrence(struct ListElement*& first)
{
  struct ListElement* tmp= first;
  while(tmp != NULL){
    first = tmp->next;
    free(tmp);
    tmp = first;
  }
  tmp = NULL;
}


struct ListElement* FillListWithNumbers(struct ListElement* first,int count)
{
  for(int i = 1; i <= count; i++)
  {
      first = AddElementToList(first, i);
  }
  return first;
}

void ShowListValueRekursiv(struct ListElement* item, bool forward, int position)
{
  if(item != NULL)
  {
    if(forward)
    {
      printf("Pos:%i | Adress:%p | Value:%i\n", position, item, item->value);
    }
    ShowListValueRekursiv(item->next, forward, position+1);
    if(!forward)
    {
      printf("Pos:%i | Value:%i\n", position, item->value);
    }
  }
}

void AddElementToListPointer(struct ListElement** first, int value){
  //1. Create a new Element
  struct ListElement* tmp = NULL;
  tmp = (struct ListElement*) malloc (sizeof(struct ListElement));

  if(tmp != NULL){
    tmp->value = value;
    //3. set next
    tmp->next = *first;
    //4. set first pointer to new item
    *first = tmp;
  }
  tmp = NULL;
}

void AddElementToListRefernce(struct ListElement*& first, int value){
  //1. Create a new Element
  struct ListElement* tmp = NULL;
  tmp = (struct ListElement*) malloc (sizeof(struct ListElement));

  if(tmp != NULL){
    tmp->value = value;
    //3. set next
    tmp->next = first;
    //4. set first pointer to new item
    first = tmp;
  }
  tmp = NULL;
}
//first->()->()->NULL
void FreeListRekursiv(struct ListElement** pointer )
{
  if(*pointer != NULL)
  {
    FreeListRekursiv(&((*pointer)->next));
    free(*pointer);
    *pointer = NULL;
  }
}
