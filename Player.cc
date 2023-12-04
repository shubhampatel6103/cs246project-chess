#include "Player.h"
#include "Piece.h"
#include "Board.h"

Player::Player(Colour c): id{c} {}

Move& Player::getMove() { return m; }

bool Player::whiteCastleShort(Board &b, int sX, int sY, int dX, int dY) {
    if (!(!b.getCellAt(sX, sY + 1).getPiece() && !b.getCellAt(sX, sY + 2).getPiece() &&
        b.getCellAt(sX, sY + 3).getPiece() && b.getCellAt(sX, sY + 3).getPiece()->getType() == 'R' && b.getCellAt(sX, sY + 3).getPiece()->getFirst())) {
            return false;
    }
    return true;
}

bool Player::blackCastleShort(Board &b, int sX, int sY, int dX, int dY) {
    if (!(!b.getCellAt(sX, sY + 1).getPiece() && !b.getCellAt(sX, sY + 2).getPiece() &&
        b.getCellAt(sX, sY + 3).getPiece() && b.getCellAt(sX, sY + 3).getPiece()->getType() == 'r' && b.getCellAt(sX, sY + 3).getPiece()->getFirst())) {
            return false;
    }
    return true;
}

bool Player::whiteCastleLong(Board &b, int sX, int sY, int dX, int dY) {
    if (!(!b.getCellAt(sX, sY - 1).getPiece() && !b.getCellAt(sX, sY - 2).getPiece() &&
        !b.getCellAt(sX, sY - 3).getPiece() && b.getCellAt(sX, sY - 4).getPiece() && b.getCellAt(sX, sY - 4).getPiece()->getType() == 'R' && b.getCellAt(sX, sY - 4).getPiece()->getFirst())) {
            return false;
    }
    return true;
}

bool Player::blackCastleLong(Board &b, int sX, int sY, int dX, int dY) {
    if (!(!b.getCellAt(sX, sY - 1).getPiece() && !b.getCellAt(sX, sY - 2).getPiece() &&
        !b.getCellAt(sX, sY - 3).getPiece() && b.getCellAt(sX, sY - 4).getPiece() && b.getCellAt(sX, sY - 4).getPiece()->getType() == 'r' && b.getCellAt(sX, sY - 4).getPiece()->getFirst())) {
            return false;
    }
    return true;
}
