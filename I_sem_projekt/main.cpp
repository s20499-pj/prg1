#include <iostream>
#include "board.hpp"

using std::cout;
using std::endl;
using std::cin;


bool endgame(Board player){
  bool end = true;
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){ //jeżeli znajduje choć jeden statek niezestrzelony gra toczy się dalej
      if(player.playground[i][j].getIsShip()==true && player.playground[i][j].getIsShot()==false) end=false;
    }
  }
  return end;
}

int main(){
  int wait;
  system("stty raw opost");

  Board boardA;
  Board boardB;
  Board *pointer_a = &boardA;
  Board *pointer_b = &boardB;

  int n;
  int* np = &n; // pointer to int
  int* const* npp = &np; // non-const pointer to const pointer to non-const int
  
  int a[2];
  int (*ap)[2] = &a; // pointer to array of int
  
  struct S { int n; };
  S s = {1};
  int* sp = &s.n; // pointer to the int that is a member of s

  struct Base {};
  struct Derived : Base {};
  
  Derived d;
  Base* p = &d;





  //playerA.setships(2);
  cout << "Player 1" << endl;
  boardA.setships(2);
  cout << "Player 1" << endl;

  cout << "teaz player drugi" << endl;

  cin >> wait;

  //playerB.setships(2);
  cout << "Player 2" << endl;
  boardB.setships(2);
  cout << "Player 2" << endl;

  cout << "rozpocznij grę" << endl;
  cin >> wait;

  system("clear");


  while (true){
    //ruch gracza A
    Board::shot(&boardA, &boardB);
    //Board::shot(pointer_a, pointer_b);

    //sprawdź czy playerB nie żyje
    if(endgame(boardB)==true){
      cout << "gracz A wygrał";
      break;
    }
    //ruch gracza B
    Board::shot(&boardB, &boardA);
    //Board::shot(pointer_b, pointer_a);
    //sprawdź czy playerA nie żyje
    if(endgame(boardA)==true){
      cout << "gracz B wygrał";
      break;
    }
  }
  
  // sprawdz wyswietlanie planszy usera1 i usera2 nawzajem

  // analiza ruchu - strzał czy celny i czy zniszczyl statek i czy koniec gry

  system("stty sane -brkint -imaxbel iutf8");
  cin >>wait;
  return 0;
}