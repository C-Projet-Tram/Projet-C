#include "graphics.h"
#include "station.h"
#include "Ligne.h"
#include "ListeTrams.h"


/*Fonctions à utiliser pour l'interface graphique
//void line(int x0, int y0, int x1, int y1)
//setcolor(int c) (ex c=RED)
//void circle(int x, int y, int radius)
//void rectangle (int left, int top, int right, int bottom)
*/

struct AnciennePosTram {
	double ancienX = 0, ancienY = 0;
};


void afficherLigneEtStation(const vector<Ligne> &ldl) 
{
	Station station1,station2;
	for (unsigned int i = 0 ; i < ldl.size() ; i++) {
		setcolor(i+1);
		for (int j = 0 ; j < ldl[i].tailleTableau()-1 ; j++) {
			station1 = ldl[i].getStation(j);
			station2 = ldl[i].getStation(j+1);
			circle(station1.getPosX(),station1.getPosY(),7);
			//Retirer le floodfill si bug, je peux pas le test moi.
			//floodfill(station1.getPosX(),station1.getPosY(),i+1);
			outtextxy(station1.getPosX()+4,station1.getPosY()+4, station1.getNom().c_str());
			line(station1.getPosX(),station1.getPosY(),station2.getPosX(),station2.getPosY());
		}
		station1 = ldl[i].getStation(ldl[i].tailleTableau()-1);
		circle(station1.getPosX(),station1.getPosY(),7);
		//floodfill(station1.getPosX()+4,station1.getPosY()+4,i+1);
	}
}

void afficherTram(const ListeTrams &ldt)
{
	
	ListeTrams tmp = ldt;
	double posX, posY;
	AnciennePosTram posTram[tmp.taille()];
	int k = 0;
	while (tmp.tram()) 
	{
		posX = tmp.tram()->tramPosX();
		posY = tmp.tram()->tramPosY();
		
		setcolor(BLACK);
		rectangle(posTram[k].ancienX-5,posTram[k].ancienY-5,posTram[k].ancienX+5,posTram[k].ancienY+5);
		setcolor(WHITE);
		rectangle(posX-5,posY-5,posX+5,posY+5);
		
		posTram[k].ancienX = posX;
		posTram[k].ancienY = posY;
		
		//Retirer le floodfill si bug, je peux pas le test moi.
		//floodfill(posX,posY,WHITE);
		
		int numTram = tmp.tram()->getNum();
	
		char tramNumPos[10];
		sprintf(tramNumPos, "%d", numTram);
		outtextxy(posX+15,posY+15,tramNumPos);
		
		tmp.Next();
		k++;
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
	outtextxy(30,30,duree);
}
