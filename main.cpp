#include <iostream>
#include"terrain.h"
#include"cases.h"
#include"fenetre.h"

using namespace std;
using namespace gestionRobotTerrain;
using namespace affichage;
int main()
{

  fenetre fenetre {900,900};
  terrain terrain{"terrain1.txt"};
  terrain.dessineTerrain(fenetre);
    return 0;
}
