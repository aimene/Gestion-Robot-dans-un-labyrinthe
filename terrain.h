#ifndef TERRAIN_H
#define TERRAIN_H

#include <iostream>
#include "point.h"
#include <vector>
#include <string>
#include "cases.h"

using namespace affichage ;
using namespace geom ;

namespace affichage { class fenetre; }
namespace geom { class point ;}

namespace gestionRobotTerrain {
    using std::string;
    using std::vector;
<<<<<<< HEAD

class cases ;
class terrain
{

=======
    using geom::point;
    using affichage::fenetre;
class terrain
{
>>>>>>> b4992c3b0418af10806689722c8bfd7374af0f2e
public:

    terrain(const string& nomFichier);
<<<<<<< HEAD
    terrain(const point & position, const string& nomFichier,const vector<vector<cases*> > terrainMatrice);
=======
    terrain(const point& position, const string& nomFichier,const vector<vector<cases*> > terrainMatrice);
>>>>>>> b4992c3b0418af10806689722c8bfd7374af0f2e
    ~terrain();

    int hauteur() const;
    int largeur() const;
    const string& nomFichier() const;
<<<<<<< HEAD
    const vector<vector<gestionRobotTerrain::cases*> >& terrainMatrice() const ;

    vector<vector<cases*> >& terrainMatriceModifieCase();
=======
    const vector<vector<cases*> > terrainMatrice() const ;

    vector<vector<gestionRobotTerrain::cases*> > terrainMatriceModifieCase();
>>>>>>> b4992c3b0418af10806689722c8bfd7374af0f2e


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
    vector<vector<gestionRobotTerrain::cases*> > d_terrain;
    string d_nomFichier;
};

}
#endif // TERRAIN_H
