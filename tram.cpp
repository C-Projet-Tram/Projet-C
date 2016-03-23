#include "tram.h"

Tram::Tram():d_direction(0),d_marche(0)
{}

Tram::Tram(bool direction,int ligne,bool marche):d_direction(direction),d_marche(marche)
{}

void Tram::enMarche()
{
	if (d_marche=0) d_marche=1;
	else d_marche=0;
}

bool Tram::tramDevant(int ligne,bool direction)
{
	//à remplir en fonction de la liste chaînée...
	//Ok maggle
}

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



