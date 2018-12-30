#include"programmeVisualisation.h"
namespace gestionRobotTerrain
{

programmeVisualisation::programmeVisualisation(affichage::fenetre& fenetre) :d_fenetre{fenetre}
{

}
fenetre& programmeVisualisation::fenetre()
{
    return d_fenetre;
}


bool programmeVisualisation::estDansTerrain(terrain& terrain,robotAvance& robot)
{
    return robot.positionRobot().x()<terrain.position().x()+terrain.tailleCase()*terrain.largeur() &&
           robot.positionRobot().y()<terrain.position().y()+terrain.tailleCase()*terrain.hauteur()
           ;
}
programmeVisualisation::~programmeVisualisation()
{

}



}
