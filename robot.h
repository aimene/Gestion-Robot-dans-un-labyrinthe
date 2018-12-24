#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include "point.h"

using namespace geom;
class robot
{
public:
    robot();
    ~robot();
    robot(const point& position,int direction);
    point positionRobot() const;
    void changerPositionRobot(const point& position);
    int direction() const;
    void changerDirection(int direction);
    void avancerRobotDe(int pas);
    void tournerDroite(const int angleEnDegre = 90);
    void tournerGauche(const int angleEnDegre = 90);
    bool estObstacleDevant() const ;
private:
    point d_position;
    int   d_direction;
};

#endif // ROBOT_H
