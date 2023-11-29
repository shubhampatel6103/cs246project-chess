#ifndef __GAME_H__
#define __GAME_H__
//#include "Player.h"
#include "Board.h"

class Game {
    Player* p1;
    Player* p2;
    Board& b;

    public:
        Game(Player* p1, Player* p2, Board& b);
        ~Game();

        void printBoard(); // prints the board to stdout
        void makeMove(int arr[4], Piece* p); // modifies the board state
        void playMove(int p); // plays the move on behalf of the player
};

#endif
