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
    try {

      if ((cin >> s) && !cin.eof()) {
        if (! (s == "move" || s == "resign" || s == "draw")) {
          cout << "Invalid command: Try Again" << endl;
          throw "invalid string";
        }
      } else {
        cout << "Invalid command: Try Again" << endl;
        break;
      }

      if (s == "resign") {
        m.setMove(true, -1, -1, -1, -1);
        return;
      }

      if (s == "draw") {
        cout << "Would you like to draw the game?" << endl;
        cout << "Enter Y to draw, N to decline" << endl;
        char ch;
        cin >> ch;
        if (ch == 'Y') {
          m.setMove(false, 100,100,100,100); // 100 is the ascii value of d. d for draw so yea :3
          return; // Dont continue
        } else {
          cout << "Draw request declined" << endl;
          continue;
        }
      }

      char sourceChar;
      char destChar;
      int sourceInt;
      int destInt;
      if (!(cin >> sourceChar) || !(cin >> sourceInt) || !(cin >> destChar) || !(cin >> destInt)) {
        cout << "Failed to read move coordinates: Try Again" << endl;
        throw "invalid string";
      } else {
        int sY = sourceChar - 'a';
        int sX = 7 - (sourceInt - 1);
        int dY = destChar - 'a';
        int dX = 7 - (destInt - 1);
        if (sX > 7 || sX < 0 || sY > 7 || sY < 0 || dX > 7 || dX < 0 || dY > 7 || dY < 0) {
          cout << "Invalid move coordinates: Try Again" << endl;
          continue;
        }

        // King logic
        if (b.getCellAt(sX, sY).hasPiece() && ((b.getCellAt(sX, sY).getPiece()->getType() == 'K' || b.getCellAt(sX, sY).getPiece()->getType() == 'k'))) {
          char type = b.getCellAt(sX, sY).getPiece()->getType();
          bool firstMove = b.getCellAt(sX, sY).getPiece()->getFirst();
          // Short castle
          if ((type == 'K' && firstMove && (sX == 7) && (dY == sY + 2) && b.getCellAt(sX, sY + 3).hasPiece() && b.getCellAt(sX, sY + 3).getPiece()->getType() == 'R' && canCastleShort(b, sX, sY, dX, dY, Colour::Black)) ||
              (type == 'k' && firstMove && (sX == 0) && (dY == sY + 2) && b.getCellAt(sX, sY + 3).hasPiece() && b.getCellAt(sX, sY + 3).getPiece()->getType() == 'r' && canCastleShort(b, sX, sY, dX, dY, Colour::White))) {
              m.setMove(false, sX, sY, dX, dY);
              b.getCellAt(dX, sY + 3).getPiece()->setFirst(false);
              b.getCellAt(dX, sY).getPiece()->setFirst(false);
              b.getCellAt(dX, sY + 1).remPiece(); // Remove the piece from the destination cell of rook
              b.getCellAt(dX, sY + 3).getPiece()->detachFromCells(b); // Detach from the cells the source piece is currently attached to 
              b.getCellAt(dX, sY + 1).addPiece(b.getCellAt(dX, sY + 3).getActualPiece()); // Add the piece to the new cell
              b.getCellAt(dX, sY + 1).getPiece()->setRow(b.getCellAt(dX, sY + 1).getRow()); // Change the position of the piece 
              b.getCellAt(dX, sY + 1).getPiece()->setCol(b.getCellAt(dX, sY + 1).getCol());
              b.getCellAt(dX, sY + 1).getPiece()->attachToCells(b); // Reattach after changing the position of the piece
              b.getCellAt(dX, sY + 3).notifyObservers(b, true);
              b.getCellAt(dX, sY + 1).notifyObservers(b, true);
              return;
          } // Long castle 
          else if ((type == 'K' && firstMove && (sX == 7) && (dY == sY - 2) && b.getCellAt(sX, sY - 4).hasPiece() && b.getCellAt(sX, sY - 4).getPiece()->getType() == 'R' && canCastleLong(b, sX, sY, dX, dY, Colour::Black)) ||
                  (type == 'k' && firstMove && (sX == 0) && (dY == sY - 2) && b.getCellAt(sX, sY - 4).hasPiece() && b.getCellAt(sX, sY - 4).getPiece()->getType() == 'r' && canCastleLong(b, sX, sY, dX, dY, Colour::White))) {
              m.setMove(false, sX, sY, dX, dY);
              b.getCellAt(dX, sY - 4).getPiece()->setFirst(false);
              b.getCellAt(dX, sY).getPiece()->setFirst(false);
              b.getCellAt(dX, sY - 1).remPiece(); // Remove the piece from the destination cell of rook
              b.getCellAt(dX, sY - 4).getPiece()->detachFromCells(b); // Detach from the cells the source piece is currently attached to 
              b.getCellAt(dX, sY - 1).addPiece(b.getCellAt(dX, sY - 4).getActualPiece()); // Add the piece to the new cell
              b.getCellAt(dX, sY - 1).getPiece()->setRow(b.getCellAt(dX, sY - 1).getRow()); // Change the position of the piece 
              b.getCellAt(dX, sY - 1).getPiece()->setCol(b.getCellAt(dX, sY - 1).getCol());
              b.getCellAt(dX, sY - 1).getPiece()->attachToCells(b); // Reattach after changing the position of the piece
              b.getCellAt(dX, sY - 4).notifyObservers(b, true);
              b.getCellAt(dX, sY - 1).notifyObservers(b, true);
              return;
          }
        }


        bool enpassant = false;
        if (b.getCellAt(sX, sY).hasPiece() && b.getCellAt(sX, sY).getPiece()->getColour() == id
            && b.getCellAt(dX, dY).isPieceObserver(b.getCellAt(sX, sY).getPiece())) {
          
          if (b.getCellAt(sX, sY).getPiece()->getType() == 'P') {
            if (dY < sY && sX == dX + 1 && b.getCellAt(sX, dY).hasPiece() && b.getCellAt(sX, dY).getPiece()->getType() == 'p') {
              // cout << "passes 2" << endl;
              if ((b.getLastMove().getCoords()[2] - b.getLastMove().getCoords()[0] == 2) &&
                  b.getLastMove().getCoords()[2] == sX && b.getLastMove().getCoords()[3] == dY) {
                b.getCellAt(sX, dY).remPiece(); 
                b.getCellAt(sX, dY).notifyObservers(b, true);
                m.setMove(false, sX, sY, sX - 1, sY - 1);
                enpassant = true;
              }
            }

            if (dY > sY && sX == dX + 1 && b.getCellAt(sX, dY).hasPiece() && b.getCellAt(sX, dY).getPiece()->getType() == 'p') {
              // cout << "passes 2" << endl;
              if ((b.getLastMove().getCoords()[2] - b.getLastMove().getCoords()[0] == 2) &&
                  b.getLastMove().getCoords()[2] == sX && b.getLastMove().getCoords()[3] == dY) {
                b.getCellAt(sX, dY).remPiece(); 
                b.getCellAt(sX, dY).notifyObservers(b, true);
                m.setMove(false, sX, sY, sX - 1, sY + 1);
                enpassant = true;
              }
            }
          }

          if (b.getCellAt(sX, sY).getPiece()->getType() == 'p') { // If we have a black pawn
            if (dY < sY && sX == dX - 1 && b.getCellAt(sX, dY).hasPiece() && b.getCellAt(sX, dY).getPiece()->getType() == 'P') {
              // cout << "passes 2" << endl;
              if ((b.getLastMove().getCoords()[2] - b.getLastMove().getCoords()[0] == -2) &&
                  b.getLastMove().getCoords()[2] == sX && b.getLastMove().getCoords()[3] == dY) {
                b.getCellAt(sX, dY).remPiece(); 
                b.getCellAt(sX, dY).notifyObservers(b, true);
                m.setMove(false, sX, sY, dX, dY);
                enpassant = true;
              }
            }

            if (dY > sY && sX == dX - 1 && b.getCellAt(sX, dY).hasPiece() && b.getCellAt(sX, dY).getPiece()->getType() == 'P') {
              // cout << "passes 2" << endl;
              if ((b.getLastMove().getCoords()[2] - b.getLastMove().getCoords()[0] == -2) &&
                  b.getLastMove().getCoords()[2] == sX && b.getLastMove().getCoords()[3] == dY) {
                b.getCellAt(sX, dY).remPiece(); 
                b.getCellAt(sX, dY).notifyObservers(b, true);
                m.setMove(false, sX, sY, dX, dY);
                enpassant = true;
              }
            }
          }

          if (!enpassant) {
            if ((b.getCellAt(dX, dY).hasPiece()) && (b.getCellAt(sX, sY).getPiece()->getColour() == b.getCellAt(dX, dY).getPiece()->getColour())) {
              
              // cout << "1" << endl;
              cout << "Invalid move: Try Again" << endl;
              continue; // add enpassant check next
            } else if ((b.getCellAt(sX, sY).getPiece()->getType() == 'p' || b.getCellAt(sX, sY).getPiece()->getType() == 'P')
                      && sY == dY && b.getCellAt(dX, dY).hasPiece()) {
              // cout << "2" << endl;
              cout << "Invalid move: Try Again" << endl;
              continue;
            } else if ((b.getCellAt(sX, sY).getPiece()->getType() == 'p' || b.getCellAt(sX, sY).getPiece()->getType() == 'P')
                      && sY != dY && !b.getCellAt(dX, dY).hasPiece()) {
              // cout << "3" << endl;
              cout << "Invalid move: Try Again" << endl;
              continue;
            } else {
              m.setMove(false, sX, sY, dX, dY);
            }
          }
          bool t = false;
          unique_ptr<Piece> temp = nullptr;
          if (b.getCellAt(dX, dY).hasPiece()) {
            temp = b.getCellAt(dX, dY).getActualPiece();
            temp.get()->detachFromCells(b);
            t = true;
          }

          b.makeMove(b.getCellAt(sX, sY), b.getCellAt(dX, dY), false);
          bool check = false;
          for (int i = 0; i < 8 && (!check); ++i) {
            for (int j = 0; j < 8 && (!check); ++j) {
              if (!b.getCellAt(i, j).hasPiece()) {
                continue;
              }
              if ((b.getCellAt(i, j).getPiece()->getType() == 'K' || b.getCellAt(i, j).getPiece()->getType() == 'k')
                  && b.getCellAt(i, j).getPiece()->getColour() == id) {
                // int n = b.getCellAt(i, j).getObservers().size();
                int observer_size = b.getCellAt(i, j).getObservers().size();
                vector<Observer *> temp_observers(observer_size, nullptr);
                for (int r = 0; r < observer_size; ++r) {
                  temp_observers[r] = b.getCellAt(i, j).getObservers()[r];
                }

                for (int k = 2; k < observer_size; ++k) { // change to 2
                  //cout << b.getCellAt(i, j).getObservers()[1] << endl;
                  Piece* observerPiece = dynamic_cast<Piece*>(temp_observers[k]);
                  if (observerPiece->getColour() != id) {
                    if ((observerPiece->getType() == 'P' || observerPiece->getType() == 'p') && j == observerPiece->getCol()) {
                      continue;
                    }
                    // cout << "4" << endl;
                    cout << "Invalid move: Try Again" << endl;
                    check = true;
                    continue;
                  }
                }
              }
            }
          }
          b.makeMove(b.getCellAt(dX, dY), b.getCellAt(sX, sY), false);
          if (t) {
            b.setupAdd(dX, dY, temp.get()->getType(), false);
          }
          if (check) {
            check = false;
            t = false;
            continue;
          }


          if ((b.getCellAt(sX, sY).getPiece()->getType() == 'p' && sX == 6)
              || (b.getCellAt(sX, sY).getPiece()->getType() == 'P' && sX == 1)) {
            cout << "What piece would you like to promote to? (Queen, Rook, Bishop, Knight)" << endl;
            char c; // add error checks
            while (cin >> c) {
              if (id == Colour::White) {
                if (c == 'Q' || c == 'R' || c == 'B' || c == 'N') {
                  b.getCellAt(sX, sY).getPiece()->detachFromCells(b);
                  b.getCellAt(sX, sY).getActualPiece();
                  b.setupAdd(sX, sY, c, true);
                  break;
                } else {
                  cout << "Invalid peice: Try Again" << endl;
                  continue;
                }
              } else {
                if (c == 'q' || c == 'r' || c == 'b' || c == 'n') {
                  b.getCellAt(sX, sY).getPiece()->detachFromCells(b);
                  b.getCellAt(sX, sY).getActualPiece();
                  b.setupAdd(sX, sY, c, true);
                  break;
                } else {
                  cout << "Invalid piece: Try Again" << endl;
                  continue;
                }
              }
            }
          }
          b.getCellAt(sX, sY).getPiece()->setFirst(false);
          return;
        } else {
          // if (!b.getCellAt(sX, sY).hasPiece()) {
          //   cout << 10 << endl;
          // } else if (! (b.getCellAt(sX, sY).getPiece()->getColour() == id)) {
          //   cout << 20 << endl;
          // } else if (!b.getCellAt(dX, dY).isPieceObserver(b.getCellAt(sX, sY).getPiece())) {
          //   cout << 30 << endl;
          // }
          cout << "Invalid move: Try Again" << endl;
        }
      }
    } catch (...) {
      // cout << "Reached catch" << endl;
      cin.clear();
      cin.ignore();
    }
  }
}
