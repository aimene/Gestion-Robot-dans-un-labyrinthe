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

<<<<<<< HEAD
    terrain();
    terrain(const point & position);
=======

    terrain(const string& nomFichier);
    terrain(const point & position, const string& nomFichier,const vector<vector<cases*>> terrainMatrice);
>>>>>>> 441206dc64c059e746062252a681b4c9c390f8b9
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
