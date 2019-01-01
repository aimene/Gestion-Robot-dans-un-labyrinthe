#ifndef ROBOTAVANCE_H
#define ROBOTAVANCE_H
#include"point.h"
#include "robot.h"
#include "terrain.h"

using namespace geom;
namespace gestionRobotTerrain
{
class robotAvance : public robot
{
public:
    robotAvance(const point& position,int direction);
    ~robotAvance();
    bool estObstacleSurSaGauche(const terrain& terrain)  ;
    bool estObstacleSurSaDroite(const terrain& terrain) ;

};
}
#endif // ROBOTAVANCE_H
