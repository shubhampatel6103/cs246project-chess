#include <iostream>
#include <string>
#include "Game.h"
#include "Board.h"
#include "Player.h"
#include <memory>
using namespace std;

int main() {
  string cmd;
  Board b;

  while (cin >> cmd) {
    if (cmd == "game") {
        string whitePlayer, blackPlayer;
        cin >> whitePlayer >> blackPlayer;
        if (whitePlayer == "human") {
            Player * p1 = make_unique<Human>();
        } else if (whitePlayer == "computer1") {
            Player * p1 = make_unique<Noob>();
        } else if (whitePlayer == "computer2") {
            Player * p1 = make_unique<Pro>();
        } else if (whitePlayer == "computer3") {
            Player * p1 = make_unique<Magnus>();
        } else if (whitePlayer == "computer4") {
            Player * p1 = make_unique<Stockfish>();
        }

        if (blackPlayer == "human") {
            Player * p2 = make_unique<Human>();
        } else if (blackPlayer == "computer1") {
            Player * p2 = make_unique<Noob>();
        } else if (blackPlayer == "computer2") {
            Player * p2 = make_unique<Pro>();
        } else if (blackPlayer == "computer3") {
            Player * p2 = make_unique<Magnus>();
        } else if (blackPlayer == "computer4") {
            Player * p2 = make_unique<Stockfish>();
        }

        Game g{p1, p2, b};

    } else if (cmd == "setup") {
        string subCommand;
        cin >> subCommand;
        if (subCommand == "+") {
            char piece, inp_col;
            int row;
            cin >> piece >> inp_col >> row;
            int col = inp_col - 'a';
            b.setupAdd(row, col, piece);
        } else if (subCommand == "-") {
            char inp_col;
            int row;
            cin >> inp_col >> row;
            int col = imp_col - 'a';
            b.setupRem(row, col);
        } else if (subCommand == "=") {
            string colour;
            cin >> colour;
            if (colour == "White") b.setupTurn(true);
            else if (colour == "Black") b.setupTurn(false);
        } else if (subCommand == "done") {
            if (b.validBoard()) break;
            else cout << "Board setup is invalid" << endl;
            cout << b;
        }
    }
  }
}
