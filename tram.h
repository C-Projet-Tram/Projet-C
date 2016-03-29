#ifndef TRAM_H
#define TRAM_H

class Tram
{
	friend class ListeTrams;
	public:
		bool tramDevant(int ligne,bool direction);//vérifie s'il y a un tram devant, renvoie true si oui, false sinon.
		void enMarche();
		/*
		Tram operator=(Tram T);
		bool operator==(Tram T);
		bool operator!=(Tram T);
		*/
	private:
		Tram():d_num(0),d_direction(0),d_marche(0),suiv(0){}
		Tram(int num,bool direction,bool marche):d_num(num),d_direction(direction),d_marche(marche),suiv(0){}
		
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
