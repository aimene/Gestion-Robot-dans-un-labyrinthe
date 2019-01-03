#include "doctest.h"
#include "robotAvance.h"
#include "terrain.h"
#include "point.h"
#include "fenetre.h"
#include "programmeVisualisation.h"

using affichage::fenetre;
using gestionRobotTerrain::robotAvance;
using gestionRobotTerrain::terrain;
using gestionRobotTerrain::programmeVisualisation;
using geom::point;

TEST_CASE("Les manipulations sur le programme de visualisation sont correctes")
{
    point positionRobot{200,350};
    int direction = robotAvance::EST;
    robotAvance robot{positionRobot,direction};
    fenetre fenetre{900,500};
    SUBCASE("Le robot est dans le terrain est correcte")
    {
        terrain terrain{"terrainBordureMur1.txt"};
        programmeVisualisation prog{fenetre};
        REQUIRE_EQ(prog.estDansTerrain(terrain,robot),true);

    }
}
