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
    void caseBordureMur::dessineBordureGauche(const fenetre& fenetre,const terrain& terrain,int ligne,int colonne) const
    {
           point hautGauche,basGauche;
            int x1 = terrain.position().x() + colonne * terrain.tailleCase();
            int y1 = terrain.position().y() + ligne * terrain.tailleCase();
            int x2 = x1;
            int y2 = y1 + terrain.tailleCase();
            hautGauche = {x1,y2};
            basGauche= {x2,y2};
            fenetre.dessineSegment(hautGauche,basGauche);
    }
    void caseBordureMur::dessineBordureHaute(const fenetre& fenetre,const terrain& terrain,int ligne,int colonne) const
    {
        point hautGauche,hautDroit;
        int x1 = terrain.position().x() + colonne *terrain.tailleCase();
          int y1 = terrain.position().y() + ligne * terrain.tailleCase();
          int x2 = x1 + colonne * terrain.tailleCase() + terrain.tailleCase();
         int  y2 = y1 + terrain.tailleCase() ;
          hautGauche = {x1,y2};
          hautDroit = {x2,y2};
          fenetre.dessineSegment(hautGauche,hautDroit);
    }
    void caseBordureMur::dessineBordureDroite(const fenetre& fenetre,const terrain& terrain,int ligne,int colonne) const
    {
        point hautDroit,basDroit;
        int x1 = terrain.position().x() + colonne * terrain.tailleCase() + terrain.tailleCase();
            int y1 = terrain.position().y() + colonne * terrain.tailleCase();
            int x2 = x1;
            int y2 = y1 + ligne * terrain.tailleCase() + terrain.tailleCase();
            hautDroit = {x1,y2};
            basDroit = {x2,y2};
            fenetre.dessineSegment(hautDroit,basDroit);
    }
    void caseBordureMur::dessineBordureBasse(const fenetre& fenetre,const terrain& terrain,int ligne,int colonne) const
    {
        point basDroit,basGauche;
        int x1 = terrain.position().x() + colonne * terrain.tailleCase() + terrain.tailleCase();
           int y1 = terrain.position().y() + ligne * terrain.tailleCase()+ terrain.tailleCase();
           int x2 = terrain.position().x() + colonne * terrain.tailleCase();
           int y2 = terrain.position().y()+ ligne * terrain.tailleCase() + terrain.tailleCase();
           basDroit = {x1,y2};
           basGauche = {x2,y2};
           fenetre.dessineSegment(basDroit,basGauche);
    }
    void caseBordureMur::dessineCases(const fenetre& fenetre,const terrain& terrain,int ligne,int colonne) const
    {
        if(estMurGauche())
            dessineBordureGauche(fenetre,terrain,ligne,colonne);

        if(estMurHaut())
          dessineBordureDroite(fenetre,terrain,ligne,colonne);

        if(estMurDroit())
           dessineBordureDroite(fenetre,terrain,ligne,colonne);

        if(estMurBas())
           dessineBordureBasse(fenetre,terrain,ligne,colonne);

    }

}
