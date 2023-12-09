#ifndef __LEVELTHREE_H__
#define __LEVELTHREE_H__
#include "Player.h"
#include <iostream>

class Board;

class LevelThree: public Player{
  public:
    LevelThree(Colour c);
    void move(Board &b) override;
    ~LevelThree() = default;
};

#endif
