#include "Queen.h"

Queen::Queen(char type, Colour colour): Piece{type, colour} {} // Constructs the queen piece with type = 'q' or 'Q', colour, and points to 9
        
int Queen::getPoints() { return points; }

void Queen::notify(Cell &c) { /*Implement this*/ }

void Queen::attachToCells(Board& b) {
    
    // The following for loop takes care of vertical cells forward
    for (int r = row + 1; r < 8; r++) { // start from where we are + 1 to the end of the board in terms of rows (row + 1 so we dont check for our own cell)
        if (!b.board[r][col].getPiece()) { // If there is no piece on that cell, then attach myself to that cell
            b.board[r][col].attach(this);
        } else { 
            b.board[r][col].attach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER ATTACHING
    }

    // The following for loop takes care of vertical cells backward
    for (int r = row - 1; r >= 0; r--) { // start from where we are + 1 to the beginning of the board in terms of rows (row - 1 1 so we dont check for our own cell)
        if (!b.board[r][col].getPiece()) { // If there is no piece on that cell, then attach myself to that cell
            b.board[r][col].attach(this);
        } else { 
            b.board[r][col].attach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER ATTACHING
    }

    // The following for loop takes care of all horitonzal cells forward
    for (int c = col + 1; col < 8; c++) { // start from where we are + 1 to the end of the board in terms of cols (col + 1 so we dont check for our own cell)
        if (!b.board[row][c].getPiece()) { // If there is no piece on that cell, then attach myself to that cell
            b.board[row][c].attach(this);
        } else { 
            b.board[row][c].attach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER ATTACHING
    }

    // The following for loop takes care of all horitonzal cells backward
    for (int c = col - 1; col >= 0; c--) { // start from where we are - 1 to the beginning of the board in terms of cols (col - 1 so we dont check for our own cell)
        if (!b.board[row][c].getPiece()) { // If there is no piece on that cell, then attach myself to that cell
            b.board[row][c].attach(this);
        } else { 
            b.board[row][c].attach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER ATTACHING
    }


    // Now for diagonal :3

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

    // Finally, we are done!
}