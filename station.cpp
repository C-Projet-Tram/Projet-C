#include "station.h"
#include <cmath>
Station::Station():d_nom(""),posX(0),posY(0),tempsArret(0)
{}

Station::Station(const Station &s)
{
	d_nom=s.d_nom;
	posX=s.posX;
	posY=s.posY;
	tempsArret=s.tempsArret;
}

double Station::distance(const Station &S) const
{
  int X=S.posX-posX,Y=S.posY-posY;
  return sqrt((X*X)+(Y*Y));
}

string Station::nom()
{
	return d_nom;
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
