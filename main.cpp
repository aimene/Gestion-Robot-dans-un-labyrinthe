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
    point positionRobotAvance{50,550};
    robotAvance robotAvance{positionRobotAvance,1};
    terrain terrain{"terrainBordureMur1final.txt"};


    fenetre.open();

        terrain.dessineTerrain(fenetre);


         programmeVisualisationRobotAvance prog {fenetre};

        prog.runAlgoPledge(terrain , robotAvance);




    fenetre.repeteJusquaBouton();
    return 0;
}
