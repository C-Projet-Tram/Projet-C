#ifndef INTERFACEGRAPHIQUE_H
#define INTERFACEGRAPHIQUE_H
#include<string>
#include <vector>

void afficherLigneEtStation(const vector<Ligne> &ldl);//Affiche les lignes et les stations sur l'interface graphique
void afficherTram(const ListeTrams &ldt);//Affiche les trams sur l'interface graphique
void afficher(const vector<Ligne> &ldl, const ListeTrams &ldt, double dureeRestante);//Utilise les fonctions du dessus pour tout afficher

#endif
