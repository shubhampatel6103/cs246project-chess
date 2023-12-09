#include "Pawn.h"
#include "Board.h"

using namespace std;

Pawn::Pawn(char type, Colour colour): Piece{type, colour} {}

int Pawn::getPoints() { return 100 * points; }

void Pawn::notify(Cell &c, Board &b, bool display) {
    this->detachFromCells(b);
    this->attachToCells(b);    
}

void Pawn::setDoubleMove(bool b) { doubleMoved = true; }
bool Pawn::getDoubleMove() { return doubleMoved; }

void Pawn::attachToCells(Board& b) {
    if (this->getColour() == Colour::Black && this->getRow() == 1) { // For black pieces we go down the grid so increase the row number
        if (this->getCol() == 0 && this->getRow() == 1) {
            // cout << "a pawn" << endl;
        }
        if (b.getCellAt(getRow() + 1, getCol()).getPiece()) { // If there is a piece in front of us when moving for the first time
            b.getCellAt(getRow() + 1, getCol()).attach(this); // We are being blocked so we only observe the cell in front of us
        } else { // Not being blocked otherwise
            b.getCellAt(getRow() + 1, getCol()).attach(this);
            if (this->getCol() == 0 && this->getRow() == 1) {
            // cout << "a pawn inside else" << endl;
        }
            b.getCellAt(getRow() + 2, getCol()).attach(this); 
        }
    } else if (this->getColour() == Colour::White && this->getRow() == 6) { // For white pieces we go down the grid so decrease the row number
        if (b.getCellAt(getRow() - 1, getCol()).getPiece()) { // If there is a piece in front of us when moving for the first time
            b.getCellAt(getRow() - 1, getCol()).attach(this); // We are being blocked so we only observe the cell in front of us
        } else { // Not being blocked otherwise
            b.getCellAt(getRow() - 1, getCol()).attach(this); 
            b.getCellAt(getRow() - 2, getCol()).attach(this); 
        }
    } else if (this->getColour() == Colour::Black) { // Not the first move so we only attach one to one cell ahead of us
        int r = getRow();
        if (0 <= r + 1 && r + 1 < 8) {
            b.getCellAt(r + 1, getCol()).attach(this);
        }
    } else {
        int r = getRow();
        if (0 <= r - 1 && r - 1 < 8) {
            b.getCellAt(r - 1, getCol()).attach(this);
        }
    }

    // Now for diagonal ;-;
    int r = getRow();
    int c = getCol();
    if (this->getColour() == Colour::Black) {
        if (0 <= r + 1 && r + 1 < 8 && 0 <= c + 1 && c + 1 < 8 /* &&  b.getCellAt(r + 1,c + 1).getPiece() && b.getCellAt(r + 1,c + 1).getPiece()->getColour() == Colour::White */) { b.getCellAt(r + 1,c + 1).attach(this);}
        if (0 <= r + 1 && r + 1 < 8 && 0 <= c - 1 && c - 1 < 8 /* && b.getCellAt(r + 1,c - 1).getPiece() && b.getCellAt(r + 1,c - 1).getPiece()->getColour() == Colour::White */) { b.getCellAt(r + 1,c - 1).attach(this);}
    } else {
        if (0 <= r - 1 && r - 1 < 8 && 0 <= c + 1 && c + 1 < 8 /* && b.getCellAt(r - 1,c + 1).getPiece() && b.getCellAt(r - 1,c + 1).getPiece()->getColour() == Colour::Black */) { b.getCellAt(r - 1,c + 1).attach(this);}
        if (0 <= r - 1 && r - 1 < 8 && 0 <= c - 1 && c - 1 < 8 /* && b.getCellAt(r - 1,c - 1).getPiece() && b.getCellAt(r - 1,c - 1).getPiece()->getColour() == Colour::Black */) { b.getCellAt(r - 1,c - 1).attach(this);}
    }

}

void Pawn::detachFromCells(Board& b) {
    if (this->getColour() == Colour::Black && this->getRow() == 1) { // For black pieces we go down the grid so increase the row number
        b.getCellAt(getRow() + 1, getCol()).detach(this); 
        b.getCellAt(getRow() + 2, getCol()).detach(this); 
    } else if (this->getColour() == Colour::White && this->getRow() == 6) { // For white pieces we go down the grid so decrease the row number
        b.getCellAt(getRow() - 1, getCol()).detach(this); 
        b.getCellAt(getRow() - 2, getCol()).detach(this); 
    } else if (this->getColour() == Colour::Black) { // Not the first move so we only attach one to one cell ahead of us
        int r = getRow();
        if (0 <= r + 1 && r + 1 < 8) {
            b.getCellAt(r + 1, getCol()).detach(this);
        }
    } else {
        int r = getRow();
        if (0 <= r - 1 && r - 1 < 8) {
            b.getCellAt(r - 1, getCol()).detach(this);
        }
    }

    // Now for diagonal ;-;
    int r = getRow();
    int c = getCol();
    if (this->getColour() == Colour::Black) {
        if (0 <= r + 1 && r + 1 < 8 && 0 <= c + 1 && c + 1 < 8) { b.getCellAt(r + 1,c + 1).detach(this); }
        if (0 <= r + 1 && r + 1 < 8 && 0 <= c - 1 && c - 1 < 8) { b.getCellAt(r + 1,c - 1).detach(this); }
    } else {
        if (0 <= r - 1 && r - 1 < 8 && 0 <= c + 1 && c + 1 < 8) { b.getCellAt(r - 1,c + 1).detach(this); }
        if (0 <= r - 1 && r - 1 < 8 && 0 <= c - 1 && c - 1 < 8) { b.getCellAt(r - 1,c - 1).detach(this); }
    }

}



