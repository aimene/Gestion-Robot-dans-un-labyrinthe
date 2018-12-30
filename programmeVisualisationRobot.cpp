#include"programmeVisualisationRobot.h"
#include "windows.h"
namespace gestionRobotTerrain
{

programmeVisualisationRobot::programmeVisualisationRobot(affichage::fenetre& fenetre)
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
        robot.dessineRobot(terrain,fenetre());
    }
}
void programmeVisualisationRobot::runAlgoPledge(terrain& terrain, robot& robot)
{
    const int tourneGauche = 1;
    const int tourneDroite = -1;
    int compteurTourne=0;
    while(estDansTerrain(terrain,robot))
    {
        robot.dessineRobot(terrain,fenetre());
        if(compteurTourne==0)
        {

            while(!robot.detecteObstacleDevant(terrain))
            {
                robot.avanceCase(terrain);
                robot.dessineRobot(terrain,fenetre());
            }
            robot.tourneDroite();
            robot.dessineRobot(terrain,fenetre());
            compteurTourne+=tourneDroite;
            if(!robot.detecteObstacleDevant(terrain))
            {
                robot.avanceCase(terrain);
                robot.dessineRobot(terrain,fenetre());
            }
        }
        if(compteurTourne!=0)
        {
            robot.tourneGauche();
            robot.dessineRobot(terrain,fenetre());
            compteurTourne+=tourneGauche;
            if(!robot.detecteObstacleDevant(terrain))
            {
                robot.avanceCase(terrain);
                robot.dessineRobot(terrain,fenetre());
                robot.tourneGauche();
                robot.dessineRobot(terrain,fenetre());
                compteurTourne+=tourneGauche;
            }
            if(robot.detecteObstacleDevant(terrain)) //else
            {
                robot.tourneDroite();
                robot.dessineRobot(terrain,fenetre());
                compteurTourne+=tourneDroite;
                robot.avanceCase(terrain);
                robot.dessineRobot(terrain,fenetre());
            }
            if(robot.detecteObstacleDevant(terrain))
            {
                robot.tourneDroite();
                robot.dessineRobot(terrain,fenetre());
                compteurTourne+=tourneDroite;
                robot.avanceCase(terrain);
                robot.dessineRobot(terrain,fenetre());
            }
            else
            {
                robot.avanceCase(terrain);
                robot.dessineRobot(terrain,fenetre());
            }
        }
    }
}


bool programmeVisualisationRobot::estDansTerrain(terrain& terrain,robot& robot)
{
    return robot.positionRobot().x()<terrain.position().x()+terrain.tailleCase()*terrain.largeur() &&
           robot.positionRobot().y()<terrain.position().y()+terrain.tailleCase()*terrain.hauteur()
           ;
}


}
