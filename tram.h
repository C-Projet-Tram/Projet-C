#ifndef TRAM_H
#define TRAM_H
#include "station.h"
#include "ligne.h"

class Tram
{
	friend class ListeTrams;
	public:
		void enMarche();
		void verifDistanceMinimale(const Tram &T2);
		void tramAvance(double secondes);
		Tram suivant();
		/*
		Tram operator=(Tram T);
		bool operator==(Tram T);
		bool operator!=(Tram T);
		*/
	private:
		Tram():d_num(0),d_vitesse(30),distanceMinimum(75),distance(0),d_direction(1),d_marche(0),suiv(0){}
		Tram(int num,int vitesse,int dMini,bool direction,bool marche,Ligne L,Station S1):
		d_num(num),d_vitesse(vitesse),distanceMinimum(dMini),distance(0),d_direction(direction),d_marche(marche),L(L),S1(S1),suiv(0)
		{
				if (direction==1)
					S2=L.stationSuivante(S1);
				else
					S2=L.stationPrecedente(S1);
		}
		
		int d_num;
		int d_vitesse;
		int distanceMinimum;
		double distance;
		Station S1,S2;
		bool d_direction;
		bool d_marche;
		Ligne L;
		Tram *suiv; 
};

#endif
