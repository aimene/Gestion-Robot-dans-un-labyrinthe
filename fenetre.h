#ifndef FENETRE_H
#define FENETRE_H

#include <iostream>
#include "point.h"

using namespace geom;
class fenetre
{
public:
 void bordureX();
 void rectangle(const point&,const point&)
 void traceSegment(const point&,const point&);
 ----
private:
   int d_hauteru,d_largeur;
};

#endif // FENETRE_H
