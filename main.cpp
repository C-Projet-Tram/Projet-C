#include <iostream>
#include <ctime>
#include "tram.h"
#include "station.h"
#include "listeStations.h"
#include "listeTrams.h"
#include "tinyxml.h"
#include "graphics.h"

using namespace std;

//Definition des variables
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
	
	TiXmlElement* root = doc.FirstChildElement();
	if(root == NULL)
	{
	    cout << "Failed to load file: No root element."<< endl;
	
	}
	
	//Parcours de toutes le listes
	for(TiXmlElement* elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement())
	{
		//Affichage du nom de la liste a charger
    	string elemName = elem->Value();
    	cout << "Element a charger : " << elemName << endl;
    	
    	if(elemName=="listeStations")
    	{
    		TiXmlElement *station = elem->FirstChildElement();
			if(!station){
				cout << "Erreur, pas de station !" << endl;
			}
			
			while (station)
			{
		
				//Assignation des donnees XML a des variables
				int num;
				
				station->QueryIntAttribute("num", &num);
				
				cout << "Station numero " << num << endl;
		
				//Iteration 
				station = station->NextSiblingElement(); 
			}
		}
		else if(elemName=="listeTrams")
		{
			TiXmlElement *tram = elem->FirstChildElement();
			if(!tram){
				cout << "Erreur, pas de tram !" << endl;
			}
			
			while (tram){
		
				//Assignation des donnees XML a des variables
				int num;
				
				tram->QueryIntAttribute("num", &num);
				
				cout << "Tram numero " << num << endl;
		
				//Iteration 
				tram = tram->NextSiblingElement(); 
			}
		}
	}
		
	/*
	
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
	*/

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
	double duree;
	cout<<"Indiquez une duree (en seconde):"<<endl;
	cin>>duree;
	long tempsDepart=clock(),tempsActuel=tempsDepart,tempsIteration=tempsDepart;
	double deltaT;
	affichageSimulation();//Juste pour test
	while(tempsDepart-tempsIteration<duree)
	{
			tempsIteration=tempsActuel;
			tempsActuel=clock();
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
				loadData();
				cout << ldt.taille();
				configSimulation();
								
				system("pause");
				system("cls");
			break;
			
		}
	}
}
