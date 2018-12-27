#ifndef PROGRAMMEVISUALISATION_H
#define PROGRAMMEVISUALISATION_H

#include"fenetre.h"
#include"terrain.h"
#include"robot.h"
using namespace affichage ;


namespace affichage { class fenetre; }
namespace gestionRobotTerrain
{
class programmeVisualisation
{
public:

    programmeVisualisation(fenetre fenetre);
    virtual ~programmeVisualisation();


    fenetre& fenetre() ;
    virtual void runAlgoMainDroite( terrain& terrain, robot& robot)=0;
    virtual void runAlgoPledje( terrain& terrain, robot& robot)=0;




protected:
    affichage::fenetre d_fenetre ;

};

}
#endif // programmeVisualisation_H
