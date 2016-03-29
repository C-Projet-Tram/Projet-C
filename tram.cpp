#include "tram.h"

void Tram::enMarche()
{
	if (d_marche==0) 
		d_marche=1;
	else
		 d_marche=0;
}

void Tram::verifDistanceMinimale(const Tram &T2)
{
	if (L==T2.L)
	{
		if (distance-T2.distance<distanceMinimum)
		{
			if (d_marche==1)
				enMarche();
		}
		else if (d_marche==0)
			enMarche();
	}
}

void Tram::tramAvance(double secondes)
{
	double pixels=secondes*d_vitesse;
	double pixelsTot=S1.distance(S2);
	double distanceAjoutee=pixels/pixelsTot;
	distance+=distanceAjoutee;
	if (distance>1)
	{
		if (d_direction==true)
		{
			S1=S2;
			S2=L.stationSuivante(S2);
			distance=0;
		}
		else
		{
			S2=S1;
			S1=L.stationPrecedente(S1);
		}
	}
}

Tram Tram::suivant()
{
	return *suiv;
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

