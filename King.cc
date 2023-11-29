#include "King.h"

King::King(char type, Colour colour): Piece(type, colour) {}

int King::getPoints() { return points; }

void King::notify(Cell &c, Board &b) {
     this->attachToCells(b);
}

void King::attachToCells(Board& b) {
    
    // We just need to check for the 8 cells around the king
    if (0 <= getRow() + 1 < 8 && 0 <= getCol() + 1 < 8) { b.getCellAt(getRow() + 1, getCol() + 1).attach(this); }
    if (0 <= getRow() - 1 < 8 && 0 <= getCol() - 1 < 8) { b.getCellAt(getRow() - 1, getCol() - 1).attach(this); }
    if (0 <= getRow() - 1 < 8 && 0 <= getCol() + 1 < 8) { b.getCellAt(getRow() - 1, getCol() + 1).attach(this); }
    if (0 <= getRow() + 1 < 8 && 0 <= getCol() - 1 < 8) { b.getCellAt(getRow() + 1, getCol() - 1).attach(this); }
    if (0 <= getRow() + 1 < 8) { b.getCellAt(getRow() + 1, getCol()).attach(this); }
    if (0 <= getRow() - 1 < 8) { b.getCellAt(getRow() - 1, getCol()).attach(this); }
    if (0 <= getCol() - 1 < 8) { b.getCellAt(getRow(), getCol() - 1).attach(this); }
    if (0 <= getCol() + 1 < 8) { b.getCellAt(getRow(), getCol() + 1).attach(this); }

}

void King::detachFromCells(Board& b) {
    
    // We just need to detach from the 8 cells around the king
    if (0 <= getRow() + 1 < 8 && 0 <= getCol() + 1 < 8) { b.getCellAt(getRow() + 1, getCol() + 1).detach(this); }
    if (0 <= getRow() - 1 < 8 && 0 <= getCol() - 1 < 8) { b.getCellAt(getRow() - 1, getCol() - 1).detach(this); }
    if (0 <= getRow() - 1 < 8 && 0 <= getCol() + 1 < 8) { b.getCellAt(getRow() - 1, getCol() + 1).detach(this); }
    if (0 <= getRow() + 1 < 8 && 0 <= getCol() - 1 < 8) { b.getCellAt(getRow() + 1, getCol() - 1).detach(this); }
    if (0 <= getRow() + 1 < 8) { b.getCellAt(getRow() + 1, getCol()).detach(this); }
    if (0 <= getRow() - 1 < 8) { b.getCellAt(getRow() - 1, getCol()).detach(this); }
    if (0 <= getCol() - 1 < 8) { b.getCellAt(getRow(), getCol() - 1).detach(this); }
    if (0 <= getCol() + 1 < 8) { b.getCellAt(getRow(), getCol() + 1).detach(this); }

}