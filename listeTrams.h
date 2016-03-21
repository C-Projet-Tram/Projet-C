#ifndef LISTETRAMS_H
#define LISTETRAMS_H
#include "tram.h"

class ListeTrams
{
	public:
		ListeTrams();
		void ajoutTram(Tram T);
		void enleverTram(Tram T);
		ListeTrams operator+=(Tram T);
		ListeTrams operator+=(ListeTrams T);
	private:
		Tram d_tram;
		ListeTrams *d_suivant;
		int nbDeTrams;
};

#endif