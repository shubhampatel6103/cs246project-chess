#include "Rook.h"
#include "Board.h"

Rook::Rook(char type, Colour colour): Piece{type, colour} {}

int Rook::getPoints() { return 100 * points; }

void Rook::notify(Cell &c, Board &b, bool display) {
    this->detachFromCells(b);
    this->attachToCells(b);
}

void Rook::attachToCells(Board& b) {
    // The following for loop takes care of vertical cells forward
    for (int r = getRow() + 1; r < 8; r++) { // start from where we are + 1 to the end of the board in terms of getRow()s (getRow() + 1 so we dont check for our own cell)
        if (!b.getCellAt(r,getCol()).getPiece()) { // If there is no piece on that cell, then attach myself to that cell
            b.getCellAt(r,getCol()).attach(this);
        } else { 
            b.getCellAt(r,getCol()).attach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER ATTACHING
    }

    // The following for loop takes care of vertical cells backward
    for (int r = getRow() - 1; r >= 0; r--) { // start from where we are + 1 to the beginning of the board in terms of getRow()s (getRow() - 1 1 so we dont check for our own cell)
        if (!b.getCellAt(r,getCol()).getPiece()) { // If there is no piece on that cell, then attach myself to that cell
            b.getCellAt(r,getCol()).attach(this);
        } else { 
            b.getCellAt(r,getCol()).attach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER ATTACHING
    }

    // The following for loop takes care of all horitonzal cells forward
    for (int c = getCol() + 1; c < 8; c++) { // start from where we are + 1 to the end of the board in terms of cols (getCol() + 1 so we dont check for our own cell)
        if (!b.getCellAt(getRow(),c).getPiece()) { // If there is no piece on that cell, then attach myself to that cell
            b.getCellAt(getRow(),c).attach(this);
        } else { 
            b.getCellAt(getRow(),c).attach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER ATTACHING
    }

    // The following for loop takes care of all horitonzal cells backward
    for (int c = getCol() - 1; c >= 0; c--) { // start from where we are - 1 to the beginning of the board in terms of cols (getCol() - 1 so we dont check for our own cell)
        if (!b.getCellAt(getRow(),c).getPiece()) { // If there is no piece on that cell, then attach myself to that cell
            b.getCellAt(getRow(),c).attach(this);
        } else { 
            b.getCellAt(getRow(),c).attach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER ATTACHING
    }
    
}

void Rook::detachFromCells(Board& b) {
    // The following for loop takes care of vertical cells forward
    for (int r = getRow() + 1; r < 8; r++) { // start from where we are + 1 to the end of the board in terms of getRow()s (getRow() + 1 so we dont check for our own cell)
        b.getCellAt(r,getCol()).detach(this);
    }

    // The following for loop takes care of vertical cells backward
    for (int r = getRow() - 1; r >= 0; r--) { // start from where we are + 1 to the beginning of the board in terms of getRow()s (getRow() - 1 1 so we dont check for our own cell)
        b.getCellAt(r,getCol()).detach(this);
    }

    // The following for loop takes care of all horitonzal cells forward
    for (int c = getCol() + 1; c < 8; c++) { // start from where we are + 1 to the end of the board in terms of cols (getCol() + 1 so we dont check for our own cell)
        b.getCellAt(getRow(),c).detach(this);
    }

    // The following for loop takes care of all horitonzal cells backward
    for (int c = getCol() - 1; c >= 0; c--) { // start from where we are - 1 to the beginning of the board in terms of cols (getCol() - 1 so we dont check for our own cell)
        b.getCellAt(getRow(),c).detach(this);
    }
    
}



