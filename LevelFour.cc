#include <iostream>
#include <string>
#include "LevelFour.h"
#include "Board.h"
#include "Move.h"
#include <stdlib.h>

using namespace std;

int eval(Board& b) {
  // For loop over 'the board' 
  // Get points from piece
  // 
  int score = 0;
  // Loop over the whole board
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (b.getCellAt(i,j).hasPiece()) { // If there is a piece
        int points = b.getCellAt(i,j).getPiece()->getPoints(); // get the points
        if (b.getCellAt(i,j).getPiece()->getColour() == Colour::Black) { points *= -1; } // if black, points *= -1
        score += points; // then just add the points to the score
      }
    }
  }
  
  bool check = false;
  bool stalemate = true;
  for (int i = 0; (i < 8 && (!check)); ++i) {
    for (int j = 0; (j < 8 && (!check)); ++j) {
      if (!b.getCellAt(i, j).hasPiece()) {
        continue;
      }
      if (b.getCellAt(i, j).getPiece()->getType() == 'K') { 
        int observer_size = b.getCellAt(i, j).getObservers().size();
        vector<Observer *> temp_observers(observer_size, nullptr);
        for (int r = 0; r < observer_size; ++r) {
          temp_observers[r] = b.getCellAt(i, j).getObservers()[r];
        }
        for (int k = 2; k < observer_size && (!check); ++k) { 
          Piece* observerPiece = dynamic_cast<Piece*>(temp_observers[k]);
          if (observerPiece->getColour() != Colour::White) {
            if (observerPiece->getType() == 'p' && j == observerPiece->getCol()) {
              continue;
            }
            check = true;
            break;
          }
        }
      }
    }
  }

  for (int i = 0; (i < 8 && (stalemate)); ++i) {
    for (int j = 0; (j < 8 && (stalemate)); ++j) {
      if (b.getCellAt(i, j).hasPiece() && b.getCellAt(i, j).getPiece()->getColour() == Colour::White) {
        continue;
      }

      int observer_size = b.getCellAt(i, j).getObservers().size();
      vector<Observer *> temp_observers(observer_size, nullptr);
      for (int r = 0; r < observer_size; ++r) {
        temp_observers[r] = b.getCellAt(i, j).getObservers()[r];
      }
      for (int k = 2; k < observer_size && stalemate; ++k) { 
        Piece* observerPiece = dynamic_cast<Piece *>(temp_observers[k]);
        int sRow = observerPiece->getRow();
        int sCol = observerPiece->getCol();
        if (observerPiece->getColour() != Colour::Black) {
          if (observerPiece->getType() == 'P' && j == observerPiece->getCol() && b.getCellAt(i, j).hasPiece()) {
            continue;
          } else if (observerPiece->getType() == 'P' && j != observerPiece->getCol() && !(b.getCellAt(i, j).hasPiece())) {
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
          for (int g = 0; g < 8 && (!isMoveInCheck); ++g) {
            for (int h = 0; h < 8 && (!isMoveInCheck); ++h) {
              if (!b.getCellAt(g, h).hasPiece()) {
                continue;
              }
              if (b.getCellAt(g, h).getPiece()->getType() == 'K') {
                // int n = b.getCellAt(g, h).getObservers().size();
                int observer_size = b.getCellAt(g, h).getObservers().size();
                vector<Observer *> temp_observers(observer_size, nullptr);
                for (int r = 0; r < observer_size; ++r) {
                  temp_observers[r] = b.getCellAt(g, h).getObservers()[r];
                }
                for (int z = 2; z < observer_size && (!isMoveInCheck); ++z) { // change to 2
                  Piece* observerPiece = dynamic_cast<Piece*>(temp_observers[z]);
                  if (observerPiece->getColour() != Colour::White) {
                    if (observerPiece->getType() == 'p' && h == observerPiece->getCol()) {
                      continue;
                    }
                    isMoveInCheck = true;
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
          } else {
            stalemate = false;
          }

        }
      }
    }
  }
  
  if (check && stalemate) {
    score += 100000;
  } else if (check) {
    score += 90;
  } else if (stalemate) {
    return 0;
  }


  check = false;
  stalemate = true;
  for (int i = 0; (i < 8 && (!check)); ++i) {
    for (int j = 0; (j < 8 && (!check)); ++j) {
      if (!b.getCellAt(i, j).hasPiece()) {
        continue;
      }
      if (b.getCellAt(i, j).getPiece()->getType() == 'k') {
        int observer_size = b.getCellAt(i, j).getObservers().size();
        vector<Observer *> temp_observers(observer_size, nullptr);
        for (int r = 0; r < observer_size; ++r) {
          temp_observers[r] = b.getCellAt(i, j).getObservers()[r];
        }
        for (int k = 2; k < observer_size && (!check); ++k) {
          Piece* observerPiece = dynamic_cast<Piece*>(temp_observers[k]);
          
          
          
          if (observerPiece->getColour() != Colour::Black) {
            if (observerPiece->getType() == 'P' && j == observerPiece->getCol()) {
              continue;
            }
            check = true;
            break;
          }
        }
      }
    }
  }

  for (int i = 0; (i < 8 && (stalemate)); ++i) {
    for (int j = 0; (j < 8 && (stalemate)); ++j) {
      if (b.getCellAt(i, j).hasPiece() && b.getCellAt(i, j).getPiece()->getColour() == Colour::Black) {
        continue;
      }

      int observer_size = b.getCellAt(i, j).getObservers().size();
      vector<Observer *> temp_observers(observer_size, nullptr);
      for (int r = 0; r < observer_size; ++r) {
        temp_observers[r] = b.getCellAt(i, j).getObservers()[r];
      }
      for (int k = 2; k < observer_size && stalemate; ++k) { 
        Piece* observerPiece = dynamic_cast<Piece *>(temp_observers[k]);
        cout << observerPiece << endl; 
        int sRow = observerPiece->getRow();
        int sCol = observerPiece->getCol();
        if (observerPiece->getColour() != Colour::White) {
          if (observerPiece->getType() == 'p' && j == observerPiece->getCol() && b.getCellAt(i, j).hasPiece()) {
            continue;
          } else if (observerPiece->getType() == 'p' && j != observerPiece->getCol() && !(b.getCellAt(i, j).hasPiece())) {
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
          for (int g = 0; g < 8 && (!isMoveInCheck); ++g) {
            for (int h = 0; h < 8 && (!isMoveInCheck); ++h) {
              if (!b.getCellAt(g, h).hasPiece()) {
                continue;
              }
              if (b.getCellAt(g, h).getPiece()->getType() == 'k') {
                int observer_size = b.getCellAt(g, h).getObservers().size();
                vector<Observer *> temp_observers(observer_size, nullptr);
                for (int r = 0; r < observer_size; ++r) {
                  temp_observers[r] = b.getCellAt(g, h).getObservers()[r];
                }
                for (int z = 2; z < observer_size && (!isMoveInCheck); ++z) {
                  Piece* observerPiece = dynamic_cast<Piece*>(temp_observers[z]);
                  if (observerPiece->getColour() != Colour::Black) {
                    if (observerPiece->getType() == 'P' && h == observerPiece->getCol()) {
                      continue;
                    }
                    isMoveInCheck = true;
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
          } else {
            stalemate = false;
          }

        }
      }
    }
  }
  
  if (check && stalemate) {
    score -= 100000;
  } else if (check) {
    score -= 90;
  } else if (stalemate) {
    return 0;
  } 


  srand(score);
  int randomizer = rand() % 50;
  return (score + randomizer - 25);
}


LevelFour::LevelFour(Colour c): Player{c} {} 

void LevelFour::move(Board &b) {
  cout << "moving computer" << endl;
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
      
      if (id == Colour::White) {
        int mMax = -10000;
        int mMove[4] = {-1, -1, -1, -1};

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
                  }
                }
                if (!isMoveInCheck) {

                  int mOneMin = 10000;
                  int mOneMove[4] = {-1, -1, -1, -1};
          //__________________________________________________
                  for (int iOne = 0; (iOne < 8); ++iOne) {
                    for (int jOne = 0; (jOne < 8); ++jOne) {
                      
                      if (b.getCellAt(iOne, jOne).hasPiece() && b.getCellAt(iOne, jOne).getPiece()->getColour() != id) {
                        continue;
                      }
                      int observer_sizeOne = b.getCellAt(iOne, jOne).getObservers().size();
                      vector<Observer *> temp_observersOne(observer_sizeOne, nullptr);
                      for (int rOne = 0; rOne < observer_sizeOne; ++rOne) {
                        temp_observersOne[rOne] = b.getCellAt(iOne, jOne).getObservers()[rOne];
                      }
                      for (int kOne = 2; kOne < observer_sizeOne; ++kOne) {
                        Piece* observerPieceOne = dynamic_cast<Piece *>(temp_observersOne[kOne]);
                        int sRowOne = observerPieceOne->getRow();
                        int sColOne = observerPieceOne->getCol();
                        if (observerPieceOne->getColour() != id) {
                          if ((observerPieceOne->getType() == 'p' || observerPieceOne->getType() == 'P') && jOne == observerPieceOne->getCol() && b.getCellAt(iOne, jOne).hasPiece()) {
                            continue;
                          } else if ((observerPieceOne->getType() == 'p' || observerPieceOne->getType() == 'P') && jOne != observerPieceOne->getCol() && !(b.getCellAt(iOne, jOne).hasPiece())) {
                            continue;
                          }
                          
                          bool tOne = false;
                          unique_ptr<Piece> tempOne = nullptr;
                          

                          if (b.getCellAt(iOne, jOne).hasPiece()) {
                            tempOne = b.getCellAt(iOne, jOne).getActualPiece();
                            tempOne.get()->detachFromCells(b);
                            tOne = true;
                          }
                          b.makeMove(b.getCellAt(observerPieceOne->getRow(), observerPieceOne->getCol()), b.getCellAt(iOne, jOne), false);
                          bool isMoveInCheckOne = false;
                          for (int gOne = 0; gOne < 8 && (!isMoveInCheckOne); ++gOne) {
                            for (int hOne = 0; hOne < 8 && (!isMoveInCheckOne); ++hOne) {
                              if (!b.getCellAt(gOne, hOne).hasPiece()) {
                                continue;
                              }
                              if ((b.getCellAt(gOne, hOne).getPiece()->getType() == 'k' || b.getCellAt(gOne, hOne).getPiece()->getType() == 'K') && b.getCellAt(gOne, hOne).getPiece()->getColour() != id) {
                                int observer_sizeOne = b.getCellAt(gOne, hOne).getObservers().size();
                                vector<Observer *> temp_observersOne(observer_sizeOne, nullptr);
                                for (int rOne = 0; rOne < observer_sizeOne; ++rOne) {
                                  temp_observersOne[rOne] = b.getCellAt(gOne, hOne).getObservers()[rOne];
                                }
                                for (int zOne = 2; zOne < observer_sizeOne && (!isMoveInCheckOne); ++zOne) { // change to 2
                                  Piece* observerPieceOne = dynamic_cast<Piece*>(temp_observersOne[zOne]);
                                  if (observerPieceOne->getColour() == id) {
                                    if ((observerPieceOne->getType() == 'P' || observerPieceOne->getType() == 'p') && hOne == observerPieceOne->getCol()) {
                                      continue;
                                    }
                                    isMoveInCheckOne = true;
                                  }
                                }
                              }
                            }
                          }
                          if (!isMoveInCheckOne) {
                            
                            int mTwoMax = 10000;
                            int mTwoMove[4] = {-1, -1, -1, -1};
                    //__________________________________________________
                            for (int iTwo = 0; (iTwo < 8); ++iTwo) {
                              for (int jTwo = 0; (jTwo < 8); ++jTwo) {
                                
                                if (b.getCellAt(iTwo, jTwo).hasPiece() && b.getCellAt(iTwo, jTwo).getPiece()->getColour() == id) {
                                  continue;
                                }
                                int observer_sizeTwo = b.getCellAt(iTwo, jTwo).getObservers().size();
                                vector<Observer *> temp_observersTwo(observer_sizeTwo, nullptr);
                                for (int rTwo = 0; rTwo < observer_sizeTwo; ++rTwo) {
                                  temp_observersTwo[rTwo] = b.getCellAt(iTwo, jTwo).getObservers()[rTwo];
                                }
                                for (int kTwo = 2; kTwo < observer_sizeTwo; ++kTwo) {
                                  Piece* observerPieceTwo = dynamic_cast<Piece *>(temp_observersTwo[kTwo]);
                                  int sRowTwo = observerPieceTwo->getRow();
                                  int sColTwo = observerPieceTwo->getCol();
                                  if (observerPieceTwo->getColour() == id) {
                                    if ((observerPieceTwo->getType() == 'p' || observerPieceTwo->getType() == 'P') && jTwo == observerPieceTwo->getCol() && b.getCellAt(iTwo, jTwo).hasPiece()) {
                                      continue;
                                    } else if ((observerPieceTwo->getType() == 'p' || observerPieceTwo->getType() == 'P') && jTwo != observerPieceTwo->getCol() && !(b.getCellAt(iTwo, jTwo).hasPiece())) {
                                      continue;
                                    }
                                    
                                    bool tTwo = false;
                                    unique_ptr<Piece> tempTwo = nullptr;
                                    

                                    if (b.getCellAt(iTwo, jTwo).hasPiece()) {
                                      tempTwo = b.getCellAt(iTwo, jTwo).getActualPiece();
                                      tempTwo.get()->detachFromCells(b);
                                      tTwo = true;
                                    }
                                    b.makeMove(b.getCellAt(observerPieceTwo->getRow(), observerPieceTwo->getCol()), b.getCellAt(iTwo, jTwo), false);
                                    bool isMoveInCheckTwo = false;
                                    for (int gTwo = 0; gTwo < 8 && (!isMoveInCheckTwo); ++gTwo) {
                                      for (int hTwo = 0; hTwo < 8 && (!isMoveInCheckTwo); ++hTwo) {
                                        if (!b.getCellAt(gTwo, hTwo).hasPiece()) {
                                          continue;
                                        }
                                        if ((b.getCellAt(gTwo, hTwo).getPiece()->getType() == 'k' || b.getCellAt(gTwo, hTwo).getPiece()->getType() == 'K') && b.getCellAt(gTwo, hTwo).getPiece()->getColour() == id) {
                                          int observer_sizeTwo = b.getCellAt(gTwo, hTwo).getObservers().size();
                                          vector<Observer *> temp_observersTwo(observer_sizeTwo, nullptr);
                                          for (int rTwo = 0; rTwo < observer_sizeTwo; ++rTwo) {
                                            temp_observersTwo[rTwo] = b.getCellAt(gTwo, hTwo).getObservers()[rTwo];
                                          }
                                          for (int zTwo = 2; zTwo < observer_sizeTwo && (!isMoveInCheckTwo); ++zTwo) { // change to 2
                                            Piece* observerPieceTwo = dynamic_cast<Piece*>(temp_observersTwo[zTwo]);
                                            if (observerPieceTwo->getColour() != id) {
                                              if ((observerPieceTwo->getType() == 'P' || observerPieceTwo->getType() == 'p') && hTwo == observerPieceTwo->getCol()) {
                                                continue;
                                              }
                                              isMoveInCheckTwo = true;
                                            }
                                          }
                                        }
                                      }
                                    }
                                    if (!isMoveInCheckTwo) {
                                      int currentEval = eval(b);
                                      if (currentEval > mTwoMax) {
                                        mTwoMax = currentEval;
                                        mTwoMove[0] = sRowTwo;
                                        mTwoMove[1] = sColTwo;
                                        mTwoMove[3] = iTwo;
                                        mTwoMove[4] = jTwo;
                                      }
                                    }
                                    b.makeMove(b.getCellAt(iTwo, jTwo), b.getCellAt(sRowTwo, sColTwo), false);
                                    if (tTwo) {
                                      b.setupAdd(iTwo, jTwo, tempTwo.get()->getType(), false);
                                    }
                                    tTwo = false;
                                    isMoveInCheckTwo = false;
                                  }
                                }
                              }
                            }

                            if (mTwoMax < mOneMin) {
                              mOneMin = mTwoMax;
                              mOneMove[0] = sRowOne;
                              mOneMove[1] = sColOne;
                              mOneMove[2] = iOne;
                              mOneMove[3] = jOne;
                            }
                            // __________________________________________

                          }
                          b.makeMove(b.getCellAt(iOne, jOne), b.getCellAt(sRowOne, sColOne), false);
                          if (tOne) {
                            b.setupAdd(iOne, jOne, tempOne.get()->getType(), false);
                          }
                          tOne = false;
                          isMoveInCheckOne = false;
                            
                          
                        }
                      }
                    }
                  }

                  if (mOneMin > mMax) {
                    mMax = mOneMin;
                    mMove[0] = sRow;
                    mMove[1] = sCol;
                    mMove[2] = i;
                    mMove[3] = j;
                  }

                //__________________________________________________`

                }

                b.makeMove(b.getCellAt(i, j), b.getCellAt(sRow, sCol), false);
                if (t) {
                  b.setupAdd(i, j, temp.get()->getType(), false);
                }
                t = false;
                isMoveInCheck = false;
                  
              }
            }
          }
        }

        m.setMove(false, mMove[0], mMove[1], mMove[2], mMove[3]);
        return;
      }

    } catch (...) {
      // cout << "Reached catch" << endl;
      cin.clear();
      cin.ignore();
    }
  }
}


  // for (int i = 0; i < 8; ++i) {
  //     for (int j = 0; j < 8; ++j) {

  //     }
  // } 

