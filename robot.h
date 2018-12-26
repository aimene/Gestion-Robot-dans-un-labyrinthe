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
    void changePositionRobot(const point& position);
    int direction() const;
    void changeDirection(int direction);
    void tourneDroite();
    void tourneGauche();
    static const int EST = 1;
    static const int NORD = 2;
    static const int OUEST = 3;
    static const int SUD = 4;
private:
    point d_position;
    int   d_direction;
};
}
#endif // ROBOT_H
