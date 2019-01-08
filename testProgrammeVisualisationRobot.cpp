#include "doctest.h"
#include "robotAvance.h"
#include "terrain.h"
#include "point.h"
#include "fenetre.h"
#include "programmeVisualisationRobot.h"
#include "cases.h"
#include "caseBordureMur.h"

using affichage::fenetre;
using gestionRobotTerrain::robot;
using gestionRobotTerrain::cases;
using gestionRobotTerrain::caseBordureMur;
using gestionRobotTerrain::terrain;
using gestionRobotTerrain::programmeVisualisationRobot;
using geom::point;

TEST_CASE("Les manipulations sur le programme de visualisation robot sont correctes")
{
    point positionRobot{200,200};
    point positionTerrain = positionRobot;
    int direction = robot::EST;
    robot robot{positionRobot,direction};
    fenetre fenetre{900,500};
    caseBordureMur * caseborduremurPlein= new caseBordureMur{true,true,true,true};
    caseBordureMur *caseBordureMurAvecCreux = new caseBordureMur {true,false,true,true};
    std::vector<cases*> terrainEntoure;
    std::vector<std::vector<cases*> > matriceTerrain;
    SUBCASE("Le robot est dans le terrain est correcte")
    {
        terrainEntoure.push_back(caseborduremurPlein);
        matriceTerrain.push_back(terrainEntoure);
        terrain terrain{positionTerrain,"test.txt",0,50,matriceTerrain};
        programmeVisualisationRobot prog{fenetre};
        bool estDansTerrain = prog.estDansTerrain(terrain,robot);
        REQUIRE_EQ(estDansTerrain,true);
    }
}
