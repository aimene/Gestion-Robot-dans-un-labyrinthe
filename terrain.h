#ifndef TERRAIN_H
#define TERRAIN_H

#include <iostream>
#include "point.h"
#include <vector>
#include "cases.h"
#include "std.h"
using namespace geom;
class terrain
{
public:

    terrain();
    terrain(const point & position);
    terrain()
    ~terrain();
    int hauteur() const;
    int largeur() const;
    void changerHauteur( int hauteur);
    void changerLargeur( int largeur);
    void litTerrain(const string& nomFichier);
    void sauveTerrain() ;
   string nomFichier() const;
// accesseur et manipulateur terrain
   void dessineTerrain(fenetre& fenetre);
   void chanegrNomFichier(const string& nomFichier);

private:
    point d_position
    int largeur,hauteur;
    vector<vector<cases*> > d_terrain;
    string& d_nomFichier;
};

#endif // TERRAIN_H
