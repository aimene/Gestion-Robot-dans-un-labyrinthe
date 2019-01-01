#include "doctest.h"
#include "robot.h"
#include "terrain.h"
#include "point.h"


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
        robot = {positionRobotObstacleDevant,direction};
        terrain terrain{"terrainBordureMur1.txt"};
        bool detecteObstacle = robot.detecteObstacleDevant(terrain);

        REQUIRE(detecteObstacle == true );
    }
    SUBCASE("Le robot avance est correct")
    {
        terrain terrain{"terrainBordureMur1.txt"};
        std::cout<<robot.positionRobot();
        bool avance = robot.avanceCase(terrain);
        REQUIRE(avance == true );
    }
}
