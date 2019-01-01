#include"fenetreAffichage.h"

namespace affichage
{

fenetreAffichage::fenetreAffichage() : fenetreAffichage{0.0,1.0,0.0,1.0}
{}

fenetreAffichage::fenetreAffichage(double srcmin, double srcmax) : fenetreAffichage{srcmin,srcmax,0.0,1.0}
{}
fenetreAffichage::fenetreAffichage(double srcmin, double srcmax, double destmin, double destmax):
            d_srcmin{srcmin}, d_srcmax{srcmax}, d_destmin{destmin}, d_destmax{destmax}
{
  computeDelta();
}

double fenetreAffichage::destFromSrc(double src) const
{
  return d_destmin+d_delta*(src-d_srcmin);
}

double fenetreAffichage::srcFromDest(double dest) const
{
  return d_srcmin+(dest-d_destmin)/d_delta;
}

double fenetreAffichage::deltaSrc() const
{
  return d_delta;
}

fenetreAffichage& fenetreAffichage::changeSrcMin(double srcmin)
{
  d_srcmin = srcmin;
  computeDelta();
  return *this;
}

fenetreAffichage& fenetreAffichage::changeSrcMax(double srcmax)
{
  d_srcmax = srcmax;
  computeDelta();
  return *this;
}
fenetreAffichage& fenetreAffichage::changeSrc(double srcmin, double srcmax)
{
  d_srcmin = srcmin;
  d_srcmax = srcmax;
  computeDelta();
  return *this;
}

fenetreAffichage& fenetreAffichage::changeDestMin(double destmin)
{
  d_destmin = destmin;
  computeDelta();
  return *this;
}

fenetreAffichage& fenetreAffichage::changeDestMax(double destmax)
{
  d_destmax = destmax;
  computeDelta();
  return *this;
}

fenetreAffichage& fenetreAffichage::changeDest(double destmin, double destmax)
{
  d_destmin = destmin;
  d_destmax = destmax;
  computeDelta();
  return *this;
}

void fenetreAffichage::computeDelta()
{
  d_delta = (d_destmax-d_destmin)/(d_srcmax-d_srcmin);
}

}

