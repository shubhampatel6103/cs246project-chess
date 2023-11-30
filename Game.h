#ifndef __GAME_H__
#define __GAME_H__
#include "Player.h"
#include "Board.h"
#include "Move.h"

class Game {
    Player* p1;
    Player* p2;
    Board& b;

    public:
        Game(Player* p1, Player* p2, Board& b);
        ~Game();

        void printBoard(); // prints the board to stdout
        void makeMove(Move& m, Piece* p); // modifies the board state
        void playMove(int p); // plays the move on behalf of the player
};

#endif
