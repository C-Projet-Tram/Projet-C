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
	S1=T2->getStation1();
	S2=T2->getStation2();
	d_direction=T2->getDirection();
	d_marche=T2->getMarche();
	L=T2->getLigne();
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
	return S1;
}

Station Tram::getStation2() const
{
	return S2;
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
	return L;
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
		verifDistanceMinimale(tmp);
		tmp=tmp->suiv;
	}
}


void Tram::verifDistanceMinimale(Tram *T2)
{
	if (L==T2->L)
	{
		if (distance-T2->distance<distanceMinimum)
		{
			if (d_marche==1)
				enMarche();
		}
		else if (d_marche==0)
			enMarche();
	}
}

void Tram::tramAvance(double milisecondes)
{
	double pixels=milisecondes*d_vitesse/1000;
	double pixelsTot=S1.distance(S2);
	double distanceAjoutee=pixels/pixelsTot;
	distance+=distanceAjoutee;
	if (distance>1)
	{
		if (d_direction==true)
		{
			if (L.GetListe()[L.TailleTableau()]==S2)
			{
				changeDirection();
				Station Stmp=S2;
				S2=S1;
				S1=Stmp;
			}
			else
			{
				S1=S2;
				S2=L.stationSuivante(S2);
				distance=0;
			}
		}
		else
		{
			if (L.GetListe()[0]==S2)
			{
				changeDirection();
				Station Stmp=S2;
				S2=S1;
				S1=Stmp;
			}
			else
			{
				S2=S1;
				S1=L.stationPrecedente(S1);
				distance=0;
			}
		}
	}
}

void Tram::changeDirection()
{
	d_direction=!d_direction;
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
	S1=T.S1;
	S2=T.S2;
	d_direction=T.d_direction;
	d_marche=T.d_marche;
	L=T.L;
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

