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
    while(estDansTerrain(terrain, robot))
    {
        while(!robot.detecteObstacleDevant(terrain))
        {
            robot.tourneDroite();
        }
        robot.tourneGauche();
        if(!robot.detecteObstacleDevant(terrain))
        {

        }
        else
        {

        }

        robot.dessineRobot(terrain,fenetre() );

    }
}

void programmeVisualisationRobot::runAlgoPledje( terrain& terrain, robot& robot)
{

}

bool programmeVisualisationRobot::estDansTerrain(terrain& terrain,robot& robot)
{
    return robot.positionRobot().x()<terrain.position().x()+terrain.tailleCase()*terrain.largeur() &&
           robot.positionRobot().y()<terrain.position().y()+terrain.tailleCase()*terrain.hauteur()
           ;
}


}

