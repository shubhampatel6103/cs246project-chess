#include "Bishop.h"

Bishop::Bishop(char type, Colour colour): Piece{type, colour} {}

int Bishop::getPoints() { return points; }

void Bishop::notify(Board &b) {
    this->attachToCells(b);
}

void Bishop::attachToCells(Board& b) {

    // The following is for South - East Diagonal
    int r = row + 1;
    int c = col + 1; // now r and c are a diagonal bottom - right to the piece
    while (r < 8 && c < 8) {
        if (!b.board[r][c].getPiece()) {
            b.board[r][c].attach(this);
            r++; 
            c++; // Ensures that we are moving forward in the SouthEast Direction
        } else { 
            b.board[r][c].attach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER ATTACHING
    }


    // The following is for North - West Diagonal
    int r = row - 1;
    int c = col - 1; // now r and c are a diagonal top - left to the piece
    while (r >= 0 && c >= 0) {
        if (!b.board[r][c].getPiece()) {
            b.board[r][c].attach(this);
            r--; 
            c--; // Ensures that we are moving forward in the NorthWest Direction
        } else { 
            b.board[r][c].attach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER ATTACHING
    }


    // The following is for South - West Diagonal
    int r = row + 1; 
    int c = col - 1; // now r and c are a diagonal bottom - left to the piece
    while (r < 8 && c >= 0) {
        if (!b.board[r][c].getPiece()) {
            b.board[r][c].attach(this);
            r++; 
            c--; // Ensures that we are moving forward in the SouthWest Direction
        } else { 
            b.board[r][c].attach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER ATTACHING
    }

    // The following is for North - East Diagonal
    int r = row - 1; 
    int c = col + 1; // now r and c are a diagonal top - right to the piece
    while (r >= 0 && c < 8) {
        if (!b.board[r][c].getPiece()) {
            b.board[r][c].attach(this);
            r--; 
            c++; // Ensures that we are moving forward in the NorthEast Direction
        } else { 
            b.board[r][c].attach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER ATTACHING
    }
    
}

void Bishop::detachFromCells(Board& b) {

    // The following is for South - East Diagonal
    int r = row + 1;
    int c = col + 1; // now r and c are a diagonal bottom - right to the piece
    while (r < 8 && c < 8) {
        if (!b.board[r][c].getPiece()) {
            b.board[r][c].detach(this);
            r++; 
            c++; // Ensures that we are moving forward in the SouthEast Direction
        } else { 
            b.board[r][c].detach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER DETACHING
    }


    // The following is for North - West Diagonal
    int r = row - 1;
    int c = col - 1; // now r and c are a diagonal top - left to the piece
    while (r >= 0 && c >= 0) {
        if (!b.board[r][c].getPiece()) {
            b.board[r][c].detach(this);
            r--; 
            c--; // Ensures that we are moving forward in the NorthWest Direction
        } else { 
            b.board[r][c].detach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER DETACHING
    }


    // The following is for South - West Diagonal
    int r = row + 1; 
    int c = col - 1; // now r and c are a diagonal bottom - left to the piece
    while (r < 8 && c >= 0) {
        if (!b.board[r][c].getPiece()) {
            b.board[r][c].detach(this);
            r++; 
            c--; // Ensures that we are moving forward in the SouthWest Direction
        } else { 
            b.board[r][c].detach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER DETACHING
    }

    // The following is for North - East Diagonal
    int r = row - 1; 
    int c = col + 1; // now r and c are a diagonal top - right to the piece
    while (r >= 0 && c < 8) {
        if (!b.board[r][c].getPiece()) {
            b.board[r][c].detach(this);
            r--; 
            c++; // Ensures that we are moving forward in the NorthEast Direction
        } else { 
            b.board[r][c].detach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER DETACHING
    }
    
}