#ifndef __QUEEN_H__
#define __QUEEN_H__
#include "Piece.h"

class Queen : public Piece {
    int points = 9;

    public:
        Queen(char type, Colour colour); // Constructs the queen piece with type = 'q' and points = 9
        ~Queen() = default;
        
        int getPoints() override;
        void notify(Cell &c, Board &b, bool display) override;
        void attachToCells(Board& b) override; // Attaches self to the cells in the vertical, horizontal and diagonal directions
        void detachFromCells(Board& b) override; // Detaches self from the cells in the vertical, horizontal and diagonal directions
};

#endif





