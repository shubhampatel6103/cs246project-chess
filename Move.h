#ifndef __Move_H__
#define __Move_H__
#include "Player.h"
#include <iostream>

class Move {
  bool resign;
  int coords[4];
  public:
    Move(bool r, int sX, int sY, int dX, int dY);
    ~Move() = default;
    int* getCoords();
    void setMove(bool r, int sX, int sY, int dX, int dY);
};

#endif
