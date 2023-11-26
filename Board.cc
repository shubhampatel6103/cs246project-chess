#include "Board.h"
#include <vector>
using namespace std;

Board::Board(int size): size{size} {
    for (int i = 0; i < size; ++i) {
        Piece::Colour colour = ()
        vector<Cell> row{};
        board[i].emplace_back(row);
        for (int j = 0; j < size; ++j) {
            Cell c(i, j, Piece::Colour::)
            board[i].emplace_back();
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

void Board::setup() {

}
