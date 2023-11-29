#ifndef __HUMAN_H__
#define __HUMAN_H__
#include "Player.h"
#include <iostream>

class Board;

class Human: public Player{
  public:
    Human(int p);
    void move(Board &b) override;
    ~Human() = default;
};

#endif
