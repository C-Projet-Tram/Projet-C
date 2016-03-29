#ifndef LISTETRAMS_H
#define LISTETRAMS_H
#include "tram.h"

class ListeTrams
{
	public:
		ListeTrams();
		~ListeTrams();
		int taille() const;
		void ajouter(int num,int vitesse,int dMini,int s1,int s2,bool direction,bool marche);
		/*
		void enleverTram(Tram T);
		ListeTrams operator+=(Tram T);
		ListeTrams operator+=(ListeTrams T);
		*/
	private:
		Tram *t;

};

#endif
