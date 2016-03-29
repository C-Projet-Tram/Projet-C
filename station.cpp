#include "station.h"
#include <cmath>
Station::Station():posX(0),posY(0)
{}

double Station::distance(const Station &S2) const
{
  int X=S2.posX-posX,Y=S2.posY-posY;
  return sqrt((X*X)+(Y*Y));
}
