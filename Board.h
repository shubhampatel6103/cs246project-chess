#ifndef __BOARD_H__
#define __BOARD_H__
#include "Cell.h"
#include <vector>

class Board {
    int size;
    bool firstPlayerTurn;
    std::vector<std::vector<Cell>> board;

public:
    Board(int size = 8);
    ~Board();
    
    Cell getCellAt(int row, int col);
    bool getCurrentTurn();

    void setup();
    void changeTurn();
    void makeMove(Cell source, Cell Dest);
}