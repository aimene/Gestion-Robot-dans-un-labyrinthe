#include "doctest.h"
#include "robot.h"
#include "terrain.h"
#include "point.h"

using gestionRobotTerrain::terrain;

TEST_CASE("Les manipulations sur le terrai sont correctes")
{
    SUBCASE("La lecture du terrain est correct")
    {
       terrain terrain{"terrainBordureMur1.txt"};
        terrain.litTerrain();
        REQUIRE_EQ(terrain.litTerrain(),true );
    }
    SUBCASE("")
    {

    }
}
