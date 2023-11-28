#include "King.h"

King::King(char type, Colour colour): Piece(type, colour) {}

int King::getPoints() { return points; }

void King::notify(Cell &c) { /*Implement this */ }

void King::attachToCells(Board& b) {
    
    // We just need to check for the 8 cells around the king
    if (0 <= row + 1 < 8 && 0 <= col + 1 < 8) { b.board[row + 1][col + 1].attach(this); }
    if (0 <= row - 1 < 8 && 0 <= col - 1 < 8) { b.board[row - 1][col - 1].attach(this); }
    if (0 <= row - 1 < 8 && 0 <= col + 1 < 8) { b.board[row - 1][col + 1].attach(this); }
    if (0 <= row + 1 < 8 && 0 <= col - 1 < 8) { b.board[row + 1][col - 1].attach(this); }
    if (0 <= row + 1 < 8) { b.board[row + 1][col].attach(this); }
    if (0 <= row - 1 < 8) { b.board[row - 1][col].attach(this); }
    if (0 <= col - 1 < 8) { b.board[row][col - 1].attach(this); }
    if (0 <= col + 1 < 8) { b.board[row][col + 1].attach(this); }

}