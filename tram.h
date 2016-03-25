#ifndef TRAM_H
#define TRAM_H

class Tram
{
	friend class listeTrams;
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
		
		//Need ya help, genre listeTrams a pas accès aux infos private de cette classe, pourtant c'est friend .. Maybe le header idk
		int d_num;
		bool d_direction;
		bool d_marche;
		Tram *suiv; 
};

#endif
