#include <iostream>
#include "TextDisplay.h"
#include "Cell.h"
using namespace std;

TextDisplay::TextDisplay() {}

void TextDisplay::notify(Cell &c, Board &b, bool display) {
  if (display) {
    if (c.getPiece() == nullptr) {
      if (((c.getRow() + c.getCol()) % 2) == 0) {
        theDisplay[c.getRow()][c.getCol() + 2] = ' ';
      } else {
        theDisplay[c.getRow()][c.getCol() + 2] = '_';
      }
    } else {
      theDisplay[c.getRow()][c.getCol() + 2] = c.getPiece()->getType();
    }
  }
}

TextDisplay::~TextDisplay() {}


ostream &operator<<(ostream &out, const TextDisplay &td) {
  cout << endl << "====== Current Board ======" << endl;
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      out << td.theDisplay[i][j];
    }
    out << endl;
  }
  cout << "===========================" << endl << endl;
  return out;
}



