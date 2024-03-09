#include "magazin.h"

magasin::magazin() : nb_emp(0), nb_cl(0) {}

    magazin:: ~magazin() {
        for (auto& emp : liste_emp) {
            delete emp;
        }
        for (auto& pc : nb_pc) {
            delete pc.first;
        }
    }
     void magazin:: ajouterEmploye(employe* emp) {
        liste_emp.push_back(emp);
        nb_emp++;
    }
    void  magazin::ajouterPiece(Piece* pc) {
        if (nb_pc.find(pc) != nb_pc.end()) {
            nb_pc[pc]++;
        } else {
            nb_pc[pc] = 1;
        }
    }
 bool magazin:: verifierDisponibilite(int Reference)
 {
     for (auto& x:nb_pc)
     {
         return(x.first.Reference==Reference);
     }
     return nullptr;
 }
 void magazin::supprimerEmploye(employe* emp)
 {
 int index = -1;
    for (int i = 0; i < liste_emp.size(); i++) {
        if (liste_emp[i] == emp) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        liste_emp.erase(liste_emp.begin() + index);
        nb_emp--;
        cout << "Employe supprime avec succes !" << endl;
    }
    else {
        cout << "L'employe n'est pas present dans la liste !" << endl;
    }
}
Piece* Magazin::verifierDisponibilite(int Reference, int nb) {
    Piece* piece_disponible = nullptr;
    bool piece_trouvee = false;
    // Recherche de la pièce avec la référence donnée
    for (const auto& it : nb_pc) {
        if (it.first->getReference() == Reference) {
            // Si la pièce est trouvée, vérifier si elle est disponible en quantité suffisante
            if (it.second >= nb) {
                // Si oui, récupérer l'adresse de la pièce trouvée
                piece_disponible = it.first;
                piece_trouvee = true;
                break;
            } else {
                // Si la quantité demandée est supérieure à la quantité disponible, sortir de la boucle
                break;
            }
        }
    }

    // Si la pièce est trouvée, décrémenter le nombre de pièces disponibles dans le magasin
    if (piece_trouvee && piece_disponible != nullptr)
        {
        nb_pc[piece_disponible] -= nb;
    }

    // Retourner un pointeur vers la pièce disponible (ou nullptr si elle n'est pas disponible)
    return piece_disponible;
}
void fournirPiece(int a,int b)
{
    int m;
    while(true)
    {
        cout<<"\n il ya une necessite de "<<b<<" pieces de reference "<<a<<" a fournir "<<" donner un nombre qui ui est plus grand pour remplir votre atelier"<<endl;
        cin>>m;
        if(m>=b) break;
    }
     piece p=getPiece (a);
    for(int i=0;i<b;i++)
        ajouterPiece(p);
}
magazin(const magazin& m){
    nb_emp=m.nb_emp
    nb_cl=m.nb_cl
    for (int i = 0; i < m.liste_emp.size(); i++) {
    employe* copieEmp = new employe(*m.liste_emp[i]);
    liste_emp.push_back(copieEmp);
    }
   }
