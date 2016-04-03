#include "listeTrams.h"

ListeTrams::ListeTrams():t(0)
{}

ListeTrams::ListeTrams(const ListeTrams &lt):t(lt.t)
{}

ListeTrams::~ListeTrams()
{
	while(t) // t != 0
	{
		Tram *tmp=t->suiv;
		delete t;
		t = tmp;
	}
}

//M�thode qui retourne la taille de la liste chain�e
int ListeTrams::taille() const
{
	int taille=0;
	Tram *tmp = t;
	while(tmp)
	{
		taille++;
		tmp=tmp->suiv;
	}
	return taille;
}

//M�thode qui ajoute un tram � la liste chain�e dans l'ordre croissant de son num
void ListeTrams::ajouter(int num,int vitesse,int dMini,Station station1,bool direction,bool marche,const Ligne &ligne) 
{
	//Cas cha�non vide
	if(t == 0)
	{
		t = new Tram(num,vitesse,dMini,direction,marche,ligne,station1);
		return;
	} 
	//Cas t�te
	if(num < t->d_num)
	{
		Tram *tmp = t;		
		t = new Tram(num,vitesse,dMini,direction,marche,ligne,station1);
		t->suiv = tmp;
		return;
	}
	//Le reste 
	Tram *t0 = 0, *t1=t;
	while(t1 != 0 && t1->d_num < num)
	{
		t0 = t1;
		t1 = t1->suiv;
	}
	
	Tram *t = new Tram(num,vitesse,dMini,direction,marche,ligne,station1);
	t0->suiv = t;
	t->suiv = t1;
}

Tram *ListeTrams::tram()
{
	return t;
}

void ListeTrams::Next()
{
	t=t->suiv;
}

