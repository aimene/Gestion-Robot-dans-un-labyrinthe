#ifndef ROBOTAVANCE_H
#define ROBOTAVANCE_H
#include"point.h"
#include "robot.h"
#include "terrain.h"

using namespace geom;
namespace gestionRobotTerrain {
class robotAvance : public robot
{
public:
    robotAvance(const point& position,int direction,int pas);
    ~robotAvance();
    bool estObstacleSurSaGauche(const terrain& terrain) const ;
    bool estObstacleSurSaDroite(const terrain& terrain) const;
private:
  int d_pas;
  point d_position;
};
}
#endif // ROBOTAVANCE_H
