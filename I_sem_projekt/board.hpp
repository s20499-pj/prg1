#ifndef board_hpp
#define board_hpp
using std::string;

class Board{
  char board [10][10];
public:
  Board();
  //void change(char x, int m, int n);
  //void print(int m, int n);
  void draw();
  string boardtostring();
  void stringtoboard(string x);
  void shot();
  void setships(int size);
  bool checksetships(int size, int y, int x, int r);

};
#endif
