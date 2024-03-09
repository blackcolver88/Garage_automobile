#ifndef ATELIER_H
#define ATELIER_H
#include"employe.h"
#include"piece.h"
#include"voiture.h"
class atelier
{
 private:
   int capaciteMax;
   voiture* v;
   static vector<voiture*> voit;
   static  vector<voiture*> voit_att;
   static vector<employe*>liste_t;
   static vector<Piece*>liste_p;
   static map<string,float>rep;
public:
    atelier();


~atelier();
}
void ajouterVoiture(voiture*);
void supprimerVoiture(voiture*);
voiture* rechercher_v(int code_v);
void afficherStatistiques();
static float verifierDisponibilite(string);
bool verifierDisponibilite(employe* technicien, date debut, date fin);
void affecterTechnicien(employe* technicien, voiture* voiture);
void marquerReptermine(int matricule);
float getPrix(string);

};

#endif // ATELIER_H
