#include <iostream>
#include"terrain.h"
#include <cstdlib>
#include"cases.h"
#include"fenetre.h"

#include"robot.h"

#include"point.h"
#include"programmeVisualisationRobotDeplacements.h"
#include"programmeVisualisationRobotAvanceDeplacements.h"

#include "programmeVisualisationRobot.h"
#include "programmeVisualisationRobotAvance.h"

using namespace std;
using  gestionRobotTerrain::terrain;

using  gestionRobotTerrain::robot;
using  gestionRobotTerrain::robotAvance;

using  gestionRobotTerrain::programmeVisualisationRobot;
using  gestionRobotTerrain::programmeVisualisationRobotAvance;
using  gestionRobotTerrain::programmeVisualisationRobotAvanceDeplacements;
using  gestionRobotTerrain::programmeVisualisationRobotDepacements;
using namespace affichage;
using affichage::fenetre;
using namespace geom;
int main()
{
    while (1)
    {
        int choixTerrain;
        int choixRobot;
        int choixAlgos;

        while (choixTerrain!=1 && choixTerrain!=2 && choixTerrain!=0)
        {

            system("CLS");
            cout << "Vous avez le choix entre: \n"
                 << " 1. Un labyrinthe dont les murs sont des cases du terrrain\n"
                 << " 2. Un labyrinthe dont les murs sont autours des cases et les separent\n"
                 << " 0. Quitter\n"

                 << " Saisisez votre choix: ";
            cin >> choixTerrain;
        }
        if(choixTerrain==0)
            break ;
        while (choixRobot!=1 && choixRobot!=2 && choixRobot!=0)
        {

            system("CLS");
            cout << "Vous avez le choix entre: \n"
                 << " 1. Un robot standard\n"
                 << " 2. Un robot avance\n"
                 << " 0. Quitter\n"
                 << " Saisisez votre choix: ";
            cin >> choixRobot;


        }
        if(choixRobot==0)
            break ;

        while (choixAlgos!=1 && choixAlgos!=2 && choixAlgos!=3 && choixAlgos!=4 && choixAlgos!=0)
        {

            system("CLS");
            cout << "Vous avez le choix entre: \n"
                 << " 1. Algorithme de main droite\n"
                 << " 2. Algorithme de Pledge\n"
                 << " 3. Algorithme de main droite avec déplacements\n"
                 << " 4. Algorithme de Pledge avec déplacements\n"
                 << " 0. Quitter\n"
                 << " Saisisez votre choix: ";
            cin >> choixAlgos;


        }
        if(choixAlgos==0)
            break ;

        fenetre fenetre {900,800};
        terrain terrain{} ;
          fenetre.open();
        terrain.dessineTerrain(fenetre);

        point position{50,550};
        if(choixTerrain==1)
        {
            terrain.changeNomFichier("terrainCaseMur1final.txt");
        }
        if(choixTerrain==2)
        {
         terrain.changeNomFichier("terrainBordureMur1final.txt");
        }
        if(choixRobot==1)
        {
            robot robot{position,1};

            if(choixAlgos==1 || choixAlgos==3)
            {
                programmeVisualisationRobot  prog{fenetre};
                if(choixAlgos==1)
                {

                    prog.runAlgoMainDroite(terrain , robot);
                }
                if(choixAlgos==3)
                {
                    prog.runAlgoPledge(terrain , robot);
                }
            }
            if(choixAlgos==2 || choixAlgos==4)
            {
                programmeVisualisationRobotDepacements  progs {fenetre};
                if(choixAlgos==2)
                {

                    progs.runAlgoMainDroite(terrain,robot);
                }
                if(choixAlgos==4)
                {
                    progs.runAlgoPledge(terrain,robot);
                }
            }

        }

        if(choixRobot==2)
        {
            robotAvance robot{position,1};

            if(choixAlgos==1 || choixAlgos==3)
            {
                programmeVisualisationRobotAvance  prog {fenetre};
                if(choixAlgos==1)
                {

                    prog.runAlgoMainDroite(terrain, robot);
                }
                if(choixAlgos==3)
                {
                    prog.runAlgoPledge(terrain, robot);
                }
            }
            if(choixAlgos==2 || choixAlgos==4)
            {
                programmeVisualisationRobotAvanceDeplacements  progs {fenetre};
                if(choixAlgos==2)
                {

                    progs.runAlgoMainDroite(terrain, robot);
                }
                if(choixAlgos==4)
                {
                    progs.runAlgoPledge(terrain, robot);
                }
            }

        }

    }


}
