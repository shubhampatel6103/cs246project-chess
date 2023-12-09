#ifndef __LEVELFIVE_H__
#define __LEVELFIVE_H__
#include "Player.h"
#include <iostream>

class Board;

class LevelFive: public Player{
  public:
    LevelFive(Colour c);
    void move(Board &b) override;
    ~LevelFive() = default;
};

#endif
