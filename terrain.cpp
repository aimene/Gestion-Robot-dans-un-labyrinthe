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


terrain::terrain(const string& nomFichier):d_nomFichier{nomFichier}
{
    litTerrain();
}

terrain::terrain(const point & position, const string& nomFichier,int type,int tailleCase,const vector<vector<cases*> > terrainMatrice)
    :d_position{position}, d_nomFichier{nomFichier},d_type{type},d_tailleCase{tailleCase}, d_terrain {terrainMatrice}
{
    changeHauteur(d_terrain.size());
    changeLargeur(d_terrain[0].size());
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
const point& terrain::position() const
{
    return d_position;
}
const string& terrain::nomFichier() const
{
    return d_nomFichier;
}
int terrain::type() const
{
    return d_type ;
}
int terrain::tailleCase() const
{
    return d_tailleCase;
}
const vector<vector<cases*> >& terrain::terrainMatrice() const
{
    return d_terrain;
}


vector<vector<cases*> >& terrain::terrainMatriceModifieCase()

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
        char isMur ='1';
        fichier>> d_position;
        fichier>> d_hauteur;
        fichier>> d_largeur;
        fichier>> d_type;
        string ligne ;

        if(type()==1)
        {
            for(int i=0 ; i< hauteur(); ++i )
            {
                getline(fichier, ligne);

                for(int j=0; j < largeur(); ++j)
                {
                    caseMur* caseMurs = new caseMur{false};
                    if(ligne[j]==isMur)
                        caseMurs->changeValeurMur(true);
                    else
                        caseMurs->changeValeurMur(false);

                    d_terrain[i][j]=caseMurs;
                }
            }
        }
        else
        {
            for(int i=0 ; i< hauteur(); ++i )
            {
                getline(fichier, ligne);

                for(int j=0; j < largeur(); j+4)
                {
                    caseBordureMur* caseborduremur= new caseBordureMur{false,false,false,false};
                    if(ligne[j]==isMur)
                        caseborduremur->changeMurGauche(true);
                    else
                       caseborduremur->changeMurGauche(false);
                    if(ligne[j+1]==isMur)
                        caseborduremur->changeMurHaut(true);
                    else
                       caseborduremur->changeMurHaut(false);
                    if(ligne[j+2]==isMur)
                      caseborduremur->changeMurDroit(true);
                    else
                       caseborduremur->changeMurDroit(false);
                    if(ligne[j+3]==isMur)
                      caseborduremur->changeMurBas(true);
                    else
                       caseborduremur->changeMurBas(false);

                   terrainMatriceModifieCase()[i][j]=caseborduremur;
                }

            }
        }
        fichier.close();
        return true ;
    }
    else
        return false;
}

void terrain::sauveTerrain()
{

}

void terrain::dessineTerrain(fenetre& fenetre)
{

}




}
