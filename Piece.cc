#include "Piece.h"

Piece::Piece(char type, Colour colour): type{type}, colour{colour} {
    row = col = -1;
} // Initialize the type and colour of the piece

char Piece::getType() { return type; }

Colour Piece::getColour() { return colour; }

int Piece::getRow() { return row; }

int Piece::getCol() { return col; }

void Piece::setRow(int r) { row = r; }

void Piece::setCol(int c) { col = c; }

bool Piece::getFirst() { return firstMove; }

void Piece::setFirst(bool first) { firstMove = first; }



