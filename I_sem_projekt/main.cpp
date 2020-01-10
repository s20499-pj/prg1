#include <iostream>
#include "board.hpp"

using std::cout;
using std::endl;
using std::cin;

int main(){
  int wait;
  system("stty raw opost");

  Board boardA;
  Board boardB;

  while(true)
  {  
  system("clear");
  cout << "Gracz pierwszy rozkłada statki" << endl;
  cout << "Naciśnij enter by rozpocząć rozmieszczanie statków" << endl;
  wait=getchar();
  if(wait==13) break;
  }

  boardA.setships(4);
  boardA.setships(3);
  boardA.setships(3);
  boardA.setships(2);
  boardA.setships(2);
  boardA.setships(2);
  boardA.setships(1);
  boardA.setships(1);
  boardA.setships(1);
  boardA.setships(1);

  while(true)
  {
  system("clear");
  cout << "Teaz gracz drugi" << endl;
  cout << "Naciśnij enter by rozpocząć rozmieszczanie statków" << endl;
  wait=getchar();
  if(wait==13) break;
  }

  boardB.setships(4);
  boardB.setships(3);
  boardB.setships(3);
  boardB.setships(2);
  boardB.setships(2);
  boardB.setships(2);
  boardB.setships(1);
  boardB.setships(1);
  boardB.setships(1);
  boardB.setships(1);

    while(true)
  {
  system("clear");
  cout << "Aby rozpocząć grę naciśnij enter" << endl;
  wait=getchar();
  if(wait==13) break;
  }


  while(true){
    Board::shot(&boardA, &boardB);
    if(endgame(boardB)==true){
      system("clear");
      cout << endl << "Gracz pierwszy wygrał";
      break;
    }
    while(true){
      system("clear");
    cout << "Ruch gracza B, naciśnij enter" << endl;
    wait=getchar();
    if(wait==13) break;
    }

    Board::shot(&boardB, &boardA);
    if(endgame(boardA)==true){
      system("clear");
      cout << endl << "Gracz drugi wygrał";
      break;
    }
    while(true){
      system("clear");
    cout << "Ruch gracza A, naciśnij enter" << endl;
    wait=getchar();
    if(wait==13) break;
    }
  }

  system("stty sane -brkint -imaxbel iutf8");
  wait=getchar();
  return 0;
}