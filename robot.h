#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include "point.h"
#include "terrain.h"

using namespace geom;
namespace gestionRobotTerrain {
class robot
{
public:
    robot();
    ~robot();
    robot(const point& position,int direction);
    point positionRobot() const;
    void dessineRobot(const terrain& terrain);
    bool detecteObstacleDevant(const terrain& terrain);
    void avanceCase(const terrain& terrain);
    void changerPositionRobot(const point& position);
    int direction() const;
    void changerDirection(int direction);
    void tournerDroite(const int angleEnDegre = 90);
    void tournerGauche(const int angleEnDegre = 90);
    const int EST = 1;
    const int NORD = 2;
    const int OUEST = 3;
    const int SUD = 4;
private:
    point d_position;
    int   d_direction;
};
}
#endif // ROBOT_H
