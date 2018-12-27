#include"programmeVisualisationRobot.h"
namespace gestionRobotTerrain
{

programmeVisualisationRobot::programmeVisualisationRobot(affichage::fenetre fenetre)
    :programmeVisualisation{fenetre}
{

}

programmeVisualisationRobot::~programmeVisualisationRobot()
{

}
void programmeVisualisationRobot::runAlgoMainDroite( terrain& terrain, robot& robot)
{
    while(robot.positionRobot().x()<terrain.position().x())
    {
        while(!robot.detecteObstacleDevant(terrain))
        {
            robot.tourneDroite();
        }
        robot.tourneGauche();
        robot.avanceCase(terrain);
        robot.dessineRobot(terrain,fenetre() );
    }
}

void programmeVisualisationRobot::runAlgoPledje( terrain& terrain, robot& robot)
{

}


}

