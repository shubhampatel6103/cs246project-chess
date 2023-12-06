#ifndef __BISHOP_H__
#define __BISHOP_H__
#include "Piece.h"

class Bishop : public Piece {
    int points = 3;

    public:
        Bishop(char type, Colour colour); // Constructs the bishop piece with type = 'b' or 'B' and points = 3
        ~Bishop() = default;
        int getPoints() override;
        void notify(Cell &c, Board &b, bool display) override;
        void attachToCells(Board& b) override; // Attaches self to the cells in the diagonal directions
        void detachFromCells(Board& b) override; // Attaches self to the cells in the diagonal directions
};

#endif
