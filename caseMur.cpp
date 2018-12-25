#include "cases.h"
#include "caseMur.h"
#include"fenetre.h"
#include "terrain.h"

namespace gestionRobotTerrain
{

using affichage::fenetre;
caseMur::caseMur(int segment,bool mur):cases(segment),d_mur{mur}
{}
caseMur::~caseMur()
{}
bool caseMur::estMur() const
{
    return d_mur;
}
void caseMur::changerMurValeur(bool change)
{
   d_mur = change;
}
void caseMur::dessineCases(const fenetre& fenetre) const
{}


}

