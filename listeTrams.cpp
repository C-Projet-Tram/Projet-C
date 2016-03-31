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

//Méthode qui ajoute un tram à la liste chainée dans l'ordre croissant de son num
void ListeTrams::ajouter(int num,int vitesse,int dMini,Station S1,bool direction,bool marche,const Ligne &L) 
{
	//Cas chaînon vide
	if(t == 0)
	{
		t= new Tram(num,vitesse,dMini,direction,marche,L,S1);
		return;
	} 
	//Cas tête
	if(num < t->d_num)
	{
		Tram *tmp = t;		
		t = new Tram(num,vitesse,dMini,direction,marche,L,S1);
		t->suiv = tmp;
		return;
	}
	//Le reste 
	Tram *t0 = 0, *t1=t;
	while(t1!=0 && t1->d_num < num)
	{
		t0=t1;
		t1=t1->suiv;
	}
	
	Tram *t = new Tram(num,vitesse,dMini,direction,marche,L,S1);
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

/* OLD
Tram *ListeTrams::operator=(const Tram *T)
{
	*this=T;
}

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
