#ifndef __KNIGHT_H__
#define __KNIGHT_H__
#include "Piece.h"

class Knight : public Piece {
    bool moved;
    int points = 3;

    public:
        Knight(char type, Colour colour); // Constructs the knight piece with type = 'n' or 'N" and points = 3
        ~Knight() = default;
        int getPoints() override;
        void attachToCells(Board& b) override; // Attaches self to the cells in the diagonal directions
        void detachFromCells(Board& b) override;
        void notify(Cell &c, Board &b, bool display) override;
};

#endif
