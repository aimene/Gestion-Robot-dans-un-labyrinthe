#ifndef TERRAIN_H
#define TERRAIN_H

#include <iostream>
#include "point.h"
#include <vector>
#include<string>
#include "cases.h"

namespace gestionRobotTerrain {
    using std::string ;
    using std::vector;
    using geom::point;
    using affichage::fenetre ;
class terrain
{
    class cases ;
public:
    terrain(const string& nomFichier);
    terrain(const point & position, const string& nomFichier,const vector<vector<cases*>> terrainMatrice);
    ~terrain();

    int hauteur() const;
    int largeur() const;
    const string& nomFichier() const;
    const vector< vector<gestionRobotTerrain::cases*> > terrainMatrice() const ;

    vector< vector<cases*> > terrainMatriceModifieCase();


    void changeNomFichier(const string& nomFichier);

    bool litTerrain(const string& nomFichier);
    void sauveTerrain() ;


    void dessineTerrain(fenetre& fenetre);

    static const string repertoire ;
private:
    void changeHauteur( int hauteur);
    void changeLargeur( int largeur);

    point d_position;
    string d_nomFichier;
    vector<vector<gestionRobotTerrain::cases*> > d_terrain;
    int d_largeur,d_hauteur;
};
}
#endif // TERRAIN_H
