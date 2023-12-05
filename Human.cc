#include <iostream>
#include <string>
#include "Human.h"
#include "Board.h"
#include "Move.h"
#include <memory>

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

      // En pessant white takes diagonal left
      if (b.getCellAt(sX, sY).getPiece()->getType() == 'P') {
        if (dY < sY && sX == dX + 1 && b.getCellAt(sX, dY).hasPiece() && b.getCellAt(sX, dY).getPiece()->getType() == 'p') {
          cout << "passes 2" << endl;
          if ((b.getLastMove().getCoords()[2] - b.getLastMove().getCoords()[0] == 2) &&
              b.getLastMove().getCoords()[2] == sX && b.getLastMove().getCoords()[3] == dY) {
            b.getCellAt(sX, dY).remPiece(); 
            b.getCellAt(sX, dY).notifyObservers(b);
            m.setMove(false, sX, sY, sX - 1, sY - 1);
            return;
          }
        }

        if (dY > sY && sX == dX + 1 && b.getCellAt(sX, dY).hasPiece() && b.getCellAt(sX, dY).getPiece()->getType() == 'p') {
          cout << "passes 2" << endl;
          if ((b.getLastMove().getCoords()[2] - b.getLastMove().getCoords()[0] == 2) &&
              b.getLastMove().getCoords()[2] == sX && b.getLastMove().getCoords()[3] == dY) {
            b.getCellAt(sX, dY).remPiece(); 
            b.getCellAt(sX, dY).notifyObservers(b);
            m.setMove(false, sX, sY, sX - 1, sY + 1);
            return;
          }
        }
      }

      if (b.getCellAt(sX, sY).getPiece()->getType() == 'p') { // If we have a black pawn
        if (dY < sY && sX == dX - 1 && b.getCellAt(sX, dY).hasPiece() && b.getCellAt(sX, dY).getPiece()->getType() == 'P') {
          cout << "passes 2" << endl;
          if ((b.getLastMove().getCoords()[2] - b.getLastMove().getCoords()[0] == -2) &&
              b.getLastMove().getCoords()[2] == sX && b.getLastMove().getCoords()[3] == dY) {
            b.getCellAt(sX, dY).remPiece(); 
            b.getCellAt(sX, dY).notifyObservers(b);
            m.setMove(false, sX, sY, dX, dY);
            return;
          }
        }

        if (dY > sY && sX == dX - 1 && b.getCellAt(sX, dY).hasPiece() && b.getCellAt(sX, dY).getPiece()->getType() == 'P') {
          cout << "passes 2" << endl;
          if ((b.getLastMove().getCoords()[2] - b.getLastMove().getCoords()[0] == -2) &&
              b.getLastMove().getCoords()[2] == sX && b.getLastMove().getCoords()[3] == dY) {
            b.getCellAt(sX, dY).remPiece(); 
            b.getCellAt(sX, dY).notifyObservers(b);
            m.setMove(false, sX, sY, dX, dY);
            return;
          }
        }
      }

      // // En pessant white takes diagonal right
      // if (b.getCellAt(sX, sY).getPiece()->getType() == 'P') {
      //   if (dY > sY && b.getCellAt(sX, dY).getPiece()->getType() == 'p') {
      //     if (b.getCellAt(sX, dY).getPiece()->getMoves() == 1) {
      //       b.getCellAt(sX, dY).remPiece(); 
      //       b.getCellAt(sX, dY).notifyObservers(b);
      //       m.setMove(false, sX, sY, sX - 1, sY + 1);
      //       return;
      //     }
      //   }
      // }

      // // Black double move, set num_moves to 1
      // if (b.getCellAt(sX, sY).getPiece()->getType() == 'p' && dX == sX + 2 && b.getCellAt(sX, sY).getPiece()->getFirst()
      //     && !b.getCellAt(sX + 1, sY).hasPiece() && !b.getCellAt(sX + 2, sY).hasPiece()) {
      //       b.getCellAt(sX, sY).getPiece()->setFirst(false);
      //       b.getCellAt(sX, sY).getPiece()->incrementMoves();
      //       m.setMove(false, sX, sY, dX, dY);
      //       return;
      // }



      // Pawn logic (Does not cover en passant yet)
      // If we have a piece, which is a pawn (type == 'p' or 'P')
      if (b.getCellAt(sX, sY).hasPiece() && (b.getCellAt(sX, sY).getPiece()->getType() == 'p' || b.getCellAt(sX, sY).getPiece()->getType() == 'P')) {
        char type = b.getCellAt(sX, sY).getPiece()->getType();
        if (type == 'p' && (dX == sX + 1) && (dY == sY) && b.getCellAt(dX, dY).hasPiece()) {
          cout << "Invalid move: Try Again" << endl;
          continue;
        } else if (type == 'P' && (dX == sX - 1) && (dY == sY) && b.getCellAt(dX, dY).hasPiece()) {
          cout << "Invalid move: Try Again" << endl;
          cout << "Check 1 " << endl;
          continue;
        } else if (type == 'p' && (dX == sX + 1) && (dY == sY + 1 || dY == sY - 1) && !b.getCellAt(dX, dY).hasPiece()) {
          cout << "Invalid move: Try Again" << endl;
          continue;
        } else if (type == 'P' && (dX == sX - 1) && (dY == sY + 1 || dY == sY - 1) && !b.getCellAt(dX, dY).hasPiece()) {
          cout << "Invalid move: Try Again" << endl;
          cout << "Check 2" << endl;
          continue;
        }
      }

      // King logic
      if (b.getCellAt(sX, sY).hasPiece() && (b.getCellAt(sX, sY).getPiece()->getType() == 'K' || b.getCellAt(sX, sY).getPiece()->getType() == 'k')) {
        char type = b.getCellAt(sX, sY).getPiece()->getType();
        bool firstMove = b.getCellAt(sX, sY).getPiece()->getFirst();
        // White king
        if (type == 'K' && firstMove && (sX == dX) && (dY == sY + 2) && whiteCastleShort(b, sX, sY, dX, dY)) {
            m.setMove(false, sX, sY, dX, dY);
            b.getCellAt(dX, sY + 3).getPiece()->setFirst(false);
            b.getCellAt(dX, sY).getPiece()->setFirst(false);
            b.getCellAt(dX, sY + 1).remPiece(); // Remove the piece from the destination cell of rook
            b.getCellAt(dX, sY + 3).getPiece()->detachFromCells(b); // Detach from the cells the source piece is currently attached to 
            b.getCellAt(dX, sY + 1).addPiece(b.getCellAt(dX, sY + 3).getActualPiece()); // Add the piece to the new cell
            b.getCellAt(dX, sY + 1).getPiece()->setRow(b.getCellAt(dX, sY + 1).getRow()); // Change the position of the piece 
            b.getCellAt(dX, sY + 1).getPiece()->setCol(b.getCellAt(dX, sY + 1).getCol());
            b.getCellAt(dX, sY + 1).getPiece()->attachToCells(b); // Reattach after changing the position of the piece
            b.getCellAt(dX, sY + 3).notifyObservers(b);
            b.getCellAt(dX, sY + 1).notifyObservers(b);
            return;
        } else if (type == 'K' && firstMove && (sX == dX) && (dY == sY - 2) && whiteCastleLong(b, sX, sY, dX, dY)) {
            m.setMove(false, sX, sY, dX, dY);
            b.getCellAt(dX, sY - 4).getPiece()->setFirst(false);
            b.getCellAt(dX, sY).getPiece()->setFirst(false);
            b.getCellAt(dX, sY - 1).remPiece(); // Remove the piece from the destination cell of rook
            b.getCellAt(dX, sY - 4).getPiece()->detachFromCells(b); // Detach from the cells the source piece is currently attached to 
            b.getCellAt(dX, sY - 1).addPiece(b.getCellAt(dX, sY - 4).getActualPiece()); // Add the piece to the new cell
            b.getCellAt(dX, sY - 1).getPiece()->setRow(b.getCellAt(dX, sY - 1).getRow()); // Change the position of the piece 
            b.getCellAt(dX, sY - 1).getPiece()->setCol(b.getCellAt(dX, sY - 1).getCol());
            b.getCellAt(dX, sY - 1).getPiece()->attachToCells(b); // Reattach after changing the position of the piece
            b.getCellAt(dX, sY - 4).notifyObservers(b);
            b.getCellAt(dX, sY - 1).notifyObservers(b);
            return;
        // Black king
        } else if (type == 'k' && firstMove && (sX == dX) && (dY == sY - 2) && blackCastleLong(b, sX, sY, dX, dY)) {
            m.setMove(false, sX, sY, dX, dY);
            b.getCellAt(dX, sY - 4).getPiece()->setFirst(false);
            b.getCellAt(dX, sY).getPiece()->setFirst(false);
            b.getCellAt(dX, sY - 1).remPiece(); // Remove the piece from the destination cell of rook
            b.getCellAt(dX, sY - 4).getPiece()->detachFromCells(b); // Detach from the cells the source piece is currently attached to 
            b.getCellAt(dX, sY - 1).addPiece(b.getCellAt(dX, sY - 4).getActualPiece()); // Add the piece to the new cell
            b.getCellAt(dX, sY - 1).getPiece()->setRow(b.getCellAt(dX, sY - 1).getRow()); // Change the position of the piece 
            b.getCellAt(dX, sY - 1).getPiece()->setCol(b.getCellAt(dX, sY - 1).getCol());
            b.getCellAt(dX, sY - 1).getPiece()->attachToCells(b); // Reattach after changing the position of the piece
            b.getCellAt(dX, sY - 4).notifyObservers(b);
            b.getCellAt(dX, sY - 1).notifyObservers(b);  
            return;
        } else if (type == 'k' && firstMove && (sX == dX) && (dY == sY + 2) && blackCastleShort(b, sX, sY, dX, dY)) {
            m.setMove(false, sX, sY, dX, dY);
            b.getCellAt(dX, sY + 3).getPiece()->setFirst(false);
            b.getCellAt(dX, sY).getPiece()->setFirst(false);
            b.getCellAt(dX, sY + 1).remPiece(); // Remove the piece from the destination cell of rook
            b.getCellAt(dX, sY + 3).getPiece()->detachFromCells(b); // Detach from the cells the source piece is currently attached to 
            b.getCellAt(dX, sY + 1).addPiece(b.getCellAt(dX, sY + 3).getActualPiece()); // Add the piece to the new cell
            b.getCellAt(dX, sY + 1).getPiece()->setRow(b.getCellAt(dX, sY + 1).getRow()); // Change the position of the piece 
            b.getCellAt(dX, sY + 1).getPiece()->setCol(b.getCellAt(dX, sY + 1).getCol());
            b.getCellAt(dX, sY + 1).getPiece()->attachToCells(b); // Reattach after changing the position of the piece
            b.getCellAt(dX, sY + 3).notifyObservers(b);
            b.getCellAt(dX, sY + 1).notifyObservers(b);
            return;
        }
      }


      if (b.getCellAt(sX, sY).hasPiece() && b.getCellAt(sX, sY).getPiece()->getColour() == id && b.getCellAt(dX, dY).isPieceObserver(b.getCellAt(sX, sY).getPiece()) && 
         (!b.getCellAt(dX, dY).hasPiece() || b.getCellAt(dX, dY).getPiece()->getColour() != id)) {
        m.setMove(false, sX, sY, dX, dY);
        b.getCellAt(sX, sY).getPiece()->setFirst(false);
        return;
      } else {
        cout << "Invalid move: Try Again" << endl;
      }
    }
  }
}
