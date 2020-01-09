#ifndef cell_hpp
#define cell_hpp

class Cell{
private:
  bool IsShip;
  bool IsShot;
public:
  Cell();
  bool getIsShip();
  void setIsShip(bool);
  bool getIsShot();
  void setIsShot(bool);  
};
#endif
