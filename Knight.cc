#include "Knight.h"

Knight::Knight(char type, Colour colour): Piece{type, colour} {}

int Knight::getPoints() { return points; }

void Knight::notify(Cell &c, Board &b) {
    this->attachToCells(b);
}

void Knight::attachToCells(Board& b) {

    // As a knight, there are only 8 possible moves

    // Case 1
    int r = getRow() - 2; // Two steps forward
    int c = getCol() + 1; // One step right
    if (0 <= r < 8 && 0 <= c <= 8) { b.getCellAt(r,c).attach(this); }

    // Case 2
    int c = getCol() - 1; // One step left
    if (0 <= r < 8 && 0 <= c <= 8) { b.getCellAt(r,c).attach(this); }

    // Case 3
    int r = getRow() + 2; // Two steps back
    int c = getCol() + 1; // One step right
    if (0 <= r < 8 && 0 <= c <= 8) { b.getCellAt(r,c).attach(this); }

    // Case 4
    int c = getCol() - 1; // One step left
    if (0 <= r < 8 && 0 <= c <= 8) { b.getCellAt(r,c).attach(this); }

    // Case 5
    int c = getCol() - 2; // Two steps left
    int r = getRow() + 1; // One step back
    if (0 <= r < 8 && 0 <= c <= 8) { b.getCellAt(r,c).attach(this); }

    // Case 6
    int r = getRow() - 1; // One step forward
    if (0 <= r < 8 && 0 <= c <= 8) { b.getCellAt(r,c).attach(this); }

    // Case 7
    int c = getCol() + 2; // Two steps right
    int r = getRow() + 1; // One step back
    if (0 <= r < 8 && 0 <= c <= 8) { b.getCellAt(r,c).attach(this); }

    // Case 8
    int r = getRow() - 1; // One step foward
    if (0 <= r < 8 && 0 <= c <= 8) { b.getCellAt(r,c).attach(this); }

}