#include "classetram.h"

using namespace std;

tram::tram():d_direction(0),d_lignedetram(0),d_vitesse(0)
{
	d_instance++;
}

tram::tram(bool direction,int ligne,int vitesse):d_direction(direction),d_lignedetram(ligne),d_vitesse(vitesse)
{
}

bool tram::tramDevant(int ligne,bool direction)
{
	//à remplir en fonction de la liste chaînée...
	//Ok maggle
}

tram::~tram()
{
	d_intance--;
}
