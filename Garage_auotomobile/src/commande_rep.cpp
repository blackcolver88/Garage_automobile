#include "commande_rep.h"
#include "atelier.h"
commande_rep::commande_rep() : Cout(0) {}
commande_rep::~commande_rep()
{
    for (auto it = pieces->begin(); it != pieces->end(); it++)
    {
        delete it->first;
    }
    for (auto it = rep->begin(); it != rep->end(); it++)
    {
        delete it->first;
    }
    for (auto x : vt)
    {
        delete x;
    }
    vt.clear();
    delete rep;
    delete pieces;
}

void commande_rep::afficher()
{
    cout << "\n commande reparation de cout :" << Cout << endl;
    int i = 0;
    for (auto& x : v)
    {
        cout << "\n ***pour la voiture de matricule: " << x.first << ":" << endl;
        cout << "\n affichages des reparations et de leurs commissions" << endl;
        for (auto it = rep[i].begin(); it != rep[i].end(); it++)
        {
            cout << " - " << *(it->first) << " :" << it->second << " dinars de commission" << endl;
        }
        cout << "\n affichage des pieces commandées avec leur quantite et leur prix unitaire" << endl;
        for (auto it = pieces[i].begin(); it != pieces[i].end(); it++)
        {
            cout << " \n - piece " << *(it->first) << " : " << it->second.first << " x " << it->second.second << " dinars" << endl;
        }
        cout << "\n affichage des dates de début et de fin de la reparation de la voiture :" << endl;
        cout << " \t   reparation du ";
        x.second.first.afficher();
        cout << " au ";
        x.second.second.afficher();
        i++;
    }
}

void commande_rep::ajouter_rep(int a, string s)
{
    int i = -1;
    for (int j = 0;j<vt.size(); j++) {
        if (vt[j]->getMatricule() == a) {
            i = j;
            break;
        }
    }
    if (i == -1) {
        if (verifierDisponibilite(a, s) == 2) {
            voiture* p =atel->rechercher_v(a);
            vt.push_back(p);
            i = vt.size() - 1;
        }
        else {
            return;
        }
    }
    float p = atelier::getPrix(s);
    rep[i].insert(std::make_pair(new string(s), p));
}

void commande_rep::ajouter_v(voiture p)
{
    vt.push_back(new voiture(p));
    v.insert(std::make_pair(p.getMatricule(), std::make_pair(p.getDate_debut(), p.getDate_fin_reelle())));
}

int commande_rep::verifierDisponibilite(int a, string r)
{
    for (int i = 0; i<vt.size(); i++)
    {
        if (vt[i]->getMatricule() == a)
        {
            for (auto &x : rep[i])
            {
                if (*(x.first) == r) {
                    return 0;
                }
            }
            return 1;
        }
    }
    return 2;
}

void supprimer_rep(string nom_rep, int index) {
    bool found = false;
    map<string*, map<int, float>> reparations;
    auto it1 = reparations.begin();
    while (it1 != reparations.end() && !found) {
        auto& reparations = it1->second;
        if (*(it1->first) == nom_rep) {
            found = true;
            auto it2 = reparations.find(index);
            if (it2 != reparations.end()) {
                reparations.erase(it2);
                cout << "\n Reparation supprimee avec succes" << endl;
            }
        }
        ++it1;
    }
    if (!found) {
        cout << "\n Le nom du repertoire n'existe pas" << endl;
    }
}
