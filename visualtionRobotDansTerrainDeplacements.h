#ifndef VISUALISATIONROBOTDANSTERRAINDEPLACEMENTS_H
#define VISUALISATIONROBOTDANSTERRAINDEPLACEMENTS_H

#include "robotAvance.h"
class visualisationRobotDansTerrainAlgoMainDroite
{
class terrain;
public:

    visualtionRobotDansTerrain();
    ~visualtionRobotDansTerrain();
    virtual void algorithmeMainDroite(const terrain& terrain,const robot& robot) override;
    virtual void void algorithmeDePledge(const terrain& terrain,const robot& robot) override;
    virtual void sortirRobotDuLabyrinthe(const terrain& terrain,const robot& robot) override;

private:

};
#endif // VISUALISATIONROBOTDANSTERRAINDEPLACEMENTS_H
