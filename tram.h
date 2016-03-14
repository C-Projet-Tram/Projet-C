#ifndef TRAM_H
#define TRAM_H

class Tram
{
	public:
		Tram();//initialisation
		Tram(bool direction,int ligne,int vitesse);//initialisation avec variables
		bool tramDevant(int ligne,bool direction);//vérifie s'il y a un tram devant, renvoie bool si vrai et int si faux kek
	private:
		bool d_direction;
		int d_vitesse;
};

#endif
