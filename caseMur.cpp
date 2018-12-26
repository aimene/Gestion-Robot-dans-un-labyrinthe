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
point caseMur::basGauche(const terrain& terrain, int ligne, int colonne) const
{
    return point{terrain.position().x() + colonne*terrain.tailleCase() ,terrain.position().y() + ligne*terrain.tailleCase() + terrain.tailleCase()} ;
}

point caseMur::basDroit(const terrain& terrain ,int ligne, int colonne) const
{
    return point{terrain.position().x() + colonne*terrain.tailleCase()+terrain.tailleCase() ,terrain.position().y() + ligne*terrain.tailleCase() + terrain.tailleCase()} ;
}

point caseMur::hautGauche(const terrain& terrain, int ligne, int colonne) const
{
    return point{terrain.position().x() + colonne*terrain.tailleCase() ,terrain.position().y() + ligne*terrain.tailleCase()} ;
}

point caseMur::hautDroit(const terrain& terrain ,int ligne, int colonne) const
{
    return point{terrain.position().x() + colonne*terrain.tailleCase()+terrain.tailleCase() ,terrain.position().y() + ligne*terrain.tailleCase() } ;

}
void caseMur::dessineCases(const fenetre& fenetre,const terrain& terrain, int ligne, int colonne) const
{
    if (estMur())
    {
        fenetre.dessineRectanglePlein(basGauche(terrain, ligne , colonne),hautGauche(terrain , ligne , colonne),
                                      hautDroit(terrain, ligne , colonne),basDroit(terrain, ligne , colonne));
    }
}


}

