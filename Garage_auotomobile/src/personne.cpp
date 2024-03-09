#include "personne.h"
personne::personne()
{
 nom=' ';
 prenom=' ';
 CIN=0;
 numero_telephone=0;
 date_de_naissance=date();
}
personne::personne(const &p)
{
    nom=p.nom;
    prenom=p.prenom;
    CIN=p.CIN;
     for (auto it = p.numero_telephone.begin(); it != p.numero_telephone.end(); it++)
      {
        int* n = new int(it);
      }
    date_de_naissance=p.date_de_naissance;
}

personne::personne(string nm,string pr,int c,int nt,date d)
{
  nom=nm;
  prenom=pr;
  CIN=c;
  numero_telephone=nt;
  date_de_naissance=d;
}
void saisir()
{
    cout<<"donner le nom"<<endl;
    cin>>nom;
    cout<<"donner le prenom"<<endl;
    cin>>prenom;
    cout<<"donner le CIN"<<endl;
    cin>>CIN;
    cout<<"donner le numero de telephone"<<endl;
    cin>>numero_telephone;
    cout<<"donner la date de naissance "<<endl;
    date_de_naissance.saisir();
}
void afficher()
{
    cout<<"le nom est: "<<nom<<endl;
    cout<<"le prenom est: "<<prenom <<endl;
    cout<<"le CIN est: "<<CIN <<endl;
    cout<<"le numero de telephone est: "<<numero_telephone<<endl;
    cout<<"la date de naissance est: "<<endl;
    date_de_naissance.afficher();
}
personne::~personne()
{
}
istream& operator>>(istream& in,personne& p)
{
    cout<<"donner le nom : "<<endl;
    in>>p.nom ;
    cout<<"\n donner le prenom :"<<endl;
    in>>p.personne ;
    cout<<"\n donner le nombre des sims : "<<endl;
    in>>p.numero_telephone.size();
    cout<<"\n donner les numéros des sims : "<<endl;
    for(auto it=p.numero_telephone.begin(),it!=p.numero_telephone.end(),it++)
    {
        in>>*it ;
    }
    cout<<"\n donner la date de naissance :"<<endl;
    in>>p.date_de_naissance ;
    return in ;
}
ostream& operator<<(ostream& out,personne& p)
{
    cout<<"Voici son nom : "<<endl;
    out>>p.nom ;
    cout<<"\n voici son prenom :"<<endl;
    out>>p.personne ;
    cout<<"\n voici le nombre des sims : "<<endl;
    out>>p.numero_telephone.size();
    cout<<"\n Voici les numéros des sims : "<<endl;
    for(auto it=p.numero_telephone.begin(),it!=p.numero_telephone.end(),it++)
    {
        out>>*it ;
    }
    cout<<"\n Voici la date de naissance :"<<endl;
    out>>p.date_de_naissance ;
    return out ;
}
void personne::creerpersonne(fstream& per){
per.open("C:\\Users\\yassin\\cours\\semestre2\\programmation orienté objets\\proj\\piece.txt", ios::in | ios::out | ios::trunc);
if(!per.is_open())exit(-1);
}
ostream& operator<< (ostream& out , personne* per )
{
    out<<setw(10)<<per->nom;
    out<<setw(10)<<per->prenom<<endl;;
    out<<"numero_telephone :"<<endl;
    for(auto it=per->numero_telephone.begin();it!=per->numero_telephone.end();it++)
        out<<setw(10)<<*it;
    out<<setw(10)<<per->date_de_naissance.saisir();
    return out;
}


istream& operator>> (istream& in, personne* per)
{
    in.seekg(0);
    in>>per->nom;
    in>>per->prenom;
    for(auto it=per->numero_telephone.begin();it!=per->numero_telephone.end();it++)
        in>>*it;
    in>>per->date_de_naissance.afficher();
    return in;
}

