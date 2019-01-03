#include "doctest.h"
#include "robotAvance.h"
#include "terrain.h"
#include "point.h"
#include "fenetre.h"
#include "programmeVisualisationRobot.h"

using affichage::fenetre;
using gestionRobotTerrain::robot;
using gestionRobotTerrain::terrain;
using gestionRobotTerrain::programmeVisualisationRobot;
using geom::point;

TEST_CASE("Les manipulations sur le programme de visualisation robot sont correctes")
{
    point positionRobot{200,350};
    int direction = robot::EST;
    robot robot{positionRobot,direction};
    fenetre fenetre{900,500};
    SUBCASE("Le robot est dans le terrain est correcte")
    {
        terrain terrain{"terrainBordureMur1.txt"};
        programmeVisualisationRobot prog{fenetre};
        REQUIRE_EQ(prog.estDansTerrain(terrain,robot),true);
    }
}
