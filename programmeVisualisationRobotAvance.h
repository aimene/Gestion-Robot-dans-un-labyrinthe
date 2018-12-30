#ifndef PROGRAMMEVISUALISATIONROBOTAVANCE_H
#define PROGRAMMEVISUALISATIONROBOTAVANCE_H

#include"programmeVisualisation.h"
using namespace affichage ;


namespace affichage { class fenetre; }
namespace gestionRobotTerrain
{
class programmeVisualisationRobotAvance : public programmeVisualisation
{

public:

    programmeVisualisationRobotAvance(affichage::fenetre& fenetre);
    virtual ~programmeVisualisationRobotAvance();

    virtual void majFenetre(terrain& terrain, robot& robot) override;

    virtual void runAlgoMainDroite( terrain& terrain, robot& robot)override;
    virtual void runAlgoPledge( terrain& terrain, robot& robot)override;




};

}
#endif // programmeVisualisation_H


