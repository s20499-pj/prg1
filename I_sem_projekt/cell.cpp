#include <iostream>
#include "cell.hpp"

Cell::Cell(){
  this->IsShip = false;
  this->IsShot = false;
}

bool Cell::getIsShip(){
  return IsShip;
}

void Cell::setIsShip(bool s){
  IsShip = s;
}

bool Cell::getIsShot(){
  return IsShot;
}

void Cell::setIsShot(bool s){
  IsShot = s;
}
