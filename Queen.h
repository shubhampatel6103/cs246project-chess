#include "Piece.h"

class Queen : public Piece {

    public:
        Queen(); // Constructs the queen piece with type = 'q' and points = 9
        void attachToCells(Board& b); // Attaches self to the cells in the vertical direction and diagonal directions
}