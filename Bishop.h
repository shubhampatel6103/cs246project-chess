#include "Piece.h"

class Bishop : public Piece {

    public:
        Bishop(); // Constructs the bishop piece with type = 'b' and points = 3
        void attachToCells(Board& b); // Attaches self to the cells in the diagonal directions
};