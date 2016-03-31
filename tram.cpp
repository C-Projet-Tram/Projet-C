#include "tram.h"

void Tram::enMarche()
{
	d_marche=!d_marche;
}

Tram::Tram(const Tram *T2)
{
	d_num=T2->getNum();
	d_vitesse=T2->getVitesse();
	distanceMinimum=T2->getDistanceMinimum();
	distance=T2->getDistance();
	station1=T2->getStation1();
	station2=T2->getStation2();
	d_direction=T2->getDirection();
	d_marche=T2->getMarche();
	ligne=T2->getLigne();
	suiv=T2->getSuivant();
}

int Tram::getNum() const
{
	return d_num;
}

int Tram::getVitesse() const
{
	return d_vitesse;
}

int Tram::getDistanceMinimum() const
{
	return distanceMinimum;
}

double Tram::getDistance() const
{
	return distance;
}

Station Tram::getStation1() const
{
	return station1;
}

Station Tram::getStation2() const
{
	return station2;
}

bool Tram::getDirection() const
{
	return d_direction;
}

bool Tram::getMarche() const
{
	return d_marche;
}

Ligne Tram::getLigne() const
{
	return ligne;
}

Tram *Tram::getSuivant() const
{
	return suiv;
}

void Tram::verifToutTram(Tram *T2)
{
	Tram *tmp=T2;
	while(tmp)
	{
		if (this != tmp)
			verifDistanceMinimale(tmp);
			tmp = tmp->suiv;
	}
}


void Tram::verifDistanceMinimale(Tram *T2) 
{
	if (ligne == T2->ligne)
	{
		if (distance-T2->distance < distanceMinimum)
		{
			if (d_marche == 1)
				enMarche();
		}
		else if (d_marche == 0)
			enMarche();
	}
}

void Tram::tramAvance(double milisecondes)
{
	double pixels = milisecondes*d_vitesse/1000;
	double pixelsTot = station1.distance(station2);
	double distanceAjoutee = pixels/pixelsTot;
	distance += distanceAjoutee;
	if (distance > 1)
	{
		if (d_direction == true)
		{
			if (ligne.getListe()[ligne.tailleTableau()-1]==station2)
			{
				changeDirection();
				Station Stmp=station2;
				station2=station1;
				station1=Stmp;
			}
			else
			{
				station1=station2;
				station2=ligne.stationSuivante(station2);
				distance=0;
			}
		}
		else
		{
			if (ligne.getListe()[0]==station2)
			{
				changeDirection();
				Station Stmp=station2;
				station2=station1;
				station1=Stmp;
			}
			else
			{
				station2 = station1;
				station1 = ligne.stationPrecedente(station1);
				distance = 0;
			}
		}
	}
}

void Tram::changeDirection()
{
	d_direction = !d_direction;
}


Tram *Tram::getSuivant()
{
	return suiv;
}

/*
Tram Tram::operator=(Tram T)
{
	if (this==&T) return T;
	d_num=T.d_num;
	d_vitesse=T.d_vitesse;
	distance=T.distance;
	station1=T.station1;
	station2=T.station2;
	d_direction=T.d_direction;
	d_marche=T.d_marche;
	ligne=T.ligne;
	suiv=T.suiv;
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

