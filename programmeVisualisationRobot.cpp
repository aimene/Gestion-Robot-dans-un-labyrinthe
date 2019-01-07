#include"programmeVisualisationRobot.h"
#include "windows.h"
namespace gestionRobotTerrain
{

programmeVisualisationRobot::programmeVisualisationRobot(affichage::fenetre& fenetre)
    :d_fenetre{fenetre}
{

}

programmeVisualisationRobot::~programmeVisualisationRobot()
{

}
fenetre& programmeVisualisationRobot::fenetre()
{
    return d_fenetre;
}


bool programmeVisualisationRobot::estDansTerrain(terrain& terrain,robot& robot)
{
    return robot.positionRobot().x()<terrain.position().x()+terrain.tailleCase()*terrain.largeur() &&
           robot.positionRobot().y()<terrain.position().y()+terrain.tailleCase()*terrain.hauteur();
}
void programmeVisualisationRobot::majFenetre(terrain& terrain, robot& robot)
{

    fenetre().clear();
    terrain.dessineTerrain(fenetre());
    robot.dessineRobot(terrain,fenetre() );
    fenetre().wait(500);

}

void programmeVisualisationRobot::runAlgoMainDroite( terrain& terrain,robot& robot)
{
    terrain.dessineTerrain(fenetre());
    majFenetre( terrain,robot);
    while(estDansTerrain(terrain,robot))
    {
        if(robot.detecteObstacleDevant(terrain))
        {
            robot.tourneDroite();
            majFenetre( terrain,robot);
            if(robot.detecteObstacleDevant(terrain))
            {
                robot.tourneDroite();

            }
            else
            {
                robot.avanceCase(terrain);

            }

        }
        else
        {
            robot.tourneDroite();
            majFenetre( terrain,robot);
            if(robot.detecteObstacleDevant(terrain))
            {
                robot.tourneGauche();
                 majFenetre( terrain,robot);

                robot.avanceCase(terrain);

            }
            else
            {
                robot.avanceCase(terrain);

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
    fenetre().close();
}




}
