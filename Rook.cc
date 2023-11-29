#include "Rook.h"

Rook::Rook(char type, Colour colour): Piece{type, colour} {}

int Rook::getPoints() { return points; }

void Rook::notify(Board &b) {
    this->attachToCells(b);
}

void Rook::attachToCells(Board& b) {

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
    
}

void Rook::detachFromCells(Board& b) {

    // The following for loop takes care of vertical cells forward
    for (int r = row + 1; r < 8; r++) { // start from where we are + 1 to the end of the board in terms of rows (row + 1 so we dont check for our own cell)
        if (!b.board[r][col].getPiece()) { // If there is no piece on that cell, then attach myself to that cell
            b.board[r][col].detach(this);
        } else { 
            b.board[r][col].detach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER DETACHING
    }

    // The following for loop takes care of vertical cells backward
    for (int r = row - 1; r >= 0; r--) { // start from where we are + 1 to the beginning of the board in terms of rows (row - 1 1 so we dont check for our own cell)
        if (!b.board[r][col].getPiece()) { // If there is no piece on that cell, then attach myself to that cell
            b.board[r][col].detach(this);
        } else { 
            b.board[r][col].detach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER DETACHING
    }

    // The following for loop takes care of all horitonzal cells forward
    for (int c = col + 1; col < 8; c++) { // start from where we are + 1 to the end of the board in terms of cols (col + 1 so we dont check for our own cell)
        if (!b.board[row][c].getPiece()) { // If there is no piece on that cell, then attach myself to that cell
            b.board[row][c].detach(this);
        } else { 
            b.board[row][c].detach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER DETACHING
    }

    // The following for loop takes care of all horitonzal cells backward
    for (int c = col - 1; col >= 0; c--) { // start from where we are - 1 to the beginning of the board in terms of cols (col - 1 so we dont check for our own cell)
        if (!b.board[row][c].getPiece()) { // If there is no piece on that cell, then attach myself to that cell
            b.board[row][c].detach(this);
        } else { 
            b.board[row][c].detach(this);
            break;
        } // Otherwise, we are being blocked so we break AFTER DETACHING
    }
    
}