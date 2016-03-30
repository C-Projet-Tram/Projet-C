#ifndef LIGNE_H
#define LIGNE_H
#include "station.h"
#include <vector>

using namespace std;

class Ligne
{
	public:
		Ligne();
		Station stationSuivante(const Station &S) const;
		Station stationPrecedente(const Station &S) const;
		int TailleTableau() const;
		vector <Station> GetListe() const;
		bool operator==(const Ligne &L) const;
	private:
		vector <Station> d_liste;
};

#endif
