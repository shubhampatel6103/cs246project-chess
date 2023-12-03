#include <iostream>
#include "GraphicsDisplay.h"
#include "Cell.h"
using namespace std;

GraphicsDisplay::GraphicsDisplay(int n): gridSize{n} {
  w.fillRectangle(0, 0, WIN_SIZE, WIN_SIZE, Xwindow::Black);
  int len = WIN_SIZE / gridSize;
  for (int i = 0; i < gridSize; ++i) {
    for (int j = 0; j < gridSize; ++j) {
        if ((i + j) % 2 == 0) {
            w.fillRectangle(j * len, i * len, len, len, Xwindow::White);
        }
    }
  }
}

void GraphicsDisplay::notify(Cell &c, Board &b) {
  int len = WIN_SIZE / gridSize;
  string image = "assets/";
  if (c.getPiece() == nullptr) {
    if (c.getColour() == Colour::White) w.fillRectangle(c.getCol() * len, c.getRow() * len, len, len, Xwindow::White);
    else w.fillRectangle(c.getCol() * len, c.getRow() * len, len, len, Xwindow::Black);
    return;
  } else {
    if (c.getPiece()->getType() == 'K') image += "king-white";
    else if (c.getPiece()->getType() == 'Q') image += "queen-white";
    else if (c.getPiece()->getType() == 'R') image += "rook-white";
    else if (c.getPiece()->getType() == 'N') image += "knight-white";
    else if (c.getPiece()->getType() == 'B') image += "bishop-white";
    else if (c.getPiece()->getType() == 'P') image += "pawn-white";
    else if (c.getPiece()->getType() == 'k') image += "king-black";
    else if (c.getPiece()->getType() == 'q') image += "queen-black";
    else if (c.getPiece()->getType() == 'r') image += "rook-black";
    else if (c.getPiece()->getType() == 'n') image += "knight-black";
    else if (c.getPiece()->getType() == 'b') image += "bishop-black";
    else if (c.getPiece()->getType() == 'p') image += "pawn-black";

    if (c.getColour() == Colour::White) image += "-white.png";
    else image += "-white.png";
  }
  w.drawImage(image.c_str(), c.getCol() * len, c.getRow() * len);
}

GraphicsDisplay::~GraphicsDisplay() {
}
