#include "Knight.h"

Knight::Knight(): Piece('n', 3) {}

void Knight::attachToCells(Board& b) {

    // As a knight, there are only 8 possible moves

    // Case 1
    int r = row - 2; // Two steps forward
    int c = col + 1; // One step right
    if (0 <= r < 8 && 0 <= c <= 8) { b.board[r][c].attach(this); }

    // Case 2
    int c = col - 1; // One step left
    if (0 <= r < 8 && 0 <= c <= 8) { b.board[r][c].attach(this); }

    // Case 3
    int r = row + 2; // Two steps back
    int c = col + 1; // One step right
    if (0 <= r < 8 && 0 <= c <= 8) { b.board[r][c].attach(this); }

    // Case 4
    int c = col - 1; // One step left
    if (0 <= r < 8 && 0 <= c <= 8) { b.board[r][c].attach(this); }

    // Case 5
    int c = col - 2; // Two steps left
    int r = row + 1; // One step back
    if (0 <= r < 8 && 0 <= c <= 8) { b.board[r][c].attach(this); }

    // Case 6
    int r = row - 1; // One step forward
    if (0 <= r < 8 && 0 <= c <= 8) { b.board[r][c].attach(this); }

    // Case 7
    int c = col + 2; // Two steps right
    int r = row + 1; // One step back
    if (0 <= r < 8 && 0 <= c <= 8) { b.board[r][c].attach(this); }

    // Case 8
    int r = row - 1; // One step foward
    if (0 <= r < 8 && 0 <= c <= 8) { b.board[r][c].attach(this); }

}