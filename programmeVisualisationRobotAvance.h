#ifndef PROGRAMMEVISUALISATIONROBOTAVANCE_H
#define PROGRAMMEVISUALISATIONROBOTAVANCE_H

#include "terrain.h"
#include "robotAvance.h"
#include"fenetre.h"
using namespace affichage;


namespace affichage { class fenetre; }
namespace gestionRobotTerrain
{
class programmeVisualisationRobotAvance
{
public:

    programmeVisualisationRobotAvance(affichage::fenetre& fenetre);
    virtual ~programmeVisualisationRobotAvance();

     fenetre& fenetre();
    bool estDansTerrain(terrain& terrain,robotAvance& robot);
    virtual void majFenetre(terrain& terrain, robotAvance& robot) ;

    virtual void runAlgoMainDroite( terrain& terrain, robotAvance& robot);
    virtual void runAlgoPledge( terrain& terrain, robotAvance& robot);

private :


    affichage::fenetre d_fenetre ;



};

}
#endif // programmeVisualisation_H


