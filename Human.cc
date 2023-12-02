#include <iostream>
#include <string>
#include "Human.h"
#include "Board.h"
#include "Move.h"


using namespace std;

Human::Human(Colour c): Player{c} {} 

void Human::move(Board &b) {
  string s;
  while (true) {
    if ((cin >> s)) {
      if (! (s == "move" || s == "resign")) {
        cout << "Invalid command: Try Again" << endl;
        continue;
      }
    } else {
      cout << "Invalid command: Try Again" << endl;
      break;
    }

    if (s == "resign") {
      m.setMove(true, -1, -1, -1, -1);
      return;
    }

    char sourceChar;
    char destChar;
    int sourceInt;
    int destInt;
    if (!(cin >> sourceChar) || !(cin >> sourceInt) || !(cin >> destChar) || !(cin >> destInt)) {
      cout << "Failed to read move coordinates: Try Again" << endl;
      continue;
    } else {
      int sY = sourceChar - 'a';
      int sX = 7 - (sourceInt - 1);
      int dY = destChar - 'a';
      int dX = 7 - (destInt - 1);
      if (sX > 7 || sX < 0 || sY > 7 || sY < 0 || dX > 7 || dX < 0 || dY > 7 || dY < 0) {
        cout << "Inavlid move coordinates: Try Again" << endl;
        continue;
      }

      if (b.getCellAt(sX, sY).hasPiece() && (b.getCellAt(sX, sY).getPiece()->getType() == 'p' || b.getCellAt(sX, sY).getPiece()->getType() == 'P')) {
        char type = b.getCellAt(sX, sY).getPiece()->getType();
        if (type == 'p' && (dX == sX + 1) && b.getCellAt(dX, dY).hasPiece()) {
          cout << "Invalid move: Try Again" << endl;
          continue;
        } else if (type == 'P' && (dX == sX - 1) && b.getCellAt(dX, dY).hasPiece()) {
          cout << "Invalid move: Try Again" << endl;
          continue;
        } else if (type == 'P' && (dX == sX - 1) && (dY == sY + 1 || dY == sY - 1) && !b.getCellAt(dX, dY).hasPiece()) {
          cout << "Invalid move: Try Again" << endl;
          continue;
        } else if (type == 'p' && (dX == sX + 1) && (dY == sY + 1 || dY == sY - 1) && !b.getCellAt(dX, dY).hasPiece()) {
          cout << "Invalid move: Try Again" << endl;
          continue;
        }
      }

      if (b.getCellAt(sX, sY).hasPiece() && b.getCellAt(sX, sY).getPiece()->getColour() == id && b.getCellAt(dX, dY).isPieceObserver(b.getCellAt(sX, sY).getPiece()) && 
         (!b.getCellAt(dX, dY).hasPiece() || b.getCellAt(dX, dY).getPiece()->getColour() != id)) {
        m.setMove(false, sX, sY, dX, dY);
        return;
      } else {
        cout << "Invalid move: Try Again" << endl;
      }
    }
  }
}
