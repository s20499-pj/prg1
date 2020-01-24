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
      if(playground[i][j].getIsShip()==true && playground[i][j].getIsShot()==true) cout << " " << "X";
      else if(playground[i][j].getIsShip()==true && playground[i][j].getIsShot()==false) cout << " " << "M";
      else if(playground[i][j].getIsShip()==false && playground[i][j].getIsShot()==true) cout << " " << "o";
      else if(playground[i][j].getIsShip()==false && playground[i][j].getIsShot()==false) cout << " " << "~";
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
      if(y>=0 || x>=0 || x<10 || y<10){
	if(r==0){
	  if(playground[y-1][x+i].getIsShip()==true && (y-1>=0 && x+i>=0 && x+i<10 && y-1<10)) empty_field=false;
	  if(playground[y][x+i].getIsShip()==true && (y>=0 && x+i>=0 && x+i<10 && y<10)) empty_field=false;
	  if(playground[y+1][x+i].getIsShip()==true && (y+1>=0 && x+i>=0 && x+i<10 && y+1<10)) empty_field=false;
	}
	else{
	  if(playground[y+i][x-1].getIsShip()==true && (y+i>=0 && x-1>=0 && x-1<10 && y+i<10)) empty_field=false;
	  if(playground[y+i][x].getIsShip()==true && (y+i>=0 && x>=0 && x<10 && y+i<10)) empty_field=false;
	  if(playground[y+i][x+1].getIsShip()==true && (y+i>=0 && x+1>=0 && x+1<10 && y+i<10)) empty_field=false;
	}
      }
      else ;
    }
  }
  else empty_field=false;
  return empty_field;
}

void Board::shot(Board *my_board, Board *target_board){
  int m=5;
  int n=5;
  char key=' ';
  Board cpmap;
  do{
    system("clear");
    my_board->draw();
    cout << endl;
    
    for(int i=0; i<100; i++){
      if(target_board->playground[i/10][i%10].getIsShot()==true)cpmap.playground[i/10][i%10].setIsShot(true);
      cpmap.playground[m][n].setIsShot(true);
    }
    for(int i=0; i<100; i++){
      if (m==i/10 && n==i%10){
        cout << " 0";
        }
      else{
        if (target_board->playground[i/10][i%10].getIsShot()==false) cout << " ~";
        else if(target_board->playground[i/10][i%10].getIsShot()==true && target_board->playground[i/10][i%10].getIsShip()==true) cout << " X";
        else if (target_board->playground[i/10][i%10].getIsShot()==true && target_board->playground[i/10][i%10].getIsShip()==false) cout << " o";
        else cout << "Er";
        }
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
      if(target_board->playground[m][n].getIsShot()==false){
        target_board->playground[m][n].setIsShot(true);
      //sprawdź czy statek jest zniszczony
      if(target_board->playground[m][n].getIsShip()==true) checkdestroy(target_board, m, n);
      key='q';
      }
      break;
    }
  }
  while(key!='q');
}

bool endgame(Board player){
  bool end = true;
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){ //jeżeli znajduje choć jeden statek niezestrzelony gra toczy się dalej
      if(player.playground[i][j].getIsShip()==true && player.playground[i][j].getIsShot()==false) end=false;
    }
  }
  return end;
}

void checkdestroy(Board *target_board, int m, int n){
  bool destroy = true;
  Board oneship;
  int i;
  
  i=0;
  while (true){
    if(target_board->playground[m+i][n].getIsShip()==true){
      oneship.playground[m+i][n]=target_board->playground[m+i][n];
      i++;
    }
    else break;
  }
  i=0;
  while (true){
    if(target_board->playground[m-i][n].getIsShip()==true){
      oneship.playground[m-i][n]=target_board->playground[m-i][n];
      i++;
    }
    else break;
  }
  i=0;
  while (true){
    if(target_board->playground[m][n+i].getIsShip()==true){
      oneship.playground[m][n+i]=target_board->playground[m][n+i];
      i++;
    }
    else break;
  }
  i=0;
  while (true){
    if(target_board->playground[m][n-i].getIsShip()==true){
      oneship.playground[m][n-i]=target_board->playground[m][n-i];
      i++;
    }
    else break;
  }

  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
      if (oneship.playground[i][j].getIsShip()==true && oneship.playground[i][j].getIsShot()==false){
        destroy=false;
      }
    }
  }
  if(destroy==true){
    for (int i = 0; i < 10; i++){
      for (int j = 0; j < 10; j++){
        if(oneship.playground[i][j].getIsShip()==true){
          if(i+1>=0 && i+1<10 && j >=0 && j<10) target_board->playground[i+1][j].setIsShot(true);
          if(i+1>=0 && i+1<10 && j+1>=0 && j+1<10) target_board->playground[i+1][j+1].setIsShot(true);
          if(i+1>=0 && i+1<10 && j-1>=0 && j-1<10) target_board->playground[i+1][j-1].setIsShot(true);
          if(i>=0 && i<10 && j+1>=0 && j+1<10) target_board->playground[i][j+1].setIsShot(true);
          if(i>=0 && i<10 && j-1>=0 && j-1<10) target_board->playground[i][j-1].setIsShot(true);
          if(i-1>=0 && i-1<10 && j+1>=0 && j+1<10) target_board->playground[i-1][j+1].setIsShot(true);
          if(i-1>=0 && i-1<10 && j >=0 && j<10) target_board->playground[i-1][j].setIsShot(true);
          if(i-1>=0 && i-1<10 && j-1>=0 && j-1<10) target_board->playground[i-1][j-1].setIsShot(true);
        }
      }
    }
  }
}
