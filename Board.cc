#include "Board.h"
#include <vector>
using namespace std;

Board::Board(int size): size{size} {
    td = make_unique<TextDisplay> ();
    //gd = make_unique<GraphicsDisplay> (size);
    board = vector<vector<Cell>>(size, vector<Cell>(size, Cell(0, 0, Colour::Black)));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            Colour colour = ((i + j) % 2 == 0 ? Colour::White : Colour::Black);
            board[i][j].setRow(i);
            board[i][j].setCol(j);
            board[i][j].setColour(colour);
            board[i][j].attach(td.get());
            // c.attach(gd);
            board[i][j].notifyObservers(*this);
        }
    }
}

Board::~Board() {
    for (auto row : board) {
        row.clear();
    }
    board.clear();
}

Cell& Board::getCellAt(int row, int col) { return board[row][col]; }
bool Board::getCurrentTurn() { return firstPlayerTurn; }

void Board::setupAdd(int row, int col, char piece) {
    unique_ptr<Piece> p = nullptr;
    if (piece == 'K') p = make_unique<King>(piece, Colour::White);
    if (piece == 'Q') p = make_unique<Queen>(piece, Colour::White);
    if (piece == 'R') p = make_unique<Rook>(piece, Colour::White);
    if (piece == 'B') p = make_unique<Bishop>(piece, Colour::White);
    if (piece == 'N') p = make_unique<Knight>(piece, Colour::White);
    if (piece == 'P') p = make_unique<Pawn>(piece, Colour::White);

    if (piece == 'k') p = make_unique<King>(piece, Colour::Black);
    if (piece == 'q') p = make_unique<Queen>(piece, Colour::Black);
    if (piece == 'r') p = make_unique<Rook>(piece, Colour::Black);
    if (piece == 'b') p = make_unique<Bishop>(piece, Colour::Black);
    if (piece == 'n') p = make_unique<Knight>(piece, Colour::Black);
    if (piece == 'p') p = make_unique<Pawn>(piece, Colour::Black);
    
    p->setRow(row);
    p->setCol(col); 

    getCellAt(row, col).addPiece(move(p));
    getCellAt(row, col).notifyObservers(*this);
}

void Board::setupRem(int row, int col) {
    cout << "Row: " << getCellAt(row,col).getRow() << " Col: " << getCellAt(row,col).getCol() << endl;
    cout << getCellAt(row, col).getPiece() << endl;
    cout << "Piece type: " << getCellAt(row, col).getPiece()->getType() << endl;
    getCellAt(row, col).remPiece();
    getCellAt(row, col).notifyObservers(*this);
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
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            Piece * p = getCellAt(i, j).getPiece();
            if (p) {
                if (row_count == 0 || row_count == 7) {
                    if (p->getType() == 'p' || p->getType() == 'P') {
                        return false;
                    }
                }
                if (p->getType() == 'K') {
                    ++king_white;
                }
                if (p->getType() == 'k') {
                    ++king_black;
                }
                if (king_black > 1 || king_white > 1) return false;
            }
        }
        ++row_count;
    }

    for (auto row : board) {
        for (auto cell : row) {
            Piece * p = cell.getPiece();
            if (p) p->notify(cell, *this);
        }
    }
    return true;
}

void Board::makeMove(Cell& source, Cell& dest) {
    // Make move
    if (dest.getPiece()) { dest.getPiece()->detachFromCells(*this); } // Detach the piece at the destination from cells  
    dest.remPiece(); // Remove the piece from the destination cell
    source.getPiece()->detachFromCells(*this); // Detach from the cells the source piece is currently attached to 
    dest.addPiece(source.getActualPiece()); // Add the piece to the new cell
    dest.getPiece()->setRow(dest.getRow()); // Change the position of the piece 
    dest.getPiece()->setCol(dest.getCol());
    dest.getPiece()->attachToCells(*this); // Reattach after changing the position of the piece

    getCellAt(source.getRow(), source.getCol()).notifyObservers(*this);
    getCellAt(dest.getRow(), dest.getCol()).notifyObservers(*this);

    // NOTE - We dont need to remove from the source cell since adding the piece to the destination will give ownership to the destination cell
    

    // Implement checks, checkmate
}

ostream& operator<<(ostream &out, const Board& b) {
    out << *b.td;
    return out;
}
