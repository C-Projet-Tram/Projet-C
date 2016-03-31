#include "graphics.h"
#include <vector>
#include "station.h"
#include "Ligne.h"
#include "ListeTrams.h"

/*Fonctions à utiliser pour l'interface graphique
//void line(int x0, int y0, int x1, int y1)
//setcolor(int c) (ex c=RED)
//void circle(int x, int y, int radius)
//void rectangle (int left, int top, int right, int bottom)
*/

void afficherLigneEtStation(const vector<Ligne> &ldl) 
{
	Station station1,station2;
	for (unsigned int i = 0 ; i < ldl.size() ; i++) {
		setcolor(i+1);
		station1=station2;
		for (int j = 0 ; j < ldl[i].tailleTableau()-1 ; j++) {
			station1 = ldl[i].getStation(j);
			station2 = ldl[i].getStation(j+1);
			circle(station1.getPosX(),station1.getPosY(),10);
			line(station1.getPosX(),station1.getPosY(),station2.getPosX(),station2.getPosY());
		}
		station1 = ldl[i].getStation(ldl[i].tailleTableau()-1);
		circle(station1.getPosX(),station1.getPosY(),10);
	}
}

void afficherTram(const ListeTrams &ldt)
{
	setcolor(WHITE);
	ListeTrams tmp = ldt;
	Station station1, station2;
	int posX, posY;
	double dtram , vecteurX , vecteurY;
	while (tmp.tram()) {
		station1 = tmp.tram()->getStation1();
		station2 = tmp.tram()->getStation2();
		dtram = tmp.tram()->getDistance();
		
		vecteurX = station2.getPosX()-station1.getPosX();
		vecteurY = station2.getPosY()-station1.getPosY();
		
		posX = station1.getPosX()+dtram*vecteurX;
		posY = station1.getPosY()+dtram*vecteurY;
		
		rectangle(posX-10,posY-10,posX+10,posY+10);
		
		tmp.Next();
	}
}

void afficher(const vector<Ligne> &ldl, const ListeTrams &ldt)
{
	cleardevice();
	setbkcolor(BLACK);
	afficherLigneEtStation(ldl);
	afficherTram(ldt);
}
