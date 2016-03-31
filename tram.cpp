#include "tram.h"

void Tram::enMarche()
{
	d_marche=!d_marche;
}

Tram::Tram(const Tram *T2)
{
	d_num=T2->d_num;
	d_vitesse=T2->d_vitesse;
	distanceMinimum=T2->distanceMinimum;
	distance=T2->distance;
	S1=T2->S1;
	S2=T2->S2;
	d_direction=T2->d_direction;
	d_marche=T2->d_marche;
	L=T2->L;
	suiv=T2->suiv;
}

void Tram::verifToutTram(const Tram *T2)
{
	Tram *tmp=new Tram(T2);
	while(tmp)
	{
		verifDistanceMinimale(tmp);
		tmp=tmp->suiv;
	}
}


void Tram::verifDistanceMinimale(const Tram *T2)
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
			if (L.getListe()[L.TailleTableau()]==S2)
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
			if (L.getListe()[0]==S2)
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

Tram *Tram::suivant()
{
	return suiv;
}

void Tram::changeDirection()
{
	d_direction=!d_direction;
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

