#include "garage_auto.h"

garage_auto::garage_auto()
{
    nb_emp=0;
    ent=new employe;
    nb_cl=0;
    map<client*,facture*> cl_fact;
    atelier At;
    magasin mg;
    map<int,float> taxe;
    map<pair<double,double>,float> solde;
}
garage_auto::~garage_auto()
{
    for (auto& ep : employe) {
            delete employe;
        }
}
void ajouterEmployee(employee* ep)
{
    employe em;
    em.saisir;
    employee[nb_emp]=em;
    nb_emp++ ;
}
void supprimerMembre(employe* em, int& nb_emb, int index) {

    if (index < 0 || index >= nb_emb) {
        cout << "Index invalide." <<endl;
        return;
    }
    delete em[index];
    for (int i = index; i < taille - 1; i++) {
        em[i] = em[i + 1];
    }
    nb_emb--;
}
void ajouterclient(client cl)
{
     if (cl_fact.find(cl) != cl_fact.end()) {
            cl_fact[cl]++;
        } else {
            cl_fact[cl] = 1;
        }
}

