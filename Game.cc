#include "Game.h"

using namespace std;

Game::Game(Player* p1, Player* p2, Board& b): p1{p1}, p2{p2}, b{b} {}

Game::~Game() {}

void Game::printBoard() {
    cout << b << endl;
}

void Game::makeMove(int arr[4], Piece* p) {
        b.getCellAt(arr[0],arr[1]).remPiece(); // This is where we were (Source)

    if (b.getCellAt(arr[2],arr[3]).hasPiece()) { // This is where we went (Desitnation)
        b.getCellAt(arr[2],arr[3]).remPiece(); // Remove the piece that already exists
        b.getCellAt(arr[2],arr[3]).addPiece(p); // Add the piece that we moved
    } else {
        b.getCellAt(arr[2],arr[3]).addPiece(p);
    }
}

void Game::playMove(int p) {
    if (p == 1) { // play the move on behalf of p1 if p = 1
        makeMove(p1->playMove(), p1);
    } 
    else { // else, play the move on behalf of p2
        makeMove(p2->playMove(), p2);
    } // Might need to add try excepts, ideally should be handled by player class
}


