#include "facture.h"
#include "date .h"
facture::facture()
{
    paiement = true ;
    total=0;
    penalite=0;
}
facture::facture(const facture& f)
{
    paiement=f.paiement;
    total=f.total;
    date_pay=f.date_pay;
    date_lim=f.date_lim;
    penalite=f.penalite;
    for (auto it = f.pc.begin(); it != f.pc.end(); it++)
      {
        piece* t = new piece(it);
      }
    for (auto it = f.rp.begin(); it != f.rp.end(); it++)
      {
        piece* r = new string(it);
      }
}
facture::~facture()
{
    //dtor
}
void facture::afficher()
{
    cout<<"Voici l'etat de paiement : "<< endl;
    cout<< paiement << endl;
    cout<<"Voici le total : "<< endl;
    cout<< total<< endl;
    cout<<"Voici la date de paiement : "<< endl;
    date_pay.afficher();
    cout<<"Voici la date limite de paiement : "<< endl;
    date_lim.afficher();
    cout<<"Voici la penalite : "<< endl;
    cout<< penalite << endl;
}
void calculCout()
{
    Cout=commande_achat::getCout() + commande_rep::getcout() ;
}
int depassement()
{
    int n=date_pay.nb_jour();
    int m=date_lim.nb_jour();
    if (date_pay<date_lim)
    {
        cout<<"il n'ya pas de depassement"<<endl;
    }
    else
    {
      return(n-m);
    }
}
bool est_achat() const {
    return commande_achat::getTotal() > 0 && commande_rep::getTotal() == 0;
}

bool est_rep() const {
    return commande_achat::getTotal() == 0 && commande_rep::getTotal() > 0;
}
