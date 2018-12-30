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
    fenetre().clear();
    terrain.dessineTerrain(fenetre());
    robot.dessineRobot(terrain,fenetre() );
    while(!robot.detecteObstacleDevant(terrain))
    {
        robot.tourneDroite();
        fenetre().clear();
        terrain.dessineTerrain(fenetre());
        robot.dessineRobot(terrain,fenetre() );
    }
    robot.tourneGauche();
    fenetre().clear();
    terrain.dessineTerrain(fenetre());
    robot.dessineRobot(terrain,fenetre() );
    while(estDansTerrain(terrain, robot))
    {

        robot.tourneDroite();
        fenetre().clear();
        terrain.dessineTerrain(fenetre());
        robot.dessineRobot(terrain,fenetre() );
        fenetre().wait(500);

        if(robot.detecteObstacleDevant(terrain))
        {
            fenetre().clear();
            robot.tourneGauche();
            terrain.dessineTerrain(fenetre());
            robot.dessineRobot(terrain,fenetre() );
            fenetre().wait(500);

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
            fenetre().clear();
            terrain.dessineTerrain(fenetre());
            robot.dessineRobot(terrain,fenetre() );
            robot.avanceCase(terrain);
        fenetre().wait(500);

            fenetre().clear();
            terrain.dessineTerrain(fenetre());
            robot.dessineRobot(terrain,fenetre() );
             fenetre().wait(500);

            if(robot.detecteObstacleDevant(terrain))
            {

                robot.tourneGauche();
                fenetre().clear();
                terrain.dessineTerrain(fenetre());
                robot.dessineRobot(terrain,fenetre() );
            fenetre().wait(500);

            }

        }
        fenetre().clear();
        terrain.dessineTerrain(fenetre());
        robot.dessineRobot(terrain,fenetre() );
        fenetre().wait(500);
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
        fenetre().clear();
        terrain.dessineTerrain(fenetre());
        robot.dessineRobot(terrain,fenetre());
        fenetre().wait(500);
        if(compteurTourne==0)
        {

            while(!robot.detecteObstacleDevant(terrain))
            {
                robot.avanceCase(terrain);
                fenetre().clear();
                terrain.dessineTerrain(fenetre());
                robot.dessineRobot(terrain,fenetre());
                fenetre().wait(500);
            }
            robot.tourneDroite();
            fenetre().clear();
            terrain.dessineTerrain(fenetre());
            robot.dessineRobot(terrain,fenetre());
            fenetre().wait(500);
            compteurTourne+=tourneDroite;
            if(!robot.detecteObstacleDevant(terrain))
            {
                robot.avanceCase(terrain);
                fenetre().clear();
                terrain.dessineTerrain(fenetre());
                robot.dessineRobot(terrain,fenetre());
                fenetre().wait(500);
            }
        }
        if(compteurTourne!=0)
        {
            robot.tourneGauche();
            fenetre().clear();
            terrain.dessineTerrain(fenetre());
            robot.dessineRobot(terrain,fenetre());
            fenetre().wait(500);
            compteurTourne+=tourneGauche;
            if(!robot.detecteObstacleDevant(terrain))
            {
                robot.avanceCase(terrain);
                fenetre().clear();
                terrain.dessineTerrain(fenetre());
                robot.dessineRobot(terrain,fenetre());

                fenetre().wait(500);
                robot.tourneGauche();
                fenetre().clear();
                terrain.dessineTerrain(fenetre());
                robot.dessineRobot(terrain,fenetre());
                fenetre().wait(500);
                compteurTourne+=tourneGauche;
            }
            if(robot.detecteObstacleDevant(terrain))
            {
                robot.tourneDroite();
                fenetre().clear();
                terrain.dessineTerrain(fenetre());
                robot.dessineRobot(terrain,fenetre());
                fenetre().wait(500);
                compteurTourne+=tourneDroite;

            }
            if(robot.detecteObstacleDevant(terrain))
            {
                robot.tourneDroite();
                fenetre().clear();
                terrain.dessineTerrain(fenetre());
                robot.dessineRobot(terrain,fenetre());
                fenetre().wait(500);
                compteurTourne+=tourneDroite;
                fenetre().clear();
                terrain.dessineTerrain(fenetre());
                robot.avanceCase(terrain);
                robot.dessineRobot(terrain,fenetre());
                fenetre().wait(500);
                fenetre().clear();
                terrain.dessineTerrain(fenetre());
                robot.dessineRobot(terrain,fenetre());
                fenetre().wait(500);
            }
            else
            {
                robot.avanceCase(terrain);
                fenetre().clear();
                terrain.dessineTerrain(fenetre());
                robot.dessineRobot(terrain,fenetre());
                fenetre().wait(500);
            }
        }
        std::cout<<compteurTourne<<std::endl;
        fenetre().clear();
        terrain.dessineTerrain(fenetre());
        robot.dessineRobot(terrain,fenetre());
        fenetre().wait(500);
        std::cout<<"terrain"<<terrain.position()<<std::endl;
        std::cout<<robot.positionRobot()<<std::endl;
    }
    terrain.dessineTerrain(fenetre());
    robot.dessineRobot(terrain,fenetre());
    fenetre().repeteJusquaBouton();
}

bool programmeVisualisationRobot::estDansTerrain(terrain& terrain,robot& robot)
{
    return robot.positionRobot().x()<terrain.position().x()+terrain.tailleCase()*terrain.largeur() &&
           robot.positionRobot().y()<terrain.position().y()+terrain.tailleCase()*terrain.hauteur()
           ;
}


}
