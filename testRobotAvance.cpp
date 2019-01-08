#include "doctest.h"
#include "robotAvance.h"
#include "terrain.h"
#include "point.h"
#include "fenetre.h"
#include "cases.h"
#include "caseBordureMur.h"
using affichage::fenetre;
using gestionRobotTerrain::robotAvance;
using gestionRobotTerrain::terrain;
using gestionRobotTerrain::cases;
using gestionRobotTerrain::caseBordureMur;
using geom::point;

TEST_CASE("Les manipulations sur un robot avance sont correctes")
{
    point positionRobot{200,200};
    point positionTerrain{200,200};
    point positionRobotObstacleDevant{250,350};
    int direction = robotAvance::EST;
    int point = 100;
    int nouvelleDirection;
    robotAvance robot{positionRobot,direction};
    fenetre fenetre{900,500};
    robot = {positionRobot,direction};
    caseBordureMur * caseborduremurPlein= new caseBordureMur{true,true,true,true};
    caseBordureMur *caseBordureMurAvecCreux = new caseBordureMur {true,false,true,true};
    std::vector<cases*> terrainEntoure;
    std::vector<std::vector<cases*> > matriceTerrain;
    SUBCASE("Le robot Avance detecte un obstacle a sa droite est correct")
    {
        fenetre.open();
        terrainEntoure.push_back(caseborduremurPlein);
        matriceTerrain.push_back(terrainEntoure);
        terrain terrain{positionTerrain,"test.txt",0,50,matriceTerrain};
        terrain.dessineTerrain(fenetre);
        robot.dessineRobot(terrain,fenetre);
        bool detecteObstacleDroite = robot.estObstacleSurSaDroite(terrain);
        REQUIRE_EQ(detecteObstacleDroite,true );
        fenetre.close();
    }
    SUBCASE("Le robot Avance detecte un obstacle a sa gauche")
    {

        fenetre.open();
        terrainEntoure.push_back(caseborduremurPlein);
        matriceTerrain.push_back(terrainEntoure);
        terrain terrain{positionTerrain,"test.txt",0,50,matriceTerrain};
        terrain.dessineTerrain(fenetre);
        robot.dessineRobot(terrain,fenetre);
        bool detecteObstacleGauche = robot.estObstacleSurSaGauche(terrain);
        REQUIRE_EQ(detecteObstacleGauche,true );
        fenetre.close();
    }
}
