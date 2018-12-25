#ifndef CASEBORDUREMUR_H
#define CASEBORDUREMUR_H
#include "cases.h"

namespace gestionRobotTerrain
{
class terrain;
class point;
class fenetre;
class caseBordureMur : public cases
{
public:
    caseBordureMur(int segment,bool murGauche,bool murDroit,bool murBas,bool murHaut);
    virtual void dessineCases(const fenetre& fenetre,const terrain& terrain)  ;
    bool estMurGauche() const;
    bool estMurDroit() const;
    bool estMurBas()const;
    bool estMurHaut()const;
    void changeMurGauche(bool change);
    void changeMurDroit(bool change);
    void changeMurHaut(bool change);
    void changeMurBas(bool change);

private:
   bool d_gauche, d_droit , d_bas , d_haut ;
};

}

#endif // CASEBORDUREMUR_H
