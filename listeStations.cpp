#include "listeStations.h"

ListeStations::ListeStations()
{}

Station ListeStations::stationSuivante(const Station &S) const
{
	int i;
	for(i=0;i<d_liste.size() && d_liste[i]!=S;i++)
	if (d_liste[i]==S)
		return d_liste[i+1];
}

Station ListeStations::stationPrecedente(const Station &S) const
{
	int i;
	for(i=0;i<d_liste.size() && d_liste[i]!=S;i++)
	if (d_liste[i]==S)
		return d_liste[i-1];
}
