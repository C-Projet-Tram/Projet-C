#include <iostream>
#include <ctime>
#include "tram.h"
#include "station.h"
#include "listeStations.h"
#include "listeTrams.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
	long tempsDepart=time(0),tempsActuel=tempsDepart,tempsIteration=tempsDepart,deltaT;
	int duree;
	cout<<"Indiquez une durée (en seconde):"<<endl;
	cin>>duree;
	duree*=1000;
	while(tempsActuel-tempsDepart<duree)
	{
			tempsIteration=tempsActuel;
			tempsActuel=time(0);
			deltaT=tempsActuel-tempsIteration;
			
			
	}
}
