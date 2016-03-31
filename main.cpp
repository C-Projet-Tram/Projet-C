#include <iostream>
#include <ctime>
#include "tram.h"
#include "station.h"
#include "Ligne.h"
#include "listeTrams.h"
#include "tinyxml.h"
#include "graphics.h"

using namespace std;

//Definition des variables
ListeTrams ldt;
vector<Ligne> ldl;

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
    	
		if(elemName=="listeLignes")
		{
			TiXmlElement *ligne = elem->FirstChildElement();
			if(!ligne){
				cout << "Erreur, pas de ligne !" << endl;
			}
			
			while (ligne){
		
				//Assignation des donnees XML a des variables
				Ligne l;
				cout << "Ligne : " << endl;
				
								
	    		TiXmlElement *station = ligne->FirstChildElement()->FirstChildElement();
				if(!station){
					cout << "Erreur, pas de station !" << endl;
				}
				
				while (station)
				{
			
					//Assignation des donnees XML a des variables
					int posX,posY,tempsArret;
					string nom;
					
					nom = station->Attribute("nom");
					cout << "\tStation " << nom << ",";
					station->QueryIntAttribute("posX", &posX);
					cout << "se trouvant en (" << posX << ",";
					station->QueryIntAttribute("posY", &posY);
					cout <<  posY << ") : "<< endl;
					station->QueryIntAttribute("tempsArret", &tempsArret);
					cout << "\t\tTemps d'arret : " << tempsArret << endl;
					
					//Creation et ajout de la station
					Station s(nom,posX,posY,tempsArret);
					l.ajouter(s);
					//Iteration 
					station = station->NextSiblingElement();
				}
				
				//Ajout de la ligne à la liste de lignes
				ldl.push_back(l);
				//Iteration 
				ligne = ligne->NextSiblingElement(); 
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
				int num,vitesse,distanceMini,direct,mar,ligne,numStation;
				
				tram->QueryIntAttribute("num", &num);
				cout << "Tram numero " << num << endl;
				tram->QueryIntAttribute("vitesse", &vitesse);
				cout << "\tVitesse : " << vitesse << endl;
				tram->QueryIntAttribute("distanceMini", &distanceMini);
				cout << "\tDistance minimum : " << distanceMini << endl;
				tram->QueryIntAttribute("direction", &direct);
				cout << "\tDirection : " << direct << endl;
				tram->QueryIntAttribute("marche", &mar);
				cout << "\tMarche : " << mar << endl;
				tram->QueryIntAttribute("ligne", &ligne);
				cout << "\tLigne : " << ligne << endl;
				
				tram->QueryIntAttribute("station", &numStation);
				//Creation de la station par recopie
				Station station(ldl[ligne].getStation(numStation));
				cout << "\tStation : " << station.getNom() << endl;
				
				bool direction = direct;
				bool marche = marche;
				
				//Test
				
				
				//Ajout a la liste chainee de trams
				ldt.ajouter(num,vitesse,distanceMini,station,direction,marche,ldl[ligne]); 
				
				//Iteration 
				tram = tram->NextSiblingElement(); 
			}
		}
	}
		
}
/*
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
*/
void configSimulation(ListeTrams &ldt)
{
	ListeTrams lt;//need changer les params de base
	double duree;
	cout << "Indiquez une durée (en seconde):" << endl;
	cin >> duree;
	double clockActuel = clock() , clockIteration , deltaClock;
	while( (clockActuel/1000) < duree )
	{
		clockIteration = clockActuel;
		deltaClock = clockActuel-clockIteration;
		ListeTrams tmp = ldt;
		while(tmp.tram())
		{
			//changer la distance des trams et vérifier s'il y a quelqu'un devant
			tmp.tram()->verifToutTram(tmp.tram()->getSuivant());
			tmp.tram()->tramAvance(deltaClock);
			tmp.Next();
		}
		clockActuel = clock();
		//deltaClock=deltaClock/CLOCKS_PER_SEC;
		cout << deltaClock << endl;
	}
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
				configSimulation(ldt);
								
				system("pause");
				system("cls");
			break;
			
			case 2:
				{}
			/* Je pose ça la, désolé. 
			A la fin de la durée donné. Afficher une petite fenêtre pour demander si on veut quitter l'appli ou relancer la simu.
			Donc soit on ferme tout, soit on remontre la 1ère fenêtre ?
			*/
		}
	}
}
