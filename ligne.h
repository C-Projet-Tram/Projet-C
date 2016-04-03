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
		
		int tailleTableau() const;//Renvoie la taille de d_liste
		vector <Station> getListe() const;//Renvoie d_liste
		Station getStation(int i) const;//Renvoie la station à la position i dans la liste d_liste
		
		bool operator==(const Ligne &ligne) const;//opérateur de comparaison avec une autre ligne
	private:
		vector <Station> d_liste;
};

#endif
