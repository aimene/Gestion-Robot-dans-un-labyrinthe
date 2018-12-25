#include "cases.h"
#include "caseMur.h"
#include"fenetre.h"
#include "terrain.h"

namespace gestionRobotTerrain
{

using affichage::fenetre;
caseMur::caseMur(bool mur):d_mur{mur}
{}
caseMur::~caseMur()
{}
bool caseMur::estMur() const
{
    return d_mur;
}
void caseMur::changeMurValeur(bool change)
{
   d_mur = change;
}
void caseMur::dessineMur(const fenetre& fenetre,const terrain& terrain, int ligne , int colonne) const
{
    int x1,y1,x2,y2;
    point basGauche,hautDroit ;
   if (estMur())
   {
       x1 = terrain.position().x() + colonne*terrain.tailleCase() ;
       y1 = terrain.position().y() + ligne*terrain.tailleCase() + terrain.tailleCase();
       x2 = terrain.position().x() + colonne*terrain.tailleCase()+terrain.tailleCase();
       y2 = terrain.position().y() + ligne*terrain.tailleCase();
       basGauche = {x1,y1};
       hautDroit = {x2,y2};
       fenetre.dessineRectanglePlein(basGauche,hautDroit);
   }
}
void caseMur::dessineCases(const fenetre& fenetre,const terrain& terrain, int ligne , int colonne) const
{
    dessineMur(fenetre,terrain,ligne,colonne);
}


}

