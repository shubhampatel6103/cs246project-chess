#include "Piece.h"

class King : public Piece {
    bool moved;

    public:
        King(); // Constructs the King piece with type = 'k' and points = 10
        void attachToCells(Board& b); // Attaches self to the cells in the vertical and horizontal directions
};

