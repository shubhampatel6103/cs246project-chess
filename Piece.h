#include "Observer.h"
#include "Cell.h"
#include "Board.h"


class Piece : public Observer {
    enum class Colour {Black=0, White};

    char type;
    Colour colour;
    int row, col, points;

    public:
        Piece(char type, int points); // Initializes the object 
        char getType(); // Returns the type of piece ('k' for king, 'n' for knight and so on)
        Colour getColour(); // Returns the colour of the piece (Black or White)
        int getRow(); // Returns the row at which the piece is located on the board
        int getCol(); // Return the column at which the piece is located on the board
        void setRow(int r); // Sets the row to r
        void setCol(int c); // Sets the col to c

        virtual void attachToCells(Board& b) = 0; // attaches the piece to the cells required
        void notify(Cell& c); // Calls attachToCells on the piece ... we dont even need this
}