#include "doctest.h"
#include "robot.h"
#include "terrain.h"
#include "point.h"
#include "fenetre.h"

using affichage::fenetre;
using gestionRobotTerrain::robot;
using gestionRobotTerrain::terrain;

using geom::point;

TEST_CASE("Les manipulations sur le robot sont correctes")
{
    point positionRobot{200,350};
    point positionRobotObstacleDevant{250,350};
    int direction = robot::EST;
    int point = 100;
    int nouvelleDirection;
    robot robot{positionRobot,direction};
    SUBCASE("Le robot position du robot change est correct")
    {

        REQUIRE_GT(robot.positionRobot().x() + point,positionRobot.x());
    }
    SUBCASE("Le robot tourne gauche est correcte")
    {
        robot.tourneGauche();
        REQUIRE_NE(robot.direction(),direction);
        nouvelleDirection = robot::NORD;
        REQUIRE_EQ(robot.direction(),nouvelleDirection);
    }
    SUBCASE("Le robot tourne a  droite est correct")
    {
        robot.tourneDroite();
        REQUIRE_NE(robot.direction(),direction);
        nouvelleDirection = robot::SUD;
        REQUIRE_EQ(robot.direction(),nouvelleDirection);
    }
    SUBCASE("Le robot detecte un obstacle est correct")
    {
        fenetre fenetre{900,500};
        robot = {positionRobotObstacleDevant,direction};
        fenetre.open();
        terrain terrain{"terrainBordureMur1.txt"};
        terrain.dessineTerrain(fenetre);
        robot.dessineRobot(terrain,fenetre);
        bool detecteObstacle = robot.detecteObstacleDevant(terrain);
        std::cout<<detecteObstacle;
        REQUIRE_EQ(detecteObstacle,true );
        fenetre.repeteJusquaBouton();

    }
    SUBCASE("Le robot avance est correct")
    {
        fenetre fenetre{900,500};
        fenetre.open();
        terrain terrain{"terrainBordureMur1.txt"};
        terrain.dessineTerrain(fenetre);
        robot.dessineRobot(terrain,fenetre);
        std::cout<<robot.positionRobot();
        fenetre.wait(1000);
        bool avance = robot.avanceCase(terrain);
        robot.dessineRobot(terrain,fenetre);
        REQUIRE(avance == true );
        fenetre.repeteJusquaBouton();
    }
}
