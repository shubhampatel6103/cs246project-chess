#include "Pawn.h"
#include "Board.h"

Pawn::Pawn(char type, Colour colour): Piece{type, colour} {}

int Pawn::getPoints() { return points; }

void Pawn::notify(Cell &c, Board &b) {
    this->attachToCells(b);    
}

void Pawn::attachToCells(Board& b) {
    char myType = getType();
    Colour myColour = getColour();

    if (firstMove) {
        if (this->getColour() == Colour::Black) { // For black pieces we go down the grid so increase the row number
            if (b.getCellAt(getRow() + 1, getCol()).getPiece()) { // If there is a piece in front of us when moving for the first time
                b.getCellAt(getRow() + 1, getCol()).attach(std::make_unique<Pawn>(myType, myColour)); // We are being blocked so we only observe the cell in front of us
            } else { // Not being blocked otherwise
                b.getCellAt(getRow() + 1, getCol()).attach(std::make_unique<Pawn>(myType, myColour)); 
                b.getCellAt(getRow() + 2, getCol()).attach(std::make_unique<Pawn>(myType, myColour)); 
            }
        } else { // For white pieces we go down the grid so decrease the row number
            if (b.getCellAt(getRow() - 1, getCol()).getPiece()) { // If there is a piece in front of us when moving for the first time
                b.getCellAt(getRow() - 1, getCol()).attach(std::make_unique<Pawn>(myType, myColour)); // We are being blocked so we only observe the cell in front of us
            } else { // Not being blocked otherwise
                b.getCellAt(getRow() - 1, getCol()).attach(std::make_unique<Pawn>(myType, myColour)); 
                b.getCellAt(getRow() - 2, getCol()).attach(std::make_unique<Pawn>(myType, myColour)); 
            }
        }
    } else { // Not the first move so we only attach one to one cell ahead of us
        if (this->getColour() == Colour::Black) {
            if (0 <= getRow() + 1 < 8) {
                b.getCellAt(getRow() + 1, getCol()).attach(std::make_unique<Pawn>(myType, myColour));
            }
        } else {
            if (0 <= getRow() - 1 < 8) {
                b.getCellAt(getRow() - 1, getCol()).attach(std::make_unique<Pawn>(myType, myColour));
            }
        }
    }

    // Now for diagonal ;-;
    if (this->getColour() == Colour::Black) {
        if (0 <= getRow() + 1 < 8 && 0 <= getCol() + 1 < 8 && b.getCellAt(getRow() + 1,getCol() + 1).getPiece()) { b.getCellAt(getRow() + 1,getCol() + 1).attach(std::make_unique<Pawn>(myType, myColour)); }
        if (0 <= getRow() + 1 < 8 && 0 <= getCol() - 1 < 8 && b.getCellAt(getRow() + 1,getCol() - 1).getPiece()) { b.getCellAt(getRow() + 1,getCol() - 1).attach(std::make_unique<Pawn>(myType, myColour)); }
    } else {
        if (0 <= getRow() - 1 < 8 && 0 <= getCol() + 1 < 8 && b.getCellAt(getRow() - 1,getCol() + 1).getPiece()) { b.getCellAt(getRow() - 1,getCol() + 1).attach(std::make_unique<Pawn>(myType, myColour)); }
        if (0 <= getRow() - 1 < 8 && 0 <= getCol() - 1 < 8 && b.getCellAt(getRow() - 1,getCol() - 1).getPiece()) { b.getCellAt(getRow() - 1,getCol() - 1).attach(std::make_unique<Pawn>(myType, myColour)); }
    }

}

void Pawn::detachFromCells(Board& b) {
    char myType = getType();
    Colour myColour = getColour();

    if (firstMove) {
        if (this->getColour() == Colour::Black) { // For black pieces we go down the grid so increase the row number
            b.getCellAt(getRow() + 1, getCol()).detach(std::make_unique<Pawn>(myType, myColour)); 
            b.getCellAt(getRow() + 2, getCol()).detach(std::make_unique<Pawn>(myType, myColour)); 
        } else { // For white pieces we go down the grid so decrease the row number
            b.getCellAt(getRow() - 1, getCol()).detach(std::make_unique<Pawn>(myType, myColour)); 
            b.getCellAt(getRow() - 2, getCol()).detach(std::make_unique<Pawn>(myType, myColour)); 
        }
    } else { // Not the first move so we only detach from one cell ahead of us
        if (this->getColour() == Colour::Black) {
            if (0 <= getRow() + 1 < 8) {
                b.getCellAt(getRow() + 1, getCol()).detach(std::make_unique<Pawn>(myType, myColour));
            }
        } else {
            if (0 <= getRow() - 1 < 8) {
                b.getCellAt(getRow() - 1, getCol()).detach(std::make_unique<Pawn>(myType, myColour));
            }
        }
    }

    // Now for diagonal ;-;
    if (this->getColour() == Colour::Black) {
        b.getCellAt(getRow() + 1,getCol() + 1).detach(std::make_unique<Pawn>(myType, myColour));
        b.getCellAt(getRow() + 1,getCol() - 1).detach(std::make_unique<Pawn>(myType, myColour)); 
    } else {
        b.getCellAt(getRow() - 1,getCol() + 1).detach(std::make_unique<Pawn>(myType, myColour)); 
        b.getCellAt(getRow() - 1,getCol() - 1).detach(std::make_unique<Pawn>(myType, myColour));
    }

}

