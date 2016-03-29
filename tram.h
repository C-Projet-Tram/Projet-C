#ifndef TRAM_H
#define TRAM_H
#include "station.h"

class Tram
{
	friend class ListeTrams;
	public:
		bool tramDevant(int ligne,bool direction);//verifie s'il y a un tram devant, renvoie true si oui, false sinon.
		void enMarche();
		void verifDistanceMinimale(const Tram &T2);
		/*
		Tram operator=(Tram T);
		bool operator==(Tram T);
		bool operator!=(Tram T);
		*/
	private:
		Tram():d_num(0),d_vitesse(30),distanceMinimum(75),distance(0),d_direction(1),d_marche(0),suiv(0){}
		Tram(int num,int vitesse,int dMini,int s1,int s2,bool direction,bool marche):
		d_num(num),d_vitesse(vitesse),distanceMinimum(dMini),distance(0),d_direction(direction),d_marche(marche),suiv(0){}//ICI FAUT FAIRE EN SORTE AVEC LES STATION EN INT
		
		int d_num;
		int d_vitesse;
		int distanceMinimum;
		double distance;
		Station S1,S2;
		bool d_direction;
		bool d_marche;
		Tram *suiv; 
};

#endif
