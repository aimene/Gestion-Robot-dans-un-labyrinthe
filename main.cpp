#include <iostream>
#include"terrain.h"
#include <cstdlib>
#include"cases.h"
#include"fenetre.h"

using namespace std;
using namespace gestionRobotTerrain;
using namespace affichage;
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

        }
        else if (choix[0] == '3')
        {

        }
        else if (choix[0] == '3')
        {

        }
        else if (choix[0] > '1' || choix [0] < '1') // validation de l'utilisateur
        {

        }
        else
        {

        }

    }

  /*fenetre fenetre {900,900};
  terrain terrain{"terrain0.txt"};
  terrain.dessineTerrain(fenetre);*/

}
