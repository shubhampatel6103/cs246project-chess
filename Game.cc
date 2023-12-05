#include "Game.h"

using namespace std;

Game::Game() {}

Game::~Game() {}

void Game::setPlayers(unique_ptr<Player> player1, unique_ptr<Player> player2) {
    p1 = move(player1);
    p2 = move(player2);
}

void Game::makeMove(Move& m, Board& b) {
    b.setLastMove(m);
    b.makeMove(b.getCellAt(m.getCoords()[0], m.getCoords()[1]), b.getCellAt(m.getCoords()[2], m.getCoords()[3]));
}

char Game::playMove(int p, Board& b) {
    if (p == 1) { // play the move on behalf of p1 if p = 1
        p1.get()->move(b);
        if (p1->getMove().getResigned()) { return 'r'; }
        makeMove(p1->getMove(), b);
    } 
    else { // else, play the move on behalf of p2
        p2.get()->move(b);
        if (p2->getMove().getResigned()) { return 'r'; }
        makeMove(p2->getMove(), b);
    } // Might need to add try excepts, ideally should be handled by player class
    return 'n';
}

// char Game::playMove(int p, Board& b) {
//   if (p == 1) { // play the move on behalf of p1 if p = 1
//     p1.get()->move(b);
//     if (p1->getMove().getResigned()) { return 'r'; }
//     makeMove(p1->getMove(), b);

//     bool check = false;
//     bool stalemate = true;
//     for (int i = 0; (i < 8 && (!check)); ++i) {
//       for (int j = 0; (j < 8 && (!check)); ++j) {
//         if (!b.getCellAt(i, j).hasPiece()) {
//           continue;
//         }
//         if (b.getCellAt(i, j).getPiece()->getType() == 'k') { // check this
//           int n = b.getCellAt(i, j).getObservers().size();
//           for (int k = 1; k < n; ++k) { // change to 2
//             Piece* observerPiece = dynamic_cast<Piece*>(b.getCellAt(i, j).getObservers()[k]);
            
            
            
//             if (observerPiece->getColour() != Colour::Black) {
//               if (observerPiece->getType() == 'P' && j == observerPiece->getCol()) {
//                 continue;
//               }
//               check = true;
//               break;
//             }
//           }
//         }
//       }
//     }

//     for (int i = 0; (i < 8 && (stalemate)); ++i) {
//       for (int j = 0; (j < 8 && (stalemate)); ++j) {
        

//         if (b.getCellAt(i, j).hasPiece() && b.getCellAt(i, j).getPiece()->getColour() == Colour::Black) {
//           continue;
//         }

//         int n = b.getCellAt(i, j).getObservers().size();

//         for (int k = 1; k < n; ++k) { // change to 2
          
//           Piece* observerPiece = dynamic_cast<Piece*>(b.getCellAt(i, j).getObservers()[k]);

//           int sRow = observerPiece->getRow();
//           int sCol = observerPiece->getCol();
//           if (observerPiece->getColour() != Colour::White) {
            
//             if (observerPiece->getType() == 'p' && j == observerPiece->getCol() && b.getCellAt(i, j).hasPiece()) {
//               continue;
//             } else if (observerPiece->getType() == 'p' && j != observerPiece->getCol() && !(b.getCellAt(i, j).hasPiece())) {
//               continue;
//             }
            
//             bool t = false;
//             unique_ptr<Piece> temp = nullptr;
//             if (b.getCellAt(i, j).hasPiece()) {
//               temp = b.getCellAt(i, j).getActualPiece();
//               temp.get()->detachFromCells(b);
//               t = true;
//             }
//             b.makeMove(b.getCellAt(observerPiece->getRow(), observerPiece->getCol()), b.getCellAt(i, j));
//             bool isMoveInCheck = false;
//             for (int g = 0; g < 8 && (!isMoveInCheck); ++g) {
//               for (int h = 0; h < 8 && (!isMoveInCheck); ++h) {
//                 if (!b.getCellAt(g, h).hasPiece()) {
//                   continue;
//                 }
//                 if (b.getCellAt(g, h).getPiece()->getType() == 'k') {
//                   int n = b.getCellAt(g, h).getObservers().size();
//                   for (int z = 1; z < n; ++z) { // change to 2
//                     //cout << b.getCellAt(g, h).getObservers()[1] << endl;
//                     Piece* observerPiece = dynamic_cast<Piece*>(b.getCellAt(g, h).getObservers()[z]);
//                     if (observerPiece->getColour() != Colour::Black) {
//                       if (observerPiece->getType() == 'P' && j == observerPiece->getCol()) {
//                         continue;
//                       }
//                       isMoveInCheck = true;
//                     }
//                   }
//                 }
//               }
//             }

//             b.makeMove(b.getCellAt(i, j), b.getCellAt(sRow, sCol));
//             if (t) {
//               b.setupAdd(i, j, temp.get()->getType());
//             }
//             if (isMoveInCheck) {
//               isMoveInCheck = false;
//               t = false;
//             } else {
//               //cout << i << j << sRow << sCol << endl;
//               stalemate = false;
//             }

//           }
//         }
//       }
//     }

//     if (check && stalemate) {
//       cout << "Checkmate" << endl; // handle White wins
//       return 'w';
//     } else if (check) {
//       cout << "Black is in check" <<  endl; 
//     } else if (stalemate) {
//       cout << "Stalemate: This game is a draw" << endl; // handle draw
//       return 'd';
//     } else {
//       cout << "nothing" << endl;
//       return 'n';
//     }
//   } else { // else, play the move on behalf of p2
//     p2.get()->move(b);
//     if (p2->getMove().getResigned()) { return 'r'; }
//     makeMove(p2->getMove(), b);


//     bool check = false;
//     bool stalemate = true;
//     for (int i = 0; (i < 8 && (!check)); ++i) {
//       for (int j = 0; (j < 8 && (!check)); ++j) {
//         if (!b.getCellAt(i, j).hasPiece()) {
//           continue;
//         }
//         if (b.getCellAt(i, j).getPiece()->getType() == 'K') { // check this
//           int n = b.getCellAt(i, j).getObservers().size();
//           for (int k = 1; k < n; ++k) { // change to 2
//             Piece* observerPiece = dynamic_cast<Piece*>(b.getCellAt(i, j).getObservers()[k]);
            
            
            
//             if (observerPiece->getColour() != Colour::White) {
//               if (observerPiece->getType() == 'p' && j == observerPiece->getCol()) {
//                 continue;
//               }
//               check = true;
//               break;
//             }
//           }
//         }
//       }
//     }

//     for (int i = 0; (i < 8 && (stalemate)); ++i) {
//       for (int j = 0; (j < 8 && (stalemate)); ++j) {
        

//         if (b.getCellAt(i, j).hasPiece() && b.getCellAt(i, j).getPiece()->getColour() == Colour::White) {
//           continue;
//         }

//         int n = b.getCellAt(i, j).getObservers().size();

//         for (int k = 1; k < n; ++k) { // change to 2
          
//           Piece* observerPiece = dynamic_cast<Piece*>(b.getCellAt(i, j).getObservers()[k]);

//           int sRow = observerPiece->getRow();
//           int sCol = observerPiece->getCol();
//           if (observerPiece->getColour() != Colour::Black) {
            
//             if (observerPiece->getType() == 'P' && j == observerPiece->getCol() && b.getCellAt(i, j).hasPiece()) {
//               continue;
//             } else if (observerPiece->getType() == 'P' && j != observerPiece->getCol() && !(b.getCellAt(i, j).hasPiece())) {
//               continue;
//             }
            
//             bool t = false;
//             unique_ptr<Piece> temp = nullptr;
//             if (b.getCellAt(i, j).hasPiece()) {
//               temp = b.getCellAt(i, j).getActualPiece();
//               temp.get()->detachFromCells(b);
//               t = true;
//             }
//             b.makeMove(b.getCellAt(observerPiece->getRow(), observerPiece->getCol()), b.getCellAt(i, j));
//             bool isMoveInCheck = false;
//             for (int g = 0; g < 8 && (!isMoveInCheck); ++g) {
//               for (int h = 0; h < 8 && (!isMoveInCheck); ++h) {
//                 if (!b.getCellAt(g, h).hasPiece()) {
//                   continue;
//                 }
//                 if (b.getCellAt(g, h).getPiece()->getType() == 'k') {
//                   int n = b.getCellAt(g, h).getObservers().size();
//                   for (int z = 1; z < n; ++z) { // change to 2
//                     //cout << b.getCellAt(g, h).getObservers()[1] << endl;
//                     Piece* observerPiece = dynamic_cast<Piece*>(b.getCellAt(g, h).getObservers()[z]);
//                     if (observerPiece->getColour() != Colour::White) {
//                       if (observerPiece->getType() == 'p' && j == observerPiece->getCol()) {
//                         continue;
//                       }
//                       isMoveInCheck = true;
//                     }
//                   }
//                 }
//               }
//             }

//             b.makeMove(b.getCellAt(i, j), b.getCellAt(sRow, sCol));
//             if (t) {
//               b.setupAdd(i, j, temp.get()->getType());
//             }
//             if (isMoveInCheck) {
//               isMoveInCheck = false;
//               t = false;
//             } else {
//               //cout << i << j << sRow << sCol << endl;
//               stalemate = false;
//             }

//           }
//         }
//       }
//     }

//     if (check && stalemate) {
//       cout << "Checkmate" << endl; // handle Black wins
//       return 'b';
//     } else if (check) {
//       cout << "White is in check" <<  endl; 
//     } else if (stalemate) {
//       cout << "Stalemate: This game is a draw" << endl; // handle draw
//       return 'd';
//     } else {
//       cout << "nothing" << endl;
//       return 'n';
//     }


//   } // Might need to add try excepts, ideally should be handled by player class
//   return 'n';
// }