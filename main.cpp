#include <iostream>
#include "tinyxml.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

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
	//Tram tr; Ici ?
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
					
		
		//Assignation des données au tram
		//Tram tr; Ou là ?
		
		//Ajout à la liste chainée
		
		//Iteration 
		elem = elem->NextSiblingElement(); 
	}
	
}

void showTramList()
{
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
