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
const point& robot::positionRobot() const
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
            return (dynamic_cast<caseMur*>(d_terrain[ligne][colonne+1]))->estMur();
            break;
        case OUEST:
            return (dynamic_cast<caseMur*>(d_terrain[ligne][colonne-1]))->estMur();
            break;
        case NORD :
            return  (dynamic_cast<caseMur*>(d_terrain[ligne+1][colonne]))->estMur();
            break;
        case SUD :
            return  (dynamic_cast<caseMur*>(d_terrain[ligne-1][colonne]))->estMur();
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
                return (dynamic_cast<caseBordureMur*>(d_terrain[ligne][colonne]))->estMurDroit();
                break;
            case OUEST:
                return (dynamic_cast<caseBordureMur*>(d_terrain[ligne][colonne]))->estMurGauche();
                break;
            case NORD :
                return  (dynamic_cast<caseBordureMur*>(d_terrain[ligne][colonne]))->estMurHaut();
                break;
            case SUD :
                           std::cout<<" dynamic_cast<caseBordureMur*>(d_terrain[ligne][colonne]))->estMurBas() avant robot = "<< (dynamic_cast<caseBordureMur*>(d_terrain[ligne][colonne]))->estMurBas()<< std::endl;

                return  (dynamic_cast<caseBordureMur*>(d_terrain[ligne][colonne]))->estMurBas();
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
            d_position.move (terrain.tailleCase(),0);
            return true;
        }
        break;
    case OUEST:
        if(detecteObstacleDevant(terrain))
            return false ;
        else
        {
            d_position.move(-terrain.tailleCase(),0);
            return true;
        }
        break;
    case NORD :
        if(detecteObstacleDevant(terrain))
            return false ;
        else
        {
            d_position.move(0,+terrain.tailleCase());
            return true;
        }
        break;
    case SUD :
        if(detecteObstacleDevant(terrain))
            return false ;
        else
        {
            d_position.move(0,-terrain.tailleCase());
            return true;
        }
        break;
    }

}
void robot::dessineRobot(terrain& terrain, fenetre& fenetre)
{

    int unQuartCase = terrain.tailleCase()/4;

    point basGauche {positionRobot().x()+unQuartCase,positionRobot().y()+unQuartCase};
    point hautGauche {positionRobot().x()+unQuartCase,positionRobot().y()+3*unQuartCase};
    point hautDroit {positionRobot().x()+3*unQuartCase,positionRobot().y()+3*unQuartCase};
    point basDroit {positionRobot().x()+3*unQuartCase,positionRobot().y()+unQuartCase};
    point directionPoint {pointDirection(unQuartCase)};

    switch(d_direction)
    {
    case EST :
           fenetre.dessinePolyPleinEst(basGauche,hautGauche,hautDroit,basDroit,directionPoint);
        break;
    case OUEST:
           fenetre.dessinePolyPleinOuest(basGauche,hautGauche,hautDroit,basDroit,directionPoint);
        break;
    case NORD :
            fenetre.dessinePolyPleinNord(basGauche,hautGauche,hautDroit,basDroit,directionPoint);
        break;
    case SUD :
           fenetre.dessinePolyPleinSud(basGauche,hautGauche,hautDroit,basDroit,directionPoint);
        break;
    }

}

point robot::pointDirection(int unQuartCase )
{
    switch(d_direction)
    {
    case EST :
        return point{positionRobot().x()+3*unQuartCase+unQuartCase/2,positionRobot().y()+2*unQuartCase};
        break;
    case OUEST:
        return point{positionRobot().x()+unQuartCase/2,positionRobot().y()+2*unQuartCase};
        break;
    case NORD :
        return  point{positionRobot().x()+2*unQuartCase,positionRobot().y()+3*unQuartCase+unQuartCase/2};
        break;
    case SUD :
        return  point{positionRobot().x()+2*unQuartCase,positionRobot().y()+unQuartCase/2};
        break;
    }
}
}




