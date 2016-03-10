#ifndef "classetram.h"
#define "classetram.h"

class tram {
	// Private section
	public:
		// Public Declarations c'est joli
		tram();//initialisation
		tram(bool direction,int ligne,int vitesse);//initialisation avec variables
		bool tramDevant(int ligne,bool direction);//vérifie s'il y a un tram devant, renvoie bool si vrai et int si faux kek
		~tram();//destructeur
	protected:
		// Protected Declarations
		bool d_direction;
		int d_lignedetram;
		int d_vitesse;
		int d_instance;
};



#endif

