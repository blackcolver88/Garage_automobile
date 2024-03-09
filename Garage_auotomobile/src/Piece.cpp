#include "Piece.h"
Piece::Piece()
{
}
Piece::Piece(string nm,int Ref,string fr,float pr )
{
 nom=nm;
 Reference=Ref;
 fournisseur=fr;
 prix=pr;
}
Piece::Piece(const Piece& p)
{
 nom=p.nom;
 Reference=p.Reference;
 fournisseur=p.fournisseur;
 prix=p.prix;

}
Piece::~Piece()
{
    //dtor
}
istream& operator>>(istream& in,Piece& p)
{
    cout<<"donner le nom du piece :"<<endl;
    in>>p.nom ;
    cout<<"\n donner le reference du piece :"<<endl;
    in>>p.Reference;
    cout<<"\n donner le fournisseur du piece :"<<endl;
    in>>p.fournisseur;
    cout<<"\n donner le prix du piece :"<<endl;
    in>>p.prix;
    return in ;
}
ostream& operator<<(ostream& out,Piece& p)
{
    out<<"Le nom du piece est : "<<p.nom<<endl;
    out<<"Le reference du piece est : "<<p.Reference<<endl;
    out<<"Le fournisseur du piece est : "<<p.fournisseur<<endl;
    out<<"Le prix du piece est : "<<p.prix<<endl;
    return out ;
}
void piece::creerpiece(fstream& f){
f.open("C:\\Users\\yassin\\cours\\semestre2\\programmation orienté objets\\proj\\piece.txt", ios::in | ios::out | ios::trunc);
if(!f.is_open())exit(-1);
}
ostream& operator<< (ostream& out , piece* p )
{
    out<<setw(10)<<p->nom;
    out<<setw(10)<<p->Reference<<endl;;
    out<<"Fournisseur:"<<endl;
    for(auto it=p->fournisseur.begin();it!=p->fournisseur.end();it++)
        out<<setw(10)<<*it;
    out<<setw(10)<<p->prix;
    return out;
}
istream& operator>> (istream& in, piece* p)
{
    in.seekg(0);
    in>>p->nom;
    in>>p->Reference;
    for(auto it=p->fournisseur.begin();it!=p->fournisseur.end();it++)
        in>>*it;
    in>>p->prix;
    return in;
}
