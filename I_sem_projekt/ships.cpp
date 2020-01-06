#include <iostream>
#include "board.hpp"
#include <fstream>
#include <unistd.h>

using std::cout;
using std::cin;
using std::endl;
using std::fstream;


int main(){
  system("stty raw opost"); // zmiana stty 
  Board board; //plansza gracza
  Board player;//pole w które strzela gracz
  Board enemy; //pole w które strzela przeciwnik

  string pathtoenemy; //ścieżka do pliku przeciwnika
  cout << "Wpisz ścieżkę katalogu domowego przeciwnika" << endl;
  pathtoenemy = "/home/s20499/nauka/prg1/I_sem_projekt/.enemy";
  /*cin >> pathtoenemy;*/
  
  //dodawanie statków   
  board.setships(4);
  board.setships(3);

  //stworzenie pliku wymiany
  system("touch .shipstmp");
  system("chmod 744 .shipstmp");
  
  // kto zaczyna
  bool move;
  fstream fenemy;
  fenemy.open( pathtoenemy, std::ios::in );    
  if(fenemy.good()==true) move=1;
  else move=0;
  fenemy.close();

  //definicja ruchu przeciwnika
  void enemymove(){
    string estring = enemy.boardtostring();
    string tmp;
    bool endloop = 0;
    do{
      fenemy.open( pathtoenemy, std::ios::in );
      getline(fenemy, tmp);
      fenemy.close();
      for(int i=0; i<100 ; i++){
	if(estring[i]!=tmp[i]) endloop=1;
      }
      usleep(1000000);
    }
    while(endloop==0);
    enemy.stringtoboard(tmp);
  }

  //definicja ruchu gracza
  void playermove(){
    player.shot();
  }

  
  //gra
  int licznik=0;
  do{
    enemymove();
    playermove();
    licznik++;
    //przeczytaj plik przeciwnika
    //odpowiedz czy pudło czy trawił czy zniszczył
  }
  while(licznik<3);
  //wynik

  //usunięcie plików
  //  shipstmp.close();
  //system("rm .shipstmp");
  
  // stty default
  system("stty sane -brkint -imaxbel iutf8");
  int a;
  cin >>a;
  return 0;	
}

