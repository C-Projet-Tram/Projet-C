#ifndef LISTETRAMS_H
#define LISTETRAMS_H
#include "tram.h"

class ListeTrams
{
	public:
		ListeTrams();
		ListeTrams(const ListeTrams *lt);
		~ListeTrams();
		int taille() const;
		void ajouter(int num,int vitesse,int dMini,Station S1,Station S2,bool direction,bool marche,Ligne L);
		Tram tram();
		/*
		void enleverTram(Tram T);
		ListeTrams operator+=(Tram T);
		ListeTrams operator+=(ListeTrams T);
		*/
	private:
		Tram *t;

};

#endif
