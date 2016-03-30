#include "station.h"
#include <cmath>
Station::Station():posX(0),posY(0),tempsArret(0)
{}

double Station::distance(const Station &S) const
{
  int X=S.posX-posX,Y=S.posY-posY;
  return sqrt((X*X)+(Y*Y));
}

bool Station::operator!=(const Station &S) const
{
	if (this==&S) return false;
	if (posX==S.posX)
		if (posY==S.posY)
			if (tempsArret==S.tempsArret)
				return false;
	return true;
}

bool Station::operator==(const Station &S) const
{
	if (this==&S) return true;
	if (posX==S.posX)
		if (posY==S.posY)
			if (tempsArret==S.tempsArret)
				return true;
	return false;
}
