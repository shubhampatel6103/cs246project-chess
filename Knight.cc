#include "Knight.h"
#include "Board.h"
#include <memory>

Knight::Knight(char type, Colour colour): Piece{type, colour} {}

int Knight::getPoints() { return 100 * points; }

void Knight::notify(Cell &c, Board &b, bool display) {
    this->detachFromCells(b);
    this->attachToCells(b);
}

void Knight::attachToCells(Board& b) {
    // As a knight, there are only 8 possible moves

    // Case 1
    int r = getRow() - 2; // Two steps forward
    int c = getCol() + 1; // One step right
    if (0 <= r && r < 8 && 0 <= c && c < 8) { b.getCellAt(r,c).attach(this); }

    // Case 2
    c = getCol() - 1; // One step left
    if (0 <= r && r < 8 && 0 <= c && c < 8) { b.getCellAt(r,c).attach(this); }

    // Case 3
    r = getRow() + 2; // Two steps back
    c = getCol() + 1; // One step right
    if (0 <= r && r < 8 && 0 <= c && c < 8) { b.getCellAt(r,c).attach(this); }

    // Case 4
    c = getCol() - 1; // One step left
    if (0 <= r && r < 8 && 0 <= c && c < 8) { b.getCellAt(r,c).attach(this); }

    // Case 5
    c = getCol() - 2; // Two steps left
    r = getRow() + 1; // One step back
    if (0 <= r && r < 8 && 0 <= c && c < 8) { b.getCellAt(r,c).attach(this); }

    // Case 6
    r = getRow() - 1; // One step forward
    if (0 <= r && r < 8 && 0 <= c && c < 8) { b.getCellAt(r,c).attach(this); }

    // Case 7
    c = getCol() + 2; // Two steps right
    r = getRow() + 1; // One step back
    if (0 <= r && r < 8 && 0 <= c && c < 8) { b.getCellAt(r,c).attach(this); }

    // Case 8
    r = getRow() - 1; // One step foward
    if (0 <= r && r < 8 && 0 <= c && c < 8) { b.getCellAt(r,c).attach(this); }

}

void Knight::detachFromCells(Board& b) {
    // As a knight, there are only 8 possible moves

    // Case 1
    int r = getRow() - 2; // Two steps forward
    int c = getCol() + 1; // One step right
    if (0 <= r && r < 8 && 0 <= c && c < 8) { b.getCellAt(r,c).detach(this); }

    // Case 2
    c = getCol() - 1; // One step left
    if (0 <= r && r < 8 && 0 <= c && c < 8) { b.getCellAt(r,c).detach(this); }

    // Case 3
    r = getRow() + 2; // Two steps back
    c = getCol() + 1; // One step right
    if (0 <= r && r < 8 && 0 <= c && c < 8) { b.getCellAt(r,c).detach(this); }

    // Case 4
    c = getCol() - 1; // One step left
    if (0 <= r && r < 8 && 0 <= c && c < 8) { b.getCellAt(r,c).detach(this); }

    // Case 5
    c = getCol() - 2; // Two steps left
    r = getRow() + 1; // One step back
    if (0 <= r && r < 8 && 0 <= c && c < 8) { b.getCellAt(r,c).detach(this); }

    // Case 6
    r = getRow() - 1; // One step forward
    if (0 <= r && r < 8 && 0 <= c && c < 8) { b.getCellAt(r,c).detach(this); }

    // Case 7
    c = getCol() + 2; // Two steps right
    r = getRow() + 1; // One step back
    if (0 <= r && r < 8 && 0 <= c && c < 8) { b.getCellAt(r,c).detach(this); }

    // Case 8
    r = getRow() - 1; // One step foward
    if (0 <= r && r < 8 && 0 <= c && c < 8) { b.getCellAt(r,c).detach(this); }
}
