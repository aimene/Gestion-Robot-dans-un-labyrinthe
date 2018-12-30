
#ifndef PROGRAMMEVISUALISATIONROBOTAVANCEDEPLACEMENTS_H
#define PROGRAMMEVISUALISATIONROBOTAVANCEDEPLACEMENTS_H

#include"programmeVisualisationRobotAvance.h"
using namespace affichage ;
using namespace geom;


namespace geom { class point; }
namespace affichage { class fenetre; }
namespace gestionRobotTerrain
{
class programmeVisualisationRobotAvanceDeplacements : public programmeVisualisationRobotAvance
{

public:

    programmeVisualisationRobotAvanceDeplacements(affichage::fenetre& fenetre);
    virtual ~programmeVisualisationRobotAvanceDeplacements();

    virtual void majFenetre(terrain& terrain, robotAvance& robotAvance )  ;




};

}
#endif // programmeVisualisation_H

