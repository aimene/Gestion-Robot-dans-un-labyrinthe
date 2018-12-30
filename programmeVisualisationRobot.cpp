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

void programmeVisualisationRobot::majFenetre(terrain& terrain, robot& robot)
{

    fenetre().clear();
    terrain.dessineTerrain(fenetre());
    robot.dessineRobot(terrain,fenetre() );
    fenetre().wait(500);

}

void programmeVisualisationRobot::runAlgoMainDroite( terrain& terrain, robot& robot)
{
    terrain.dessineTerrain(fenetre());
 majFenetre( terrain,robot);
    while(!robot.detecteObstacleDevant(terrain))
    {
        robot.tourneDroite();
        majFenetre( terrain,robot);

    }
    robot.tourneGauche();
    majFenetre( terrain,robot);

    while(estDansTerrain(terrain, robot))
    {

        robot.tourneDroite();

        majFenetre( terrain,robot);

        if(robot.detecteObstacleDevant(terrain))
        {

            robot.tourneGauche();

            majFenetre( terrain,robot);
            if(robot.detecteObstacleDevant(terrain))
            {

                robot.tourneGauche();

            }
            else
            {
                robot.avanceCase(terrain);

            }
        }
        else
        {
            majFenetre( terrain,robot);

            robot.avanceCase(terrain);


            majFenetre( terrain,robot);

            if(robot.detecteObstacleDevant(terrain))
            {

                robot.tourneGauche();
                majFenetre( terrain,robot);

            }


        }
        majFenetre( terrain,robot);
    }
    terrain.dessineTerrain(fenetre());
    fenetre().repeteJusquaBouton();
}
void programmeVisualisationRobot::runAlgoPledge(terrain& terrain, robot& robot)
{
    const int tourneGauche = 1;
    const int tourneDroite = -1;
    int compteurTourne=0;
    while(estDansTerrain(terrain,robot))
    {
        if(compteurTourne==0)
        {
            std::cout<<"compteurTourne==0"<<std::endl;

            while(!robot.detecteObstacleDevant(terrain))
            {
                std::cout<<"moi detecteObstacle";
                robot.avanceCase(terrain);
            }
            robot.tourneDroite();
            compteurTourne+=tourneDroite;
            if(!robot.detecteObstacleDevant(terrain))
                robot.avanceCase(terrain);
        }
        if(compteurTourne!=0)
        {
            robot.tourneGauche();
            compteurTourne+=tourneGauche;
            if(!robot.detecteObstacleDevant(terrain))
            {
                robot.avanceCase(terrain);
                robot.tourneGauche();
                compteurTourne+=tourneGauche;
            }
            if(robot.detecteObstacleDevant(terrain)) //else
            {
                robot.tourneDroite();
                compteurTourne+=tourneDroite;
                robot.avanceCase(terrain);
            }
            if(robot.detecteObstacleDevant(terrain))
            {
                robot.tourneDroite();
                compteurTourne+=tourneDroite;
                robot.avanceCase(terrain);
            }
            else
            {
                robot.avanceCase(terrain);
            }
        }

    }
}





}
