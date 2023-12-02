#ifndef __CELL_H__
#define __CELL_H__
#include "Piece.h"
#include "Observer.h"
#include <vector>
#include <memory>
#include <iostream>
class Observer;
class Piece;

enum class Colour;

class Cell {
    int row, col;
    Colour cellColour;
    Piece * piece;
    // unique_ptr<Piece> piece;
    std::vector<Observer *> observers;

public:
    Cell(int row, int col, Colour colour, Piece * piece);
    ~Cell();

    Piece * getPiece();
    // unique_ptr<Piece> getPiece();
    Colour getColour();
    int getRow();
    int getCol();
    bool hasPiece();
    bool isPieceObserver(Piece * p);
    // void addPiece(shared_ptr<Piece> newPiece);
    void addPiece(Piece * newPiece);
    void remPiece();
    void notifyObservers(Board& b);
    void attach(Observer * o);
    void detach(Observer * o);
    void setRow(int row);
    void setCol(int col);
    void setColour(Colour colour);
};

#endif
