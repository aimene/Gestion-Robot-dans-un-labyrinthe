#include "caseBordureMur.h"





namespace gestionRobotTerrain
{
    caseBordureMur::caseBordureMur(bool murGauche,bool murDroit,bool murBas,bool murHaut):d_gauche{murGauche},d_droit{murDroit},d_bas{murBas},d_haut{murHaut}
    {}
       caseBordureMur::~caseBordureMur()
    {

    }
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
        if(estMurGauche())
        {
            fenetre.dessineSegment(hautGauche(terrain,ligne,colonne),basGauche(terrain,ligne,colonne));
        }
        if(estMurHaut())
        {
           fenetre.dessineSegment(hautGauche(terrain,ligne,colonne),hautDroit(terrain,ligne,colonne));
        }
        if(estMurDroit())
        {
            fenetre.dessineSegment(hautDroit(terrain,ligne,colonne),basDroit(terrain,ligne,colonne));
        }
        if(estMurBas())
        {
          fenetre.dessineSegment(basDroit(terrain,ligne,colonne),basGauche(terrain,ligne,colonne));
        }

    }

}
