#ifndef LISTETRAMS_H
#define LISTETRAMS_H
#include "tram.h"

class ListeTrams
{
	public:
		ListeTrams();//Constructeur par défaut
		ListeTrams(const ListeTrams &lt);//Constructeur par recopie
		~ListeTrams();//Destructeur par défaut
		int taille() const;//Renvoie la taille de la liste de Trams
		void ajouter(int num,int vitesse,int dMini,Station station1,bool direction,bool marche,const Ligne &ligne);//Ajoute un tram à la liste de tram
		Tram *tram();//Renvoie la tête t
		void Next();//Transforme le tram t en tram suiv de la classe Tram

	private:
		Tram *t;

};

#endif
