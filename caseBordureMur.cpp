#include "caseBordureMur.h"
#include "terrain.h"
#include"cases.h"
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
    void caseBordureMur::dessineCases(const fenetre& fenetre)

    {

    }

}
