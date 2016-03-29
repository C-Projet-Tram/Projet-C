#include <iostream>
#include <ctime>
#include "tram.h"
#include "station.h"
#include "listeStations.h"
#include "listeTrams.h"
#include "tinyxml.h"
#include "graphics.h"

using namespace std;

//Définition des variables
ListeTrams ldt;

void loadData()
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
	//TiXmlElement *elem = hdl.FirstChildElement().FirstChildElement().Element();
	//TiXmlElement *station = hdl.FirstChildElement("listeStations");
	TiXmlElement *tram = hdl.FirstChildElement("listeTrams").FirstChildElement("Tram").Element();
	
	//Création des trams grâce aux données XML
	/*if(!station){
		cout << "Aucune station existante" << endl;
	}*/
	if(!tram){
		cout << "Aucun tram existant" << endl;
	}
	
	while (tram){
		
		//Assignation des données XML à des variables
		int num,dData,mData;
		bool direction;
		bool marche;
		
		tram->QueryIntAttribute("num", &num);
		tram->QueryIntAttribute("direction", &dData);
		tram->QueryIntAttribute("marche", &mData);
		
		//Conversion des valeurs int en boolean			
		direction = dData;
		marche = mData;
		
		//Ajout à la liste chainée de trams
		ldt.ajouter(num,direction,marche);

		//Iteration 
		tram = tram->NextSiblingElement(); 
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
	long tempsDepart=time(0),tempsActuel=tempsDepart,tempsIteration=tempsDepart;
	double duree,deltaT;
	cout<<"Indiquez une durée (en seconde):"<<endl;
	cin>>duree;
	affichageSimulation();//Juste pour test
	while(difftime(tempsActuel,tempsDepart)<duree)
	{
			tempsIteration=tempsActuel;
			tempsActuel=time(0);
			deltaT=difftime(tempsActuel,tempsIteration);
			
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
				loadData();
				cout << ldt.taille();
				configSimulation();
								
				system("pause");
				system("cls");
			break;
			
		}
	}
}
