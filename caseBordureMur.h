#ifndef CASEBORDUREMUR_H
#define CASEBORDUREMUR_H
#include "cases.h"

namespace gestionRobotTerrain
{

class caseBordureMur : public cases
{
public:
    caseBordureMur(double segment,bool murGauche,bool murDroit,bool murBas,bool murHaut);
    virtual void dessineCases(const fenetre& fenetre,const terrain& terrain,int ligne,int colonne) override ;
    bool estMurGauche();
    bool estMurDroit();
    bool estMurBas();
    bool estMurHaut();
    void changeMurGauche(bool change);
    void changeMurDroit(bool change);
    void changeMurHaut(bool change);
    void changeMurBas(bool change);

private:
   bool d_gauche, d_droit , d_bas , d_haut ;
};

}

#endif // CASEBORDUREMUR_H
