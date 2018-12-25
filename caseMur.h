#ifndef CASEMUR_H
#define CASEMUR_H
#include "cases.h"
namespace gestionRobotTerrain
{

class caseMur : public cases
{
    public:
        caseMur(int segment, bool mur = true);
        ~caseMur();
        virtual void dessineCases(const fenetre& fenetre) ;
        bool estMur() const ;
        void changerMurValeur(bool change) ;
    private:
        bool d_mur ; // vrai si mur
};
}
#endif // CASEMUR_H
