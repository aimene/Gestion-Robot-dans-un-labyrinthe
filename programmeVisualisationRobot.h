#ifndef PROGRAMMEVISUALISATIONROBOT_H
#define PROGRAMMEVISUALISATIONROBOT_H


#include"fenetre.h"
#include "terrain.h"
#include "robot.h"


using namespace affichage ;


namespace affichage { class fenetre; }
namespace gestionRobotTerrain
{
class programmeVisualisationRobot
{

public:

    programmeVisualisationRobot(affichage::fenetre& fenetre);
    virtual ~programmeVisualisationRobot();
    fenetre& fenetre();
    bool estDansTerrain(terrain& terrain,robot& robot);
    virtual void majFenetre(terrain& terrain, robot& robot) ;

   virtual void runAlgoMainDroite( terrain& terrain, robot& robot);
    virtual void runAlgoPledge( terrain& terrain, robot& robot);



private :

    affichage::fenetre d_fenetre ;


};

}
#endif // programmeVisualisation_H

