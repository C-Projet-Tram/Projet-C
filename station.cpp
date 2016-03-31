#include "station.h"
#include <cmath>

Station::Station():d_nom(""),posX(0),posY(0),tempsArret(0)
{}

Station::Station(const Station &station)
{
	d_nom = station.getNom();
	posX = station.getPosX();
	posY = station.getPosY();
	tempsArret = station.getTempsArret();
}

double Station::distance(const Station &station) const
{
  int X = station.posX-posX, Y = station.posY-posY; 
  return sqrt((X*X)+(Y*Y));
}

string Station::getNom() const
{
	return d_nom;
}

int Station::getPosX() const
{
	return posX;
}

int Station::getPosY() const
{
	return posY;
}

int Station::getTempsArret() const
{
	return tempsArret;
}

bool Station::operator!=(const Station &S) const
{
	if (this == &S) return false;
	if (d_nom == S.d_nom)
		if (posX == S.posX)
			if (posY == S.posY)
				if (tempsArret==S.tempsArret)
					return false;
	return true;
}

bool Station::operator==(const Station &S) const
{
	if (this == &S) return true;
	if (d_nom == S.d_nom)
		if (posX == S.posX)
			if (posY == S.posY)
				if (tempsArret == S.tempsArret)
				return true;
	return false;
}
