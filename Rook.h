#ifndef __ROOK_H__
#define __ROOK_H__
#include "Piece.h"

class Rook : public Piece {
    bool moved;
    int points = 5;

    public:
        Rook(char type, Colour colour); // Constructs the rook piece with type = 'r' and points = 5
        ~Rook() = default;
        int getPoints() override;
        void notify(Cell &c, Board &b, bool display) override;
        void attachToCells(Board& b) override; // Attaches self to the cells in the vertical and horizontal directions
        void detachFromCells(Board& b) override; // Detach self from the cells in the vertical and horizontal directions
};

#endif




