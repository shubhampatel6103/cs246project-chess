#include "Player.h"
#include "Piece.h"

Player::Player(Colour c): id{c} {}

Move& Player::getMove() { return m; }
