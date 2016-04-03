#include "graphics.h"
#include "station.h"
#include "Ligne.h"
#include "ListeTrams.h"

void afficherLigneEtStation(const vector<Ligne> &ldl) 
{
	Station station1,station2;
	for (unsigned int i = 0 ; i < ldl.size() ; i++) {
		setcolor(i+1);
		for (int j = 0 ; j < ldl[i].tailleTableau()-1 ; j++) {
			station1 = ldl[i].getStation(j);
			station2 = ldl[i].getStation(j+1);
			circle(station1.getPosX(),station1.getPosY(),7);

			outtextxy(station1.getPosX()+4,station1.getPosY()+4, station1.getNom().c_str());
			line(station1.getPosX(),station1.getPosY(),station2.getPosX(),station2.getPosY());
		}
		station1 = ldl[i].getStation(ldl[i].tailleTableau()-1);
		circle(station1.getPosX(),station1.getPosY(),7);

		outtextxy(station1.getPosX()+4,station1.getPosY()+4, station1.getNom().c_str());
	}
}

void afficherTram(const ListeTrams &ldt)
{
	
	ListeTrams tmp = ldt;
	double posX, posY;
	int numTram = 0;
	
	setcolor(WHITE);
	while (tmp.tram()) 
	{
		posX = tmp.tram()->tramPosX();
		posY = tmp.tram()->tramPosY();
		
		rectangle(posX-5,posY-5,posX+5,posY+5);
		
		numTram = tmp.tram()->getNum();
	
		char tramNumPos[10];
		sprintf(tramNumPos, "%d", numTram);
		outtextxy(posX+15,posY+15,tramNumPos);
		
		tmp.Next();
	}
}

void afficher(const vector<Ligne> &ldl, const ListeTrams &ldt, double dureeRestante)
{
	char duree[10];
	cleardevice();
	setbkcolor(BLACK);

	afficherLigneEtStation(ldl);
	afficherTram(ldt);
	int dureeint = static_cast<int>(dureeRestante);
	sprintf(duree, "%d", dureeint);
	setcolor(WHITE);

	outtextxy(10,10,"Durée restante : ");
	outtextxy(150,10,duree);
}
