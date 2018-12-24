#include "terrain.h"
#include <fstream>

using namespace std;
using gestionRobotTerrain::cases;
using gestionRobotTerrain::point;
namespace gestionRobotTerrain
{


terrain::terrain(const string& nomFichier):d_nomFichier{nomFichier}
{
    litTerrain(nomFichier);
}

terrain::terrain(const point& position, const string& nomFichier, const vector<vector<cases*> >terrainMatrice)
    :d_position{position}, d_nomFichier{nomFichier},d_terrain {terrainMatrice}
{
    changeHauteur(d_terrain[0].size());
    //changeLargeur(d_terrain[0][0].size());
}

terrain::~terrain()
{
    for(int i =0; i< hauteur(); ++i)
    {
        for(int j =0; j< largeur(); ++i)
        {
            delete terrainMatriceModifieCase()[i][j];
        }
    }
}

int terrain::hauteur() const
{
    return d_hauteur;
}

int terrain::largeur() const
{
    return d_largeur;
}

const string& terrain::nomFichier() const
{
    return d_nomFichier;
}

const vector< vector<cases*> > terrain::terrainMatrice() const
{
    return d_terrain;
}

vector<vector<cases*> > terrain::terrainMatriceModifieCase()
{
    return d_terrain;
}

void terrain::changeHauteur(int hauteur)
{
    d_hauteur=hauteur;
}

void terrain::changeLargeur(int largeur)
{
    d_largeur=largeur;
}

void terrain::changeNomFichier(const string& nomFichier)
{
    d_nomFichier = nomFichier;
    litTerrain(nomFichier);
}

bool terrain::litTerrain(const string& nomFichier)
{
    ifstream fichier(nomFichier.c_str()); // on ouvre le fichier en lecture

    if(fichier)  // si l'ouverture a réussi
    {
        fichier>> d_position;
        fichier>> d_hauteur;
        fichier>> d_largeur;
        string ligne ;
        for(int i=0 ; i<hauteur();++i )
        {
            fichier>>ligne ;
            if(terrainMatriceModifieCase()[0][0] typeof caseMur)
            {
                for(int j=0; j < largeur(); ++j)
                    if(ligne[j]=="1")
                        terrainMatriceModifieCase()[i][j].changeMur(true);
                    else
                        terrainMatriceModifieCase()[i][j].changeMur(false);

            else
            {
                for(int j=0; j < largeur(); j+4)
                {
                    if(ligne[j]=="1")
                        terrainMatriceModifieCase()[i][j].changeMurGauche(true);
                    else
                        terrainMatriceModifieCase()[i][j].changeMurGauche(false);
                    if(ligne[j+1]=="1")
                        terrainMatriceModifieCase()[i][j].changeMurHaut(true);
                    else
                        terrainMatriceModifieCase()[i][j].changeMurHaut(false);
                    if(ligne[j+2]=="1")
                        terrainMatriceModifieCase()[i][j].changeMurDroit(true);
                    else
                        terrainMatriceModifieCase()[i][j].changeMurDroit(false);
                    if(ligne[j+3]=="1")
                        terrainMatriceModifieCase()[i][j].changeMurBas(true);
                    else
                        terrainMatriceModifieCase()[i][j].changeMurBas(false);

                }
            }

        }

        fichier.close();  // on ferme le fichier
        return false ;
    }
    else  // sinon
        return false;

    // cerr << "Impossible d'ouvrir le fichier !" << endl;


}

void terrain::sauveTerrain()
{

}

void terrain::dessineTerrain(fenetre& fenetre)
{

}




}
