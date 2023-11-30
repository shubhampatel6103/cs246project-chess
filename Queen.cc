#include "Queen.h"
#include "Board.h"

Queen::Queen(char type, Colour colour): Piece{type, colour} {} // Constructs the queen piece with type = 'q' or 'Q', colour, and points to 9
        
int Queen::getPoints() { return points; }

void Queen::notify(Cell &c, Board &b) {
    this->attachToCells(b);
}

void Queen::attachToCells(Board& b) {
    // The following for loop takes care of vertical cells forward
    for (int r = getRow() + 1; r < 8; r++) { // start from where we are + 1 to the end of the getCellAt( in terms of rows (getRow() + 1 so we dont check for our own cell)
        if (!b.getCellAt(r, getCol()).getPiece()) { // If there is no piece on that cell, then attach myself to that cell
            b.getCellAt(r, getCol()).attach(this);
        } else { 
            b.getCellAt(r, getCol()).attach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER ATTACHING
    }

    // The following for loop takes care of vertical cells backward
    for (int r = getRow() - 1; r >= 0; r--) { // start from where we are + 1 to the beginning of the getCellAt( in terms of rows (getRow() - 1 1 so we dont check for our own cell)
        if (!b.getCellAt(r, getCol()).getPiece()) { // If there is no piece on that cell, then attach myself to that cell
            b.getCellAt(r, getCol()).attach(this);
        } else { 
            b.getCellAt(r, getCol()).attach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER ATTACHING
    }

    // The following for loop takes care of all horitonzal cells forward
    for (int c = getCol() + 1; getCol() < 8; c++) { // start from where we are + 1 to the end of the getCellAt( in terms of cols (getCol() + 1 so we dont check for our own cell)
        if (!b.getCellAt(getRow(), c).getPiece()) { // If there is no piece on that cell, then attach myself to that cell
            b.getCellAt(getRow(), c).attach(this);
        } else { 
            b.getCellAt(getRow(), c).attach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER ATTACHING
    }

    // The following for loop takes care of all horitonzal cells backward
    for (int c = getCol() - 1; getCol() >= 0; c--) { // start from where we are - 1 to the beginning of the getCellAt( in terms of cols (getCol() - 1 so we dont check for our own cell)
        if (!b.getCellAt(getRow(), c).getPiece()) { // If there is no piece on that cell, then attach myself to that cell
            b.getCellAt(getRow(), c).attach(this);
        } else { 
            b.getCellAt(getRow(), c).attach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER ATTACHING
    }


    // Now for diagonal :3

    // The following is for South - East Diagonal
    int r = getRow() + 1;
    int c = getCol() + 1; // now r and c are a diagonal bottom - right to the piece
    while (r < 8 && c < 8) {
        if (!b.getCellAt(r, c).getPiece()) {
            b.getCellAt(r, c).attach(this);
            r++; 
            c++; // Ensures that we are moving forward in the SouthEast Direction
        } else { 
            b.getCellAt(r, c).attach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER ATTACHING
    }


    // The following is for North - West Diagonal
    r = getRow() - 1;
    c = getCol() - 1; // now r and c are a diagonal top - left to the piece
    while (r >= 0 && c >= 0) {
        if (!b.getCellAt(r, c).getPiece()) {
            b.getCellAt(r, c).attach(this);
            r--; 
            c--; // Ensures that we are moving forward in the NorthWest Direction
        } else { 
            b.getCellAt(r, c).attach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER ATTACHING
    }


    // The following is for South - West Diagonal
    r = getRow() + 1; 
    c = getCol() - 1; // now r and c are a diagonal bottom - left to the piece
    while (r < 8 && c >= 0) {
        if (!b.getCellAt(r, c).getPiece()) {
            b.getCellAt(r, c).attach(this);
            r++; 
            c--; // Ensures that we are moving forward in the SouthWest Direction
        } else { 
            b.getCellAt(r, c).attach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER ATTACHING
    }

    // The following is for North - East Diagonal
    r = getRow() - 1; 
    c = getCol() + 1; // now r and c are a diagonal top - right to the piece
    while (r >= 0 && c < 8) {
        if (!b.getCellAt(r, c).getPiece()) {
            b.getCellAt(r, c).attach(this);
            r--; 
            c++; // Ensures that we are moving forward in the NorthEast Direction
        } else { 
            b.getCellAt(r, c).attach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER ATTACHING
    }

    // Finally, we are done!
}

void Queen::detachFromCells(Board& b) {
    // The following for loop takes care of vertical cells forward
    for (int r = getRow() + 1; r < 8; r++) { // start from where we are + 1 to the end of the getCellAt( in terms of rows (getRow() + 1 so we dont check for our own cell)
        if (!b.getCellAt(r, getCol()).getPiece()) { // If there is no piece on that cell, then attach myself to that cell
            b.getCellAt(r, getCol()).detach(this);
        } else { 
            b.getCellAt(r, getCol()).detach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER ATTACHING
    }

    // The following for loop takes care of vertical cells backward
    for (int r = getRow() - 1; r >= 0; r--) { // start from where we are + 1 to the beginning of the getCellAt( in terms of rows (getRow() - 1 1 so we dont check for our own cell)
        if (!b.getCellAt(r, getCol()).getPiece()) { // If there is no piece on that cell, then attach myself to that cell
            b.getCellAt(r, getCol()).detach(this);
        } else { 
            b.getCellAt(r, getCol()).detach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER ATTACHING
    }

    // The following for loop takes care of all horitonzal cells forward
    for (int c = getCol() + 1; getCol() < 8; c++) { // start from where we are + 1 to the end of the getCellAt( in terms of cols (getCol() + 1 so we dont check for our own cell)
        if (!b.getCellAt(getRow(), c).getPiece()) { // If there is no piece on that cell, then attach myself to that cell
            b.getCellAt(getRow(), c).detach(this);
        } else { 
            b.getCellAt(getRow(), c).detach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER DETACHING
    }

    // The following for loop takes care of all horitonzal cells backward
    for (int c = getCol() - 1; getCol() >= 0; c--) { // start from where we are - 1 to the beginning of the getCellAt( in terms of cols (getCol() - 1 so we dont check for our own cell)
        if (!b.getCellAt(getRow(), c).getPiece()) { // If there is no piece on that cell, then attach myself to that cell
            b.getCellAt(getRow(), c).detach(this);
        } else { 
            b.getCellAt(getRow(), c).detach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER DETACHING
    }


    // Now for diagonal :3

    // The following is for South - East Diagonal
    int r = getRow() + 1;
    int c = getCol() + 1; // now r and c are a diagonal bottom - right to the piece
    while (r < 8 && c < 8) {
        if (!b.getCellAt(r, c).getPiece()) {
            b.getCellAt(r, c).detach(this);
            r++; 
            c++; // Ensures that we are moving forward in the SouthEast Direction
        } else { 
            b.getCellAt(r, c).detach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER DETACHING
    }


    // The following is for North - West Diagonal
    r = getRow() - 1;
    c = getCol() - 1; // now r and c are a diagonal top - left to the piece
    while (r >= 0 && c >= 0) {
        if (!b.getCellAt(r, c).getPiece()) {
            b.getCellAt(r, c).detach(this);
            r--; 
            c--; // Ensures that we are moving forward in the NorthWest Direction
        } else { 
            b.getCellAt(r, c).detach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER DETACHING
    }


    // The following is for South - West Diagonal
    r = getRow() + 1; 
    c = getCol() - 1; // now r and c are a diagonal bottom - left to the piece
    while (r < 8 && c >= 0) {
        if (!b.getCellAt(r, c).getPiece()) {
            b.getCellAt(r, c).detach(this);
            r++; 
            c--; // Ensures that we are moving forward in the SouthWest Direction
        } else { 
            b.getCellAt(r, c).detach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER DETACHING
    }

    // The following is for North - East Diagonal
    r = getRow() - 1; 
    c = getCol() + 1; // now r and c are a diagonal top - right to the piece
    while (r >= 0 && c < 8) {
        if (!b.getCellAt(r, c).getPiece()) {
            b.getCellAt(r, c).detach(this);
            r--; 
            c++; // Ensures that we are moving forward in the NorthEast Direction
        } else { 
            b.getCellAt(r, c).detach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER DETACHING
    }

    // Finally, we are done!
}
