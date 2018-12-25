#include "caseBordureMur.h"





namespace gestionRobotTerrain
{
    caseBordureMur::caseBordureMur(bool murGauche,bool murDroit,bool murBas,bool murHaut):d_gauche{murGauche},d_droit{murDroit},d_bas{murBas},d_haut{murHaut}
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
            x1 = terrain.position().x() + colonne * terrain.tailleCase();
            y1 = terrain.position().y() + ligne * terrain.tailleCase();
            x2 = x1;
            y2 = y1 + terrain.tailleCase();
            hautGauche = {x1,y2};
            basGauche= {x2,y2};
            fenetre.dessineterrain.tailleCase(hautGauche,basGauche);
        }
        else if(estMurHaut())
        {
          x1 = terrain.position().x() + colonne *terrain.tailleCase();
          y1 = terrain.position().y() + ligne * terrain.tailleCase();
          x2 = x1 + colonne * terrain.tailleCase() + terrain.tailleCase();
          y2 = y1 + terrain.tailleCase() ;
          hautGauche = {x1,y2};
          hautDroit = {x2,y2};
          fenetre.dessineterrain.tailleCase(hautGauche,hautDroit);
        }
        else if(estMurDroit())
        {
            x1 = terrain.position().x() + colonne * terrain.tailleCase() + terrain.tailleCase();
            y1 = terrain.position().y() + colonne * terrain.tailleCase();
            x2 = x1;
            y2 = y1 + ligne * terrain.tailleCase() + terrain.tailleCase();
            hautDroit = {x1,y2};
            basDroit = {x2,y2};
            fenetre.dessineterrain.tailleCase(hautDroit,basDroit);
        }
        else if(estMurBas())
        {
           x1 = terrain.position().x() + colonne * terrain.tailleCase() + terrain.tailleCase();
           y1 = terrain.position().y() + ligne * terrain.tailleCase();
           x2 = terrain.position().x() + colonne * terrain.tailleCase();
           y2 = terrain.position().y()+ ligne * terrain.tailleCase() + terrain.tailleCase();
           basDroit = {x1,y2};
           basGauche = {x2,y2};
           fenetre.dessineterrain.tailleCase(basDroit,basGauche);
        }

    }

}
