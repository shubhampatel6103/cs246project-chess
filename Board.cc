#include "Board.h"
#include <vector>
#include <memory>
using namespace std;

Board::Board(int size): size{size} {
    td = make_unique<TextDisplay> ();
    //gd = make_unique<GraphicsDisplay> (size);
    for (int i = 0; i < size; ++i) {
        Colour colour = (i % 2 == 0 ? Colour::White : Colour::Black);
        vector<Cell> row{};
        board[i].emplace_back(row);
        for (int j = 0; j < size; ++j) {
            Cell c(i, j, colour, nullptr);
            colour = ( colour == Colour::White ? Colour::Black : Colour::White);
            c.attach(td);
            c.notifyObservers();
            c.attach(gd);
            board[i].emplace_back(c);
        }
    }
}

Board::~Board() {
    for (auto row : board) {
        row.clear();
    }
    board.clear();
}

Cell Board::getCellAt(int row, int col) { return board[row][col]; }
bool Board::getCurrentTurn() { return firstPlayerTurn; }

void Board::setupAdd(int row, int col, char piece) {
    Piece* p = nullptr; // Should work but please double check @Shubham
    if (piece == 'K') Piece * p = make_unique<King>(piece, Colour::White);
    if (piece == 'Q') Piece * p = make_unique<Queen>(piece, Colour::White);
    if (piece == 'R') Piece * p = make_unique<Rook>(piece, Colour::White);
    if (piece == 'B') Piece * p = make_unique<Bishop>(piece, Colour::White);
    if (piece == 'N') Piece * p = make_unique<Knight>(piece, Colour::White);
    if (piece == 'P') Piece * p = make_unique<Pawn>(piece, Colour::White);

    if (piece == 'k') Piece * p = make_unique<King>(piece, Colour::Black);
    if (piece == 'q') Piece * p = make_unique<Queen>(piece, Colour::Black);
    if (piece == 'r') Piece * p = make_unique<Rook>(piece, Colour::Black);
    if (piece == 'b') Piece * p = make_unique<Bishop>(piece, Colour::Black);
    if (piece == 'n') Piece * p = make_unique<Knight>(piece, Colour::Black);
    if (piece == 'p') Piece * p = make_unique<Pawn>(piece, Colour::Black);
    
    getCellAt(row, col).addPiece(p);
}

void Board::setupRem(int row, int col) {
    getCellAt(row, col).remPiece();
}

void Board::setupTurn(bool first) {
    firstPlayerTurn = first;
}

void Board::changeTurn() {
    if (firstPlayerTurn) firstPlayerTurn = false;
    else firstPlayerTurn = true;
}

bool Board::validBoard() {
    int row = 0, king_black = 0, king_white = 0;
    for (auto row : board) {
        for (auto cell : row) {
            Piece * p = cell.getPiece();
            if (p) {
                if (row == 0 || row == 7) {
                    if (p->getType() == 'p' || p->getType() == 'P') {
                        return false;
                    }
                }
                if (p->getType() == 'K') ++king_white;
                if (p->getType() == 'k') ++king_black;
            }
        }
        ++row;
        if (king_black > 1 || king_white > 1) return false;
    }
    for (auto row : board) {
        for (auto cell : row) {
            Piece * p = cell.getPiece();
            if (p) p->notify(*cell, *this);
        }
    }
    return true;
}

void Board::makeMove(Cell source, Cell Dest) {
    // Make move
}

ostream& operator<<(ostream &out, const Board &b) {
    return out << td;
}
