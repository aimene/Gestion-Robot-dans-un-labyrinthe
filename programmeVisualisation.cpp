#include"programmeVisualisation.h"
namespace gestionRobotTerrain
{

programmeVisualisation::programmeVisualisation(affichage::fenetre fenetre) :d_fenetre{fenetre}
{

}
fenetre& programmeVisualisation::fenetre()
{
    return d_fenetre;
}
programmeVisualisation::~programmeVisualisation()
{

}



}
