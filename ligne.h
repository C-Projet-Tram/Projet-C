#ifndef LIGNE_H
#define LIGNE_H
#include "listeStations.h"
class Ligne
{
	public:
		Ligne();
	private:
		ListeStations d_listeStation;
		static int nblignes;
};

#endif
