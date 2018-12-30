
#include"programmeVisualisationRobotAvanceDeplacements.h"
#include "windows.h"
#include"robotAvance.h"
#include"point.h"
namespace gestionRobotTerrain
{

programmeVisualisationRobotAvanceDeplacements::programmeVisualisationRobotAvanceDeplacements(affichage::fenetre& fenetre)
    :programmeVisualisationRobotAvance{fenetre}
{

}

programmeVisualisationRobotAvanceDeplacements::~programmeVisualisationRobotAvanceDeplacements()
{

}
void programmeVisualisationRobotAvanceDeplacements::majFenetre(terrain& terrain, robotAvance& robot)
{
    robot.dessineRobot(terrain,fenetre() );
    fenetre().wait(500);
}





}

