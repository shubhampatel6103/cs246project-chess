#include "Pawn.h"

Pawn::Pawn(): Piece('p', 1), firstMove{true} {};

void Pawn::attachToCells(Board& b) {
    if (firstMove) {
        if (this->getColour() == Colour::Black) {

        } else {

        }
    } else {
        if (this->getColour() == Colour::Black) {

        } else {
            
        }
    }
}

