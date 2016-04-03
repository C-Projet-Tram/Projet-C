#ifndef TRAM_H
#define TRAM_H
#include "station.h"
#include "ligne.h"

class Tram
{
	friend class ListeTrams;
	public:
		Tram();//Constructeur par défaut
		Tram(const Tram *T2);//Constructeur par recopie
		Tram(int num,int vitesse,int dMini,bool direction,bool marche,Ligne ligne,Station station1);//Constructeur avec variables
		void enMarche();//Inverse le booléen d_marche qui arrête/démarre un tram
		void verifDistanceMinimale(Tram *T2);//Vérifie la distance minimale avec un autre Tram via la distance (euclidienne)
		void verifToutTram(Tram *T2);//Utilise la fonction ci-dessus mais sur toute la liste de tram
		void tramAvance(double milisecondes);//Fait avancer un tram du nombre de milisecondes indiquées
		void changeDirection();//Inverse le booléen d_direction qui fait rouler un tram dans un sens ou dans l'autre
		void initialiseStation2();//Initialise la station2 avec la station1 en fonction de d_direction
		double tramPosX() const;//Renvoie la posX d'un tram
		double tramPosY() const;//Renvoie la posY d'un tram
		int numeroStation() const;//Renvoie le numéro i de station1 dans la variable ligne
		
		int getNum() const;//Renvoie d_num
		int getVitesse() const;//Renvoie d_vitesse
		int getDistanceMinimum() const;//Renvoie distanceMinimum
		double getDistance() const;//Renvoie distance
		Station getStation1() const;//Renvoie station1
		Station getStation2() const;//Renvoie station2
		bool getDirection() const;//Renvoie d_direction
		bool getMarche() const;//Renvoie d_marche
		Ligne getLigne() const;//Renvoie ligne
		double getTempsArret() const;//Renvoie tempsArret
		Tram *getSuivant() const;//Renvoie suiv en constante
		Tram *getSuivant();//Renvoie suiv de façon à être modifiable

	private:
		int d_num;
		int d_vitesse;
		int distanceMinimum;
		double distance;
		bool d_direction;
		bool d_marche;
		Ligne ligne;
		Station station1 , station2;
		double tempsArret;
		Tram *suiv;
};

#endif
