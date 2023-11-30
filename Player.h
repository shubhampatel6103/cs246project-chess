#ifndef __PLAYER_H__
#define __PLAYER_H__

enum Colour;
class Move;
class Board;


class Player {
  Colour id;
  Move m = Move{false, -1, -1, -1. -1};
  public:
    Player(Colour c);
    virtual void move(Board &b) = 0;
    ~Player() = default;
};

#endif
