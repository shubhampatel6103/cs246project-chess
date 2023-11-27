#ifndef __PAWN_H__
#define __PAWN_H__
#include "Piece.h"

class Pawn : public Piece {
    bool firstMove;
    int points = 1;

    public:
        Pawn(char type, Colour colour); // Constructs the Pawn piece with type = 'p' and points = 1
        ~Pawn() = default;
        int getPoints();
        void notify(Cell &c) override;
        void attachToCells(Board& b) override; // Attaches self to the cells in the vertical and horizontal directions
};

#endif
