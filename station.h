#ifndef STATION_H
#define STATION_H
#include <iostream>
using namespace std;

class Station
{
	public:
		Station();
		Station(string nom,int X,int Y,int tArret):d_nom(nom),posX(X),posY(Y),tempsArret(tArret){}
		Station(const Station &s);
		double distance(const Station &S) const;
		string nom();
		bool operator!=(const Station &S) const;
		bool operator==(const Station &S) const;
	private:
		string d_nom;
		int posX,posY;
		int tempsArret;
};

#endif
