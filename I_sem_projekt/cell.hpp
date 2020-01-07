#ifndef cell_hpp
#define cell_hpp

class Cell{
  Cell();
private:
  bool IsShip;
  bool IsShot;
public:
  bool getIsShip();
  void setIsShip(bool);
  bool getIsShot();
  void setIsShot(bool);  
};
#endif
