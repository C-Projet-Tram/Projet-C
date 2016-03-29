#ifndef LISTESTATIONS_H
#define LISTESTATIONS_H
#include "station.h"
#include <vector>

using namespace std;

class ListeStations
{
	friend class Ligne;
	public:
		ListeStations();
		Station stationSuivante(const Station &S) const;
		Station stationPrecedente(const Station &S) const;
	private:
		vector<Station> d_liste;
};

#endif
