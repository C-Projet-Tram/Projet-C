#include <iostream>
#include <ctime>
#include "tram.h"
#include "station.h"
#include "Ligne.h"
#include "listeTrams.h"
#include "tinyxml.h"
#include "graphics.h"
#include "interfacegraphique.h"
#include <windows.h>

using namespace std;

//Definition des variables
ListeTrams ldt;
vector<Ligne> ldl;

void loadData()
{
	string nomFichier;
	cout << "Nom du fichier sans l'extention (par defaut SavedData)" << endl;
	cout << "Entrez le nom : ";cin >> nomFichier;
	if(nomFichier=="")
		nomFichier = "SavedData";
	nomFichier += ".xml";
	//Ouverture du fichier
	TiXmlDocument doc("SavedData.xml");
	//Si erreur lors de l'ouverture du document
	if(!doc.LoadFile())
	{
	    cout << "loading error" << endl;
	    cout << "error #" << doc.ErrorId() << " : " << doc.ErrorDesc() << endl;
	}
	

	//On pointe sur le fichier
	TiXmlHandle hdl(&doc);
	
	//Assignation au premier noeud
	TiXmlElement* root = doc.FirstChildElement();
	//S'il ne trouve pas le noeud 
	if(root == NULL)
	{
	    cout << "Erreur du chargement du noeud principal !"<< endl;
	
	}
	
	//Parcours de tous les noeuds
	for(TiXmlElement* elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement())
	{
		//Affichage du nom du noeud a charger
    	string elemName = elem->Value();
    	
    	//Si c'est le noeud listeLignes
		if(elemName=="listeLignes")
		{
			TiXmlElement *ligne = elem->FirstChildElement();
			//S'il ne trouve pas le noeud/ou erreur
			if(!ligne){
				cout << "Erreur du chargement des lignes !" << endl;
			}
			
			//Parcours des lignes
			while (ligne){
		
				//Assignation des donnees XML a des variables
				Ligne l;

								
	    		TiXmlElement *station = ligne->FirstChildElement()->FirstChildElement();
	    		//S'il ne trouve pas le noeud/ou erreur
				if(!station){
					cout << "Erreur du chargement des stations !" << endl;
				}
				
				//Parcours des stations
				while (station)
				{
			
					//Assignation des donnees XML a des variables
					int tempsArret;
					double posX,posY;
					string nom;
					
					nom = station->Attribute("nom");
					station->QueryDoubleAttribute("posX", &posX);
					station->QueryDoubleAttribute("posY", &posY);
					station->QueryIntAttribute("tempsArret", &tempsArret);
					
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
		//Si c'est le noeud listeTrams
		else if(elemName=="listeTrams")
		{
			TiXmlElement *tram = elem->FirstChildElement();
			//S'il ne trouve pas le noeud/ou erreur
			if(!tram){
				cout << "Erreur du chargement des trams !" << endl;
			}
			//Parcours des trams
			while (tram){
		
				//Assignation des donnees XML a des variables
				int num,vitesse,distanceMini,direct,mar,ligne,numStation;	
				tram->QueryIntAttribute("num", &num);
				tram->QueryIntAttribute("vitesse", &vitesse);
				tram->QueryIntAttribute("distanceMini", &distanceMini);
				tram->QueryIntAttribute("direction", &direct);
				tram->QueryIntAttribute("marche", &mar);
				tram->QueryIntAttribute("ligne", &ligne);
				tram->QueryIntAttribute("station", &numStation);
				//Creation de la station par recopie
				Station station(ldl[ligne].getStation(numStation));

				bool direction = direct;
				bool marche = mar;

				//Ajout a la liste chainee de trams
				ldt.ajouter(num,vitesse,distanceMini,station,direction,marche,ldl[ligne]); 
				
				//Iteration 
				tram = tram->NextSiblingElement(); 
			}
		}
	}
		
}

void configSimulation(ListeTrams &ldt , const vector < Ligne > &ldl)
{
	double duree;
	cout << "Indiquez une duree (en seconde):" << endl;
	cin >> duree;
	clock_t start_t = clock(), clockActuel, clockIteration =start_t;
	opengraphsize(1000,600);
	ListeTrams tmp;
	double dureeRestante = duree - ((clock() - start_t) / (double) CLOCKS_PER_SEC);
	while( (clock() - start_t) / (double) CLOCKS_PER_SEC < duree )
	{
		clockActuel = clock();
		clock_t deltaClock = clockActuel-clockIteration;
		clockIteration = clockActuel;
		tmp = ldt;
		while(tmp.tram())
		{
			//changer la distance des trams et vérifier s'il y a quelqu'un devant
			tmp.tram()->verifToutTram(tmp.tram());
			tmp.tram()->tramAvance(deltaClock / (double) CLOCKS_PER_SEC);
			tmp.Next();
		}
		afficher(ldl, ldt, dureeRestante);
		Sleep(1000);
		dureeRestante = duree - ((clock() - start_t) / (double) CLOCKS_PER_SEC);
	}
}

int main()
{
	int choice=0;
	
	loadData();
	
	
	//Choix utilisateur
	while(choice != 2)
	{
		system("cls");
		cout << "----------------------------" << endl;
		cout << "\t Menu" << endl;
		cout << " Faites votre choix : " << endl;
		cout << "\t1 - Lancer la simulation" << endl;
		cout << "\t2 - Quitter" << endl;
		cout << "----------------------------" << endl;
		
		cout << "Choice : "; cin >> choice;
		
		if(choice==1)
		{

				configSimulation(ldt,ldl);
				getch();
				closegraph();
				
				system("pause");
				system("cls");
		}
	}
	return 0;
}
