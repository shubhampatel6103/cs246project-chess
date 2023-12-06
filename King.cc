#include "King.h"
#include "Board.h"
#include <memory>

King::King(char type, Colour colour): Piece(type, colour) {}

int King::getPoints() { return 100 * points; }

void King::notify(Cell &c, Board &b, bool display) {
    this->detachFromCells(b);
    this->attachToCells(b);
}

void King::attachToCells(Board& b) {
    
    // We just need to check for the 8 cells around the king
    int r = getRow();
    int c = getCol();
    if (0 <= r + 1 && r + 1 < 8 && 0 <= c + 1 && c + 1 < 8 /* && (!b.getCellAt(r + 1, c + 1).getPiece() || b.getCellAt(r + 1, c + 1).getPiece()->getColour() != this->getColour()) */) { b.getCellAt(r + 1, c + 1).attach(this); }
    if (0 <= r - 1 && r - 1 < 8 && 0 <= c - 1 && c - 1 < 8 /* && (!b.getCellAt(r - 1, c - 1).getPiece() || b.getCellAt(r - 1, c - 1).getPiece()->getColour() != this->getColour()) */) { b.getCellAt(r - 1, c - 1).attach(this); }
    if (0 <= r - 1 && r - 1 < 8 && 0 <= c + 1 && c + 1 < 8 /* && (!b.getCellAt(r - 1, c + 1).getPiece() || b.getCellAt(r - 1, c + 1).getPiece()->getColour() != this->getColour()) */) { b.getCellAt(r - 1, c + 1).attach(this); }
    if (0 <= r + 1 && r + 1 < 8 && 0 <= c - 1 && c - 1 < 8 /* && (!b.getCellAt(r + 1, c - 1).getPiece() || b.getCellAt(r + 1, c - 1).getPiece()->getColour() != this->getColour()) */) { b.getCellAt(r + 1, c - 1).attach(this); }
    if (0 <= r + 1 && r + 1 < 8 /* && (!b.getCellAt(r + 1, c).getPiece() || b.getCellAt(r + 1, c).getPiece()->getColour() != this->getColour()) */) { b.getCellAt(r + 1, c).attach(this); }
    if (0 <= r - 1 && r - 1 < 8 /* && (!b.getCellAt(r - 1, c).getPiece() || b.getCellAt(r - 1, c).getPiece()->getColour() != this->getColour()) */) { b.getCellAt(r - 1, c).attach(this); }
    if (0 <= c - 1 && c - 1 < 8 /* && (!b.getCellAt(r, c - 1).getPiece() || b.getCellAt(r, c - 1).getPiece()->getColour() != this->getColour()) */) { b.getCellAt(r, c - 1).attach(this); }
    if (0 <= c + 1 && c + 1 < 8 /* && (!b.getCellAt(r, c + 1).getPiece() || b.getCellAt(r, c + 1).getPiece()->getColour() != this->getColour()) */) { b.getCellAt(r, c + 1).attach(this); }

}

void King::detachFromCells(Board& b) {
    
    // We just need to detach from the 8 cells around the king
    // char myType = getType();
    // Colour myColour = getColour();
    int r = getRow();
    int c = getCol();
    if (0 <= r + 1 && r + 1 < 8 && 0 <= c + 1 && c + 1 < 8) { b.getCellAt(r + 1, c + 1).detach(this); }
    if (0 <= r - 1 && r - 1 < 8 && 0 <= c - 1 && c - 1 < 8) { b.getCellAt(r - 1, c - 1).detach(this); }
    if (0 <= r - 1 && r - 1 < 8 && 0 <= c + 1 && c + 1 < 8) { b.getCellAt(r - 1, c + 1).detach(this); }
    if (0 <= r + 1 && r + 1 < 8 && 0 <= c - 1 && c - 1 < 8) { b.getCellAt(r + 1, c - 1).detach(this); }
    if (0 <= r + 1 && r + 1 < 8) { b.getCellAt(r + 1, c).detach(this); }
    if (0 <= r - 1 && r - 1 < 8) { b.getCellAt(r - 1, c).detach(this); }
    if (0 <= c - 1 && c - 1 < 8) { b.getCellAt(r, c - 1).detach(this); }
    if (0 <= c + 1 && c + 1 < 8) { b.getCellAt(r, c + 1).detach(this); }

}
