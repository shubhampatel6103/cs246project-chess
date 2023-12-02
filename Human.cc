#include <iostream>
#include <string>
#include "Human.h"
#include "Board.h"
#include "Move.h"


using namespace std;

Human::Human(Colour c): Player{c} {} 

void Human::move(Board &b) {
  string s;
  while (cin >> s) {
    if (s == "resign") {
      m.setMove(true, -1, -1, -1, -1);
      return;
    }
    if (s == "move") {
      char sourceChar;
      char destChar;
      int sourceInt;
      int destInt;
      while (true) {
        if (!(cin >> sourceChar) || !(cin >> sourceInt) || !(cin >> destChar) || !(cin >> destInt)) {
          cout << "Invalid move command: Try Again" << endl;
          break;
        } else {
          int sX = sourceChar - 'a';
          int sY = 8 - sourceInt;
          int dX = destChar - 'a';
          int dY = 8 - destInt;
          if (sX > 7 || sX < 0 || sY > 7 || sY < 0 || dX > 7 || dX < 0 || dY > 7 || dY < 0) {
            continue;
          }
          //cout << b.getCellAt(sY, sX).hasPiece(); // Always prints 0 even though it has piece
                                                    // Keep happening even in other parts of the code
          if (b.getCellAt(sY, sX).hasPiece() && b.getCellAt(sY, sX).getPiece()->getColour() == id 
              && b.getCellAt(dY, dX).isPieceObserver(b.getCellAt(sY, sX).getPiece())) {
            m.setMove(false, sY, sX, dY, dX);
            return;
          } 
        }
      }
    } else {
      cout << "Invalid command: Try Again" << endl;
    }
  }
}
