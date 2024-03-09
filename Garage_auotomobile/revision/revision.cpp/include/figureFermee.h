#ifndef FIGUREFERMEE_H
#define FIGUREFERMEE_H


class figureFermee
{
    float aire;
    public:
        figureFermee();
        virtual ~figureFermee();
        virtual void calculAire()=0;
        virtual void afficher(string="");

};

#endif // FIGUREFERMEE_H
