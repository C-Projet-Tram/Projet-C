#ifndef LISTETRAMS_H
#define LISTETRAMS_H
#include "tram.h"

class ListeTrams
{
	public:
		ListeTrams();
		ListeTrams(const ListeTrams &lt);
		~ListeTrams();
		int taille() const;
		void ajouter(int num,int vitesse,int dMini,Station station1,bool direction,bool marche,const Ligne &ligne);
		Tram *tram();
		void Next();

	private:
		Tram *t;

};

#endif
