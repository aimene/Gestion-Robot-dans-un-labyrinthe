#include "caseBordureMur.h"
#include "terrain.h"
#include "cases.h"

using geom::point;
using affichage::fenetre;

namespace gestionRobotTerrain
{
    caseBordureMur::caseBordureMur(int segment,bool murGauche,bool murDroit,bool murBas,bool murHaut):cases{segment},d_gauche{murGauche},d_droit{murDroit},d_bas{murBas},d_haut{murHaut}
    {}
    bool caseBordureMur::estMurGauche()const
    {
        return d_gauche;
    }
    bool caseBordureMur::estMurDroit() const
    {
        return d_droit;
    }
    bool caseBordureMur::estMurBas() const
    {
        return d_bas;
    }
    bool caseBordureMur::estMurHaut() const
    {
        return d_haut;
    }
    void caseBordureMur::changeMurBas(bool change)
    {
         d_bas=change;
    }
    void caseBordureMur::changeMurDroit(bool change)
    {
        d_haut = change;
    }
    void caseBordureMur::changeMurGauche(bool change)
    {
        d_gauche = change;
    }
    void caseBordureMur::changeMurHaut(bool change)
    {
        d_haut = change ;
    }
    void caseBordureMur::dessineCases(const fenetre& fenetre,const terrain& terrain)
    {
        int x1,y1,x2,y2
        point point1,point2;
        if(estMurGauche())
        {
            x1 = terrain.position().x();
            y1 = terrain.position().y();
            x2 = x1;
            y2 = y1 + terrain.hauteur();
            point1 = {x1,y2};
            point2 = {x2,y2}
            fenetre.dessineSegment(point1,point2);
        }
        else if(estMurHaut())
        {
          x1 = terrain.position().x();
          y1 = terrain.position().y();
          x2 = x1 + largeur();
          y2 = y1 + hauteur();
        }
        else if(estMurDroit())
        {

        }
        else if(estMurBas())
        {

        }

    }

}
