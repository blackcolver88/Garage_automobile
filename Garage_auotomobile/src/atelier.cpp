#include "atelier.h"
// Constructeur par défaut
atelier::atelier() {
    capaciteMax = 0;
}

// Constructeur avec capacité maximale
atelier::atelier(int cap) {
    capaciteMax = cap;
}

// Destructeur
atelier::~atelier() {
    // Libérer la mémoire allouée aux voitures
    for (auto& v : voit) {
        delete v;
    }
    for (auto& v : voit_att) {
        delete v;
    }
    // Libérer la mémoire allouée aux employés
    for (auto& e : liste_t) {
        delete e;
    }
    // Libérer la mémoire allouée aux pièces
    for (auto& p : liste_p) {
        delete p;
    }
}
// Ajouter une voiture à l'atelier
void atelier::ajouterVoiture(voiture* v)
 {
    if (voit.size() < capaciteMax) {
        voit.push_back(v);
    }
    else {
         while(true)
{
    string s;
    cout<<"\n atelier plein voulez vous mettre votre voiture en attente: repondre par yes ou no"<<endl;
cin>>s;
if(s=="no"||s=="NO"||s=="No"||s=="nO")
    {
        break;
    }
if(s=="yes"||s=="Yes"||s=="yEs"||s=="yeS"||s=="YEs"||s=="YeS"||s=="yES"||s=="YES")
{

        voit_att.push_back(v);
        break;
    }
}
    }}
    voiture* atelier::rechercher_v(int code_v) {
    for (auto& v : voit) {
        if (v->getMatricule() == code_v) {
            return v;
        }
        for (auto& v : voit_att) {
        if (v->getMatricule() == code_v) {
            return v;
        }

    }
    return nullptr;
}
    }
    // Supprimer une voiture de l'atelier
void atelier::supprimerVoiture(voiture* v)
{
    if(rechercher_v(v->getMatricule())!=nullptr)
    {
    // Supprimer la voiture des listes voit et voit_att
    voit.erase(std::remove(voit.begin(), voit.end(), v), voit.end());
    voit_att.erase(std::remove(voit_att.begin(), voit_att.end(), v), voit_att.end());
    // Libérer la mémoire allouée à la voiture
    delete v;
    }
    else cout<<"\n cette voiture n'existe pas deja dans notre atelier"<<endl;
}



// Afficher les statistiques de l'atelier (nombre de voitures en réparation, coût total des réparations, etc.)
void atelier::afficherStatistiques() {
    int nbVoitures = voit.size();
    int nbVoituresAttente = voit_att.size();
    int nbVoituresReparation = nbVoitures + nbVoituresAttente;
    float coutTotal = 0;
    for (auto& v : voit) {
        for (auto& r : v->rep) {
            coutTotal += r.second;
        }
    }
   int nb_voiture_non_reparees = 0;
    int nb_voiture_en_cours = 0;
    int nb_voiture_reparees = 0;
    for (int i = 0; i < voit.size(); i++){
        voiture* v = voit[i];
        if (v->getIndex_rep() == 0){
            nb_voiture_non_reparees++;
        } else if (v->getIndex_rep() == 1){
            nb_voiture_en_cours++;
        } else if (v->getIndex_rep() == 2){
            nb_voiture_reparees++;
        }
    }
    float cout_total_reparations=0;
     for (auto v : voit)
     {
         if (v->getIndex_rep() == 2)
            cout_total_reparations += v->cout_reparation();
     }
    cout << "Nombre de voitures non réparées : " << nb_voiture_non_reparees << endl;
    cout << "Nombre de voitures en cours de réparation : " << nb_voiture_en_cours << endl;
    cout << "Nombre de voitures déjà réparées : " << nb_voiture_reparees << endl;
    cout << "Coût total des réparations effectuées : " << cout_total_reparations << endl;
}
bool atelier::verifierDisponibilite(employe* technicien, date debut, date fin)
 {
    // Vérifier si le technicien est disponible pour toute la période
    for (int i = 0; i < technicien->getNbV(); i++) {
        voiture v = technicien->getTabV()[i];
        if (v.getIndex_rep() == 1 && !(v.getDate_debut()>fin|| debut > v.getDate_fin_env()))
            {
            // Le technicien n'est pas disponible pour toute la période
            return false;
        }
    }
    // Le technicien est disponible pour toute la période
    return true;
}
void atelier::affecterTechnicien(employe* technicien, voiture* voiture) {
    // Vérifier la disponibilité du technicien
    if (!verifierDisponibilite(technicien, voiture->getDate_debut(), voiture->getDate_fin_env())) {
        cout << "Le technicien n'est pas disponible pour cette période." << endl;
    }

    // Trouver une place libre dans le tableau des voitures du technicien
    int index_v = -1;
    for (int i = 0; i < technicien->getNb_v_max(); i++) {
        if ((technicien->getTabV())+i == nullptr) {
            index_v = i;
            break;
        }
    }

    // Vérifier si une place libre a été trouvée
    if (index_v == -1) {
        cout << "Le technicien a atteint sa capacité maximale de voitures à réparer." << endl;
    }

    // Ajouter la voiture à la liste des voitures du technicien
    *((technicien->getTabV())+index_v) =*voiture;

    // Mettre à jour le statut de la voiture
    voiture->setIndex_rep(1);

    // Ajouter la voiture à la liste des voitures en attente de réparation
    voit_att.push_back(voiture);
}
void atelier::marquerReptermine(int matricule) {
    for (int i = 0; i < voit.size(); i++) {
        if (voit[i]->getMatricule() == matricule) {
            // Trouver l'employee responsable de la voiture
            employe* technicien = nullptr;
            for (int j = 0; j < liste_t.size(); j++) {
                for (int k = 0; k < liste_t[j]->getNbV(); k++) {
                    if ((liste_t[j]->getTabV())[k] == *voit[i]) {
                        technicien = liste_t[j];
                        // Enlever la voiture du tableau du technicien
                        liste_t[j]->setTab_v(k, nullptr);
                        break;
                    }
                }
                if (technicien != nullptr) {
                    break;
                }
            }
            // Mettre à jour les dates de fin de la voiture
            voit[i]->setDate_fin_reelle(date());
            voit[i]->setIndex_rep(2);
            // Enlever la voiture de la liste des voitures à réparer
            voit.erase(voit.begin() + i);

        }
    }
}
static float atelier::getPrix(string s)
{
    return(rep[s]);
}
float verifierDisponibilite(string Rep)
{
    auto it=rep.find(Rep);
    if(it!=rep.end()) return(rep[Rep]);
    return(-1);
}
atelier::atelier(const atelier& a)
{
   capaciteMax=a.capaciteMax;
    v = new voiture[capaciteMax];
    for (int i = 0; i < capaciteMax; i++) {
        v[i] = other.v[i];
    }
    for (auto& voi : other.voit) {
        voit.push_back(new Piece(*voi));
    }
    for (auto& voi_t : other.voit_att) {
        voit_att.push_back(new Piece(*voi_t));
    }
    for (auto& e : other.liste_t) {
        liste_t.push_back(new Piece(*e));
    }
    for (auto& p : other.liste_p) {
        liste_p.push_back(new Piece(*p));
    }
    for (auto& entry : other.rep) {
        rep[entry.first] = new float(*entry.second);
    }
}
