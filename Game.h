#ifndef __GAME_H__
#define __GAME_H__
#include "Player.h"
#include "Board.h"
#include "Move.h"

class Game {
    std::unique_ptr<Player> p1 = nullptr;
    std::unique_ptr<Player> p2 = nullptr;
    Board& b;

    public:
        Game(Board& b);
        ~Game();

        void setPlayers(std::unique_ptr<Player> player1, std::unique_ptr<Player> player2);
        void printBoard(); // prints the board to stdout
        void makeMove(Move& m); // modifies the board state
        bool playMove(int p); // plays the move on behalf of the player
};

#endif
