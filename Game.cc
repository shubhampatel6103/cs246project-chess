#include "Game.h"

using namespace std;

Game::Game(Player* p1, Player* p2, Board& b): p1{p1}, p2{p2}, b{b} {}

Game::~Game() {}

void Game::printBoard() {
    cout << b << endl;
}

void Game::makeMove(Move& m) {
    b.makeMove(b.getCellAt(m.getCoords()[0], m.getCoords()[1]), b.getCellAt(m.getCoords()[2], m.getCoords()[3]));
}

bool Game::playMove(int p) {
    if (p == 1) { // play the move on behalf of p1 if p = 1
        p1->move(b);
        if (p1->getMove().getResigned()) { return false; }
        makeMove(p1->getMove());
    } 
    else { // else, play the move on behalf of p2
        p2->move(b);
        if (p2->getMove().getResigned()) { return false; }
        makeMove(p2->getMove());
    } // Might need to add try excepts, ideally should be handled by player class
    return true;
}