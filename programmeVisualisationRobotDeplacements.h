#ifndef PROGRAMMEVISUALISATIONROBOTDEPLACEMENTS_H
#define PROGRAMMEVISUALISATIONROBOTDEPLACEMENTS_H

#include"programmeVisualisationRobot.h"
using namespace affichage ;
using namespace geom;


namespace geom { class point; }
namespace affichage { class fenetre; }
namespace gestionRobotTerrain
{
class programmeVisualisationRobotDepacements : public programmeVisualisationRobot
{

public:

    programmeVisualisationRobotDepacements(affichage::fenetre& fenetre);
    virtual ~programmeVisualisationRobotDepacements();

    virtual void majFenetre(terrain& terrain, robot& robot) override;

   // virtual void runAlgoMainDroite( terrain& terrain, robot& robot)override;
   // virtual void runAlgoPledge( terrain& terrain, robot& robot)override;



};

}
#endif // programmeVisualisation_H

