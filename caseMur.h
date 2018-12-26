#ifndef CASEMUR_H
#define CASEMUR_H
#include "cases.h"
namespace gestionRobotTerrain
{

class caseMur : public cases
{
    public:
        caseMur( bool mur = true);
        ~caseMur();
        virtual void dessineCases(const fenetre& fenetre,const terrain& terrain,int ligne,int colonne)const override ;
        void dessineMur(const fenetre& fenetre,const terrain& terrain, int ligne , int colonne) const ;
        bool estMur() const ;
        void changeMurValeur(bool change) ;



    private:
        bool d_mur ; // vrai si mur
};
}
#endif // CASEMUR_H
