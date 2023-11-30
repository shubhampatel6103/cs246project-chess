#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <vector>
#include "Observer.h"
class Board;
class Cell;

class TextDisplay: public Observer {
  std::vector<std::vector<char>> theDisplay {{'8', ' ', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}, 
                                             {'7', ' ','p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                                             {'6', ' ',' ', '_', ' ', '_', ' ', '_', ' ', '_'},
                                             {'5', ' ','_', ' ', '_', ' ', '_', ' ', '_', ' '},
                                             {'4', ' ',' ', '_', ' ', '_', ' ', '_', ' ', '_'},
                                             {'3', ' ','_', ' ', '_', ' ', '_', ' ', '_', ' '},
                                             {'2', ' ','P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                                             {'1', ' ','R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                                             {' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                             {' ', ' ','a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
 public:
  TextDisplay();

  void notify(Cell &c, Board &b) override;
  ~TextDisplay();

  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
