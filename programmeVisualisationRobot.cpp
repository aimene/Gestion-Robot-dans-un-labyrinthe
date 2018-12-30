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

    while(!robot.detecteObstacleDevant(terrain))
    {
        robot.tourneDroite();
    }
    robot.tourneGauche();

    while(estDansTerrain(terrain, robot))
    {
        robot.tourneDroite();
        if(robot.detecteObstacleDevant(terrain))
        {
            robot.tourneGauche();
            if(robot.detecteObstacleDevant(terrain))
                robot.tourneGauche();
            else
                robot.avanceCase(terrain);
        }
        else
        {
            robot.avanceCase(terrain);
            if(robot.detecteObstacleDevant(terrain))
                robot.tourneGauche();

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

