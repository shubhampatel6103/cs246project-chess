#include "Observer.h"
#include "Cell.h"
#include "Board.h"

class Piece : public Observer {
    enum class Colour {Black=0, White};
    Colour colour;
    char type;
    int row, col;

    public:
        Piece(); // Initializes the object 
        char getType(); // Returns the type of piece ('k' for king, 'n' for knight and so on)
        Colour getColour(); // Returns the colour of the piece (Black or White)
        int getRow(); // Returns the row at which the piece is located on the board
        int getCol(); // Return the column at which the piece is located on the board
        void setRow(int r); // Sets the row to r
        void setCol(int c); // Sets the col to c

        void notify(Cell& c); // Calls attachToCells on the piece ... we dont even need this
        virtual void attachToCells(Board& b) = 0; // attaches 
}