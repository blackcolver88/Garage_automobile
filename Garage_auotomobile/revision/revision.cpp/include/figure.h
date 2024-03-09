#ifndef FIGURE_H
#define FIGURE_H


class figure
{
    int couleur;
    int epaisseur;
    public:
        figure(int,int);
        virtual ~figure();
        virtual void afficher(string ="")=0;
        virtual void saisir()=0;


};

#endif // FIGURE_H
