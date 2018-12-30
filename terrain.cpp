#include "terrain.h"
#include"caseMur.h"
#include"caseBordureMur.h"
using namespace std;

namespace gestionRobotTerrain
{

terrain::terrain():d_type{},d_position{},d_largeur{},d_hauteur{},d_tailleCase{},d_terrain{},d_nomFichier{}
{}
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

void terrain::changeNomFichier(const string& nomFichier)
{
    d_nomFichier = nomFichier;
    litTerrain();
}

bool terrain::litTerrain()
{
    std::cout<<"avvant de lire le ficher " << std::endl;
    ifstream fichier(string{repertoire+d_nomFichier}); // on ouvre le fichier en lecture

    if(fichier)  // si l'ouverture a réussi
    {

        fichier>> d_position;
        std::cout<<"d_position = " <<d_position<< std::endl;
        fichier>> d_hauteur;

        fichier>>d_largeur;
        fichier>>d_type;
        fichier>>d_tailleCase;
        string ligne ;


        if(type()==typeCaseMur)
            litCaseMur(fichier,ligne);
        else
        {
            if(type()==typeCaseBordureMur)
                litCaseBordureMur(fichier,ligne);
        }


        std::cout<<"fin = " << std::endl;
        fichier.close();
        return true ;
    }
    else
        return false;
}

void terrain::litCaseMur(std::ifstream& fichier,string& ligne)
{
    std::cout<<" litCaseMur " << std::endl;
    for(int i=0 ; i< hauteur(); ++i )
    {
        fichier>>ligne;
        vector<cases*> colonne ;
        colonne.reserve(largeur());

        for(int j=0; j < largeur(); ++j)
        {
            caseMur* caseMurs = new caseMur{false};

            if(ligne[j]==isMur)
                caseMurs->changeMurValeur(true);
            else
                caseMurs->changeMurValeur(false);

            colonne.push_back(caseMurs);

        }
        d_terrain.push_back(colonne);

    }

}

void terrain::litCaseBordureMur(std::ifstream& fichier,string& ligne)
{
    for(int i=0 ; i< hauteur(); ++i )
    {
        fichier>>ligne;
        vector<cases*> colonne ;
        colonne.reserve(largeur());
        std::cout<<" largeur() " << largeur()<<std::endl;

        for(int j=0; j <largeur()*4; j+=4)
        {

            caseBordureMur* caseborduremur= new caseBordureMur{false,false,false,false};
            if(ligne[j]==isMur)
                caseborduremur->changeMurGauche(true);
            else
                caseborduremur->changeMurGauche(false);

            if(ligne[j+2]==isMur)
                caseborduremur->changeMurDroit(true);
            else
                caseborduremur->changeMurDroit(false);

            if(ligne[j+1]==isMur)
                caseborduremur->changeMurBas(true);
            else
                caseborduremur->changeMurBas(false);

            if(ligne[j+3]==isMur)
                caseborduremur->changeMurHaut(true);
            else
                caseborduremur->changeMurHaut(false);

            colonne.push_back(caseborduremur);
        }
        d_terrain.push_back(colonne);
    }
}

void terrain::sauveTerrain()
{

    ofstream fichier(string{repertoire+nomFichier()+".txt"});
    fichier<<nomFichier()<<endl;
    fichier<<position()<<endl;
    fichier<<hauteur()<<endl;
    fichier<<largeur()<<endl;
    fichier<<type()<<endl;
    fichier<<tailleCase()<<endl;
    for(int i = 0; i<hauteur(); ++i)
    {
        for(int j = 0 ; j<largeur(); ++j)
        {
            fichier<<terrainMatrice()[i][j];
        }
        fichier<<endl;
    }
    fichier.close();
}

void terrain::dessineTerrain(fenetre& fenetre)
{
    for(int i = 0 ; i< hauteur(); ++i)
    {
        for(int j = 0 ; j< largeur(); ++j)
        {
            d_terrain[i][j]->dessineCases(fenetre, *this, i, j);
        }
    }
}




}
