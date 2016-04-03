#include "tram.h"

Tram::Tram(const Tram *tram)
{
	d_num = tram->d_num;
	d_vitesse = tram->d_vitesse;
	distanceMinimum = tram->distanceMinimum;
	distance = tram->distance;
	station1 = tram->station1;
	station2 = tram->station2;
	d_direction = tram->d_direction;
	d_marche = tram->d_marche;
	ligne = tram->ligne;
	tempsArret = tram->tempsArret;
	suiv = tram->suiv;
}

Tram::Tram():d_num(0),d_vitesse(30),distanceMinimum(75),distance(0),d_direction(1),d_marche(0),tempsArret(0),suiv(0)
{}

Tram::Tram(int num,int vitesse,int dMini,bool direction,bool marche,Ligne ligne,Station station1):
	d_num(num),d_vitesse(vitesse),distanceMinimum(dMini),distance(0),d_direction(direction),d_marche(marche),ligne(ligne),station1(station1),tempsArret(0),suiv(0)
{
	initialiseStation2();
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

double Tram::getTempsArret() const
{
	return tempsArret;
}

Tram *Tram::getSuivant() const
{
	return suiv;
}

Tram *Tram::getSuivant()
{
	return suiv;
}


void Tram::verifToutTram(Tram *tram)
{
	Tram *tmp = tram;
	while(tmp)
	{
		if (this != tmp)
			verifDistanceMinimale(tmp);
			tmp = tmp->suiv;
	}
}

int Tram::numeroStation() const
{
	unsigned int i;
	for(i=0; i < ligne.getListe().size() && ligne.getListe()[i] != station1; i++);
	return i;
}


void Tram::verifDistanceMinimale(Tram *tram) 
{
	if (ligne == tram->ligne)
	{
		if (d_direction == tram->d_direction)
		{
			if (((numeroStation() < tram->numeroStation()) && (d_direction == 1)) || ((numeroStation() > tram->numeroStation()) && (d_direction == 0)))
			{
				Station tmpStation1(tramPosX(), tramPosY());
				Station tmpStation2(tram->tramPosX(), tram->tramPosY());
				if (tmpStation1.distance(tmpStation2) < distanceMinimum)
				{
					if (d_marche == 1)
						enMarche();
				}
				else if (d_marche == 0)
					enMarche();
			}
		}
	}
}

void Tram::tramAvance(double milisecondes)
{
	if (d_marche)//Vérifie si le tram est en marche
	{
		double pixels = milisecondes*d_vitesse/1000;
		double pixelsTot = station1.distance(station2);
		double distanceAjoutee = pixels/pixelsTot;
		distance += distanceAjoutee;
		if (distance >= 1)//Si un tram atteint la station2
		{
			if (d_direction)//En fonction de la direction
			{
				if (ligne.getListe()[ligne.tailleTableau()-1] == station2)//S'il arrive à un terminus
				{
					tempsArret = station2.getTempsArret();
					enMarche();
					changeDirection();
					Station Stmp = station2;
					station2 = station1;
					station1 = Stmp;
					distance = 0;
				}
				else//Les cas autres que le terminus
				{
					tempsArret = station2.getTempsArret();
					enMarche();
					station1 = station2;
					station2 = ligne.stationSuivante(station2);
					distance = 0;
				}
			}
			else
			{
				if (ligne.getListe()[0] == station2)//S'il arrive à un terminus
				{
					tempsArret = station2.getTempsArret();
					enMarche();
					changeDirection();
					Station Stmp = station2;
					station2 = station1;
					station1 = Stmp;
					distance = 0;
				}
				else//Les cas autres que le terminus
				{
					tempsArret = station2.getTempsArret();
					enMarche();
					station1 = station2;
					station2 = ligne.stationPrecedente(station1);
					distance = 0;
				}
			}
		}
	}
	else
	{
		if (tempsArret > 0)//Vérifie s'il est à l'arrêt
		{
			tempsArret -= milisecondes;
		}
		else//Initialise tempsArret à 0 au cas où tempsArret est négatif ( ce qui arrive presque tout le temps )
		{
			tempsArret = 0;
			enMarche();
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

double Tram::tramPosX() const
{
	double vecteurStationX = station2.getPosX()-station1.getPosX();
	return station1.getPosX() + distance*vecteurStationX;	
}

double Tram::tramPosY() const
{
	double vecteurStationY = station2.getPosY()-station1.getPosY();
	return station1.getPosY() + distance*vecteurStationY;	
}


void Tram::changeDirection()
{
	d_direction = !d_direction;
}

void Tram::enMarche()
{
	d_marche = !d_marche;
}


