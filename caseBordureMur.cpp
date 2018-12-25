#include "caseBordureMur.h"





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
    void caseBordureMur::dessineCases(const fenetre& fenetre,const terrain& terrain,int ligne,int colonne) const
    {
        int x1,y1,x2,y2;
        point basGauche,hautGauche,basDroit,hautDroit;
        if(estMurGauche())
        {
            x1 = terrain.position().x() + colonne * segment();
            y1 = terrain.position().y() + ligne * segment();
            x2 = x1;
            y2 = y1 + segment();
            hautGauche = {x1,y2};
            basGauche= {x2,y2};
            fenetre.dessineSegment(hautGauche,basGauche);
        }
        else if(estMurHaut())
        {
          x1 = terrain.position().x() + colonne *segment();
          y1 = terrain.position().y() + ligne * segment();
          x2 = x1 + colonne * segment() + segment();
          y2 = y1 + segment() ;
          hautGauche = {x1,y2};
          hautDroit = {x2,y2};
          fenetre.dessineSegment(hautGauche,hautDroit);
        }
        else if(estMurDroit())
        {
            x1 = terrain.position().x() + colonne * segment() + segment();
            y1 = terrain.position().y() + colonne * segment();
            x2 = x1;
            y2 = y1 + ligne * segment() + segment();
            hautDroit = {x1,y2};
            basDroit = {x2,y2};
            fenetre.dessineSegment(hautDroit,basDroit);
        }
        else if(estMurBas())
        {
           x1 = terrain.position().x() + colonne * segment() + segment();
           y1 = terrain.position().y() + ligne * segment();
           x2 = terrain.position().x() + colonne * segment();
           y2 = terrain.position().y()+ ligne * segment() + segment();
           basDroit = {x1,y2};
           basGauche = {x2,y2};
           fenetre.dessineSegment(basDroit,basGauche);
        }

    }

}
