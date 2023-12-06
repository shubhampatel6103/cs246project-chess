#ifndef __GAME_H__
#define __GAME_H__
#include "Player.h"
#include "Board.h"
#include "Move.h"

class Game {
    std::unique_ptr<Player> p1 = nullptr;
    std::unique_ptr<Player> p2 = nullptr;

    public:
        Game();
        ~Game();

        void setPlayers(std::unique_ptr<Player> player1, std::unique_ptr<Player> player2);
        void makeMove(Move& m, Board & b, bool display); // modifies the board state
        char playMove(int p, Board & b); // plays the move on behalf of the player
};

#endif
