#ifndef EMPLOYE_H
#define EMPLOYE_H
#include "personne.h"
#include "voiture.h"
class employe: public personne
{
    int nmbre_d_v_max;
    int nmbre_de_v;
    voiture* tab_v;
    float salaire;
    bool secteur;
    public:
        employe();
        employe(string,float);
        employe(const employe& other);
        employe(string s,string m,int c,float f);
       employe(bool ,date,string ,string ,int ,int  ,int  ,float );
        void sector_reveal(employe);
        void saisir();
        void afficher();
        virtual ~employe();
        void setSalaire(float);
        float getSalaire()const{return salaire;};
        bool getSecteur(){return(secteur);};
        voiture* getTabV(){return(tab_v);};
        int getNbV(){return(nmbre_de_v);};
        int getNb_v_max(){return nmbre_d_v_max;};
        void setTab_v(int k,voiture* v){*(tab_v+k)=*v;};
        bool operator==(const employe& e) const {return this->CIN == e.CIN;}
        friend ostream& operator<<(ostream& os, const employe& emp) ;
       friend  istream& operator>>(istream& is, employe& emp);
       friend istream& operator>>(istream& is, employe* e);
      friend  ostream& operator<<(ostream& os, const employe* e);
      void creerFichierEmploye(fstream& f) ;
      void viderFichierEmploye(fstream& f);
};
