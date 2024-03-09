#ifndef DATE_H
#define DATE_H
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class date
{
    protected :
    int jour;
    int mois;
    int annee;
    public:
        date ();
        date(int,int,int);
        void afficher();
        void saisir();
        int getAnnee(){return(annee);};
        int getMois(){return(mois);};
        int getJour(){return(jour);};
        template<typename a>
        bool operator> <>( const date<a>&) const;
        int nb_jour();

date::date()
{
    jour=0;
    mois=0;
    annee=0;
}
date::date(int j,int m,int a)
{
    jour=j;
    mois=m;
    annee=a;
}
void date::saisir()
{
    cout<<" \n donner l'annee"<<endl;
    cin>>annee;
    while(true)
    {
    cout<<" \n donner le mois"<<endl;
    cin>>mois;
    if(mois>=1&&mois<=12) break;
    }
    int tab[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(annee/4==0) tab[1]=29;
    while (true)
    {
    cout<<" \n donner le jour"<<endl;
    cin>>jour;
    if(jour>=1&&jour<=tab[mois-1]) break;
    }
}
void date::afficher()
{
    cout<<jour<<"/"<<mois<<"/"<<annee<<endl;
}
template <class T>
bool date::operator>(const T& d) const
{
    int n1,n2;
    int  tab[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(d.annee/4==0) tab[1]=29;
    n2=d.annee*365+(d.mois-1)*tab[d.mois-2]+d.jour;
    if(annee/4==0) tab[1]=29;
    n1=annee*365+(mois-1)*tab[mois-2]+jour;
    return(n1>n2);

}
int date::nb_jour()
{
    int tab[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if ((annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0) {
    tab[1] = 29;
  }
     int nb_jour=0;
     for(int i=0;i<mois-1;i++)
     {
         nb_jour+=tab[i];
     }
      nb_jour+=annee*365+jour;
      return(nb_jour);

}


};

#endif // DATE_H
