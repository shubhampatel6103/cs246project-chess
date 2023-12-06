#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <vector>
#include "Observer.h"
class Board;
class Cell;

class TextDisplay: public Observer {
  std::vector<std::vector<char>> theDisplay {{'8', ' ', ' ', '_', ' ', '_', ' ', '_', ' ', '_'}, 
                                             {'7', ' ', '_', ' ', '_', ' ', '_', ' ', '_', ' '},
                                             {'6', ' ', ' ', '_', ' ', '_', ' ', '_', ' ', '_'},
                                             {'5', ' ', '_', ' ', '_', ' ', '_', ' ', '_', ' '},
                                             {'4', ' ', ' ', '_', ' ', '_', ' ', '_', ' ', '_'},
                                             {'3', ' ', '_', ' ', '_', ' ', '_', ' ', '_', ' '},
                                             {'2', ' ', ' ', '_', ' ', '_', ' ', '_', ' ', '_'},
                                             {'1', ' ', '_', ' ', '_', ' ', '_', ' ', '_', ' '},
                                             {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                             {' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
 public:
  TextDisplay();

  void notify(Cell &c, Board &b, bool display);
  ~TextDisplay();

  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif


