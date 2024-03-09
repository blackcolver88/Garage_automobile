#ifndef VOITURE_H
#define VOITURE_H
#include"date .h"
#include"piece.h"
#include"atelier.h"
using namespace std;
class voiture
{
    int matricule;
    string marque;
    string modele;
    int anneeFabrication;
    map<string*,float> rep;
    map<Piece*,int> p_detach;
    date date_debut;
    date date_fin_env;
    date date_fin_reelle;
    int index_rep;//0 si la reparation n'est pas encore commencee
                  // 1 si la reparation est en cours
                  // 2 si la reparation est accomplie
    public:
         friend class atelier;
        voiture();
        voiture(const voiture&);
        virtual ~voiture();
        int getMatricule(){return(matricule);};
   void afficher();
   void ajouter_rep(string*,float);
  void renouveler_date(date d){date_fin_env=d;};// au cas de probleme de reparation retarder la date envisagee
  void setIndex_rep(int a){index_rep=a;};
  int getIndex_rep(){return index_rep;};
  void commander_piece(int a,int b );
 string getMarque(){return(marque);};
 void setDate_debut(date d){date_debut=d;};
 date getDate_fin_env(){return(date_fin_env);};
 date getDate_debut(){return(date_debut);};
 float cout_reparation();
void setDate_fin_reelle(date d){date_fin_reelle=d;};
friend void ajouter_v(voiture p);
map<string*,float> getRep(){return(rep);};
bool operator==(const voiture& other) const{return(matricule==other.matricule);};
};
#endif // VOITURE_H
