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
	Station s1,s2;
	for (unsigned int i = 0 ; i < ldl.size() ; i++) {
		setcolor(i+1);
		s1=s2;
		for (int j = 0 ; j < ldl[i].tailleTableau()-1 ; j++) {
			s1 = ldl[i].getStation(j);
			s2 = ldl[i].getStation(j+1);
			circle(s1.getPosX(),s1.getPosY(),10);
			line(s1.getPosX(),s1.getPosY(),s2.getPosX(),s2.getPosY());
		}
		s1 = ldl[i].getStation(ldl[i].tailleTableau()-1);
		circle(s1.getPosX(),s1.getPosY(),10);
	}
}

void afficherTram(const ListeTrams &ldt)
{
	setcolor(WHITE);
	ListeTrams tmp = ldt;
	Station s1, s2;
	int posX, posY;
	double dtram , dstation;
	while (tmp.tram()) {
		s1 = tmp.tram()->getStation1();
		s2 = tmp.tram()->getStation2();
		dtram = tmp.tram()->getDistance();
		dstation = s1.distance(s2);
		
		posX = dtram/dstation*s2.getPosX()+(1-dtram/dstation)*s1.getPosX();
		posY = dtram/dstation*s2.getPosY()+(1-dtram/dstation)*s1.getPosY();
		
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
