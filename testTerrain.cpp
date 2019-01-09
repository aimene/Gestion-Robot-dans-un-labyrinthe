#include "doctest.h"
#include "robot.h"
#include "terrain.h"
#include "point.h"
#include <iostream>
#include <string.h>
using gestionRobotTerrain::terrain;

TEST_CASE("Les manipulations sur le terrain sont correctes")
{
    SUBCASE("La lecture du terrain est correct")
    {
       terrain terrain{"terrainBordureMur1final.txt"};
        bool lit = terrain.litTerrain();
        REQUIRE_EQ(lit,true );
    }
    SUBCASE("Changer le nom du fichier terrain est correct")
    {
         terrain terrain{"terrainBordureMur1final.txt"};
         std::string nomFichier ="nouveauNom";
         terrain.changeNomFichier(nomFichier);
         REQUIRE_EQ(terrain.nomFichier(),nomFichier);
    }
}
