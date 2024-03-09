#ifndef CLIENT_H
#define CLIENT_H
#include "voiture.h"
class client : public personne
{
    facture fact_client;
    int nmbre_voiture;
    int* liste_matricule;
    public:
        client();
        void saisir();
        void afficher();
        int getnmbr_voiture{return nmbr_voiture;};
        voiture ajoutervoiture(matricule);
        void payer();
        virtual ~client();

};

#endif // CLIENT_H
