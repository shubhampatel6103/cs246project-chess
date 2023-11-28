#include "Board.h"
#include <vector>
#include <memory>
using namespace std;

Board::Board(int size): size{size} {
    td = make_unique<TextDisplay> (size /*Args*/);
    gd = make_unique<GraphicsDisplay> (size);
    for (int i = 0; i < size; ++i) {
        Piece::Colour colour = (i % 2 == 0 ? Piece::Colour::White : Piece::Colour::Balck);
        vector<Cell> row{};
        board[i].emplace_back(row);
        for (int j = 0; j < size; ++j) {
            Cell c(i, j, colour, nullptr);
            colour = ( colour == Piece::Colour::White ? Piece::Colour::Black : Piece::Colour::White);
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
    if (piece == "K") {Piece * p = make_unique<King>(piece, 10)}
    Piece * p = make_unique<Piece> (/*Args*/);
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

void Board::makeMove(Cell source, Cell Dest) {
    // Make move
}

ostream& Board::operator<<(ostream &out, const Board &b) {
    return out << td;
}
