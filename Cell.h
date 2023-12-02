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
    // Piece * piece;
    std::unique_ptr<Piece> piece = nullptr;
    std::vector<Observer *> observers{};

public:
    Cell(int row = 0, int col = 0, Colour colour = Colour::Black);
    ~Cell();
    Cell(const Cell& c);
    Cell(Cell&& c);
    Piece * getPiece();
    std::unique_ptr<Piece> getActualPiece();
    // shared_ptr<Piece> getPiece();
    Colour getColour();
    int getRow();
    int getCol();
    bool hasPiece();
    bool isPieceObserver(Piece * p);
    void addPiece(std::unique_ptr<Piece> newPiece);
    //void addPiece(Piece * newPiece);
    void remPiece();
    void notifyObservers(Board& b);
    void attach(Observer * o);
    void detach(Observer * o);
    void setRow(int row);
    void setCol(int col);
    void setColour(Colour colour);
};

#endif
