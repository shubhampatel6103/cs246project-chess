#ifndef __PIECE_H__
#define __PIECE_H__
#include "Observer.h"
#include "Cell.h"
#include "Board.h"

enum class Colour {Black=0, White};

class Piece : public Observer {
    char type;
    Colour colour;
    int row, col;

    public:
        Piece(char type, Colour colour); // Initializes the object 
        char getType(); // Returns the type of piece ('k' for king, 'n' for knight and so on) with capital letters denoting white pieces
        Colour getColour(); // Returns the colour of the piece (Black or White)
        int getRow(); // Returns the row at which the piece is located on the board
        int getCol(); // Return the column at which the piece is located on the board
        void setRow(int r); // Sets the row to r
        void setCol(int c); // Sets the col to c

        virtual void attachToCells(Board& b) = 0; // Attaches the piece to the cells required
        virtual void detachFromCells(Board& b) = 0; // Detaches the piece from the cells required
        virtual void notify(Cell &c, Board &b) = 0; // Abstract method
};

#endif
