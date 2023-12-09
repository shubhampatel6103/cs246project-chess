#include <iostream>
#include "GraphicsDisplay.h"
#include "Cell.h"
using namespace std;

GraphicsDisplay::GraphicsDisplay(int n): gridSize{n} {
}

void GraphicsDisplay::notify(Cell &c, Board &b, bool display) {
  if (!(display)) return;
    int len = WIN_SIZE / gridSize;
    string image = "assets/";
    if (!c.hasPiece()) {
      if (c.getColour() == Colour::White) w.drawImage("assets/empty-white.png", c.getCol() * len, c.getRow() * len);
      else w.drawImage("assets/empty-green.png", c.getCol() * len, c.getRow() * len);
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
      else image += "-green.png";
    }
    //cout << "Image string:" << image.c_str() << endl;
    w.drawImage(image.c_str(), c.getCol() * len, c.getRow() * len);
}

GraphicsDisplay::~GraphicsDisplay() {
}
