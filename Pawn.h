#include "Piece.h"

class Pawn : public Piece {
    bool firstMove;

    public:
        Pawn(); // Constructs the Pawn piece with type = 'p' and points = 1
        void attachToCells(Board& b); // Attaches self to the cells in the vertical and horizontal directions
};

