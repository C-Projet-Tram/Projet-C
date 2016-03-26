#include <iostream>
#include <ctime>
#include "tram.h"
#include "station.h"
#include "listeStations.h"
#include "listeTrams.h"

using namespace std;

#include "tinyxml.h"
#include "listeTrams.h"

using namespace std;
//Définition des variables
ListeTrams ldt;

void loadTramList()
{
	//Ouverture du fichier
	TiXmlDocument doc("SavedData.xml");
	//Si erreur lors de l'ouverture du document
	if(!doc.LoadFile())
	{
	    cout << "loading error" << endl;
	    cout << "error #" << doc.ErrorId() << " : " << doc.ErrorDesc() << endl;
	}
	
	//On pointe sur la liste des trams
	TiXmlHandle hdl(&doc);
	TiXmlElement *elem = hdl.FirstChildElement().FirstChildElement().Element();
	
	//Création des trams grâce aux données XML
	if(!elem){
		cout << "root doesn't exist'" << endl;
	}
	
	while (elem){
		
		//Assignation des données XML à des variables
		int num;
		bool direction;
		bool marche;
		
		elem->QueryIntAttribute("num", &num);
		elem->QueryBoolAttribute("direction", &direction);
		elem->QueryBoolAttribute("marche", &marche);
					
		
		//Ajout à la liste chainée de trams
		ldt.ajouter(num,direction,marche);

		//Iteration 
		elem = elem->NextSiblingElement(); 
	}
	
}

void showTramList()
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
	//A FAIRE
}

int main()
{
	int choice=0;
	
	
	while(choice != 2)
	{
		cout << "----------------------------" << endl;
		cout << "\t Menu" << endl;
		cout << " Please make your choice : " << endl;
		cout << "\t1 - Load Tram list" << endl;
		cout << "\t2 - Quit" << endl;
		cout << "----------------------------" << endl;
		
		cout << "Choice : "; cin >> choice;
		
		switch(choice)
		{
		
			case 1:
				loadTramList();
				showTramList();
				system("pause");
				system("cls");
			break;
			
		}
	}
}
