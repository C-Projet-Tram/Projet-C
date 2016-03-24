#include "listeTrams.h"
ListeTrams::ListeTrams():d_suivant(0),nbDeTrams(0)
{}

void ListeTrams::ajoutTram(Tram T)
{
	ListeTrams *tmp=this;
	while(tmp->d_suivant!=0)
		tmp=tmp->d_suivant;
	tmp->d_suivant->d_tram=T;
	nbDeTrams++;
}

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
	nbDeTrams--;
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
}
