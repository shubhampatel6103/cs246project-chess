#ifndef __KING_H__
#define __KING_H__
#include "Piece.h"

class King : public Piece {
    bool moved;
    int points = 10;

    public:
        King(char type, Colour colour); // Constructs the King piece with type = 'k' or 'K', colour and points = 10
        ~King() = default;
        int getPoints();
        void attachToCells(Board& b) override; // Attaches self to the cells in the vertical and horizontal directions
        void notify(Cell &c) override;
};

#endif
