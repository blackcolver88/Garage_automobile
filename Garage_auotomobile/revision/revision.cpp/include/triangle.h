#ifndef TRIANGLE_H
#define TRIANGLE_H


class triangle
{
    int base;
    int hauteur;
    public:
        triangle(int,int,int,int);
        void calculAire();
        void afficher(string="");
        void saisir();
        virtual ~triangle();
};

#endif // TRIANGLE_H
