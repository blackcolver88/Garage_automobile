#include "voiture.h"
#include"atelier.h"
voiture::voiture()
{
    cout<<"\n donner la matricule de votre voiture"<<endl;
    cin>>matricule;
    cout<<"\n donner la marque de votre voiture"<<endl;
    cin>> marque;
    cout<<"\n donner le modele de votre voiture"<<endl;
    cin>>modele;
    cout<<"\n donner l'anne de fabrication de votre voiture"<<endl;
    cin>>anneeFabrication;
    //diagnostique de voiture
    while(true)
    {
string s;
cout<<"\n cette voiture necessite t_elle une reparation?"<<endl;
cin>>s;
if(s=="no"||s=="NO"||s=="No"||s=="nO")
    {
        break;
    }
if(s=="yes"||s=="Yes"||s=="yEs"||s=="yeS"||s=="YEs"||s=="YeS"||s=="yES"||s=="YES")
{
    string t;
    cout<<"\n donner le type de cette reparation"<<endl;
    cin>>t;
    float p;
    p=atelier::verifierDisponibilite(t);
    if(p!=-1)
    {
        ajouter_rep(&t,p);
    }
    else
    {
        cout<<"\n cette reparation n'est pas disponible dans cet atelier"<<endl;
    }

}
}
while(true)
{string s;
cout<<"\n cette voiture necessite  un achat d'une piece detachee?"<<endl;
cin>>s;
if(s=="no"||s=="NO"||s=="No"||s=="nO")
    {
        break;
    }
if(s=="yes"||s=="Yes"||s=="yEs"||s=="yeS"||s=="YEs"||s=="YeS"||s=="yES"||s=="YES")
{
    int t;
    int p;
    cout<<"\n donner la referance de cette piece et le nombre necessaire "<<endl;
    cin>>t>>p;
    commander_piece(t,p);

}

}
cout<<"\n donner la date de debut de reparation de cette voiture"<<endl;
date_debut.saisir();
while(true)
{
    date d;
    cout<<"\n donner la date de fin de reparation envisagee pour cette voiture"<<endl;
    d.saisir();
    if(d>date_debut) break;
}
  index_rep=0;

}
voiture::voiture(const voiture &v) {
    num = v.num;
    matricule = v.matricule;
    marque = v.marque;
    modele = v.modele;
    anneeFabrication = v.anneeFabrication;
    date_debut = v.date_debut;
    date_fin_env = v.date_fin_env;
    date_fin_reelle = v.date_fin_reelle;
    index_rep = v.index_rep;

    // copie profonde de la map rep
    for (auto it = v.rep.begin(); it != v.rep.end(); it++) {
        string* nkey = new string(*(it->first));
        rep.insert(make_pair(nkey, it->second));
    }
    // copie profonde de la map p_detach
    for (auto it = v.p_detach.begin(); it != v.p_detach.end(); it++) {
        piece* nkey = new piece(*it->first);
        p_detach.insert(make_pair(nkey, it->second));
    }
}

voiture::~voiture()
{
    for(auto& x:rep)
    {
        delete x.first;
    }
    for(auto& x:p_detach)
    {
        delete x.first;
    }
    rep.clear();
    p_detach.clear();
}
void voiture::afficher()
{
    cout<<"\n matricule:  "<<matricule<<endl;
    cout<<"\n marque:  "<<marque<<endl;
    cout<<"\n modele:  "<<modele<<endl;
    cout<<"\n anneFabrication:  "<<anneeFabrication<<endl;
    switch(index_rep)
    {
         case 0: cout<<"\n la reparation de cette voiture n'a pas encore commencee"<<endl;break;
        case 1: cout<<"\n la reparation de cette voiture est en cours"<<endl;break;
        case 2: cout<<"\n la reparation de cette voiture est deja accomplie"<<endl;break;
    }
     cout<<"\n date_debut_reparation:  "<<endl;
     date_debut.afficher();
    if(index_rep!=2)
    {
        cout<<"\n date_fin_reparation_envisagee:  "<<endl;
        date_fin_env.afficher();
    }
    else
    {
        cout<<"\n date_fin_reparation:  "<<endl;
        date_fin_reelle.afficher();


}
 void voiture::ajouter_rep(string s,float f)
 {
     rep[&s]=f;
 }
 void voiture::commander_piece(int a,int b )
 {
     piece p;
     p=chercher(a);
   bool k;
   k=atelier::verifierDisponibilite(p,b);

   if(k==false)
   {
       k=atelier::verifierDisponibilite(p);
       if(k==false)
           cout<<"\n cette piece n'existe pas dans ce magasin"<<endl;
       else
       {
       string s;
        cout<<"\n ce nombre n'existe pas dans ce magasin\n"<<endl;
       while(true)
{
     cout<<"\n voulez vous demander le chef magasin de fournir votre piece le plus tot possible?:taper yes ou no"<<endl;
       cin>>s;
if(s=="no"||s=="NO"||s=="No"||s=="nO")
    {
        break;
    }
if(s=="yes"||s=="Yes"||s=="yEs"||s=="yeS"||s=="YEs"||s=="YeS"||s=="yES"||s=="YES")
    magasin::fournirPiece(p,b);

   }
 }
   }
    p_detach.insert(make_pair(p*,b));
      atelier::supprimerPiece(p,b);
 }
 float cout_reparation()
 {
     float c=0;
     for(auto &x:rep)
        c+=x.second;
     return c;
 }
}

