#include "Piece.h"

class Knight : public Piece {
    bool moved;

    public:
        Knight(); // Constructs the knight piece with type = 'n' and points = 3
        void attachToCells(Board& b); // Attaches self to the cells in the diagonal directions
};