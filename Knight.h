#ifndef __KNIGHT_H__
#define __KNIGHT_H__
#include "Piece.h"

class Knight : public Piece {
    bool moved;
    int points = 3;

    public:
        Knight(char type, Colour colour); // Constructs the knight piece with type = 'n' or 'N" and points = 3
        ~Knight() = default;
        int getPoints();
        void attachToCells(Board& b) override; // Attaches self to the cells in all directions requried
        void detachFromCells(Board& b) override; // Detaches self from the cells in all directions required
        void notify(Cell &c, Board &b) override;
};

#endif
