#include "Board.h"
#include <vector>
using namespace std;

Board::Board(int size): size{size} {
    td = make_unique<TextDisplay> ();
    //gd = make_unique<GraphicsDisplay> (size);
    board = vector<vector<Cell>>(size, vector<Cell>(size, Cell(0, 0, Colour::Black, nullptr)));
    
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            Colour colour = ((i + j) % 2 == 0 ? Colour::White : Colour::Black);
            board[i][j].setRow(i);
            board[i][j].setCol(j);
            board[i][j].setColour(colour);
            board[i][j].attach(td.get());
            board[i][j].notifyObservers(*this);
            // c.attach(gd);
            // string colourstr =  board[i][j].getColour() == Colour::White ? "White" : "Black" ;
            // cout << "Row: " << board[i][j].getRow() << " Col: " << board[i][j].getCol() << " Colour: " << colourstr << endl;
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
    // Piece* p = nullptr; 
    unique_ptr<Piece> p = nullptr;
    if (piece == 'K') p = make_unique<King>(piece, Colour::White);
    if (piece == 'Q') p = make_unique <Queen>(piece, Colour::White);
    if (piece == 'R') p = make_unique <Rook>(piece, Colour::White);
    if (piece == 'B') p = make_unique <Bishop>(piece, Colour::White);
    if (piece == 'N') p = make_unique <Knight>(piece, Colour::White);
    if (piece == 'P') p = make_unique <Pawn>(piece, Colour::White);

    if (piece == 'k') p = make_unique <King>(piece, Colour::Black);
    if (piece == 'q') p = make_unique <Queen>(piece, Colour::Black);
    if (piece == 'r') p = make_unique <Rook>(piece, Colour::Black);
    if (piece == 'b') p = make_unique <Bishop>(piece, Colour::Black);
    if (piece == 'n') p = make_unique <Knight>(piece, Colour::Black);
    if (piece == 'p') p = make_unique <Pawn>(piece, Colour::Black);
    
    p->setRow(row);
    p->setCol(col); 
    cout << "Row: " << getCellAt(row,col).getRow() << " Col: " << getCellAt(row,col).getCol() << endl; // THIS IS WORKING

    // board[row][col].addPiece(p.get());
    getCellAt(row, col).addPiece(p.get());
    p->attachToCells(*this); // We need this dont we?
    cout << getCellAt(row, col).getPiece() << endl;
    Cell c = getCellAt(row, col);
    td->notify(c, *this);
}

void Board::setupRem(int row, int col) {
    getCellAt(row, col).remPiece();
    // board[row][col].remPiece();
    Cell c = getCellAt(row, col);
    td->notify(c, *this);
    
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

void Board::makeMove(Cell source, Cell dest) {
    // Make move
    if (dest.getPiece()) { dest.getPiece()->detachFromCells(*this); } // Detach the piece at the destination from cells  
    dest.remPiece(); // Remove the piece from the destination cell
    source.getPiece()->detachFromCells(*this); // Detach from the cells the source piece is currently attached to 
    dest.addPiece(source.getPiece()); // Add the piece to the new cell
    source.getPiece()->setRow(dest.getRow()); // Change the position of the piece 
    source.getPiece()->setCol(dest.getCol());
    source.getPiece()->attachToCells(*this); // Reattach after changing the position of the piece

    // NOTE - We dont need to remove from the source cell since adding the piece to the destination will give ownership to the destination cell
    

    // Implement checks, checkmate
}

ostream& operator<<(ostream &out, const Board& b) {
    out << *(dynamic_cast<TextDisplay *> (b.td.get()));
    // out << *(b.td.get());
    return out;
}
