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

    programmeVisualisationRobot(affichage::fenetre& fenetre);
    virtual ~programmeVisualisationRobot();


    virtual void runAlgoMainDroite( terrain& terrain, robot& robot)override;
    virtual void runAlgoPledge( terrain& terrain, robot& robot,affichage::fenetre& fenetre)override;





};

}
#endif // programmeVisualisation_H

