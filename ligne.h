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
		void ajouter(const Station &S);
		Station stationSuivante(const Station &S) const; 
		Station stationPrecedente(const Station &S) const;
		
		int tailleTableau() const;
		vector <Station> getListe() const;
		Station getStation(int i);
		
		bool operator==(const Ligne &L) const;
	private:
		vector <Station> d_liste;
};

#endif
