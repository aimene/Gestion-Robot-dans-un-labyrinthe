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
    vector<vector<cases*> > d_terrain =terrain.terrainMatrice();
    int ligne = (positionRobot().y()-terrain.position().y()) / terrain.tailleCase();
    int colonne = (positionRobot().x()-terrain.position().x()) / terrain.tailleCase();
    if (terrain.type()== terrain.typeCaseMur)
    {

        switch(d_direction)
        {
        case EST :
            return dynamic_cast<caseMur*>(d_terrain[ligne][colonne+1])->estMur();
            break;
        case OUEST:
            return dynamic_cast<caseMur*>(d_terrain[ligne][colonne-1])->estMur();
            break;
        case NORD :
            return  dynamic_cast<caseMur*>(d_terrain[ligne+1][colonne])->estMur();
            break;
        case SUD :
            return  dynamic_cast<caseMur*>(d_terrain[ligne-1][colonne])->estMur();
            break;
        }

    }
    else
    {
        if(terrain.type()== terrain.typeCaseBordureMur)
        {
            switch(d_direction)
            {
            case EST :
                return dynamic_cast<caseBordureMur*>(d_terrain[ligne][colonne+1])->estMurDroit();
                break;
            case OUEST:
                return dynamic_cast<caseBordureMur*>(d_terrain[ligne][colonne-1])->estMurGauche();
                break;
            case NORD :
                return  dynamic_cast<caseBordureMur*>(d_terrain[ligne+1][colonne])->estMurHaut();
                break;
            case SUD :
                return  dynamic_cast<caseBordureMur*>(d_terrain[ligne-1][colonne])->estMurBas();
                break;
            }
        }
    }
}

bool robot::avanceCase(const terrain& terrain)
{
    switch(d_direction)
    {
    case EST :
        if(detecteObstacleDevant(terrain))
            return false ;
        else
        {
            d_position.move(d_position.x()+terrain.tailleCase(),d_position.y());
            return true;
        }
        break;
    case OUEST:
        if(detecteObstacleDevant(terrain))
            return false ;
        else
        {
            d_position.move(d_position.x()-terrain.tailleCase(),d_position.y());
            return true;
        }
        break;
    case NORD :
        if(detecteObstacleDevant(terrain))
            return false ;
        else
        {
            d_position.move(d_position.x(),d_position.y()+terrain.tailleCase());
            return true;
        }
        break;
    case SUD :
        if(detecteObstacleDevant(terrain))
            return false ;
        else
        {
            d_position.move(d_position.x(),d_position.y()-terrain.tailleCase());
            return true;
        }
        break;
    }

}



}




