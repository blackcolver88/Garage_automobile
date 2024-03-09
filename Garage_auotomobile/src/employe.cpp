#include "employe.h"
employe::employe()
{
    nmbre_d_v_max=0;
    nmbre_de_v=0;
    tab_v=new voiture;
    salaire=0;
    secteur=true;
}
 employe::employe(string s,string m,int c,float f)
 {
     this->setNom(s);
     this->setPrenom(m);
     this->setCIN(c);
     salaire=f;
 }
 employe::~employe()
{
    delete[] tab_v;
}

employe::employe(bool sec,date d,string a="",string b="",int c=0,int nvm=0,int nv=0,float s=0):personne(a ,b,c,d)
{
    nmbre_d_v_max=nvm;
    nmbre_de_v=nv;
    tab_v=new(voiture);
    salaire=s;
    secteur=sec;
}
void employe ::sector_reveal(employe e)
{
   if(e.getSecteur()==1)
    cout<<"l'employe travaille dans la magasin"<<endl;
   else
    cout<<"l'employe travaille dans l'atelier"<<endl;
}
void employe::saisir()
{
  personne::saisir();
  cout<<"donner le nombre de voiture maximale d'employe"<<endl;
  cin>>nmbre_d_v_max;
  cout<<"donner le nombre des voitures associé à l'employe"<<endl;
  cin>>nmbre_de_v;
  cout<<"donner le salaire d'employe"<<endl;
  cin>>salaire;
  cout<<"donner le secteur d'employe : 1 s'il travaille dans la magazin ou 0 s'il travaille dans l'atelier"<<endl;
  cin>>secteur;
}
void employe:: afficher()
{
    cout << "Nom: " << nom << endl;
    cout << "Prenom: " << prenom << endl;
    cout << "CIN: " << CIN << endl;
    cout << " nb Numero de telephone: " << numero_telephone.size() << endl;
      cout << "les  Numero de telephone : " << endl;
    for(auto it=numero_telephone.begin();it!=numero_telephone.end();it++)
      cout<<*it<<endl;
    cout << "Date de naissance: " ;
    date_de_naissance.afficher();
     cout<< endl;
    cout << "Salaire: " << salaire << endl;
    cout << "Secteur: " << secteur << endl;
  cout<<"le nombre de voiture maximale d'employe est: "<<nmbre_d_v_max<<endl;
  cout<<"donner le nombre des voitures associé à l'employe est: "<<nmbre_de_v<<endl;
    cout << "Voitures: " << endl;
    for (int i = 0; i < nmbre_de_v; i++) {
        tab_v[i].afficher();
    }
}
employe::employe(const employe& other): nmbre_d_v_max(other.nmbre_d_v_max), nmbre_de_v(other.nmbre_de_v),salaire(other.salaire),
      secteur(other.secteur)
{
    tab_v=new voiture[other.nmbre_d_v_max];
    for (int i = 0; i < nmbre_de_v; i++) {
        tab_v[i] = other.tab_v[i];
    }
}
ostream& operator<<(ostream& os, const employe& emp) {
    os << "Nom: " << emp.nom << endl;
    os << "Prénom: " << emp.prenom << endl;
    os << "Nombre de voitures max: " << emp.nmbre_d_v_max << endl;
    os << "Nombre de voitures actuel: " << emp.nmbre_de_v << endl;
    os << "Salaire: " << emp.salaire << endl;
    os << "Secteur: " << (emp.secteur ? "atelier" : "magasin") << endl;

    return os;
}

istream& operator>>(istream& is, employe& emp) {
    cout << "Nom: ";
    is >> emp.nom;
    cout << "Prenom: ";
    is >> emp.prenom;
    cout << "Nombre de voitures max: ";
    is >> emp.nmbre_d_v_max;
    cout << "Salaire: ";
    is >> emp.salaire;
    int secteur;
    cout << "Secteur (0 pour magasin, 1 pour atelier): ";
    is >> secteur;
    emp.tab_v = new voiture[emp.nmbre_d_v_max];

    return is;
}
istream& operator>>(istream& is, employe* e) {
    is >> static_cast<personne*>(e);
    is >> e->nmbre_d_v_max >> e->nmbre_de_v;
    e->tab_v = new voiture[e->nmbre_de_v];
    for (int i = 0; i < e->nmbre_de_v; i++) {
        is >> e->tab_v[i];
    }
    is >> e->salaire >> e->secteur;
    return is;
}
ostream& operator<<(ostream& os, const employe* e) {
    os << static_cast<const personne*>(e);
    os << e->nmbre_d_v_max << " " << e->nmbre_de_v << endl;
    for (int i = 0; i < e->nmbre_de_v; i++) {
        os << e->tab_v[i] << endl;
    }
    os << e->salaire << " " << e->secteur << endl;
    return os;
}
void employe::creerFichierEmploye(fstream& f) {
    f.open("employe.txt", ios::in | ios::out | ios::trunc);
    if (!f.is_open()) {
        cout << "Erreur lors de l'ouverture du fichier." << endl;
        exit(1);
    }
    f.close();
}
void employe::viderFichierEmploye(fstream& f) {
    f.close();
    f.open("employe.txt", ios::out | ios::trunc);
    if (!f.is_open()) {
        cout << "Erreur lors de l'ouverture du fichier." << endl;
        exit(1);
    }
    f.close();
}



#endif // EMPLOYE_H

}
