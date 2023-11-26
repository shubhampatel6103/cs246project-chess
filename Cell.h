#ifndef __CELL_H__
#define __CELL_H__
#include "Observer.h"
#include <vector>
class Piece;

class Cell {
    int row, col;
    Piece::Colour cellColour;
    Piece * piece;
    std::vector<Observer *> observers{};

public:
    Cell(int row, int col, Piece::Colour colour, Piece * piece);
    ~Cell();

    Piece * getPiece();
    Piece::Colour getColour();
    int getRow();
    int getCol();
    bool hasPiece();
    void addPiece(Piece * newPiece);
    void remPiece();
    void notifyObservers();
    void attach(Observer * o);
    void detach(Observer * o);
}

#endif
