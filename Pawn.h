#ifndef __PAWN_H__
#define __PAWN_H__
#include "Piece.h"
class Board;
class Cell;

class Pawn : public Piece {
    bool doubleMoved = false;
    int points = 1;

    public:
        Pawn(char type, Colour colour); // Constructs the Pawn piece with type = 'p' and points = 1
        ~Pawn() = default;
        int getPoints() override;
        void notify(Cell &c, Board &b, bool display) override;
        void setDoubleMove(bool b);
        bool getDoubleMove();
        void attachToCells(Board& b) override; // Attaches self to the cells in the vertical and horizontal directions
        void detachFromCells(Board& b) override; // Detaches self from the cells in the vertical and horizontal directions
};

#endif



