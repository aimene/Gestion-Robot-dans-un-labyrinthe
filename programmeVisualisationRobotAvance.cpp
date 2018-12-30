
#include"programmeVisualisationRobotAvance.h"
#include "windows.h"
namespace gestionRobotTerrain
{

programmeVisualisationRobotAvance::programmeVisualisationRobotAvance(affichage::fenetre& fenetre)
    :programmeVisualisation{fenetre}
{

}

programmeVisualisationRobotAvance::~programmeVisualisationRobotAvance()
{

}

void programmeVisualisationRobotAvance::majFenetre(terrain& terrain, robot& robot)
{

    fenetre().clear();
    terrain.dessineTerrain(fenetre());
    robot.dessineRobot(terrain,fenetre() );
    fenetre().wait(500);

}

void programmeVisualisationRobotAvance::runAlgoMainDroite( terrain& terrain, robot& robot)
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

void programmeVisualisationRobotAvance::runAlgoPledge(terrain& terrain, robot& robot)
{
    const int tourneGauche = 1;
    const int tourneDroite = -1;
    int compteurTourne=0;
    while(estDansTerrain(terrain,robot))
    {
        majFenetre( terrain,robot);
        if(compteurTourne==0)
        {

            while(!robot.detecteObstacleDevant(terrain))
            {
                robot.avanceCase(terrain);
                majFenetre( terrain,robot);
            }
            robot.tourneDroite();
            majFenetre( terrain,robot);
            compteurTourne+=tourneDroite;
            if(!robot.detecteObstacleDevant(terrain))
            {
                robot.avanceCase(terrain);
                majFenetre( terrain,robot);
            }
        }
        if(compteurTourne!=0)
        {
            robot.tourneGauche();
            majFenetre( terrain,robot);
            compteurTourne+=tourneGauche;
            if(!robot.detecteObstacleDevant(terrain))
            {
                robot.avanceCase(terrain);
                majFenetre( terrain,robot);
                robot.tourneGauche();
                majFenetre( terrain,robot);
                compteurTourne+=tourneGauche;
            }
            if(robot.detecteObstacleDevant(terrain))
            {
                robot.tourneDroite();
                majFenetre( terrain,robot);
                compteurTourne+=tourneDroite;

            }
            if(robot.detecteObstacleDevant(terrain))
            {
                robot.tourneDroite();
                majFenetre( terrain,robot);
                compteurTourne+=tourneDroite;
                robot.avanceCase(terrain);
                 majFenetre( terrain,robot);
            }
            else
            {
                robot.avanceCase(terrain);
                 majFenetre( terrain,robot);
            }
        }
        std::cout<<compteurTourne<<std::endl;
         majFenetre( terrain,robot);
        std::cout<<"terrain"<<terrain.position()<<std::endl;
        std::cout<<robot.positionRobot()<<std::endl;
    }
    terrain.dessineTerrain(fenetre());
    robot.dessineRobot(terrain,fenetre());
    fenetre().repeteJusquaBouton();
}


}
