#ifndef LISTETRAMS_H
#define LISTETRAMS_H
#include "tram.h"

class ListeTrams
{
	public:
		ListeTrams();//Constructeur par d�faut
		ListeTrams(const ListeTrams &lt);//Constructeur par recopie
		~ListeTrams();//Destructeur par d�faut
		int taille() const;//Renvoie la taille de la liste de Trams
		void ajouter(int num,int vitesse,int dMini,Station station1,bool direction,bool marche,const Ligne &ligne);//Ajoute un tram � la liste de tram
		Tram *tram();//Renvoie la t�te t
		void Next();//Transforme le tram t en tram suiv de la classe Tram

	private:
		Tram *t;

};

#endif
