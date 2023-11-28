#include <iostream>
#include "textdisplay.h"
#include "cell.h"
using namespace std;

TextDisplay::TextDisplay(): {}

void TextDisplay::notify(Cell &c) {
  if (c.getPiece() == nullptr) {
    if (((c.getRow() + c.getCol()) % 2) == 0) {
      theDisplay[c.getRow()][c.getCol() + 1] = ' ';
    } else {
      theDisplay[c.getRow()][c.getCol() + 1] = '_';
    }
  } else if (c.piece()->identify() == 0) {
    if (c.piecce()->team() == 0) {
      theDisplay[c.getRow()][c.getCol() + 1] = 'K';
    } else {
      theDisplay[c.getRow()][c.getCol() + 1] = 'k';
    }
  } else if (c.piece()->identify() == 1) {
    if (c.piecce()->team() == 0) {
      theDisplay[c.getRow()][c.getCol() + 1] = 'Q';
    } else {
      theDisplay[c.getRow()][c.getCol() + 1] = 'q';
    }
  } else if (c.piece()->identify() == 2) {
    if (c.piecce()->team() == 0) {
      theDisplay[c.getRow()][c.getCol() + 1] = 'B';
    } else {
      theDisplay[c.getRow()][c.getCol() + 1] = 'b';
    }
  } else if (c.piece()->identify() == 3) {
    if (c.piecce()->team() == 0) {
      theDisplay[c.getRow()][c.getCol() + 1] = 'N';
    } else {
      theDisplay[c.getRow()][c.getCol() + 1] = 'n';
    }
  } else if (c.piece()->identify() == 4) {
    if (c.piecce()->team() == 0) {
      theDisplay[c.getRow()][c.getCol() + 1] = 'R';
    } else {
      theDisplay[c.getRow()][c.getCol() + 1] = 'r';
    }
  } else if (c.piece()->identify() == 5) {
    if (c.piecce()->team() == 0) {
      theDisplay[c.getRow()][c.getCol() + 1] = 'P';
    } else {
      theDisplay[c.getRow()][c.getCol() + 1] = 'p';
    }
  }
}

TextDisplay::~TextDisplay() {}


ostream &operator<<(ostream &out, const TextDisplay &td) {
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 10; ++j) {
      out << td.theDisplay[i][j];
    }
    out << endl;
  }
  return out;
}
