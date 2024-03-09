#ifndef FACTURE_H
#define FACTURE_H
#include "commande_rep.h"
#include"commande_achat.h"
#include "date .h"
class facture : public commande_rep,public commande_achat
{
    protected:
    bool paiement;
    double total;
    list<piece*>pc;
    list<string*>rp;
    date date_pay;
    date date_lim;
    float penalite;
public:
    facture();
    virtual ~facture();
    void setPenalite(float);
    facture(const facture& f);
    commande_achat(const facture& );
    void afficher();
    bool getPaiement(){return(paiement);};
    int depassement();
    void calculCout();
    double gettotal(){return(total);};
    bool est_achat();
    bool est_rep();

};
#endif // FACTURE_H
