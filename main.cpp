#include <iostream>
#include"terrain.h"
#include"cases.h"
#include"fenetre.h"
#include"robot.h"
#include"point.h"
using namespace std;
using namespace gestionRobotTerrain;
using namespace affichage;
using namespace geom;
int main()
{

    fenetre fenetre {900,500};
    point positionRobot{150,150};
    robot robot{positionRobot,1};
    terrain terrain{"terrain0.txt"};
     fenetre.open();
    terrain.dessineTerrain(fenetre);

    std::cout<<" main essineTerrain = "<< std::endl;
    std::cout<<" maine dessine robot "<< std::endl;
    robot.dessineRobot(terrain,fenetre);
    fenetre.repeteJusquaBouton();
    return 0;
}
