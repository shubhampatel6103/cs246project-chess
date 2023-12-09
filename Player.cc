#include "Player.h"
#include "Piece.h"
#include "Board.h"
using namespace std;

Player::Player(Colour c): id{c} {}

Move& Player::getMove() { return m; }

bool Player::canCastleShort(Board &b, int sX, int sY, int dX, int dY, Colour attacker) {
    if ((sX != dX) || b.getCellAt(sX, sY + 1).getPiece() || b.getCellAt(sX, sY + 2).getPiece() ||
        !b.getCellAt(sX, sY + 3).getPiece()->getFirst()) {
            return false;
    }

    for (int j = 0; j < 3; ++j) {
        for (unsigned long int i = 2; i < b.getCellAt(sX, sY + j).getObservers().size(); i++) {
            auto p = static_cast<Piece *>(b.getCellAt(sX, sY + j).getObservers()[i]);
            if (p->getColour() == attacker) {
                return false;
            }
        }
    }

    return true;
}

bool Player::canCastleLong(Board &b, int sX, int sY, int dX, int dY, Colour attacker) {
    if ((sX != dX) || b.getCellAt(sX, sY - 1).getPiece() || b.getCellAt(sX, sY - 2).getPiece() ||
        b.getCellAt(sX, sY - 3).getPiece() || !b.getCellAt(sX, sY - 4).getPiece()->getFirst()) {
            return false;
    }

    for (int j = 0; j < 4; ++j) {
        for (unsigned long int i = 2; i < b.getCellAt(sX, sY - j).getObservers().size(); i++) {
            auto p = static_cast<Piece *>(b.getCellAt(sX, sY - j).getObservers()[i]);
            if (p->getColour() == attacker) {
                return false;
            }
        }
    }

    return true;
}



