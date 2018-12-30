#include "robotAvance.h"
#include "point.h"
#include "terrain.h"


namespace gestionRobotTerrain
{
    robotAvance::robotAvance(const point& position, int direction):robot(position,direction)
    {}

    robotAvance::~robotAvance(){}
 bool  robotAvance::estObstacleSurSaGauche(const terrain& terrain)
    {
        tourneGauche();
        bool value = detecteObstacleDevant(terrain);
        this->tourneDroite();
        return value;
    }
    bool robotAvance::estObstacleSurSaDroite(const terrain& terrain)
    {
        tourneDroite();
        bool value = detecteObstacleDevant(terrain);
        tourneGauche();
        return value;
    }
}
