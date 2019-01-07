#include "doctest.h"
#include "robotAvance.h"
#include "terrain.h"
#include "point.h"
#include "fenetre.h"
#include "caseBordureMur.h"
#include <vector>

using gestionRobotTerrain::terrain;
using geom::point;
using gestionRobotTerrain::cases;
using gestionRobotTerrain::caseBordureMur;

TEST_CASE("Les cases bordures murs sont correctes")
{
    caseBordureMur * caseborduremur= new caseBordureMur{true,true,true,true};
    std::vector<cases*> terrainEntoure;
    terrainEntoure.push_back(caseborduremur);
    std::vector<std::vector<cases*> > matriceTerrain;
    matriceTerrain.push_back(terrainEntoure);
    point position{200,200};
    terrain terrain{position,"testTerrainBordureMur.txt",0,50,matriceTerrain};
    SUBCASE("Un mur gauche est dans le terrain est correct")
    {
        bool murGauche = (dynamic_cast<caseBordureMur*>(matriceTerrain[0][0]))->estMurGauche();
        REQUIRE_EQ(murGauche,true);
    }
    SUBCASE("Un mur bas est dans le terrain est correct")
    {
        bool murBas = (dynamic_cast<caseBordureMur*>(matriceTerrain[0][0]))->estMurBas();
        REQUIRE_EQ(murBas,true);
    }
    SUBCASE("Un mur droit est dans le terrain est correct")
    {
        bool murDroit = (dynamic_cast<caseBordureMur*>(matriceTerrain[0][0]))->estMurDroit();
        REQUIRE_EQ(murDroit,true);
    }
    SUBCASE("Un mur haut est dans le terrain est correct")
    {
        bool murHaut = (dynamic_cast<caseBordureMur*>(matriceTerrain[0][0]))->estMurHaut();
        REQUIRE_EQ(murHaut,true);
    }
}
