#include "Cell.h"
#include <vector>

Cell::Cell(int row, int col, Colour colour, Piece * piece): row{row}, col{col}, cellColour{colour}, piece{piece} {}

Cell::~Cell() {
    observers.clear();
}

Piece * Cell::getPiece() { return piece; }
Colour Cell::getColour() { return cellColour; }
int Cell::getRow() { return row; }
int Cell::getCol() { return col; }
bool Cell::hasPiece() { return (piece ? true : false); }

bool Cell::isPieceObserver(Piece * p) {
    for (auto observer: observers) {
        if (observer == p) return true;
    }
    return false;
}

void Cell::addPiece(Piece * newPiece) { piece = newPiece; }
void Cell::remPiece() { piece = nullptr; }

void Cell::notifyObservers(Board& b) {
    for (auto observer : observers) {
        observer->notify(*this, b);
    }
}

void Cell::attach(Observer * o) { observers.emplace_back(o); }
void Cell::detach(Observer * o) { observers.erase(std::remove(observers.begin(), observers.end(), o), observers.end()); }
