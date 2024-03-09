#ifndef MAGAZIN_H
#define MAGAZIN_H
#include"atelier.h"
class magazin
{
    int nb_emp;
    int nb_cl;
    map<piece*,int> nb_pc;
   static  vector<employe*> liste_emp;
    public:
        magasin();
        virtual ~magasin();
        magazin(const magazin& m );
        static void ajouterEmploye(employe*);
        static  void ajouterPiece(piece);
        static  void supprimerEmploye(employe);
        static void supprimerPiece(piece);
        bool verifierDisponibilite(int Reference,int);
        static piece getPiece (int);
        friend class atelier;
        piece* verifierDisponibilites(int Reference, int nb);
        void fournirPiece(int,int);


};

#endif // MAGAZIN_H
