#ifndef TERRAIN_H
#define TERRAIN_H
#include<string.h>

#include <fstream>

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


    terrain();
    terrain(const string& nomFichier);
    terrain(const point & position, const string& nomFichier, int type ,int tailleCase ,const vector<vector<cases*> > terrainMatrice);
    ~terrain();

    int hauteur()  const;
    int largeur()  const;
    int type () const ;
    int tailleCase() const ;
    const point& position() const;
    const string& nomFichier() const;
    const vector<vector<gestionRobotTerrain::cases*> >& terrainMatrice() const ;

    vector<vector<cases*> >& terrainMatriceModifieCase();


    void changeNomFichier(const string& nomFichier);

    bool litTerrain();
    void litCaseMur(std::ifstream& fichier,string& ligne);
    void litCaseBordureMur(std::ifstream& fichier,string& ligne);

    void sauveTerrain() ;


    void dessineTerrain(fenetre& fenetre);

    const  int typeCaseMur = 1 ;
    const  int typeCaseBordureMur = 0 ;
    const  char isMur ='1';
    const string repertoire ="terrain/";
private:
    void changeHauteur( int hauteur);
    void changeLargeur( int largeur);


    int d_type; // 1 pour terran avec des cases murs
    point d_position;
    int d_largeur,d_hauteur, d_tailleCase;
    vector<vector<cases*> > d_terrain;
    string d_nomFichier;
};
}
#endif // TERRAIN_H
