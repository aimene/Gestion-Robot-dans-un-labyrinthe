#ifndef CASEBORDUREMUR_H
#define CASEBORDUREMUR_H

#include "cases.h"

class caseBordureMur : public cases
{
public:
    caseBordureMur(double segment,bool murGauche,bool murDroit,bool murHaut,bool murDroit);
    virtual void dessineCases(fenetre& fenetre,int ligne,int colonne) override ;
    bool estMurGauche();
    bool estMurDroit();
    bool estMurBas();
    bool estMurHaut();
    void changerMurGauche();
    void changerMurDroite();
    void changerMurHaut();
    void changer MurBas();

private:
   bool d_gauche, d_droite , d_bas , d_haut ;
};

#endif // CASEBORDUREMUR_H
