#ifndef PERSONNE_H
#define PERSONNE_H
#include "date .h"
using namespace std;
class personne
{
    string nom;
    string prenom;
    int CIN;
    list<int*> numero_telephone;
    date date_de_naissance;
    public:
        personne();
        personne(string,string,int,int,date);
        personne(const personne&);
        virtual void saisir();
        virtual void afficher();
        virtual void modifier(personne)=0;
        virtual ~personne();
        int getCIN(){return CIN;};
        friend ostream& operator<<(ostream&,personne&);
        friend istream& operator>>(istream&,personne&);
};

#endif // PERSONNE_H
