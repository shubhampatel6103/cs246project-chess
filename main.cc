#include <iostream>
#include <string>
#include "Game.h"
#include "Board.h"
#include "Player.h"
#include "Human.h"
#include <memory>
using namespace std;

int BOARD_SIZE = 8;

void defaultSetup(Board * b) {
    b->setupAdd(7, 0, 'R');
    b->setupAdd(7, 1, 'N');
    b->setupAdd(7, 2, 'B');
    b->setupAdd(7, 3, 'Q');
    b->setupAdd(7, 4, 'K');
    b->setupAdd(7, 5, 'B');
    b->setupAdd(7, 6, 'N');
    b->setupAdd(7, 7, 'R');
    b->setupAdd(6, 0, 'P');
    b->setupAdd(6, 1, 'P');
    b->setupAdd(6, 2, 'P');
    b->setupAdd(6, 3, 'P');
    b->setupAdd(6, 4, 'P');
    b->setupAdd(6, 5, 'P');
    b->setupAdd(6, 6, 'P');
    b->setupAdd(6, 7, 'P');

    b->setupAdd(0, 0, 'r');
    b->setupAdd(0, 1, 'n');
    b->setupAdd(0, 2, 'b');
    b->setupAdd(0, 3, 'q');
    b->setupAdd(0, 4, 'k');
    b->setupAdd(0, 5, 'b');
    b->setupAdd(0, 6, 'n');
    b->setupAdd(0, 7, 'r');
    b->setupAdd(1, 0, 'p');
    b->setupAdd(1, 1, 'p');
    b->setupAdd(1, 2, 'p');
    b->setupAdd(1, 3, 'p');
    b->setupAdd(1, 4, 'p');
    b->setupAdd(1, 5, 'p');
    b->setupAdd(1, 6, 'p');
    b->setupAdd(1, 7, 'p');

    b->setupTurn(true);
    b->validBoard();
}

bool validateSetupInput(int row, char col, char piece, string colour) {
    bool input_error = false;
    if (row <= 0 || row > 8) {
        cout << "Error: Row must be between 1 and 8" << endl;
        input_error = true;
    }
    if (col < 'a' || col > 'h') {
        cout << "Error: Col must be between 'a' and 'h'" << endl;
        input_error = true;
    }
    if (colour != "white" && colour != "black") {
        cout << "Error: Colour must be 'white' or 'black'" << endl;
        input_error = true;
    }
    if ((piece != 'K') && (piece != 'k') &&
        (piece != 'Q') && (piece != 'q') &&
        (piece != 'R') && (piece != 'r') &&
        (piece != 'B') && (piece != 'b') &&
        (piece != 'N') && (piece != 'n') &&
        (piece != 'P') && (piece != 'p')) {
        cout << "Error: Invalid piece initial" << endl;
        input_error = true;
    }
    if (input_error) {
        cin.ignore();
        cin.clear();
    }
    return input_error;
}

void mainCommands() {
    cout << endl << "------------------------------" << endl;
    cout << "help: \tlist commands" << endl;
    cout << "setup: \tenters setup mode" << endl;
    cout << "game: \tplays game" << endl;
    cout << "------------------------------" << endl << endl;
}

void setupCommands() {
    cout << endl << "------------------------------" << endl;
    cout << "help: \t\t\tlist commands" << endl;
    cout << "+ [piece] [a-h][1-8]: \tadd piece at cell" << endl;
    cout << "- [a-h][1-8]: \t\tremove piece from cell" << endl;
    cout << "= [white|black]: \tmake it color's turn" << endl;
    cout << "done: \t\t\texit setup mode" << endl;
    cout << "------------------------------" << endl << endl;
}

void invalidCommandMsg() {
    cout << "Invalid command" << endl;
    cout << "Enter 'help' to see valid commands" << endl;
}

void printScores(float white_score, float black_score) {
    cout << "Scores are: " << endl;
    cout << "White: " << white_score << endl;
    cout << "Black: " << black_score << '\n' << endl;
}








int main() {
  cout << "Welcome to Chess246!" << endl;
  cout << "Created by: Rushil Deep, Sharang Goel, Shubham Patel" << endl;
  mainCommands();
  bool custom_game = false; // Wouldn't work perfectly, but it's fine for now
  string cmd;
  Board b;
  float white_score = 0, black_score = 0;

  while (cin >> cmd && !cin.eof()) {
    if (cmd == "game") {
        if (!custom_game) {
            defaultSetup(&b);
        }

        string whitePlayer, blackPlayer;
        cin >> whitePlayer >> blackPlayer;
        unique_ptr<Player> p1 = nullptr;
        unique_ptr<Player> p2 = nullptr;
        if (whitePlayer == "human") {
            p1 = make_unique<Human>(Colour::White);
        } else if (whitePlayer == "computer1") {
            //Player * p1 = make_unique<Noob>();
        } else if (whitePlayer == "computer2") {
            //Player * p1 = make_unique<Pro>();
        } else if (whitePlayer == "computer3") {
            //Player * p1 = make_unique<Magnus>();
        } else if (whitePlayer == "computer4") {
            //Player * p1 = make_unique<Stockfish>();
        }

        if (blackPlayer == "human") {
            p2 = make_unique<Human>(Colour::Black);
        } else if (blackPlayer == "computer1") {
            //Player * p2 = make_unique<Noob>();
        } else if (blackPlayer == "computer2") {
            //Player * p2 = make_unique<Pro>();
        } else if (blackPlayer == "computer3") {
            //Player * p2 = make_unique<Magnus>();
        } else if (blackPlayer == "computer4") {
            //Player * p2 = make_unique<Stockfish>();
        }

        Game g{};
        g.setPlayers(move(p1), move(p2));
        cout << "First player:\t" << whitePlayer << endl;
        cout << "Second player:\t" << blackPlayer << endl;
        cout << b;
        
        while (true) {
            if (b.getCurrentTurn()) {
                char white_move = g.playMove(1, b);
                if (white_move == 'n') {
                    cout << b;
                } else if (white_move == 'r') {
                    cout << "\nBlack Wins!" << endl;
                    ++black_score;
                    b.clearBoard();
                    printScores(white_score, black_score);
                    break;
                } else if (white_move == 'd') {
                    cout << "\nGame Drawn" << endl;
                    white_score += 0.5;
                    black_score += 0.5;
                    b.clearBoard();
                    printScores(white_score, black_score);
                    break;
                } else if (white_move == 'w') {
                    cout << "\nWhite Wins!" << endl;
                    white_score++;
                    b.clearBoard();
                    printScores(white_score, black_score);
                    break;
                }
            } else b.setupTurn(true);

            char black_move = g.playMove(0, b);
            if (black_move == 'n') {
                cout << b;
            } else if (black_move == 'r') {
                cout << "\nWhite Wins!" << endl;
                ++white_score;
                b.clearBoard();
                printScores(white_score, black_score);
                break;
            } else if (black_move == 'd') {
                cout << "\nGame Drawn" << endl;
                white_score += 0.5;
                black_score += 0.5;
                printScores(white_score, black_score);
                break;
            } else if (black_move == 'b') {
                cout << "\nBlack Wins!" << endl;
                black_score++;
                b.clearBoard();
                printScores(white_score, black_score);
                break;
            }
        }

    } else if (cmd == "setup") {
        cout << endl << "Entering SETUP mode" << endl;
        string subCommand;
        while (cin >> subCommand) {
            if (subCommand == "+") {
                char piece, inp_col;
                int row;
                cin >> piece >> inp_col >> row;
                if (validateSetupInput(row, inp_col, piece, "white")) continue;
                int col = inp_col - 'a';
                row = BOARD_SIZE - row;
                b.setupAdd(row, col, piece);
                cout << b;
            } else if (subCommand == "-") {
                char inp_col;
                int row;
                cin >> inp_col >> row;
                if (validateSetupInput(row, inp_col, 'K', "white")) continue;
                int col = inp_col - 'a';
                row = BOARD_SIZE - row;
                b.setupRem(row, col);
                cout << b;
            } else if (subCommand == "=") {
                string colour;
                cin >> colour;
                if (validateSetupInput(1, 'a', 'K', colour)) continue;
                if (colour == "white") b.setupTurn(true);
                else if (colour == "black") b.setupTurn(false);
            } else if (subCommand == "done") {
                if (b.validBoard()) break;
                else cout << "Board setup is invalid" << endl;
                cout << b;
            } else if (subCommand == "help") {
                setupCommands();
            } else {
                invalidCommandMsg();
            }
        }
        cout << endl << "Exiting SETUP mode" << endl;
        custom_game = true;
    } else if (cmd == "help") {
        mainCommands();
    } else {
        invalidCommandMsg();
    }
  }

  cout << "Final Score:" << endl;
  cout << "White: " << white_score << endl;
  cout << "Black: " << black_score << endl;
}
