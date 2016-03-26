#include <iostream>
#include <ctime>
#include "tram.h"
#include "station.h"
#include "listeStations.h"
#include "listeTrams.h"
#include "tinyxml.h"
#include "graphics.h"

using namespace std;

//D�finition des variables
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
	
	//Cr�ation des trams gr�ce aux donn�es XML
	if(!elem){
		cout << "root doesn't exist'" << endl;
	}
	
	while (elem){
		
		//Assignation des donn�es XML � des variables
		int num,dData,mData;
		bool direction;
		bool marche;
		
		elem->QueryIntAttribute("num", &num);
		elem->QueryIntAttribute("direction", &dData);
		elem->QueryIntAttribute("marche", &mData);
		
		//Conversion des valeurs int en boolean			
		direction = dData;
		marche = mData;
		
		//Ajout � la liste chain�e de trams
		ldt.ajouter(num,direction,marche);

		//Iteration 
		elem = elem->NextSiblingElement(); 
	}

}

void affichageSimulation()
{
	//A REMPLIR
	int x=800,y=500,dir=0,lon=1,coul=RED;
	
	opengraphsize(1650,1000);
	setcolor(coul);

	//moveto(x,y);
	//lineto(x,y);
	
	getch();
	closegraph();	
}

void configSimulation()
{
	long tempsDepart=time(0),tempsActuel=tempsDepart,tempsIteration=tempsDepart,deltaT;
	int duree;
	cout<<"Indiquez une dur�e (en seconde):"<<endl;
	cin>>duree;
	duree*=1000;
	affichageSimulation();//Juste pour test
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
		cout << " Faites votre choix : " << endl;
		cout << "\t1 - Lancer la simulation" << endl;
		cout << "\t2 - Quitter" << endl;
		cout << "----------------------------" << endl;
		
		cout << "Choice : "; cin >> choice;
		
		switch(choice)
		{
		
			case 1:
				loadTramList();
				configSimulation();
								
				system("pause");
				system("cls");
			break;
			
		}
	}
}
