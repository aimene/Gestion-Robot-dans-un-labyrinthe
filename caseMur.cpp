#include "caseMur.h"
#include "terrain.h"
namespace gestionRobotTerrain
{

caseMur::caseMur(double segment,bool mur):cases(segment),d_mur{mur}
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
void caseMur::dessineCasses(const fenetre& fenetre,const terrain& terrain,int ligne,int colonne,)
{}

}

