#include "Board.h"
#include <vector>
using namespace std;

Board::Board(int size): size{size} {
    td = make_unique<TextDisplay> ();
    //gd = make_unique<GraphicsDisplay> (size);
    board = vector<vector<Cell>>(size, vector<Cell>(size, Cell(0, 0, Colour::Black, nullptr)));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            Colour colour = (i + j % 2 == 0 ? Colour::White : Colour::Black);
            Cell c(i, j, colour, nullptr);
            c.attach(td.get());
            c.notifyObservers(*this);
            // c.attach(gd);
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
    Piece* p = nullptr; 
    if (piece == 'K') unique_ptr<Piece> p = make_unique<King>(piece, Colour::White);
    if (piece == 'Q') unique_ptr<Piece> p = make_unique<Queen>(piece, Colour::White);
    if (piece == 'R') unique_ptr<Piece> p = make_unique<Rook>(piece, Colour::White);
    if (piece == 'B') unique_ptr<Piece> p = make_unique<Bishop>(piece, Colour::White);
    if (piece == 'N') unique_ptr<Piece> p = make_unique<Knight>(piece, Colour::White);
    if (piece == 'P') unique_ptr<Piece> p = make_unique<Pawn>(piece, Colour::White);

    if (piece == 'k') unique_ptr<Piece> p = make_unique<King>(piece, Colour::Black);
    if (piece == 'q') unique_ptr<Piece> p = make_unique<Queen>(piece, Colour::Black);
    if (piece == 'r') unique_ptr<Piece> p = make_unique<Rook>(piece, Colour::Black);
    if (piece == 'b') unique_ptr<Piece> p = make_unique<Bishop>(piece, Colour::Black);
    if (piece == 'n') unique_ptr<Piece> p = make_unique<Knight>(piece, Colour::Black);
    if (piece == 'p') unique_ptr<Piece> p = make_unique<Pawn>(piece, Colour::Black);
    
    getCellAt(row, col).addPiece(p);
    Cell c = getCellAt(row, col);
    td->notify(c, *this);
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
    int row_count = 0, king_black = 0, king_white = 0;
    for (auto row : board) {
        for (auto cell : row) {
            Piece * p = cell.getPiece();
            if (p) {
                if (row_count == 0 || row_count == 7) {
                    if (p->getType() == 'p' || p->getType() == 'P') {
                        return false;
                    }
                }
                if (p->getType() == 'K') ++king_white;
                if (p->getType() == 'k') ++king_black;
            }
        }
        ++row_count;
        if (king_black > 1 || king_white > 1) return false;
    }
    for (auto row : board) {
        for (auto cell : row) {
            Piece * p = cell.getPiece();
            if (p) p->notify(cell, *this);
        }
    }
    return true;
}

void Board::makeMove(Cell source, Cell Dest) {
    // Make move
}

ostream& operator<<(ostream &out, const Board& b) {
    out << *(dynamic_cast<TextDisplay *> (b.td.get()));
    // out << *(b.td.get());
    return out;
}
