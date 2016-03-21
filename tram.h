#ifndef TRAM_H
#define TRAM_H

class Tram
{
	public:
		Tram();//initialisation
		Tram(bool direction,int ligne,bool marche);//initialisation avec variables
		bool tramDevant(int ligne,bool direction);//vérifie s'il y a un tram devant, renvoie true si oui, false sinon.
		void enMarche();
		Tram operator=(Tram T);
		bool operator==(Tram T);
		bool operator!=(Tram T);
	private:
		bool d_direction;
		bool d_marche;
};

#endif
