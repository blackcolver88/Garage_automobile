#include "client.h"
#include "personne.h"
#include "voiture.h"

client::client()
{
    nmbre_voiture=0;
    liste_matricule=new int;
}
void saisir()
{
    personne::saisir();
    cout<<"donner le nombre des voiture du client: "<<endl;
    cin>>nmbre_voiture;
}
void afficher()
{
    personne::afficher();
    cout<<"le nombre des voiture du client est: "<<nmbre_voiture<<endl;

}

client::~client()
{
 //dctor
}
