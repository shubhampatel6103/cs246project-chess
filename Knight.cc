#include "Knight.h"
#include "Board.h"
#include <memory>

Knight::Knight(char type, Colour colour): Piece{type, colour} {}

int Knight::getPoints() { return points; }

void Knight::notify(Cell &c, Board &b) {
    this->attachToCells(b);
}

void Knight::attachToCells(Board& b) {
    
    char myType = getType();
    Colour myColour = getColour();

    // As a knight, there are only 8 possible moves

    // Case 1
    int r = getRow() - 2; // Two steps forward
    int c = getCol() + 1; // One step right
    if (0 <= r < 8 && 0 <= c <= 8) { b.getCellAt(r,c).attach(std::make_unique<Knight>(myType, myColour)); }

    // Case 2
    c = getCol() - 1; // One step left
    if (0 <= r < 8 && 0 <= c <= 8) { b.getCellAt(r,c).attach(std::make_unique<Knight>(myType, myColour)); }

    // Case 3
    r = getRow() + 2; // Two steps back
    c = getCol() + 1; // One step right
    if (0 <= r < 8 && 0 <= c <= 8) { b.getCellAt(r,c).attach(std::make_unique<Knight>(myType, myColour)); }

    // Case 4
    c = getCol() - 1; // One step left
    if (0 <= r < 8 && 0 <= c <= 8) { b.getCellAt(r,c).attach(std::make_unique<Knight>(myType, myColour)); }

    // Case 5
    c = getCol() - 2; // Two steps left
    r = getRow() + 1; // One step back
    if (0 <= r < 8 && 0 <= c <= 8) { b.getCellAt(r,c).attach(std::make_unique<Knight>(myType, myColour)); }

    // Case 6
    r = getRow() - 1; // One step forward
    if (0 <= r < 8 && 0 <= c <= 8) { b.getCellAt(r,c).attach(std::make_unique<Knight>(myType, myColour)); }

    // Case 7
    c = getCol() + 2; // Two steps right
    r = getRow() + 1; // One step back
    if (0 <= r < 8 && 0 <= c <= 8) { b.getCellAt(r,c).attach(std::make_unique<Knight>(myType, myColour)); }

    // Case 8
    r = getRow() - 1; // One step foward
    if (0 <= r < 8 && 0 <= c <= 8) { b.getCellAt(r,c).attach(std::make_unique<Knight>(myType, myColour)); }

}

//void Knight::detachFromCells(Board& b) {return;}
