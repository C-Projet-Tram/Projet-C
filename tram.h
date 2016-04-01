#ifndef TRAM_H
#define TRAM_H
#include "station.h"
#include "ligne.h"

class Tram
{
	friend class ListeTrams;
	public:
		Tram();
		Tram(const Tram *T2);
		Tram(int num,int vitesse,int dMini,bool direction,bool marche,Ligne ligne,Station station1);
		void enMarche();
		void verifDistanceMinimale(Tram *T2);
		void verifToutTram(Tram *T2);
		void tramAvance(double milisecondes);
		void changeDirection();
		void initialiseStation2();

		
		int getNum() const;
		int getVitesse() const;
		int getDistanceMinimum() const;
		double getDistance() const;
		Station getStation1() const;
		Station getStation2() const;
		bool getDirection() const;
		bool getMarche() const;
		Ligne getLigne() const;
		double getTempsArret() const;
		Tram *getSuivant() const;
		Tram *getSuivant();
		/*
		Tram operator=(Tram T);
		bool operator==(Tram T);
		bool operator!=(Tram T);
		*/
	private:
		int d_num;
		int d_vitesse;
		int distanceMinimum;
		double distance;
		bool d_direction;
		bool d_marche;
		Ligne ligne;
		Station station1 , station2;
		double tempsArret;
		Tram *suiv;
};

#endif
