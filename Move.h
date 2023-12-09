#ifndef __Move_H__
#define __Move_H__
#include <iostream>

class Move {
  bool resign;
  int coords[4];
  public:
    Move(bool r, int sX, int sY, int dX, int dY);
    ~Move() = default;
    int* getCoords(); // Gets the array of integers storing the move coordinates
    bool getResigned();
    void setMove(bool r, int sX, int sY, int dX, int dY); // Sets up a 
};

#endif


