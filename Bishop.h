#include "Piece.h"

class Bishop : public Piece {
    bool moved;

    public:
        Bishop(); // Constructs the queen piece with type = 'b' and points = 3
        void attachToCells(Board& b); // Attaches self to the cells in the diagonal directions
};