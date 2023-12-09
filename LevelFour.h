#ifndef __LEVELFOUR_H__
#define __LEVELFOUR_H__
#include "Player.h"
#include <iostream>

class Board;

class LevelFour: public Player{
  public:
    LevelFour(Colour c);
    void move(Board &b) override;
    ~LevelFour() = default;
};

#endif
