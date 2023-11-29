#ifndef __CELL_H__
#define __CELL_H__
#include "Observer.h"
#include "Piece.h"
#include <vector>
class Piece;
enum class Colour;

class Cell {
    int row, col;
    Colour cellColour;
    Piece * piece;
    std::vector<Observer *> observers{};

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
    void attach(Observer * o);
    void detach(Observer * o);
};

#endif
