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
		void ajouter(const Station &station);//Ajouter une station à la ligne
		Station stationSuivante(const Station &station) const;//Renvoie la station suivante d'une station
		Station stationPrecedente(const Station &station) const;//Renvoie la station precendente d'une station
		
		int tailleTableau() const;
		vector <Station> getListe() const;
		Station getStation(int i) const;
		
		bool operator==(const Ligne &ligne) const;
	private:
		vector <Station> d_liste;
};

#endif
