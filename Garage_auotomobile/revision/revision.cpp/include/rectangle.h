#ifndef RECTANGLE_H
#define RECTANGLE_H


class rectangle
{
    int longueur;
    int largeur;
    public:
        rectangle(int,int,int,int);
        virtual ~rectangle();
        void calculAire();
        void afficher(string="");
        void saisir();


};

#endif // RECTANGLE_H
