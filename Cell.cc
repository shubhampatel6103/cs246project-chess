#include "Cell.h"
#include <vector>

using namespace std;

Cell::Cell(int row, int col, Colour colour): row{row}, col{col}, cellColour{colour} {}

Cell::~Cell() {
    observers.clear();
}

Cell::Cell(const Cell &c): row{c.row}, col{c.col}, cellColour{c.cellColour} {}

Cell::Cell(Cell &&c): row{c.getRow()}, col{c.getCol()}, cellColour{c.getColour()} {
    piece = move(c.getActualPiece());
}

Piece * Cell::getPiece() { return piece.get(); }

unique_ptr<Piece> Cell::getActualPiece() { 
    return move(piece);
}

Colour Cell::getColour() { return cellColour; }
int Cell::getRow() { return row; }
int Cell::getCol() { return col; }

void Cell::setCol(int col) { this->col = col; }
void Cell::setRow(int row) { this->row = row; }
void Cell::setColour(Colour colour) { cellColour = colour; }
bool Cell::hasPiece() { return (piece ? true : false); }

bool Cell::isPieceObserver(Piece * p) {
    for (auto observer: observers) {
        if (observer == p) return true;
    }
    return false;
}

void Cell::addPiece(std::unique_ptr<Piece> newPiece) { 
    piece = move(newPiece);
}

void Cell::remPiece() { piece = nullptr; }

void Cell::notifyObservers(Board& b) {
    for (auto observer : observers) {
        observer->notify(*this, b);
    }
}

void Cell::attach(Observer * o) { observers.emplace_back(o); }
void Cell::detach(Observer * o) {
    for (auto it = observers.begin(); it!= observers.end(); it++) {
        if (*it == o) { 
            observers.erase(it);
            break;
        }
    }
}