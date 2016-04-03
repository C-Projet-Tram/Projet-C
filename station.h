#ifndef STATION_H
#define STATION_H
#include <iostream>
using namespace std;

class Station
{
	public:
		Station();//Constructeur par défaut
		Station(string nom,double X,double Y,int tArret);//Constructeur avec les variables
		Station(double X, double Y);//Constructeur fait spécialement pour calculer une distance à partir d'un tram
		Station(const Station &station);//Constructeur par recopie
		double distance(const Station &station) const;//Calcul de la distance (euclidienne) entre deux stations.
		
		string getNom() const;//Renvoie la variable d_nom d'une station
		int getPosX() const;//Renvoie la variable posX d'une station
		int getPosY() const;//Renvoie la variable posY d'une station
		int getTempsArret() const;//Renvoie la variable tempsArret d'une station
		
		bool operator!=(const Station &S) const;
		bool operator==(const Station &S) const;
	private:
		string d_nom; 
		double posX,posY;
		int tempsArret;
};

#endif
