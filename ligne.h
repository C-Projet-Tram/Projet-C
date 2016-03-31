#ifndef LIGNE_H
#define LIGNE_H
#include "station.h"
#include <vector>
#include <cmath>

using namespace std;

class Ligne
{
	public:
		Ligne();
		//Ligne(vector<Station> liste):d_liste(liste){}
		void ajouter(const Station &station);
		Station stationSuivante(const Station &station) const; 
		Station stationPrecedente(const Station &station) const;
		
		int tailleTableau() const;
		vector <Station> getListe() const;
		Station getStation(int i) const;
		
		bool operator==(const Ligne &ligne) const;
	private:
		vector <Station> d_liste;
};

#endif
