#include "King.h"
#include "Board.h"
#include <memory>

King::King(char type, Colour colour): Piece(type, colour) {}

int King::getPoints() { return points; }

void King::notify(Cell &c, Board &b) {
     this->attachToCells(b);
}

void King::attachToCells(Board& b) {
    
    // We just need to check for the 8 cells around the king
    char myType = getType();
    Colour myColour = getColour();
    if (0 <= getRow() + 1 < 8 && 0 <= getCol() + 1 < 8) { b.getCellAt(getRow() + 1, getCol() + 1).attach(std::make_unique<King>(myType, myColour)); }
    if (0 <= getRow() - 1 < 8 && 0 <= getCol() - 1 < 8) { b.getCellAt(getRow() - 1, getCol() - 1).attach(std::make_unique<King>(myType, myColour)); }
    if (0 <= getRow() - 1 < 8 && 0 <= getCol() + 1 < 8) { b.getCellAt(getRow() - 1, getCol() + 1).attach(std::make_unique<King>(myType, myColour)); }
    if (0 <= getRow() + 1 < 8 && 0 <= getCol() - 1 < 8) { b.getCellAt(getRow() + 1, getCol() - 1).attach(std::make_unique<King>(myType, myColour)); }
    if (0 <= getRow() + 1 < 8) { b.getCellAt(getRow() + 1, getCol()).attach(std::make_unique<King>(myType, myColour)); }
    if (0 <= getRow() - 1 < 8) { b.getCellAt(getRow() - 1, getCol()).attach(std::make_unique<King>(myType, myColour)); }
    if (0 <= getCol() - 1 < 8) { b.getCellAt(getRow(), getCol() - 1).attach(std::make_unique<King>(myType, myColour)); }
    if (0 <= getCol() + 1 < 8) { b.getCellAt(getRow(), getCol() + 1).attach(std::make_unique<King>(myType, myColour)); }

}

void King::detachFromCells(Board& b) {
    
    // We just need to detach from the 8 cells around the king
    char myType = getType();
    Colour myColour = getColour();
    if (0 <= getRow() + 1 < 8 && 0 <= getCol() + 1 < 8) { b.getCellAt(getRow() + 1, getCol() + 1).detach(std::make_unique<King>(myType, myColour)); }
    if (0 <= getRow() - 1 < 8 && 0 <= getCol() - 1 < 8) { b.getCellAt(getRow() - 1, getCol() - 1).detach(std::make_unique<King>(myType, myColour)); }
    if (0 <= getRow() - 1 < 8 && 0 <= getCol() + 1 < 8) { b.getCellAt(getRow() - 1, getCol() + 1).detach(std::make_unique<King>(myType, myColour)); }
    if (0 <= getRow() + 1 < 8 && 0 <= getCol() - 1 < 8) { b.getCellAt(getRow() + 1, getCol() - 1).detach(std::make_unique<King>(myType, myColour)); }
    if (0 <= getRow() + 1 < 8) { b.getCellAt(getRow() + 1, getCol()).detach(std::make_unique<King>(myType, myColour)); }
    if (0 <= getRow() - 1 < 8) { b.getCellAt(getRow() - 1, getCol()).detach(std::make_unique<King>(myType, myColour)); }
    if (0 <= getCol() - 1 < 8) { b.getCellAt(getRow(), getCol() - 1).detach(std::make_unique<King>(myType, myColour)); }
    if (0 <= getCol() + 1 < 8) { b.getCellAt(getRow(), getCol() + 1).detach(std::make_unique<King>(myType, myColour)); }

}