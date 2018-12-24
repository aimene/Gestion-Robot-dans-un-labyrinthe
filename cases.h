#ifndef CASES_H
#define CASES_H

#include "fenetre.h"

using namespace::affichage;
namespace gestionRobotTerrain
{

class cases
{
public:
   cases(double segment);
   virtual ~cases();
   virtual void dessineCases(fenetre& fenetre,int ligne,int colonne) = 0;
   double segment() const;
   void changeSegment(double segment) ;

private :
double d_segment;
};
}

#endif //CASE_H
