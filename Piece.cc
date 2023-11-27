#include "Piece.h"

Piece::Piece(char type, int points): type{type}, colour{Colour::Black}, row{0}, col{0}, points{points} {} // Initialize the row, column, type and colour of the piece

char Piece::getType() { return type; }

Colour Piece::getColour() { return colour; }

int Piece::getRow() { return row; }

int Piece::getCol() { return col; }

void Piece::setRow(int r) { row = r; }

void Piece::setCol(int c) { col = c; }

void Piece::notify(Cell& c) {
    this->attachToCells(Board& b);
}



