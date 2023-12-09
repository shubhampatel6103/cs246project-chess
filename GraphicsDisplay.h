#ifndef __GRAPHICSDISPLAY_H__
#define __GRAPHICSDISPLAY_H__
#include <iostream>
#include <vector>
#include "Window.h"
#include "Observer.h"
class Cell;

class GraphicsDisplay: public Observer {
  const int gridSize;
  Xwindow w;
  const int WIN_SIZE = 800;
 public:
  GraphicsDisplay(int n = 8);
  ~GraphicsDisplay();

  void notify(Cell &c, Board &b, bool display); // Cell c calls the notify function
};

#endif
