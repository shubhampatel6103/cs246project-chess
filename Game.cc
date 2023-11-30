#include "Game.h"

using namespace std;

Game::Game(Player* p1, Player* p2, Board& b): p1{p1}, p2{p2}, b{b} {}

Game::~Game() {}

void Game::printBoard() {
    cout << b << endl;
}

void Game::makeMove(Move& m, Piece* p) {
        b.getCellAt(m.getCoords()[0], m.getCoords()[1]).remPiece(); // This is where we were (Source)

    if (b.getCellAt(m.getCoords()[2],m.getCoords()[3]).hasPiece()) { // This is where we went (Desitnation)
        b.getCellAt(m.getCoords()[2],m.getCoords()[3]).remPiece(); // Remove the piece that already exists
        b.getCellAt(m.getCoords()[2],m.getCoords()[3]).addPiece(p); // Add the piece that we moved
    } else {
        b.getCellAt(m.getCoords()[2],m.getCoords()[3]).addPiece(p);
    }
}

void Game::playMove(int p) {
    if (p == 1) { // play the move on behalf of p1 if p = 1
        p1->move(b);
        makeMove(p1->getMove(), p1);
    } 
    else { // else, play the move on behalf of p2
        makeMove(p2->move(b), p2);
    } // Might need to add try excepts, ideally should be handled by player class
}


