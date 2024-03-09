#ifndef COMMANDE_ACHAT_H
#define COMMANDE_ACHAT_H


class commande_achat
{
    float Cout ;
    map<int*,pair<int,float>> piec;
    public:
        commande_achat();
        virtual ~commande_achat();
        void afficher() ;
        void ajouter_piece(int,int);
        void supprimer_piece(int,int);
        void calculCout();
        float getCout(){return(Cout);};
};

#endif // COMMANDE_ACHAT_H
