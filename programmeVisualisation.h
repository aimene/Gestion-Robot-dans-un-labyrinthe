#ifndef PROGRAMMEVISUALISATION_H
#define PROGRAMMEVISUALISATION_H

#include"fenetre.h"
#include"terrain.h"
#include"robot.h"
using namespace affichage ;

using namespace geom;


namespace geom { class point; }
namespace affichage { class fenetre; }
namespace gestionRobotTerrain
{
class programmeVisualisation
{
public:

    programmeVisualisation(fenetre& fenetre);
    virtual ~programmeVisualisation();


    fenetre& fenetre() ;
    bool estDansTerrain(terrain& terrain, robot& robot);

    virtual void majFenetre(terrain& terrain, robot& robot)=0;

    virtual void runAlgoMainDroite( terrain& terrain, robot& robot)=0;
    virtual void runAlgoPledge( terrain& terrain, robot& robot)=0;




protected:
    affichage::fenetre d_fenetre ;

};

}
#endif // programmeVisualisation_H