#ifndef VISUALISATIONROBOTDANSTERRAIN_H
#define VISUALISATIONROBOTDANSTERRAIN_H

#include "robotAvance.h"
class visualisationRobotDansTerrain
{
class terrain;
public:

    visualtionRobotDansTerrain();
    ~visualtionRobotDansTerrain();
    virtual void algorithmeMainDroite(const terrain& terrain,const robot& robot);
    virtual void algorithmeDePledge(const terrain& terrain,const robot& robot);
    virtual void sortirRobotDuLabyrinthe(const terrain& terrain,const robot& robot);

private:

};
#endif // VISUALISATIONROBOTDANSTERRAIN_H
