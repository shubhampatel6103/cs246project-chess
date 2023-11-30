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
    std::vector<std::unique_ptr<Observer>> observers{};

public:
    Cell(int row, int col, Colour colour, Piece * piece);
    ~Cell();

    Piece * getPiece();
    Colour getColour();
    int getRow();
    int getCol();
    bool hasPiece();
    void addPiece(Piece * newPiece);
    void remPiece();
    void notifyObservers();
    void attach(std::unique_ptr<Observer> o);
    void detach(std::unique_ptr<Observer> o);
};

#endif
