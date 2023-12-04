#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "Move.h"
enum class Colour;
class Board;


class Player {
  protected:
    Colour id;
    Move m{false, -1, -1, -1, -1};
    bool whiteCastleShort(Board &b, int sX, int sY, int dX, int dY);
    bool blackCastleShort(Board &b, int sX, int sY, int dX, int dY);
    bool whiteCastleLong(Board &b, int sX, int sY, int dX, int dY);
    bool blackCastleLong(Board &b, int sX, int sY, int dX, int dY);
  public:
    Player(Colour c);
    virtual void move(Board &b) = 0;
    Move& getMove();
    ~Player() = default;
};

#endif
