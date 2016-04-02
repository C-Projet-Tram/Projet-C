#ifndef STATION_H
#define STATION_H
#include <iostream>
using namespace std;

class Station
{
	public:
		Station();
		Station(string nom,double X,double Y,int tArret);
		Station(double X, double Y);
		Station(const Station &station);
		double distance(const Station &station) const;
		
		string getNom() const;
		int getPosX() const;
		int getPosY() const;
		int getTempsArret() const;
		
		bool operator!=(const Station &S) const;
		bool operator==(const Station &S) const;
	private:
		string d_nom; 
		double posX,posY;
		int tempsArret;
};

#endif
