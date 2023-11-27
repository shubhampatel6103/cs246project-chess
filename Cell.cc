#include "Cell.h"
#include <vector>

Cell::Cell(int row, int col, Piece::Colour colour, Piece * piece): row{row}, col{col}, colour{cellColour}, piece{piece} {}

Cell::~Cell() {
    observers.clear();
}

Piece * Cell::getPiece() { return piece; }
Piece::Colour Cell::getColour() { return cellColour; }
int Cell::getRow() { return row; }
int Cell::getCol() { return col; }
bool Cell::hasPiece() { return (piece ? true : false); }

void Cell::addPiece(Piece * newPiece) { piece = newPiece; }
void Cell::remPiece() { piece = nullptr; }

void Cell::notifyObservers() {
    for (auto observer : observers) {
        observer->notify(*this);
    }
}

void Cell::attach(Observer * o) { observers.emplace_back(o); }
void Cell::detach(Observer * o) { observers.erase(o); }
