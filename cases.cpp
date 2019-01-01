#include "cases.h"
namespace gestionRobotTerrain
{

point cases::basGauche(const terrain& terrain, int ligne, int colonne) const
{
    return point{terrain.position().x() + colonne*terrain.tailleCase(),terrain.position().y() + ligne*terrain.tailleCase() + terrain.tailleCase()} ;
}

point cases::basDroit(const terrain& terrain,int ligne, int colonne) const
{
    return point{terrain.position().x() + colonne*terrain.tailleCase()+terrain.tailleCase(),terrain.position().y() + ligne*terrain.tailleCase() + terrain.tailleCase()} ;
}

point cases::hautGauche(const terrain& terrain, int ligne, int colonne) const
{
    return point{terrain.position().x() + colonne*terrain.tailleCase(),terrain.position().y() + ligne*terrain.tailleCase()} ;
}

point cases::hautDroit(const terrain& terrain,int ligne, int colonne) const
{
    return point{terrain.position().x() + colonne*terrain.tailleCase()+terrain.tailleCase(),terrain.position().y() + ligne*terrain.tailleCase() } ;

}

cases::~cases()
{

}

}

