#include <iostream>
//#include <string>
#include "board.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

Board::Board(){
  for(int m=0; m<10; m++){
    for(int n=0; n<10; n++){
      board[m][n]='~';
    }
  }
}
/*void Board::change(char x, int m, int n){
  board[m][n]=x;
}
void Board::print(int m, int n){
  cout << board[m][n];
  }*/
void Board::draw(){
  for(int m=0; m<10; m++){
    for(int n=0; n<10; n++){
      cout << " " << board[m][n];
    }cout << endl;
  }
}

string Board::boardtostring(){
  string x;
  for(int i=0; i<100; i++){
    x += board[i/10][i%10];
  }
  return x;
}

/*void Board::stringtoboard(string x){
  for(int i=0; i<100; i++){
    board[i/10][i%10]=x;
  }
  }*/



void Board::shot(){
  int m=5;
  int n=5;
  char key=' ';
  char cpmap[10][10];
  do{
    system("clear");
    for(int i=0; i<100; i++) cpmap[i/10][i%10] = board[i/10][i%10];
    cpmap[m][n]='0';
    for(int i=0; i<100; i++){
      cout << " " << cpmap[i/10][i%10];
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
      if(m<10) m++;
      break;
    case 'd':
      if(n<(10)) n++;
      break;
    case 13:        //enter
      //if(pudło){
	board[m][n]='o';
	//}
      //elseif(trafiony)
      //  elseif(trafione zatop)
        
      key='q';
      break;
    }
  }
  while(key!='q');
  //player << this->boardtostring();
}

void Board::setships(int size){
  int m=5;
  int n=5;
  int r=0;
  char key=' ';
  char cpmap[10][10];
  do{
    system("clear");
    for(int i=0; i<100; i++) cpmap[i/10][i%10]=board[i/10][i%10];
    if(r==0){
      for(int i=0; i<size; i++) cpmap[m][n+i]='M';
      for(int i=0; i<100; i++){
	cout << " " << cpmap[i/10][i%10];
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
	if(n<(10-size)) n++;
	break;
      case 'r':
	m=5;
	n=5;
	if(r==0) r++;
	else r--;
	break;
      case 13:        //enter
	if(this->checksetships(size, m, n, r)==true){
	  for(int i=0; i<size; i++) board[m][n+i]=cpmap[m][n+i];
	  key='q';
	}
	break;
      }
    }
    else{
      for(int i=0; i<size; i++) cpmap[m+i][n]='M';
      for(int i=0; i<100; i++){
	cout << " " << cpmap[i/10][i%10];
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
	if(m<(10-size)) m++;
	break;
      case 'd':
	if(n<9) n++;
	break;
      case 'r':
	m=5;
	n=5;
	if(r==0) r++;
	else r--;
	break;
      case 13:        //enter
	if(this->checksetships(size, m, n, r)==true){
	  for(int i=0; i<size; i++) board[m+i][n]=cpmap[m+i][n];
	  key='q';
	}
	break;
      }
    }
  }
  while(key!='q');
}
bool Board::checksetships(int size, int y, int x, int r){
  bool okey=true;
  if(r==0){
    for (int i=-1; i<size+1; i++){
      if(board[y-1][x+i]!='M' && okey==true);
      else{
	okey=false;
      }
    }
    for (int i=-1; i<size+1; i++){
      if(board[y][x+i]!='M' && okey==true);
      else{
	okey=false;
      }
    }
    for (int i=-1; i<size+1; i++){
      if(board[y+1][x+i]!='M' && okey==true);
      else{
	okey=false;
      }
    }
  }
  else{
    for (int i=-1; i<size+1; i++){
      if(board[y+i][x-1]!='M' && okey==true);
      else{
	okey=false;
      }
    }
    for (int i=-1; i<size+1; i++){
      if(board[y+i][x]!='M' && okey==true);
      else{
	okey=false; 
      }
    }
    for (int i=-1; i<size+1; i++){
      if(board[y+i][x+1]!='M' && okey==true);
      else{
	okey=false;
      }
    }

  }
  return okey;

}
