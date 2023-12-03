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

      if (b.getCellAt(sX, sY).hasPiece() && b.getCellAt(sX, sY).getPiece()->getColour() == id
          && b.getCellAt(dX, dY).isPieceObserver(b.getCellAt(sX, sY).getPiece())) {
        if ((b.getCellAt(dX, dY).hasPiece()) && (b.getCellAt(sX, sY).getPiece()->getColour() == b.getCellAt(dX, dY).getPiece()->getColour())) {
          cout << "Invalid move: Try Again" << endl;
          continue; // add enpassant check next
        } else if ((b.getCellAt(sX, sY).getPiece()->getType() == 'p' || b.getCellAt(sX, sY).getPiece()->getType() == 'P')
                  && sY != dY && b.getCellAt(dX, dY).hasPiece()) {
          cout << "Invalid move: Try Again" << endl;
          continue;
        } else {
          m.setMove(false, sX, sY, dX, dY);
        }
        bool t = false;
        unique_ptr<Piece> temp = nullptr;
        if (b.getCellAt(dX, dY).hasPiece()) {
          temp = b.getCellAt(dX, dY).getActualPiece();
          temp.get()->detachFromCells(b);
          t = true;
        }
        b.makeMove(b.getCellAt(sX, sY), b.getCellAt(dX, dY));
        bool check = false;
        for (int i = 0; i < 8; ++i) {
          for (int j = 0; j < 8; ++j) {
            if ((b.getCellAt(i, j).getPiece()->getType() == 'K' || b.getCellAt(i, j).getPiece()->getType() == 'k')
                && b.getCellAt(i, j).getPiece()->getColour() == id) {
              int n = b.getCellAt(i, j).getObservers().size();
              for (int i = 1; i < n; ++i) {
                Piece* observerPiece = dynamic_cast<Piece*>(b.getCellAt(i, j).getObservers()[i]);
                if (observerPiece->getColour() != id) {
                  cout << "Invalid move: Try Again" << endl;
                  check = true;
                }
              }
            }
          }
        }
        b.makeMove(b.getCellAt(dX, dY), b.getCellAt(sX, sY));
        if (t) {
          b.setupAdd(dX, dY, temp.get()->getType());
        }
        if (check) {continue;}
        return;
      } else {
        cout << "Invalid move: Try Again" << endl;
      }
    }
  }
}
