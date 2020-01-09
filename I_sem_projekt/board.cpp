#include <iostream>
#include "board.hpp"
#include "cell.hpp"

using std::cout;
using std::endl;

Board::Board(){
  for(int i=0; i<100; i++){
    this->playground[i/10][i%10] = Cell();
  }
  //nrplayer=nr;
}


// mozesz dodac argument kto to wyswietla

void Board::draw(){
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      if(playground[i][j].getIsShip()==true) cout << " " << "M";
      else cout << " " << "~";
    }
    cout << endl;
  }
}

void Board::setships(int size){
  int m=5;
  int n=5;
  int r=0;
  char key=' ';
  Board cpmap;
  do{
    system("clear");
    for(int i=0; i<100; i++){
      cpmap.playground[i/10][i%10]=playground[i/10][i%10];
    }
    for(int i=0; i<size; i++){
      if(r==0) cpmap.playground[m][n+i].setIsShip(true);
      else     cpmap.playground[m+i][n].setIsShip(true);
    }
    cpmap.draw();
    
    cout << "wasd - sterowanie" << endl;
    cout << "r - obróć" << endl;
    cout << "q - pomin" << endl;
    cout << "Enter - zatwierdź" << endl;

    key=getchar();
    switch(key){
    case 'w':
      if(m>0) m--;
      break;
    case 'a':
      if(n>0) n--;
      break;
    case 's':
      if(r==0){
        if(m<9) m++;
      }
      else {
        if(m<(10-size)) m++;
      }
      break;
    case 'd':
      if(r==0) {
        if(n<(10-size)) n++;
      }
      else {
        if(n<9) n++;
      }
      break;
    case 'r':
      m=5;
      n=5;
      if(r==0) r++;
      else r--;
      break;
    case 13:        //enter                                                                                                                                             
      if(this->checksetships(size, m, n, r)==true){
        for(int i=0; i<size; i++){
          if(r==0) playground[m][n+i]=cpmap.playground[m][n+i];
          else     playground[m+i][n]=cpmap.playground[m+i][n];
        }
        key='q';
        break;
      }
    }
  }
  while(key!='q');
}

bool Board::checksetships(int size, int y, int x, int r){
  bool empty_field=true;
  if(empty_field==true){    
    for (int i=-1; i<size+1; i++){
      if(y>=0 || x>=0 || y<10 || y<10){
	if(r==0){
	  if(playground[y-1][x+i].getIsShip()==true) empty_field=false;
	  if(playground[y][x+i].getIsShip()==true) empty_field=false;
	  if(playground[y+1][x+i].getIsShip()==true) empty_field=false;
	}
	else{
	  if(playground[y+i][x-1].getIsShip()==true) empty_field=false;
	  if(playground[y+i][x].getIsShip()==true) empty_field=false;
	  if(playground[y+i][x+1].getIsShip()==true) empty_field=false;
	}
      }
      else ;
    }
  }
  else empty_field=false;
  return empty_field;
}


/*void Board::shot(){
  int m=5;
  int n=5;
  char key=' ';
  Board cpmap;
  do{
    system("clear");
    this->draw();
    cout << endl;
    
    for(int i=0; i<100; i++) cpmap.playground[i/10][i%10] = playground[i/10][i%10];
    cpmap.playground[m][n].setIsShot(true);
    for(int i=0; i<100; i++){
      if(cpmap.playground[i/10][i%10].getIsShot()==true) cout << " X";
      else cout << " ~";
      if(i%10==9) cout << endl;
    }
    key=getchar();
    switch(key){
    case 'w':
      if(m>0) m--;
      break;
    case 'a':
      if(n>0) n--;
      break;
    case 's':
      if(m<9) m++;
      break;
    case 'd':
      if(n<9) n++;
      break;
    case 13:        //enter
      playground[m][n].setIsShot(true);
      key='q';
      break;
    }
  }
  while(key!='q');
}*/

void shot(Board my_board, Board target_board){
  int m=5;
  int n=5;
  char key=' ';
  Board cpmap;
  do{
    system("clear");
    my_board.draw();
    cout << endl;
    
    for(int i=0; i<100; i++) cpmap.playground[i/10][i%10] = target_board.playground[i/10][i%10];
    cpmap.playground[m][n].setIsShot(true);
    for(int i=0; i<100; i++){
      if(cpmap.playground[i/10][i%10].getIsShot()==true) cout << " X";
      else cout << " ~";
      if(i%10==9) cout << endl;
    }
    key=getchar();
    switch(key){
    case 'w':
      if(m>0) m--;
      break;
    case 'a':
      if(n>0) n--;
      break;
    case 's':
      if(m<9) m++;
      break;
    case 'd':
      if(n<9) n++;
      break;
    case 13:        //enter
      target_board.playground[m][n].setIsShot(true);
      key='q';
      break;
    }
  }
  while(key!='q');
}