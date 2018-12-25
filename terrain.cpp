#include "terrain.h"
#include <fstream>
#include<vector>
#include"cases.h"
#include<string.h>
#include"caseMur.h"
#include"caseBordureMur.h"
using namespace std;

namespace gestionRobotTerrain
{
    using std::string;
    using std::vector;

terrain::terrain(const string& nomFichier):d_nomFichier{nomFichier}
{
    litTerrain();
}

terrain::terrain(const point & position, const string& nomFichier,const vector<vector<cases*> > terrainMatrice)
    :d_position{position}, d_nomFichier{nomFichier},d_terrain {terrainMatrice}
{
<<<<<<< HEAD
    changeHauteur(d_terrain.size());
    changeLargeur(d_terrain[0].size());
=======
    changeHauteur(d_terrain[0].size());
    //changeLargeur(d_terrain[0][0].size());
>>>>>>> b4992c3b0418af10806689722c8bfd7374af0f2e
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
<<<<<<< HEAD
const vector<vector<cases*> >& terrain::terrainMatrice() const
=======

const vector<vector<cases*> > terrain::terrainMatrice() const
>>>>>>> b4992c3b0418af10806689722c8bfd7374af0f2e
{
    return d_terrain;
}

<<<<<<< HEAD
vector<vector<cases*> >& terrain::terrainMatriceModifieCase()
=======
vector < vector<cases*> > terrain::terrainMatriceModifieCase()
>>>>>>> b4992c3b0418af10806689722c8bfd7374af0f2e
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

void terrain::chanegrNomFichier(const string& nomFichier)
{
    d_nomFichier = nomFichier;
    litTerrain();
}

bool terrain::litTerrain()
{
    ifstream fichier(string{repertoire+d_nomFichier}); // on ouvre le fichier en lecture

    if(fichier)  // si l'ouverture a réussi
    {
        fichier>> d_position;
        fichier>> d_hauteur;
        fichier>> d_largeur;
        string ligne ;
        for(int i=0 ; i< hauteur();++i )
        {

              getline(fichier, ligne);
             char isMur ='1';
            //char  isNotMur="0";
            if( d_terrain[0][0] )
            {
                for(int j=0; j < largeur(); ++j)
                   {
                       if(ligne[j]==isMur)
                       ((caseMur*)d_terrain[i][j])->changerMurValeur(true);
                    else
<<<<<<< HEAD
                        ((caseMur*)d_terrain[i][j])->changerMurValeur(false);
                   }
            }
=======
                        terrainMatriceModifieCase()[i][j].changeMur(false);
            }

>>>>>>> b4992c3b0418af10806689722c8bfd7374af0f2e
            else
            {
                for(int j=0; j < largeur(); j+4)
                {
                    if(ligne[j]==isMur)
                     ((caseBordureMur*)   terrainMatriceModifieCase()[i][j])->changeMurGauche(true);
                    else
                       ((caseBordureMur*)terrainMatriceModifieCase()[i][j])->changeMurGauche(false);
                    if(ligne[j+1]==isMur)
                       ((caseBordureMur*)terrainMatriceModifieCase()[i][j])->changeMurHaut(true);
                    else
                       ((caseBordureMur*)terrainMatriceModifieCase()[i][j])->changeMurHaut(false);
                    if(ligne[j+2]==isMur)
                       ((caseBordureMur*)terrainMatriceModifieCase()[i][j])->changeMurDroit(true);
                    else
                       ((caseBordureMur*)terrainMatriceModifieCase()[i][j])->changeMurDroit(false);
                    if(ligne[j+3]==isMur)
                       ((caseBordureMur*)terrainMatriceModifieCase()[i][j])->changeMurBas(true);
                    else
                       ((caseBordureMur*)terrainMatriceModifieCase()[i][j])->changeMurBas(false);

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
