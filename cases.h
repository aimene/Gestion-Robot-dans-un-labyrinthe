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
   cases(int segment);
   virtual ~cases();
   virtual void dessineCases(const fenetre& fenetre,const terrain& terrain) const = 0;

   int segment() const;
   void changeSegment(int segment) ;

private :
int d_segment;
};


}

#endif //CASE_H
