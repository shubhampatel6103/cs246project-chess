#ifndef __BOARD_H__
#define __BOARD_H__
#include "Cell.h"
#include "Observer.h"
#include "TextDisplay.h"
#include "GraphicsDisplay.h"
#include "Piece.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Rook.h"
#include "Knight.h"
#include "Pawn.h"
#include "Move.h"
#include <memory>
#include <vector>

class Board {
    int size;
    bool firstPlayerTurn = true;
    Move lastMove{false, -1, -1, -1, -1};
    std::vector<std::vector<Cell>> board;
    std::unique_ptr<TextDisplay> td;
    std::unique_ptr<GraphicsDisplay> gd;

public:
    Board(int size = 8);
    ~Board();
    
    Cell& getCellAt(int row, int col);
    bool getCurrentTurn();

    void setupAdd(int row, int col, char piece);
    void setupRem(int row, int col);
    void setupTurn(bool first);
    bool validBoard();
    void changeTurn();
    void makeMove(Cell& source, Cell& Dest);
    void setLastMove(Move& m);
    Move& getLastMove();

    void clearBoard();
    friend std::ostream &operator<<(std::ostream &out, const Board& b);
};

#endif
