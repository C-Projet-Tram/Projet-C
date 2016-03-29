#include "tram.h"

void Tram::enMarche()
{
	if (d_marche==0) 
		d_marche=1;
	else
		 d_marche=0;
}

void Tram::verifDistanceMinimale(const Tram &T2) const
{
	if (distance-T2.distance<distanceMinimum)
		enMarche();
}

/*
Tram Tram::operator=(Tram T)
{
	if (this==&T) return T;
	d_direction=T.d_direction;
	d_marche=T.d_marche;
	return *this;
}

bool Tram::operator==(Tram T)
{
	if (this==&T) return true;
	if (d_direction==T.d_direction)
		if (d_marche==T.d_marche)
			return true;
	return false;
}

bool Tram::operator!=(Tram T)
{
	if (this==&T) return false;
	if (d_direction!=T.d_direction)
		if (d_marche!=T.d_marche)
		return true;
	return false;
}

*/

