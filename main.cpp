#include <iostream>
#include"terrain.h"
#include <cstdlib>
#include"cases.h"
#include"fenetre.h"

#include"robot.h"

#include"point.h"
#include"programmeVisualisationRobotDeplacements.h"
#include"programmeVisualisationRobotAvanceDeplacements.h"

#include "programmeVisualisationRobot.h"
#include "programmeVisualisationRobotAvance.h"

using namespace std;
using namespace gestionRobotTerrain;
using namespace affichage;
using affichage::fenetre;
using namespace geom;
int main()
{

    fenetre fenetre {900,800};
    point positionRobotAvance{50,750};
    robot robotAvance{positionRobotAvance,1};
    terrain terrain{"terrainCaseMur1final.txt"};


    fenetre.open();

        terrain.dessineTerrain(fenetre);


         programmeVisualisationRobot prog {fenetre};

        prog.runAlgoPledge(terrain , robotAvance);




    fenetre.repeteJusquaBouton();
    return 0;
}
