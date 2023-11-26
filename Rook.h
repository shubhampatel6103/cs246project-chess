#include "Piece.h"

class Rook : public Piece {
    bool moved;

    public:
        Rook(); // Constructs the queen piece with type = 'r' and points = 5
        void attachToCells(Board& b); // Attaches self to the cells in the vertical and horizontal directions
};