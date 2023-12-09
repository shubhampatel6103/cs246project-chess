#include <iostream>
#include <string>
#include "LevelThree.h"
#include "Board.h"
#include "Move.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

LevelThree::LevelThree(Colour c): Player{c} {} 

void LevelThree::move(Board &b) {
  // cout << "moving computer" << endl;
  string s;
  while (true) {
    try {
      if ((cin >> s) && !cin.eof()) {
        if (! (s == "move" || s == "resign")) {
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

      vector<int> moves;
      for (int i = 0; (i < 8); ++i) {
        for (int j = 0; (j < 8); ++j) {
          

          if (b.getCellAt(i, j).hasPiece() && b.getCellAt(i, j).getPiece()->getColour() == id) {
            continue;
          }

          int observer_size = b.getCellAt(i, j).getObservers().size();
          vector<Observer *> temp_observers(observer_size, nullptr);
          for (int r = 0; r < observer_size; ++r) {
            temp_observers[r] = b.getCellAt(i, j).getObservers()[r];
          }

          for (int k = 2; k < observer_size; ++k) {
            Piece* observerPiece = dynamic_cast<Piece *>(temp_observers[k]);
            int sRow = observerPiece->getRow();
            int sCol = observerPiece->getCol();
            if (observerPiece->getColour() == id) {
              if ((observerPiece->getType() == 'p' || observerPiece->getType() == 'P') && j == observerPiece->getCol() && b.getCellAt(i, j).hasPiece()) {
                continue;
              } else if ((observerPiece->getType() == 'p' || observerPiece->getType() == 'P') && j != observerPiece->getCol() && !(b.getCellAt(i, j).hasPiece())) {
                continue;
              }
              
              bool t = false;
              unique_ptr<Piece> temp = nullptr;
              
              if (b.getCellAt(i, j).hasPiece()) {
                temp = b.getCellAt(i, j).getActualPiece();
                temp.get()->detachFromCells(b);
                t = true;
              }
              
              b.makeMove(b.getCellAt(observerPiece->getRow(), observerPiece->getCol()), b.getCellAt(i, j), false);
              bool isMoveInCheck = false;
              bool oponentInCheck = false;
              
              for (int g = 0; g < 8 && (!isMoveInCheck); ++g) {
                for (int h = 0; h < 8 && (!isMoveInCheck); ++h) {
                  if (!b.getCellAt(g, h).hasPiece()) {
                    continue;
                  }
                  if ((b.getCellAt(g, h).getPiece()->getType() == 'k' || b.getCellAt(g, h).getPiece()->getType() == 'K') && b.getCellAt(g, h).getPiece()->getColour() == id) {
                    int observer_size = b.getCellAt(g, h).getObservers().size();
                    vector<Observer *> temp_observers(observer_size, nullptr);
                    for (int r = 0; r < observer_size; ++r) {
                      temp_observers[r] = b.getCellAt(g, h).getObservers()[r];
                    }
                    for (int z = 2; z < observer_size && (!isMoveInCheck); ++z) {
                      Piece* observerPiece = dynamic_cast<Piece*>(temp_observers[z]);
                      if (observerPiece->getColour() != id) {
                        if ((observerPiece->getType() == 'P' || observerPiece->getType() == 'p') && h == observerPiece->getCol()) {
                          continue;
                        }
                        isMoveInCheck = true;
                      }
                    }
                  }
                  if ((b.getCellAt(g, h).getPiece()->getType() == 'k' || b.getCellAt(g, h).getPiece()->getType() == 'K') && b.getCellAt(g, h).getPiece()->getColour() != id) {
                    int observer_size = b.getCellAt(g, h).getObservers().size();
                    vector<Observer *> temp_observers(observer_size, nullptr);
                    for (int r = 0; r < observer_size; ++r) {
                      temp_observers[r] = b.getCellAt(g, h).getObservers()[r];
                    }
                    for (int z = 2; z < observer_size && (!oponentInCheck); ++z) { // change to 2
                      Piece* observerPiece = dynamic_cast<Piece*>(temp_observers[z]);
                      if (observerPiece->getColour() == id) {
                        if ((observerPiece->getType() == 'P' || observerPiece->getType() == 'p') && h == observerPiece->getCol()) {
                          continue;
                        }
                        oponentInCheck = true;
                      }
                    }
                  }
                }
              }
              
              b.makeMove(b.getCellAt(i, j), b.getCellAt(sRow, sCol), false);
              if (t) {
                b.setupAdd(i, j, temp.get()->getType(), false);
              }
              if (isMoveInCheck) {
                isMoveInCheck = false;  
                t = false;
                oponentInCheck = false;
              } else {
                m.setMove(false, sRow, sCol, i, j);
                if (t || oponentInCheck) {
                    return;
                }
                moves.emplace_back(sRow);
                moves.emplace_back(sCol);
                moves.emplace_back(i);
                moves.emplace_back(j);
              }
            }
          }
        }
      }



      for (int i = 0; (i < 8); ++i) {
        for (int j = 0; (j < 8); ++j) {

          if (b.getCellAt(i, j).hasPiece() && b.getCellAt(i, j).getPiece()->getColour() == id) {
            continue;
          }

          int observer_size = b.getCellAt(i, j).getObservers().size();
          vector<Observer *> temp_observers(observer_size, nullptr);
          for (int r = 0; r < observer_size; ++r) {
            temp_observers[r] = b.getCellAt(i, j).getObservers()[r];
          }

          for (int k = 2; k < observer_size; ++k) {
            Piece* observerPiece = dynamic_cast<Piece *>(temp_observers[k]);
            int sRow = observerPiece->getRow();
            int sCol = observerPiece->getCol();
            if (observerPiece->getColour() == id) {
              if ((observerPiece->getType() == 'p' || observerPiece->getType() == 'P') && j == observerPiece->getCol() && b.getCellAt(i, j).hasPiece()) {
                continue;
              } else if ((observerPiece->getType() == 'p' || observerPiece->getType() == 'P') && j != observerPiece->getCol() && !(b.getCellAt(i, j).hasPiece())) {
                continue;
              }
              
              bool t = false;
              unique_ptr<Piece> temp = nullptr;
              
              if (b.getCellAt(i, j).hasPiece()) {
                temp = b.getCellAt(i, j).getActualPiece();
                temp.get()->detachFromCells(b);
                t = true;
              }
              
              b.makeMove(b.getCellAt(observerPiece->getRow(), observerPiece->getCol()), b.getCellAt(i, j), false);
              bool isMoveInAttack = false;
              bool opponentInAttack = false;
              
              for (int g = 0; g < 8 && (!isMoveInAttack); ++g) {
                for (int h = 0; h < 8 && (!isMoveInAttack); ++h) {
                  if (!b.getCellAt(g, h).hasPiece()) {
                    continue;
                  }
                  if (b.getCellAt(g, h).getPiece()->getColour() == id) {
                    int observer_size = b.getCellAt(g, h).getObservers().size();
                    vector<Observer *> temp_observers(observer_size, nullptr);
                    for (int r = 0; r < observer_size; ++r) {
                      temp_observers[r] = b.getCellAt(g, h).getObservers()[r];
                    }
                    for (int z = 2; z < observer_size && (!isMoveInAttack); ++z) {
                      Piece* observerPiece = dynamic_cast<Piece*>(temp_observers[z]);
                      if (observerPiece->getColour() != id) {
                        if ((observerPiece->getType() == 'P' || observerPiece->getType() == 'p') && h == observerPiece->getCol()) {
                          continue;
                        }
                        isMoveInAttack = true;
                      }
                    }
                  }
                  if (b.getCellAt(g, h).getPiece()->getColour() != id) {
                    int observer_size = b.getCellAt(g, h).getObservers().size();
                    vector<Observer *> temp_observers(observer_size, nullptr);
                    for (int r = 0; r < observer_size; ++r) {
                      temp_observers[r] = b.getCellAt(g, h).getObservers()[r];
                    }
                    for (int z = 2; z < observer_size && (!opponentInAttack); ++z) { // change to 2
                      Piece* observerPiece = dynamic_cast<Piece*>(temp_observers[z]);
                      if (observerPiece->getColour() == id) {
                        if ((observerPiece->getType() == 'P' || observerPiece->getType() == 'p') && h == observerPiece->getCol()) {
                          continue;
                        }
                        if (b.getCellAt(g, h).hasPiece() && b.getCellAt(g, h).getPiece()->getColour() != id) {
                          opponentInAttack = true;
                        }
                      }
                    }
                  }
                }
              }
              
              b.makeMove(b.getCellAt(i, j), b.getCellAt(sRow, sCol), false);
              if (t) {
                b.setupAdd(i, j, temp.get()->getType(), false);
              }
              if (isMoveInAttack) {
                isMoveInAttack = false;  
                t = false;
                opponentInAttack = false;
              } else {
                m.setMove(false, sRow, sCol, i, j);
                if (opponentInAttack) {
                    return;
                }
                moves.emplace_back(sRow);
                moves.emplace_back(sCol);
                moves.emplace_back(i);
                moves.emplace_back(j);
              }
            }
          }
        }
      }

      if (moves.size() > 4) {
        srand(moves.size()*2);
        int rMoveIndex = rand() % ((moves.size() / 4) - 1);
        m.setMove(false, moves[rMoveIndex * 4], moves[(rMoveIndex * 4) + 1], moves[(rMoveIndex * 4) + 2], moves[(rMoveIndex * 4) + 3]);
        return;
      } else {
        return;
      }
    } catch (...) {
      cin.clear();
      cin.ignore();
    }
  }
}


