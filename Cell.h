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
    std::unique_ptr<Piece> piece = nullptr;
    std::vector<Observer *> observers{};

public:
    Cell(int row = 0, int col = 0, Colour colour = Colour::Black); // Ctor
    ~Cell(); // Dtor
    Cell(const Cell& c); // Copy ctor
    Cell(Cell&& c); // Move ctor

    Piece * getPiece();
    std::unique_ptr<Piece> getActualPiece();
    Colour getColour();
    int getRow();
    int getCol();
    
    bool hasPiece();
    bool isPieceObserver(Piece * p);
    void addPiece(std::unique_ptr<Piece> newPiece);
    void remPiece();
    void notifyObservers(Board& b);
    void attach(Observer * o);
    void detach(Observer * o);
    void setRow(int row);
    void setCol(int col);
    void setColour(Colour colour);
};

#endif
