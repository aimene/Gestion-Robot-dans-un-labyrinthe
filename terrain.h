#ifndef TERRAIN_H
#define TERRAIN_H

#include <iostream>
#include "point.h"
#include <vector>
#include "cases.h"
#include<string>
#include "std.h"
using namespace geom;

namespace gestionRobotTerrain {
class terrain
{
public:


    terrain(const string& nomFichier);
    terrain(const point & position, const string& nomFichier,const vector<vector<cases*>> terrainMatrice);
    ~terrain();

    int hauteur() const;
    int largeur() const;
    const string& nomFichier() const;
    const vector<vector<cases*>> terrainMatrice() const ;

    vector<vector<cases*>> terrainMatriceModifieCase();


    void chanegrNomFichier(const string& nomFichier);

    bool litTerrain();
    void sauveTerrain() ;


    void dessineTerrain(fenetre& fenetre);

    static const string repertoire = "terrain/";
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
