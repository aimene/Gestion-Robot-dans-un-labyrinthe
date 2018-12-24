#ifndef CASEMUR_H
#define CASEMUR_H
#include "cases.h"

class caseMur : public cases
{
    public:
        caseMur(double segment, bool mur = true);
        ~caseMur();
        virtual void dessineCases(fenetre& fenetre,int ligne,int colonne) override ;
        bool estMur() const ;
        void changerMurValeur() ;
    private:
        bool d_mur ; // vrai si mur
};
#endif // CASEMUR_H
