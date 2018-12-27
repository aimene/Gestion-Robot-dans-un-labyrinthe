#include <iostream>
#include"terrain.h"
#include"cases.h"
#include"fenetre.h"

using namespace std;
using namespace gestionRobotTerrain;
using namespace affichage;
int main()
{

  /*fenetre fenetre {900,900};
  terrain terrain{"terrain0.txt"};
  terrain.dessineTerrain(fenetre);*/
  terrain t;
   t.sauveTerrain();
    return 0;
}
