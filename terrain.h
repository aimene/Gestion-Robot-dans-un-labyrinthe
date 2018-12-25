#ifndef TERRAIN_H
#define TERRAIN_H

#include <iostream>
#include "point.h"
#include <vector>
#include<string.h>
#include"cases.h"

using namespace affichage ;
using namespace geom ;

namespace affichage { class fenetre; }
namespace geom { class point ;}

namespace gestionRobotTerrain {
    using std::string ;
    using std::vector;

class cases ;
class terrain
{

public:



    terrain(const string& nomFichier);
    terrain(const point & position, const string& nomFichier,const vector<vector<cases*> > terrainMatrice);
    ~terrain();

    int hauteur()  const;
    int largeur()  const;
    const point& position() const;
    const string& nomFichier() const;
    const vector<vector<gestionRobotTerrain::cases*> >& terrainMatrice() const ;

    vector<vector<cases*> >& terrainMatriceModifieCase();


    void changeNomFichier(const string& nomFichier);

    bool litTerrain();
    void sauveTerrain() ;


    void dessineTerrain(fenetre& fenetre);

     const string repertoire ="terrain/";
private:
    void changeHauteur( int hauteur);
    void changeLargeur( int largeur);

    point d_position;
    int d_largeur,d_hauteur;
    vector<vector<cases*> > d_terrain;
    string d_nomFichier;
};
}
#endif // TERRAIN_H
