#include"programmeVisualisationRobotAvance.h"

namespace gestionRobotTerrain
{

programmeVisualisationRobotAvance::programmeVisualisationRobotAvance(affichage::fenetre& fenetre)
    :programmeVisualisation{fenetre}
{

}

programmeVisualisationRobotAvance::~programmeVisualisationRobotAvance()
{

}

void programmeVisualisationRobotAvance::majFenetre(terrain& terrain, robotAvance& robot)
{

    fenetre().clear();
    terrain.dessineTerrain(fenetre());
    robot.dessineRobot(terrain,fenetre() );
    fenetre().wait(500);

}

void programmeVisualisationRobotAvance::runAlgoMainDroite( terrain& terrain, robotAvance& robot)
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

void programmeVisualisationRobotAvance::runAlgoPledge(terrain& terrain, robotAvance& robotAvance)
{
    const int tourneGauche = 1;
    const int tourneDroite = -1;
    int compteurTourne=0;
    while(estDansTerrain(terrain,robotAvance))
    {
        majFenetre( terrain,robotAvance);
        if(compteurTourne==0)
        {

            while(!robotAvance.detecteObstacleDevant(terrain))
            {
                robotAvance.avanceCase(terrain);
                majFenetre( terrain,robotAvance);

            }
            robotAvance.tourneDroite();
            majFenetre( terrain,robotAvance);
            compteurTourne+=tourneDroite;
            if(!robotAvance.detecteObstacleDevant(terrain))
            {
                robotAvance.avanceCase(terrain);
                majFenetre( terrain,robotAvance);
            }
        }
        if(compteurTourne!=0)
        {
            if(!robotAvance.estObstacleSurSaGauche(terrain))
            {
                robotAvance.tourneDroite();
                majFenetre(terrain,robotAvance);
                compteurTourne+=tourneDroite;
                if(!robotAvance.detecteObstacleDevant(terrain))
                {
                    robotAvance.avanceCase(terrain);
                    if(robotAvance.estObstacleSurSaGauche(terrain))
                    {
                        robotAvance.avanceCase(terrain);
                        majFenetre(terrain,robotAvance);
                    }
                }
            }
            if(robotAvance.estObstacleSurSaGauche(terrain))
            {
               if(robotAvance.detecteObstacleDevant(terrain))
               {
                   robotAvance.tourneDroite();
                   majFenetre(terrain,robotAvance);
                   compteurTourne+=tourneDroite;
               }
               else
               {
                   robotAvance.avanceCase(terrain);
                   majFenetre(terrain,robotAvance);
               }
            }
        }
    }

}
}
