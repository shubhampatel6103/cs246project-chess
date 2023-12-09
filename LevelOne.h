#ifndef __LEVELONE_H__
#define __LEVELONE_H__
#include "Player.h"
#include <iostream>

class Board;

class LevelOne: public Player{
  public:
    LevelOne(Colour c);
    void move(Board &b) override;
    ~LevelOne() = default;
};

#endif
