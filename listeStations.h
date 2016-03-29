#ifndef LISTESTATIONS_H
#define LISTESTATIONS_H
#include "station.h"
#include <vector>

using namespace std;

class ListeStations
{
	public:
		ListeStations();
	private:
		vector<Station> d_liste;
};

#endif
