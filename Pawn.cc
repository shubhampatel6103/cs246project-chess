#include "Pawn.h"

Pawn::Pawn(char type, Colour colour): Piece{type, colour} {}

int Pawn::getPoints() { return points; }

void Pawn::notify(Board &b) {
    this->attachToCells(b);    
}

void Pawn::attachToCells(Board& b) {

    if (firstMove) {
        if (this->getColour() == Colour::Black) { // For black pieces we go down the grid so increase the row number
            if (b.board[row + 1][col].getPiece()) { // If there is a piece in front of us when moving for the first time
                b.board[row + 1][col].attach(this); // We are being blocked so we only observe the cell in front of us
            } else { // Not being blocked otherwise
                b.board[row + 1][col].attach(this); 
                b.board[row + 2][col].attach(this); 
            }
        } else { // For white pieces we go down the grid so decrease the row number
            if (b.board[row - 1][col].getPiece()) { // If there is a piece in front of us when moving for the first time
                b.board[row - 1][col].attach(this); // We are being blocked so we only observe the cell in front of us
            } else { // Not being blocked otherwise
                b.board[row - 1][col].attach(this); 
                b.board[row - 2][col].attach(this); 
            }
        }
    } else { // Not the first move so we only attach one to one cell ahead of us
        if (this->getColour() == Colour::Black) {
            if (0 <= row + 1 < 8) {
                b.board[row + 1][col].attach(this);
            }
        } else {
            if (0 <= row - 1 < 8) {
                b.board[row - 1][col].attach(this);
            }
        }
    }

    // Now for diagonal ;-;
    if (this->getColour() == Colour::Black) {
        if (0 <= row + 1 < 8 && 0 <= col + 1 < 8 && b.board[row + 1][col + 1].getPiece()) { b.board[row + 1][col + 1].attach(this); }
        if (0 <= row + 1 < 8 && 0 <= col - 1 < 8 && b.board[row + 1][col - 1].getPiece()) { b.board[row + 1][col - 1].attach(this); }
    } else {
        if (0 <= row - 1 < 8 && 0 <= col + 1 < 8 && b.board[row - 1][col + 1].getPiece()) { b.board[row - 1][col + 1].attach(this); }
        if (0 <= row - 1 < 8 && 0 <= col - 1 < 8 && b.board[row - 1][col - 1].getPiece()) { b.board[row - 1][col - 1].attach(this); }
    }

}

