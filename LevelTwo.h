#ifndef __LEVELTWO_H__
#define __LEVELTWO_H__
#include "Player.h"
#include <iostream>

class Board;

class LevelTwo: public Player{
  public:
    LevelTwo(Colour c);
    void move(Board &b) override;
    ~LevelTwo() = default;
};

#endif
