#ifndef COMMANDE_REP_H
#define COMMANDE_REP_H
#include "voiture.h"
#include"magasin.h"
class commande_rep
{
    float Cout;
    atelier* atel;
    map<string*,float>* rep ;
    vector<voiture*> vt;
    map<int*,pair<int,float>> *pieces;
    map<int,pair<date,date>> v ;

    public:
         commande_rep();
        virtual ~commande_rep();
        commande_achat(const commande_rep& );
        void afficher();
        void ajouter_rep(int,string) ;
        void supprimer_rep(int,string);
        void ajouter_piece(int,int,int);
        void supprimer_piece(int);
        void ajouter_v(voiture);
        void supprimer_v(int);
        int verifierDisponibilite(int ,string );
        int verifierDisponibilite(int matricule,int Reference);
        float getcout(){return(Cout);};
};

#endif // COMMANDE_REP_H
