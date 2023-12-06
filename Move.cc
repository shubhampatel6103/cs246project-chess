#include "Move.h"


Move::Move(bool r, int sX, int sY, int dX, int dY): resign{r}, coords{sX, sY, dX, dY} {}

int* Move::getCoords() {
  return coords;
}

bool Move::getResigned() { return resign; }

void Move::setMove(bool r, int sX, int sY, int dX, int dY) {
  resign = r;
  coords[0] = sX;
  coords[1] = sY;
  coords[2] = dX;
  coords[3] = dY;
}


