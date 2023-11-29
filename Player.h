#ifndef __PLAYER_H__
#define __PLAYER_H__

class Move;
class Board;

class Player {
  int playerId;
  Move m = Move{false, -1, -1, -1. -1};
  public:
    Player(int p);
    virtual void move(Board &b) = 0;
    ~Player() = default;
};

#endif
