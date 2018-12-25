#ifndef CASES_H
#define CASES_H

#include "fenetre.h"
#include "terrain.h"

using namespace::affichage;
namespace gestionRobotTerrain
{
<<<<<<< HEAD

=======
>>>>>>> b4992c3b0418af10806689722c8bfd7374af0f2e
class cases
{
public:
   cases(int segment);
   virtual ~cases();
   virtual void dessineCases(const fenetre& fenetre) = 0;
   int segment() const;
   void changeSegment(int segment) ;

private :
int d_segment;
};
}

#endif //CASES_H
