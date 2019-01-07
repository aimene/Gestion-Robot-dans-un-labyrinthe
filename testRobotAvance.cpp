#include "doctest.h"
#include "robotAvance.h"
#include "terrain.h"
#include "point.h"
#include "fenetre.h"

using affichage::fenetre;
using gestionRobotTerrain::robotAvance;
using gestionRobotTerrain::terrain;

using geom::point;

TEST_CASE("Les manipulations sur un robot avance sont correctes")
{
    point positionRobot{200,350};
    point positionRobotObstacleDevant{250,350};
    int direction = robotAvance::EST;
    int point = 100;
    int nouvelleDirection;
    robotAvance robot{positionRobot,direction};
    fenetre fenetre{900,500};
        robot = {positionRobot,direction};
    SUBCASE("Le robot avance detecte un obstacle a sa droite est correct")
    {
        fenetre.open();
        terrain terrain{"terrainBordureMur1.txt"};
        terrain.dessineTerrain(fenetre);
        robot.dessineRobot(terrain,fenetre);
        bool detecteObstacleDroite = robot.estObstacleSurSaDroite(terrain);
        std::cout<<detecteObstacleDroite;
        REQUIRE_EQ(detecteObstacleDroite,true );
        fenetre.repeteJusquaBouton();
    }
    SUBCASE("Le robot avance detecte un obstacle a sa gauche")
    {

        fenetre.open();
        terrain terrain{"terrainBordureMur1.txt"};
        terrain.dessineTerrain(fenetre);
        robot.dessineRobot(terrain,fenetre);
        bool detecteObstacleGauche = robot.estObstacleSurSaGauche(terrain);
        std::cout<<detecteObstacleGauche;
        REQUIRE_EQ(detecteObstacleGauche,true );
        fenetre.repeteJusquaBouton();
    }
}
