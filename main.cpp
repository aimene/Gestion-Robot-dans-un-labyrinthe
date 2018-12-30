#include <iostream>
#include"terrain.h"
#include <cstdlib>
#include"cases.h"
#include"fenetre.h"
#include"robot.h"
#include"point.h"
#include"programmeVisualisationRobotDeplacements.h"

#include "programmeVisualisationRobot.h"
#include "programmeVisualisation.h"
using namespace std;
using namespace gestionRobotTerrain;
using namespace affichage;
using affichage::fenetre;
using namespace geom;
int main()
{
    fenetre fenetre {900,500};
    point positionRobot{200,350};
    robot robot{positionRobot,1};
    terrain terrain{"terrainBordureMur1.txt"};




    fenetre.open();
        terrain.dessineTerrain(fenetre);
        programmeVisualisationRobot prog {fenetre};
        prog.runAlgoMainDroite(terrain , robot);
    fenetre.repeteJusquaBouton();

    return 0;
}
