#include "Pawn.h"
#include "Board.h"

Pawn::Pawn(char type, Colour colour): Piece{type, colour} {}

int Pawn::getPoints() { return points; }

void Pawn::notify(Cell &c, Board &b) {
    this->attachToCells(b);    
}

void Pawn::attachToCells(Board& b) {
    if (firstMove) {
        if (this->getColour() == Colour::Black) { // For black pieces we go down the grid so increase the row number
            if (b.getCellAt(getRow() + 1, getCol()).getPiece()) { // If there is a piece in front of us when moving for the first time
                b.getCellAt(getRow() + 1, getCol()).attach(this); // We are being blocked so we only observe the cell in front of us
            } else { // Not being blocked otherwise
                b.getCellAt(getRow() + 1, getCol()).attach(this); 
                b.getCellAt(getRow() + 2, getCol()).attach(this); 
            }
        } else { // For white pieces we go down the grid so decrease the row number
            if (b.getCellAt(getRow() - 1, getCol()).getPiece()) { // If there is a piece in front of us when moving for the first time
                b.getCellAt(getRow() - 1, getCol()).attach(this); // We are being blocked so we only observe the cell in front of us
            } else { // Not being blocked otherwise
                b.getCellAt(getRow() - 1, getCol()).attach(this); 
                b.getCellAt(getRow() - 2, getCol()).attach(this); 
            }
        }
    } else { // Not the first move so we only attach one to one cell ahead of us
        int r = getRow();
        if (this->getColour() == Colour::Black) {
            if (0 <= r + 1 && r + 1 < 8) {
                b.getCellAt(getRow() + 1, getCol()).attach(this);
            }
        } else {
            if (0 <= r - 1 && r - 1 < 8) {
                b.getCellAt(getRow() - 1, getCol()).attach(this);
            }
        }
    }

    // Now for diagonal ;-;
    int r = getRow();
    int c = getCol();
    if (this->getColour() == Colour::Black) {
        if (0 <= r + 1 && r + 1 < 8 && 0 <= c + 1 && c + 1 < 8 && b.getCellAt(r + 1,c + 1).getPiece()) { b.getCellAt(r + 1,c + 1).attach(this); }
        if (0 <= r + 1 && r + 1 < 8 && 0 <= c - 1 && c - 1 < 8 && b.getCellAt(r + 1,c - 1).getPiece()) { b.getCellAt(r + 1,c - 1).attach(this); }
    } else {
        if (0 <= r - 1 && r - 1 < 8 && 0 <= c + 1 && c + 1 < 8 && b.getCellAt(r - 1,c + 1).getPiece()) { b.getCellAt(r - 1,c + 1).attach(this); }
        if (0 <= r - 1 && r - 1 < 8 && 0 <= c - 1 && c - 1 < 8 && b.getCellAt(r - 1,c - 1).getPiece()) { b.getCellAt(r - 1,c - 1).attach(this); }
    }

}

void Pawn::detachFromCells(Board& b) {
    int r = getRow();
    int c = getCol();
    if (firstMove) {
        if (this->getColour() == Colour::Black) { // For black pieces we go down the grid so increase the row number
            b.getCellAt(r + 1, c).detach(this); 
            b.getCellAt(r + 2, c).detach(this); 
        } else { // For white pieces we go down the grid so decrease the row number
            b.getCellAt(r - 1, c).detach(this); 
            b.getCellAt(r - 2, c).detach(this); 
        }
    } else { // Not the first move so we only detach from one cell ahead of us
        if (this->getColour() == Colour::Black) {
            if (0 <= r + 1 && r + 1 < 8) {
                b.getCellAt(r + 1, c).detach(this);
            }
        } else {
            if (0 <= r - 1 && r - 1 < 8) {
                b.getCellAt(r - 1, c).detach(this);
            }
        }
    }

    // Now for diagonal ;-;
    if (this->getColour() == Colour::Black) {
        b.getCellAt(r + 1,c + 1).detach(this);
        b.getCellAt(r + 1,c - 1).detach(this); 
    } else {
        b.getCellAt(r - 1,c + 1).detach(this); 
        b.getCellAt(r - 1,c - 1).detach(this);
    }

}

