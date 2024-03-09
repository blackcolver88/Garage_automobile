#ifndef PIECE_H
#define PIECE_H
#include<bits\stdc++.h>
using namespace std;
class Piece
{
    string nom ;
    int Reference;
    string fournisseur;
    float prix ;
    public:
        Piece();
        Piece(string,int,string,float);
        Piece(const Piece& p );
        virtual ~Piece();
        friend ostream& operator<<(ostream&,Piece&);
        friend istream& operator>>(istream&,Piece&);
        void remplir(fstream&);
};
#endif // PIECE_H
