#include <iostream>
#include"terrain.h"
#include <cstdlib>
#include"cases.h"
#include"fenetre.h"
#include"robot.h"
#include"point.h"
using namespace std;
using namespace gestionRobotTerrain;
using namespace affichage;
using namespace geom;
int main()
{
    while (1)
    {
        char choix [2];

        cout << "::Menu::\n\n"
             << " 1. Choisisez le labyrinthe\n"
             << " 2. Choisisez le robot de votre choix\n"
             << " 3. Choisiser l'algorithme de votre choix\n"
             << " 4. Quitter le programme\n\n"
             << " Saisisez votre choix: ";
        cin >> choix;

        if (choix[0] == '1')
        {
            char choixSousMenu [3];
            system("CLS");
            cout << "Vous avez le choix entre: \n"
                 << " 1. Un labyrinthe dont les murs sont des cases du terrrain\n"
                 << " 2. Un labyrinthe dont les murs sont autours des cases et les separent\n"
                 << " Saisisez votre choix: ";
            cin >> choixSousMenu;
            system("PAUSE");
            system("CLS");

        }
        else if (choix[0] == '2')
        {
            char choixSousMenu [4];
            system("CLS");
            cout << "Vous avez le choix entre: \n"
                 << " 1. Un robot standard\n"
                 << " 2. Un robot avance\n"
                 << " Saisisez votre choix: ";
            cin >> choixSousMenu;
            system("PAUSE");
            system("CLS");
        }
        else if (choix[0] == '3')
        {
            char choixSousMenu [4];
            system("CLS");
            cout << "Vous avez le choix entre: \n"
                 << " 1. Algorithme main droite\n"
                 << " 2. Algorithme de Pledge\n"
                 << " Saisisez votre choix: ";
            cin >> choixSousMenu;
            system("PAUSE");
            system("CLS");
        }
        else if (choix[0] == '4')
        {
            return 0;
        }
        else if (choix[0] > '4' || choix [0] < '1') // validation de l'utilisateur
        {
            system("CLS");
            cout << " Saisi Invalide veuillez saisir un numero correspondant\n\n";
            system("PAUSE");
        }
        else
        {
            system("CLS");
            cout << " Saisi Invalide veuillez saisir un numero correspondant\n\n";
            system("PAUSE");
            system("CLS");
        }

    }


  /*fenetre fenetre {900,900};
  terrain terrain{"terrain0.txt"};
  terrain.dessineTerrain(fenetre);*/


    fenetre fenetre {900,500};
    point positionRobot{150,150};
    robot robot{positionRobot,1};
    terrain terrain{"terrain0.txt"};
     fenetre.open();
    terrain.dessineTerrain(fenetre);

    std::cout<<" main dessineTerrain = "<< std::endl;
    std::cout<<" maine dessine robot "<< std::endl;
    robot.dessineRobot(terrain,fenetre);
    fenetre.repeteJusquaBouton();

    return 0;

}
