#include "Ligne.h"

Ligne::Ligne():d_liste(0)
{}

void Ligne::ajouter(const Station &station)
{
	d_liste.push_back(station);
}

Station Ligne::getStation(int i) const
{
	return d_liste[i];
}

Station Ligne::stationSuivante(const Station &station) const
{
	unsigned int i;
	for(i=0; i < d_liste.size(); i++)
	if (d_liste[i] == station)
		return d_liste[i+1];
	return d_liste[i-1];
}
 
Station Ligne::stationPrecedente(const Station &station) const
{
	unsigned int i;
	for(i=0; i < d_liste.size(); i++)
	if (d_liste[i] == station)
		return d_liste[i-1];
	return d_liste[i+1];
}

bool Ligne::operator==(const Ligne &ligne) const
{
	if (d_liste.size() != ligne.d_liste.size()) return false;
	for(unsigned int i=0;i < d_liste.size();i++)
		if (d_liste[i] != ligne.d_liste[i])
			return false;
	return true;
}

int Ligne::tailleTableau() const
{
	return d_liste.size();
}

vector <Station> Ligne::getListe() const
{
	return d_liste;
}
