#ifndef GARAGE_AUTO_H
#define GARAGE_AUTO_H
#include "magazin.h"
class garage_auto
{
    int nb_emp;
    employe* ent;
    int nb_cl;
    map<client*,facture*> cl_fact;
    atelier At;
    magasin mg;
    map<int,float> taxe;
    map<pair<double,double>,float> solde;
    public:
        garage_auto();
        virtual ~garage_auto();
        void ajouterEmployee(employee);
        void supprimerEmpl(employe*,int&,int);
        void ajouterclient(client);
        void supprimerClient(int);
        void ajouterfinalite(int,float);
        void ajoutersolde(pair<double,double>,float);
        ostream
        istream

};

#endif // GARAGE_AUTO_H
