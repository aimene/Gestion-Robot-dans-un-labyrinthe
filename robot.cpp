#include "robot.h"
#include "point.h"
#include "terrain.h"
using gestionRobotTerrain::robot;


namespace gestionRobotTerrain
{
robot::robot(const point& position, int direction):d_position{position},d_direction{direction}
{}
int robot::direction() const
{
    return d_direction;
}
void robot::changeDirection(int direction)
{
    d_direction = direction;
}
point robot::positionRobot() const
{
    return d_position;
}
void robot::changePositionRobot(const point& position)
{
    d_position = position;
}
void robot::tourneDroite()
{
    switch(d_direction)
    {
    case EST :
        d_direction = SUD;
        break;
    case OUEST:
        d_direction = NORD;
        break;
    case NORD :
        d_direction = EST;
        break;
    case SUD :
        d_direction = OUEST;
        break;
    }
}

void robot::tourneGauche()
{
    switch(d_direction)
    {
    case EST :
        d_direction = NORD;
        break;
    case OUEST:
        d_direction = SUD;
        break;
    case NORD :
        d_direction = OUEST;
        break;
    case SUD :
        d_direction = EST;
        break;
    }
}

bool robot::detecteObstacleDevant(const terrain& terrain)
{

}

void robot::avanceCase(const terrain& terrain)
{



}



}




