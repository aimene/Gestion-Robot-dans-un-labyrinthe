#include"programmeVisualisationRobotAvance.h"

namespace gestionRobotTerrain
{


programmeVisualisationRobotAvance::programmeVisualisationRobotAvance(affichage::fenetre& fenetre)
    :d_fenetre{fenetre}
{

}

programmeVisualisationRobotAvance::~programmeVisualisationRobotAvance()
{

}
fenetre& programmeVisualisationRobotAvance::fenetre()
{
    return d_fenetre;
}



bool programmeVisualisationRobotAvance::estDansTerrain(terrain& terrain,robotAvance& robot)
{
    return robot.positionRobot().x()<terrain.position().x()+terrain.tailleCase()*terrain.largeur() &&
           robot.positionRobot().y()<terrain.position().y()+terrain.tailleCase()*terrain.hauteur();
}
void programmeVisualisationRobotAvance::majFenetre(terrain& terrain, robotAvance& robot)
{

    fenetre().clear();
    terrain.dessineTerrain(fenetre());
    robot.dessineRobot(terrain,fenetre() );
    fenetre().wait(10);

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
    if(!robot.estObstacleSurSaDroite(terrain))
    {
        robot.tourneDroite();
            majFenetre( terrain,robot);

        robot.avanceCase(terrain);
            majFenetre( terrain,robot);

    }
    while( estDansTerrain(terrain, robot))
    {
        if(robot.estObstacleSurSaDroite(terrain))
        {

            if(robot.detecteObstacleDevant(terrain))
            {
                 robot.tourneGauche();
                     majFenetre( terrain,robot);

            }else{
                 robot.avanceCase(terrain);
                     majFenetre( terrain,robot);

            }
        }else{
            robot.tourneDroite();
             majFenetre( terrain,robot);
            robot.avanceCase(terrain);
             majFenetre( terrain,robot);
            if(robot.detecteObstacleDevant(terrain))
            {
                robot.tourneGauche();
                    majFenetre( terrain,robot);

            }

        }
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
            else
            {
                robotAvance.tourneGauche();
                majFenetre( terrain,robotAvance);
                compteurTourne+=tourneGauche;
                if(!robotAvance.detecteObstacleDevant(terrain))
                {
                    robotAvance.avanceCase(terrain);
                    majFenetre( terrain,robotAvance);
                }
                else
                {
                   robotAvance.tourneGauche();
                   majFenetre( terrain,robotAvance);
                   compteurTourne+=tourneGauche;
                }

            }
        }
        if(compteurTourne!=0)
        {
            if(!robotAvance.estObstacleSurSaGauche(terrain))
            {
                robotAvance.tourneGauche();
                compteurTourne+=tourneGauche;
                majFenetre(terrain,robotAvance);

                if(!robotAvance.detecteObstacleDevant(terrain))
                {
                    robotAvance.avanceCase(terrain);
                    majFenetre(terrain,robotAvance);
                    if(robotAvance.estObstacleSurSaGauche(terrain))
                    {
                        if(!robotAvance.detecteObstacleDevant(terrain))
                        {
                            robotAvance.avanceCase(terrain);
                            majFenetre(terrain,robotAvance);
                        }
                        else
                        {
                            robotAvance.tourneDroite();
                            majFenetre(terrain,robotAvance);
                            compteurTourne+=tourneDroite;
                        }

                    }
                }
                else
                {
                    robotAvance.tourneGauche();
                    majFenetre(terrain,robotAvance);
                    compteurTourne+=tourneGauche;
                    if(!robotAvance.detecteObstacleDevant(terrain))
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
        majFenetre( terrain,robotAvance);
    }
    terrain.dessineTerrain(fenetre());
    robotAvance.dessineRobot(terrain,fenetre());
    fenetre().close();

}
}
