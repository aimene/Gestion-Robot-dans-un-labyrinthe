#ifndef CASES_H
#define CASES_H

#include "fenetre.h"
#include"terrain.h"
using namespace::affichage;
namespace affichage
{
class fenetre;
}
namespace gestionRobotTerrain
{
class terrain ;
class cases
{
public:
    virtual ~cases();
    virtual void dessineCases(const fenetre& fenetre,const terrain& terrain,int ligne,int colonne) const = 0;
    point basGauche(const terrain& terrain,int ligne, int colonne) const ;
    point basDroit(const terrain& terrain,int ligne, int colonne) const ;
    point hautGauche(const terrain& terrain,int ligne, int colonne) const ;
    point hautDroit(const terrain& terrain,int ligne, int colonne) const ;

   /* virtual bool estMur() const ;
    virtual bool estMurGauche() const;
    virtual bool estMurDroit() const;
    virtual bool estMurBas()const;
    virtual bool estMurHaut()const;*/
};


}

#endif //CASE_H
