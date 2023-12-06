#include "Board.h"
#include <vector>
using namespace std;

Board::Board(int size): size{size} {
    td = make_unique<TextDisplay> ();
    gd = make_unique<GraphicsDisplay> (size);
    board = vector<vector<Cell>>(size, vector<Cell>(size, Cell(0, 0, Colour::Black)));
    for (int i = 0; i < size; ++i) { // Sets up cells on the board and outputs to display
        for (int j = 0; j < size; ++j) {
            Colour colour = ((i + j) % 2 == 0 ? Colour::White : Colour::Black);
            board[i][j].setRow(i);
            board[i][j].setCol(j);
            board[i][j].setColour(colour);
            board[i][j].attach(td.get());
            board[i][j].attach(gd.get());
            board[i][j].notifyObservers(*this, true);
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

void Board::setupAdd(int row, int col, char piece, bool display) {
    unique_ptr<Piece> p = nullptr; // Add the correct object depending on piece type
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
    getCellAt(row,col).getPiece()->attachToCells(*this);
    getCellAt(row,col).notifyObservers(*this, display);
}

void Board::setupRem(int row, int col, bool display) { // Remove piece from the cell
    getCellAt(row, col).getPiece()->detachFromCells(*this);
    getCellAt(row, col).remPiece();
    getCellAt(row, col).notifyObservers(*this, display);
}

void Board::setupTurn(bool first) {
    firstPlayerTurn = first;
}

void Board::changeTurn() {
    if (firstPlayerTurn) firstPlayerTurn = false;
    else firstPlayerTurn = true;
}

bool Board::validBoard() { // Checks if the custom setup of the board is valid and initiates observer pattern on pieces
    int row_count = 0, king_black = 0, king_white = 0;
    int king_white_x = 0;
    int king_white_y = 0;
    int king_black_x = 0;
    int king_black_y = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            Piece * p = getCellAt(i, j).getPiece();
            if (p) {
                if (row_count == 0 || row_count == 7) {
                    if (p->getType() == 'p' || p->getType() == 'P') {
                        cout << "Incorrect pawn placement (on last row)" << endl;
                        return false;
                    }
                }
                if (p->getType() == 'K') {
                    ++king_white;
                    king_white_x = i;
                    king_white_y = j;
                }
                if (p->getType() == 'k') {
                    ++king_black;
                    king_black_x = i;
                    king_black_y = j;
                }
            }
        }
        ++row_count;
    }
    if (! (king_black == 1 && king_white == 1)) {
        cout << "Invalid number of kings" << endl;   
        return false;
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            Piece * p = getCellAt(i, j).getPiece();
            if (p) p->notify(getCellAt(i, j), *this, true);
        }
    }

    for (unsigned long int i = 2; i < getCellAt(king_white_x, king_white_y).getObservers().size(); i++) {
        auto p = static_cast<Piece *>(getCellAt(king_white_x, king_white_y).getObservers()[i]);
        if (p->getColour() == Colour::Black) {
            if (! (p->getType() == 'p' && p->getRow() == king_white_x - 1 && p->getCol() == king_white_y)) return false;
        }
    }
    
    for (unsigned long int i = 2; i < getCellAt(king_black_x, king_black_y).getObservers().size(); i++) {
        auto p = static_cast<Piece *>(getCellAt(king_black_x, king_black_y).getObservers()[i]);
        if (p->getColour() == Colour::White) {
            if (! (p->getType() == 'P' && p->getRow() == king_black_x + 1 && p->getCol() == king_black_y)) return false;
        }
    }

    return true;
}

void Board::makeMove(Cell& source, Cell& dest, bool display) {
    // Make move

    if (dest.getPiece()) { 
        dest.getPiece()->detachFromCells(*this);
        dest.remPiece();
    } // Detach the piece at the destination from cells  
    // dest.remPiece(); // Remove the piece from the destination cell
    source.getPiece()->detachFromCells(*this); // Detach from the cells the source piece is currently attached to 
    dest.addPiece(source.getActualPiece()); // Add the piece to the new cell
    dest.getPiece()->setRow(dest.getRow()); // Change the position of the piece 
    dest.getPiece()->setCol(dest.getCol());
    dest.getPiece()->attachToCells(*this); // Reattach after changing the position of the piece

    getCellAt(source.getRow(), source.getCol()).notifyObservers(*this, display);
    getCellAt(dest.getRow(), dest.getCol()).notifyObservers(*this, display);

    // NOTE - We dont need to remove from the source cell since adding the piece to the destination will give ownership to the destination cell
}

Move& Board::getLastMove() { return lastMove; }

void Board::setLastMove(Move& m) { lastMove.setMove(false, m.getCoords()[0], m.getCoords()[1], m.getCoords()[2], m.getCoords()[3]); }

void Board::clearBoard() { // Empties the board
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; j++) {
            if (getCellAt(i,j).getPiece()) {
                getCellAt(i,j).getPiece()->detachFromCells(*this);
                getCellAt(i,j).remPiece();
                getCellAt(i,j).notifyObservers(*this, true);
            }
        }
    }
}

ostream& operator<<(ostream &out, const Board& b) { // Prints the board
    out << *b.td;
    return out;
}
