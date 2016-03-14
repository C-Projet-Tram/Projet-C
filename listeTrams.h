#ifndef LISTETRAMS_H
#define LISTETRAMS_H
#include "tram.h"
class ListeTrams
{
	public:
		ListeTrams();
	private:
		Tram d_tram;
		ListeTrams *d_suivant;
};

#endif
