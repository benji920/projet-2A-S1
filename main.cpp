#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cstdlib>
#include <vector>
#include <fstream>

#include "Carte.h"
#include "Attaque.h"
#include "Archer.h"
#include "Cavalier.h"
#include "Arbaletrier.h"
#include "Catapulte.h"
#include "Belier.h"
#include "Arthur_Pendragon.h"
#include "Jeanne_D_arc.h"
#include "Lancelot_duLac.h"
#include "Joueur.h"
#include "Guerrier.h"
#include "Jeu.h"
#include "Energie.h"
#include "Match.h"
#include "console.h"


int main()
{

int choix=30;//Variable pour choisir dans le menu



while(choix!=0){


    Match M;//Création d'un match

    menu();//Affichage du menu principal
    choix=Choisir();//Choix du joueur dans le menu


    system("cls");//On efface l'ecran
    switch (choix)//Switch pour afficher ce que le joueur a choisi
    {

    case 1:
        inscrire();//Méthode pour inscrire un joueur et pour qu'il puisse jouer

    break;

    case 2:
{
    connecter();//Méthode pour connecter le joueur s'il est déjà inscrit. Il pourra achter des cartes et regarder sa collection
    break;
}

    case 3 :
        {

        M.LancerMatch();//Lance un match pour 2 joueurs
    break;
    }
    case 4 ://Affichage des regles
        {
            Regles();
        }
        break;
    }
}



    return 0;
}
