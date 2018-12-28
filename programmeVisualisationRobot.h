#ifndef PROGRAMMEVISUALISATIONROBOT_H
#define PROGRAMMEVISUALISATIONROBOT_H

#include"programmeVisualisation.h"
using namespace affichage ;


namespace affichage { class fenetre; }
namespace gestionRobotTerrain
{
class programmeVisualisationRobot : public programmeVisualisation
{

public:

    programmeVisualisationRobot(affichage::fenetre fenetre);
    virtual ~programmeVisualisationRobot();


    virtual void runAlgoMainDroite( terrain& terrain, robot& robot)override;
    virtual void runAlgoPledje( terrain& terrain, robot& robot)override;

    bool estDansTerrain(terrain& terrain, robot& robot);



};

}
#endif // programmeVisualisation_H

