#include "Piece.h"

class Knight : public Piece {
    bool moved;

    public:
        Knight(); // Constructs the queen piece with type = 'b' and points = 3
        void attachToCells(Board& b); // Attaches self to the cells in the diagonal directions
};