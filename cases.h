#ifndef CASES_H
#define CASES_H

#include "fenetre.h"
#include"terrain.h"
using namespace::affichage;
namespace affichage { class fenetre; }
namespace gestionRobotTerrain
{
class terrain ;
class cases
{
public:
   virtual ~cases();
   virtual void dessineCases(const fenetre& fenetre,const terrain& terrain,int ligne,int colonne) const = 0;
};


}

#endif //CASE_H
