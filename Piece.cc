#include "Piece.h"

Piece::Piece(): row{0}, col{0}, type{''}, colour{Colour::Black} {} // Initialize the row, column, type and colour of the piece

char Piece::getType() { return type; }

Colour Piece::getColour() { return colour; }

int Piece::getRow() { return row; }

int Piece::getCol() { return col; }

void Piece::setRow(int r) { row = r; }

void Piece::setCol(int c) { col = c; }