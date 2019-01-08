#include "doctest.h"
#include "robot.h"
#include "terrain.h"
#include "point.h"
#include "fenetre.h"
#include <iostream>
#include <sstream>
#include <string>
#include"cases.h"
#include "caseBordureMur.h"

using affichage::fenetre;
using gestionRobotTerrain::robot;
using gestionRobotTerrain::terrain;
using gestionRobotTerrain::cases ;
using gestionRobotTerrain::caseBordureMur;
using geom::point;

TEST_CASE("Les manipulations sur le robot sont correctes")
{
    point positionRobot{200,200};
    point positionRobotObstacleDevant{250,350};
    point positionTerrain{200,200};
    int direction = robot::EST;
    int point = 100;
    int nouvelleDirection;
    robot robot{positionRobot,direction};
    fenetre fenetre{900,500};
    caseBordureMur * caseborduremurPlein= new caseBordureMur{true,true,true,true};
    caseBordureMur *caseBordureMurAvecCreux = new caseBordureMur {true,false,true,true};
    std::vector<cases*> terrainEntoure;
    std::vector<std::vector<cases*> > matriceTerrain;

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
        fenetre.open();
        terrainEntoure.push_back(caseborduremurPlein);
        matriceTerrain.push_back(terrainEntoure);
        terrain terrain{positionTerrain,"test.txt",0,50,matriceTerrain};
        terrain.dessineTerrain(fenetre);
        robot = {positionRobot,direction};
        robot.dessineRobot(terrain,fenetre);
        bool detecteObstacle = robot.detecteObstacleDevant(terrain);
        REQUIRE(detecteObstacle==true );
        fenetre.close();
    }
    SUBCASE("Le robot avance est correct")
    {
        fenetre.open();
        terrainEntoure.push_back(caseBordureMurAvecCreux);
        caseBordureMur * caseBordureMurAvecCreux2 = new caseBordureMur {false,false,true,true};
        terrainEntoure.push_back(caseBordureMurAvecCreux2);
        matriceTerrain.push_back(terrainEntoure);
        terrain terrain{positionTerrain,"test.txt",0,50,matriceTerrain};
        terrain.dessineTerrain(fenetre);
        robot.dessineRobot(terrain,fenetre);
        bool avance = robot.avanceCase(terrain);
        robot.dessineRobot(terrain,fenetre);
        REQUIRE_EQ(avance,true );
        fenetre.close();
    }
}
