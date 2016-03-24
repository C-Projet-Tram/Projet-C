#include "listeTrams.h"
ListeTrams::ListeTrams():t(0)
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

//Méthode qui retourne la taille de la liste chainée
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

void ListeTrams::ajouter(int num,bool direction,bool marche) 
{
	//Cas chaînon vide
	if(t == 0)
	{
		t= new Tram(num,direction,marche);
		return;
	}
	//Cas tête
	if(num < t->d_num)
	{
		Tram *tmp = t;		
		t = new Tram(num,direction,marche);
		t->suiv = tmp;
		return;
	}
	//Le reste 
	Tram *t0 = 0, *t1=t;
	while(t1!=0 && t1->d_num < num)
	{
		t0=c1;
		t1=t1->suiv;
	}
	
	Tram *t = new Tram(num,direction,marche);
	t0->suiv = t;
	t->suiv = t1;
}

/* OLD
void ListeTrams::ajoutTram(Tram T)
{
	ListeTrams *tmp=this;//T'es sûr pour le this ?
	while(tmp->d_suivant!=0)
		tmp=tmp->d_suivant;
	tmp->d_suivant->d_tram=T;
}
*/
/*Pas necessaire pour le moment
void ListeTrams::enleverTram(Tram T)
{
	ListeTrams *tmp2=this->d_suivant,*tmp=this;
	if (tmp->d_tram==T)
		delete this;
	else return;
	while((tmp2->d_tram!=T) && (tmp2->d_suivant!=0))
	{
		tmp=tmp->d_suivant;
		tmp2=tmp->d_suivant;
	}
	if (tmp2->d_tram==T)
	{
		tmp->d_suivant=tmp2->d_suivant;
		delete tmp2;
	}
	nbDeTrams--;//Ni là
}

ListeTrams ListeTrams::operator+=(Tram T)
{
	ajoutTram(T);
	return *this;
}

ListeTrams ListeTrams::operator+=(ListeTrams L)
{
	ListeTrams *tmp=this;
	ajoutTram(tmp->d_tram);
	while(tmp->d_suivant!=0)
	{
		tmp=tmp->d_suivant;
		ajoutTram(tmp->d_tram);
	}
}*/
