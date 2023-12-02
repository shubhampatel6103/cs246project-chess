#include "Game.h"

using namespace std;

Game::Game(Board& b): b{b} {}

Game::~Game() {}

void Game::setPlayers(unique_ptr<Player> player1, unique_ptr<Player> player2) {
    p1 = move(player1);
    p2 = move(player2);
}

void Game::printBoard() {
    cout << b;
}

void Game::makeMove(Move& m) {
    b.makeMove(b.getCellAt(m.getCoords()[0], m.getCoords()[1]), b.getCellAt(m.getCoords()[2], m.getCoords()[3]));
}

bool Game::playMove(int p) {
    if (p == 1) { // play the move on behalf of p1 if p = 1
        p1.get()->move(b);
        if (p1->getMove().getResigned()) { return false; }
        makeMove(p1->getMove());
    } 
    else { // else, play the move on behalf of p2
        p2.get()->move(b);
        if (p2->getMove().getResigned()) { return false; }
        makeMove(p2->getMove());
    } // Might need to add try excepts, ideally should be handled by player class
    return true;
}