#include"programmeVisualisationRobotDeplacements.h"
#include "windows.h"
#include"robotAvance.h"
#include"robot.h"
#include"point.h"
namespace gestionRobotTerrain
{

programmeVisualisationRobotDepacements::programmeVisualisationRobotDepacements(affichage::fenetre& fenetre)
    :programmeVisualisationRobot{fenetre}
{

}

programmeVisualisationRobotDepacements::~programmeVisualisationRobotDepacements()
{

}
void programmeVisualisationRobotDepacements::majFenetre(terrain& terrain, robot& robot)
{
    robot.dessineRobot(terrain,fenetre() );
    fenetre().wait(500);
}





}

