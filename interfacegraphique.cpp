#include "graphics.h"
#include <vector>
#include "tram.h"
#include "station.h"
#include "Ligne.h"

/*Fonctions à utiliser pour l'interface graphique
//void line(int x0, int y0, int x1, int y1)
//setcolor(int c) (ex c=RED)
//void circle(int x, int y, int radius)
//void rectangle (int left, int top, int right, int bottom)
*/

void afficherLigneEtStation(vector<Ligne> ldl) {
	Station s1,s2;
	for (int i = 0 ; i < ldl.size() ; i++) {
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
