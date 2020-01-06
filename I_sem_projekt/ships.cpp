#include <iostream>
#include "board.hpp"
//#include "file.hpp"
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::fstream;

int main(){
  system("stty raw opost"); // zmiana stty 
  Board board;
  Board player;
  Board enemy;


  
  //dodawanie statków   
  board.setships(4);
  /*board.setships(3);
    board.setships(3);
    board.setships(2);
    board.setships(2);
    board.setships(2);
    board.setships(1);
    board.setships(1);
    board.setships(1);
    board.setships(1);

    WYŁĄCZONE DO TESTOW
  */ 

    //stworzenie pliku
  system("touch .shipstmp");
  system("chmod 744 .shipstmp");
  fstream shipstmp;
  shipstmp.open( ".shipstmp", std::ios::in | std::ios::out );
  /*  if( shipstmp.good() == true )
    {
      cout << "Uzyskano dostep do pliku!" << endl;
      shipstmp << player.boardtostring();
    }
    else cout << "Dostep do pliku zostal zabroniony!" << endl;*/

  
  //zaczekanie na przeciwnika
  //bitwa

  int licznik=0;
  do{
    player.shot();
    licznik++;
    //czekaj na przeciwnika
  }
  while(licznik<3);
  
  //wynik

  //usunięcie plików
  shipstmp.close();
  //system("rm .shipstmp");
  
  // stty default
  system("stty sane -brkint -imaxbel iutf8");
  int a;
  cin >>a;
  return 0;	
}

