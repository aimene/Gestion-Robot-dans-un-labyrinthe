#include "doctest.h"
#include "robotAvance.h"
#include "terrain.h"
#include "point.h"

#include "caseMur.h"
#include <vector>



using gestionRobotTerrain::terrain;
using geom::point;
using gestionRobotTerrain::cases;
using gestionRobotTerrain::caseMur;

TEST_CASE("Les cases qui sont des murs sont correctes")
{
    caseMur * caseMurs = new caseMur{true};
    std::vector<cases*> terrainEntoure;
    terrainEntoure.push_back(caseMurs);
    std::vector<std::vector<cases*> > matriceTerrain;
    matriceTerrain.push_back(terrainEntoure);
    point position{200,200};
    terrain terrain{position,"testTerrainBordureMur.txt",0,50,matriceTerrain};
    SUBCASE("Un mur est dans le terrain est correct")
    {
        bool estMur = (dynamic_cast<caseMur*>(matriceTerrain[0][0]))->estMur();
        REQUIRE_EQ(estMur,true);
    }
}
