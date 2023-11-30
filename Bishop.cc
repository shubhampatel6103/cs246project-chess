#include "Bishop.h"
#include "Board.h"

Bishop::Bishop(char type, Colour colour): Piece{type, colour} {}

int Bishop::getPoints() { return points; }

void Bishop::notify(Cell &c, Board &b) {
    this->attachToCells(b);
}

void Bishop::attachToCells(Board& b) {

    char myType = getType();
    Colour myColour = getColour();

    // The following is for South - East Diagonal
    int r = getRow() + 1;
    int c = getCol() + 1; // now r and c are a diagonal bottom - right to the piece
    while (r < 8 && c < 8) {
        if (!b.getCellAt(r,c).getPiece()) {
            b.getCellAt(r,c).attach(std::make_unique<Bishop>(myType, myColour));
            r++; 
            c++; // Ensures that we are moving forward in the SouthEast Direction
        } else { 
            b.getCellAt(r,c).attach(std::make_unique<Bishop>(myType, myColour));
            break;
        } // Otherwise, we are being blocked so we break AFTER ATTACHING
    }


    // The following is for North - West Diagonal
    r = getRow() - 1;
    c = getCol() - 1; // now r and c are a diagonal top - left to the piece
    while (r >= 0 && c >= 0) {
        if (!b.getCellAt(r,c).getPiece()) {
            b.getCellAt(r,c).attach(std::make_unique<Bishop>(myType, myColour));
            r--; 
            c--; // Ensures that we are moving forward in the NorthWest Direction
        } else { 
            b.getCellAt(r,c).attach(std::make_unique<Bishop>(myType, myColour));
            break;
        } // Otherwise, we are being blocked so we break AFTER ATTACHING
    }


    // The following is for South - West Diagonal
    r = getRow() + 1; 
    c = getCol() - 1; // now r and c are a diagonal bottom - left to the piece
    while (r < 8 && c >= 0) {
        if (!b.getCellAt(r,c).getPiece()) {
            b.getCellAt(r,c).attach(std::make_unique<Bishop>(myType, myColour));
            r++; 
            c--; // Ensures that we are moving forward in the SouthWest Direction
        } else { 
            b.getCellAt(r,c).attach(std::make_unique<Bishop>(myType, myColour));
            break;
        } // Otherwise, we are being blocked so we break AFTER ATTACHING
    }

    // The following is for North - East Diagonal
    r = getRow() - 1; 
    c = getCol() + 1; // now r and c are a diagonal top - right to the piece
    while (r >= 0 && c < 8) {
        if (!b.getCellAt(r,c).getPiece()) {
            b.getCellAt(r,c).attach(std::make_unique<Bishop>(myType, myColour));
            r--; 
            c++; // Ensures that we are moving forward in the NorthEast Direction
        } else { 
            b.getCellAt(r,c).attach(std::make_unique<Bishop>(myType, myColour));
            break;
        } // Otherwise, we are being blocked so we break AFTER ATTACHING
    }
    
}

void Bishop::detachFromCells(Board& b) {
    char myType = getType();
    Colour myColour = getColour();

    // The following is for South - East Diagonal
    int r = getRow() + 1;
    int c = getCol() + 1; // now r and c are a diagonal bottom - right to the piece
    while (r < 8 && c < 8) {
        if (!b.getCellAt(r,c).getPiece()) {
            b.getCellAt(r,c).detach(std::make_unique<Bishop>(myType, myColour));
            r++; 
            c++; // Ensures that we are moving forward in the SouthEast Direction
        } else { 
            b.getCellAt(r,c).detach(std::make_unique<Bishop>(myType, myColour));
            break;
        } // Otherwise, we are being blocked so we break AFTER DETACHING
    }


    // The following is for North - West Diagonal
    r = getRow() - 1;
    c = getCol() - 1; // now r and c are a diagonal top - left to the piece
    while (r >= 0 && c >= 0) {
        if (!b.getCellAt(r,c).getPiece()) {
            b.getCellAt(r,c).detach(std::make_unique<Bishop>(myType, myColour));
            r--; 
            c--; // Ensures that we are moving forward in the NorthWest Direction
        } else { 
            b.getCellAt(r,c).detach(std::make_unique<Bishop>(myType, myColour));
            break;
        } // Otherwise, we are being blocked so we break AFTER DETACHING
    }


    // The following is for South - West Diagonal
    r = getRow() + 1; 
    c = getCol() - 1; // now r and c are a diagonal bottom - left to the piece
    while (r < 8 && c >= 0) {
        if (!b.getCellAt(r,c).getPiece()) {
            b.getCellAt(r,c).detach(std::make_unique<Bishop>(myType, myColour));
            r++; 
            c--; // Ensures that we are moving forward in the SouthWest Direction
        } else { 
            b.getCellAt(r,c).detach(std::make_unique<Bishop>(myType, myColour));
            break;
        } // Otherwise, we are being blocked so we break AFTER DETACHING
    }

    // The following is for North - East Diagonal
    r = getRow() - 1; 
    c = getCol() + 1; // now r and c are a diagonal top - right to the piece
    while (r >= 0 && c < 8) {
        if (!b.getCellAt(r,c).getPiece()) {
            b.getCellAt(r,c).detach(std::make_unique<Bishop>(myType, myColour));
            r--; 
            c++; // Ensures that we are moving forward in the NorthEast Direction
        } else { 
            b.getCellAt(r,c).detach(std::make_unique<Bishop>(myType, myColour));
            break;
        } // Otherwise, we are being blocked so we break AFTER DETACHING
    }
    
}