#include "Ligne.h"

Ligne::Ligne():d_liste(0)
{}

void Ligne::ajouter(const Station &S)
{
	d_liste.push_back(S);
}

Station Ligne::getStation(int i)
{
	return d_liste[i];
}

Station Ligne::stationSuivante(const Station &S) const
{
	int i;
	for(i=0;i<d_liste.size() && d_liste[i]!=S;i++)
	if (d_liste[i]==S)
		return d_liste[i+1];
}

Station Ligne::stationPrecedente(const Station &S) const
{
	int i;
	for(i=0;i<d_liste.size() && d_liste[i]!=S;i++)
	if (d_liste[i]==S)
		return d_liste[i-1];
}

bool Ligne::operator==(const Ligne &L) const
{
	if (d_liste.size()!=L.d_liste.size()) return false;
	for(int i=0;i<d_liste.size();i++)
		if (d_liste[i]!=L.d_liste[i])
			return false;
	return true;
}

int Ligne::TailleTableau() const
{
	return d_liste.size();
}

vector <Station> Ligne::getListe() const
{
	return d_liste;
}
