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
    cout << "Ruch gracza A" << endl;
    Board::shot(&boardA, &boardB);
    if(endgame(boardB)==true){
      system("clear");
      cout << endl << "Gracz pierwszy wygrał";
      break;
    }
    cout << "Ruch gracza B" << endl;
    Board::shot(&boardB, &boardA);
    if(endgame(boardA)==true){
      system("clear");
      cout << endl << "Gracz drugi wygrał";
      break;
    }
  }

  // analiza ruchu - strzał czy celny i czy zniszczyl statek i czy koniec gry

  system("stty sane -brkint -imaxbel iutf8");
  wait=getchar();
  return 0;
}