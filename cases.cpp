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
/*  bool cases::estMur() const
    {
       return true;
    }

    bool cases::estMurGauche() const
    {
 return true;
    }

    bool cases::estMurDroit() const
    {
         return true;
    }

    bool cases::estMurBas() const
    {
         return true;
    }

    bool cases::estMurHaut() const
    {
         return true;
    }*/
cases::~cases()
{

}

}

