#include "tram.h"

void Tram::enMarche()
{
	d_marche = !d_marche;
}

Tram::Tram(const Tram *tram)
{
<<<<<<< HEAD
	d_num=tram->d_num;
	d_vitesse=tram->d_vitesse;
	distanceMinimum=tram->distanceMinimum;
	distance=tram->distance;
	station1=tram->station1;
	station2=tram->station2;
	d_direction=tram->d_direction;
	d_marche=tram->d_marche;
	ligne=tram->ligne;
	suiv=tram->suiv;
}

Tram::Tram():d_num(0),d_vitesse(30),distanceMinimum(75),distance(0),d_direction(1),d_marche(0),suiv(0)
{}

Tram::Tram(int num,int vitesse,int dMini,bool direction,bool marche,Ligne ligne,Station station1):
	d_num(num),d_vitesse(vitesse),distanceMinimum(dMini),distance(0),d_direction(direction),d_marche(marche),ligne(ligne),station1(station1),suiv(0)
{
	initialiseStation2();
=======
	d_num=T2->d_num;
	d_vitesse=T2->d_num;
	distanceMinimum=T2->distanceMinimum;
	distance=T2->distance;
	station1=T2->station1;
	station2=T2->station2;
	d_direction=T2->d_direction;
	d_marche=T2->d_marche;
	ligne=T2->ligne;
	suiv=T2->suiv;
>>>>>>> origin/master
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

void Tram::verifToutTram(Tram *tram)
{
	Tram *tmp=tram;
	while(tmp)
	{
		if (this != tmp)
			verifDistanceMinimale(tmp);
			tmp = tmp->suiv;
	}
}

void Tram::verifDistanceMinimale(Tram *tram) 
{
	if (ligne == tram->ligne)
	{
		if (abs(distance-tram->distance) < distanceMinimum)
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
		if (d_direction)
		{
			if (ligne.getListe()[ligne.tailleTableau()-1] == station2)
			{
				changeDirection();
				Station Stmp = station2;
				station2 = station1;
				station1 = Stmp;
				distance = 0;
			}
			else
			{
				station1 = station2;
				station2 = ligne.stationSuivante(station2);
				distance = 0;
			}
		}
		else
		{
			if (ligne.getListe()[0] == station2)
			{
				changeDirection();
				Station Stmp = station2;
				station2 = station1;
				station1 = Stmp;
				distance = 0;
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

void Tram::initialiseStation2()
{
	if (d_direction)
		station2 = ligne.stationSuivante(station1);
	else
		station2 = ligne.stationPrecedente(station1);
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

