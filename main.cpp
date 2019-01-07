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
    fenetre fenetre {800,800};
    point positionRobot{50,550};
    robot robot{positionRobot,1};
    terrain terrain{"terrainCaseMur1final.txt"};

    fenetre.open();

        terrain.dessineTerrain(fenetre);
        programmeVisualisationRobot prog {fenetre};
        prog.runAlgoPledge(terrain,robot);


    fenetre.repeteJusquaBouton();
    return 0;
}
