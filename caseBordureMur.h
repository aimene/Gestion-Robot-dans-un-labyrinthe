#ifndef CASEBORDUREMUR_H
#define CASEBORDUREMUR_H

#include "cases.h"

class caseBordureMur : public cases
{
public:
    virtual void dessineCases(fenetre& fenetre,int ligne,int colonne) override ;
    estMurGauche();
    void changerMurGauche();
     ...
     
private:
   bool d_gauche, d_droite , d_bas , d_haut ;
};

#endif // CASEBORDUREMUR_H
