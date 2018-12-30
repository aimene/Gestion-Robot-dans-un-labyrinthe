
#include"programmeVisualisationRobotAvance.h"
#include "windows.h"
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
           robot.positionRobot().y()<terrain.position().y()+terrain.tailleCase()*terrain.hauteur()
           ;
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
            robot.tourneGauche();
              majFenetre( terrain,robot);
            if(robot.detecteObstacleDevant(terrain))
            {
                 robot.tourneGauche();
                     majFenetre( terrain,robot);

            }else{
                 robot.avanceCase(terrain);
                     majFenetre( terrain,robot);

            }
        }else{
            robot.avanceCase(terrain);
            if(robot.estObstacleSurSaDroite(terrain))
            {
                robot.tourneGauche();
                    majFenetre( terrain,robot);

            }

        }
    }
    terrain.dessineTerrain(fenetre());
    fenetre().repeteJusquaBouton();
}

void programmeVisualisationRobotAvance::runAlgoPledge(terrain& terrain, robotAvance& robot)
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
