#ifndef board_hpp
#define board_hpp

#include "cell.hpp"

class Board{
public:
  static const int BOARD_SIZE = 10;
  Board();
  Cell playground[BOARD_SIZE][BOARD_SIZE];
  void draw();
  void setships(int size);
  bool checksetships(int size, int y, int x, int r);
  static void shot(Board *my_board, Board *target_board);

};
void checkdestroy(Board *, int m, int n);
bool endgame(Board player);

#endif