#ifndef TERRAIN_H
#define TERRAIN_H

#include <iostream>
#include "point.h"
#include <vector>
#include <string>
#include "cases.h"

namespace gestionRobotTerrain {
    using std::string;
    using std::vector;
    using geom::point;
    using affichage::fenetre;
class terrain
{
public:

    terrain(const string& nomFichier);
    terrain(const point& position, const string& nomFichier,const vector<vector<cases*> > terrainMatrice);
    ~terrain();

    int hauteur() const;
    int largeur() const;
    const string& nomFichier() const;
    const vector<vector<cases*> > terrainMatrice() const ;

    vector<vector<gestionRobotTerrain::cases*> > terrainMatriceModifieCase();


    void changeNomFichier(const string& nomFichier);

    bool litTerrain();
    void sauveTerrain() ;


    void dessineTerrain(fenetre& fenetre);

    static const string repertoire ;
private:
    void changeHauteur( int hauteur);
    void changeLargeur( int largeur);

    point d_position;
    int d_largeur,d_hauteur;
    vector<vector<gestionRobotTerrain::cases*> > d_terrain;
    string d_nomFichier;
};

}
#endif // TERRAIN_H
