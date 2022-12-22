#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cstdlib>


#include "Carte.h"
#include "Attaque.h"
#include "Archer.h"
#include "Cavalier.h"
#include "Arbaletrier.h"
#include "Catapulte.h"
#include"Belier.h"
#include"Arthur_Pendragon.h"
#include "Jeanne_D_arc.h"
#include "Lancelot_duLac.h"
#include "Joueur.h"
#include <vector>
#include "Guerrier.h"

#include "Energie.h"
#include <fstream>
#include "Match.h"
#include "console.h"



void gotoligcol( int lig, int col )
{
// ressources
COORD mycoord;

mycoord.X = col;
mycoord.Y = lig;
SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void afficherCol(int x, int y)
{
    for(int i=0;i<9;i++)
    {gotoligcol(x+i,y);
    std::cout << "|" << std::endl;
    Sleep(50);}

}

void Afficher(int curs,int x, int y)
{


    gotoligcol(x,y);
    printf("%c",(curs==1)?'>':' ');
    gotoligcol(x+1,y);
    printf("%c",(curs==2)?'>':' ');
    gotoligcol(x+2,y);
    printf("%c",(curs==3)?'>':' ');
    gotoligcol(x+3,y);
    printf("%c",(curs==4)?'>':' ');
    gotoligcol(x+4,y);
    printf("%c",(curs==0)?'>':' ');

}

int Choisir()
{
    int curs = 1;
    int x=15;
    int y=63;
    int touche;
    do
    {
        Afficher(curs, x , y);
        touche = _getch();
        if (touche==0xE0) // fleche : le code fleche renvoie 2 caracteres.
        {
            touche = _getch();
            if (touche==0x50 && curs==1)  // fleche bas
                curs = 2;
            else if (touche==0x50 && curs==2)  // fleche bas
                curs = 3;
                else if (touche==0x50 && curs==3)  // fleche bas
                curs = 4;
                else if (touche==0x50 && curs==4)  // fleche bas
                curs = 0;
            else if (touche==0x48 && curs==2)  // fleche haut
                curs = 1;
                else if (touche==0x48 && curs==0)  // fleche haut
                curs = 4;
                else if (touche==0x48 && curs==4)  // fleche haut
                curs = 3;
                else if (touche==0x48 && curs==3)  // fleche haut
                curs = 2;
        }
    } while (touche!=0x0D);  // enter
    return curs;
}

void menu()
{
    system("cls");
    gotoligcol(2,28);
    std::cout << ">=>             >>                       >===>     >=>     >=> >=======> >===>>=====> >=======> " << std::endl;
    gotoligcol(3,28);
    std::cout << ">=>            >>=>                    >=>    >=>  >=>     >=> >=>            >=>     >=>" << std::endl;
    gotoligcol(4,28);
    std::cout <<">=>           >> >=>                 >=>       >=> >=>     >=> >=>            >=>     >=> " << std::endl;
    gotoligcol(5,28);
    std::cout << ">=>          >=>  >=>                >=>       >=> >=>     >=> >=====>        >=>     >=====>" << std::endl;
    gotoligcol(6,28);
    std::cout <<">=>         >=====>>=>               >=>       >=> >=>     >=> >=>            >=>     >=>" << std::endl;
    gotoligcol(7,28);
    std::cout <<">=>        >=>      >=>                >=> >> >=>  >=>     >=> >=>            >=>     >=>" << std::endl;
    gotoligcol(8,28);
    std::cout << ">=======> >=>        >=>                 >= >>=>     >====>    >=======>      >=>     >=======>" << std::endl;

    for(int i=0;i<15;i++)
    {
        gotoligcol(13,55+i);
        std::cout << "-"<< std::endl;
        Sleep(25);
    }
    gotoligcol(13,70);
    std::cout << "MENU" << std::endl << std::endl;
    for(int i=0;i<15;i++)
    {
        gotoligcol(13,74+i);
        std::cout << "-"<< std::endl;
        Sleep(25);

    }
    afficherCol(13,55);
    afficherCol(13,88);
     for(int i=0;i<34;i++)
    {
        gotoligcol(21,55+i);
        std::cout << "-"<< std::endl;
        Sleep(25);
    }
    gotoligcol(15,65);
    std::cout <<"1. s'inscrire "<< std::endl;
    gotoligcol(16,65);
    std::cout << "2. se connecter" << std::endl;
    gotoligcol(17,65);
    std::cout << "3. Lancer Match" << std::endl;
    gotoligcol(18,65);
        std::cout << "4. Regle" << std::endl;
        gotoligcol(19,65);
    std:: cout << "0. Quitter" << std::endl;
    gotoligcol(20,65);

}

void AfficherConnecter(int curs,int x, int y)
{


    gotoligcol(x,y);
    printf("%c",(curs==1)?'>':' ');
    gotoligcol(x+1,y);
    printf("%c",(curs==2)?'>':' ');
    gotoligcol(x+2,y);
    printf("%c",(curs==0)?'>':' ');

}

int ChoisirConnecter()
{
    int curs = 1;
    int x=0;
    int y=0;
    int touche;
    do
    {
        AfficherConnecter(curs, x , y);
        touche = _getch();
        if (touche==0xE0) // fleche : le code fleche renvoie 2 caracteres.
        {
            touche = _getch();
            if (touche==0x50 && curs==1)  // fleche bas
                curs = 2;
            else if (touche==0x50 && curs==2)  // fleche bas
                curs = 0;
            else if (touche==0x48 && curs==2)  // fleche haut
                curs = 1;
                else if (touche==0x48 && curs==0)  // fleche haut
                curs = 2;
        }
    } while (touche!=0x0D);  // enter
    return curs;
}

void menuConnecter()
{
    system("cls");
    std::cout << " 1. Afficher la collection du joueur "<< std::endl;
std::cout << " 2. Rentrer dans la boutique" << std::endl;
std::cout << " 0. Quitter" << std::endl;


}

void inscrire()
{
bool fin=false;
bool test=false;
std::string ligne;

    std::string nomJ1;
do{
    std::cout << "saisir Prenom Joueur 1" << std::endl;
    std::cin >> nomJ1;
  /////////////////////////////////////
    std::ifstream monFlux1("sauv.txt");

    if(monFlux1){

    while (fin==false && getline(monFlux1,ligne))


       if(ligne==nomJ1)
        {test=true;
        fin=true;}
        else
            {
            fin=false;}
    }
    else
   {
      std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." <<std::endl;
   }

   if(test==true){
    std::cout << std::endl << "Ce joueur existe deja ! Vous devez vous connecter " << std::endl << std::endl;}
    test=false;
    }while(ligne==nomJ1);
////////////////////////////////
    Joueur J1(nomJ1);

    J1.afficherboutique();

    std::string const nomFichier("sauv.txt");
    std::ofstream monFlux;
    monFlux.open(nomFichier.c_str(),std::ios::app);

    if(monFlux)
    {
        monFlux << std::endl << std::endl << nomJ1 << std::endl;
        monFlux << J1.getArgent() << std::endl;

    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
    monFlux.close();

    J1.sauvegarderCollec();

}

void seconnecterAfficherCollec()

{
bool test=false;
Console* pConsole = Console::getInstance();
std::string ligne;

    std::string nom;
    std::string choix;

    do{
           test=false;
           std::cout << "saisir votre pseudo " << std::endl;
    std::cin >> nom;

      std::ifstream monFlux1("sauv.txt");

    if(monFlux1){

    while (getline(monFlux1,ligne))

       if(ligne==nom)
        {test=true;
        }
    }
    else
   {
      std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." <<std::endl;
   }

   if(test==false)
    std::cout << std::endl << " Ce joueur n'existe pas ! Il faut d'abord s'inscrire " << std::endl;

}while(test!=true);
        Joueur J1(nom);
        J1.charger();
        J1.afficherCollecNom();
        std::cout<< "[appuyez sur ENTRER pour continuer]" << std::endl;
        if(pConsole->getInputKey()){}
}

void connecter()
{
bool test=false;
int a=30;
std::string nom;
std::string ligne;

    while(a!=0)
{
menuConnecter();
a=ChoisirConnecter();
system("cls");
switch (a)
{
case 1:
    {
seconnecterAfficherCollec();
break;
    }
case 2:
    {

        do{
           test=false;
           std::cout << "saisir votre pseudo " << std::endl;
    std::cin >> nom;

      std::ifstream monFlux1("sauv.txt");

    if(monFlux1){

    while (getline(monFlux1,ligne))


       if(ligne==nom)
        {test=true;
        }

    }
    else
   {
      std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." <<std::endl;
   }

   if(test==false)
    std::cout << std::endl << " Ce joueur n'existe pas ! Il faut d'abord s'inscrire " << std::endl;

}while(test!=true);
        Joueur J1(nom);

        J1.charger();
        J1.afficherboutique();
        J1.SupprimerFichier();
        J1.sauvegarderCollec();
        break;
    }

}


}
a=30;

}

void Regles()
{

std::cout<<"                        BIENVENUE DANS LA QUETE !"<<std::endl;
std::cout<<"Le monde sombre de plus en plus dans le chaos... Votre mission est de ramener la lumiere et la justice."<<std::endl;
std::cout<<"Creez votre armee et partez au combat pour reprendre le Saint Graal !"<<std::endl;
std::cout<<std::endl;
std::cout<<"Comment fonctionne ce monde ?"<<std::endl;
std::cout<<"En Gwendalavir, tu as le choix entre 4 types de cartes : Creature, Energie et Speciale."<<std::endl;
std::cout<<"- Ta Creature (une seule a la fois) attaque la creature adverse avec deux puissantes attaques."<<std::endl;
std::cout<<"- Ces attaques ont chacune un prix que tu payes avec des Cartes Energies (Corps a Corps, Distance, Machine,Heros)"<<std::endl;
std::cout<<"- Les Cartes Speciales ont chacune un POUVOIR unique. A toi de les decouvrir !"<<std::endl;
std::cout<<std::endl;
std::cout<<std::endl;

std::cout<<"Comment jouer ?"<<std::endl;
std::cout<<"- Inscris-toi et achète toi des cartes. A toi de monter ton armee personnelle ! Tu pourras toujours racheter des cartes."<<std::endl;
std::cout<<"- Trouve toi un adversaire a ta mesure et lance un match !"<<std::endl;
std::cout<<"- Cree toi un deck au debut du match. Une carte aleatoire est enlevee :  c'est l'ENJEU ! "<<std::endl;
std::cout<<"- Le plus valeureux remportera l'ENJEU de l'adversaire et recuperera sa carte."<<std::endl;
std::cout<<std::endl;
std::cout<<std::endl;
std::cout<<"Comment se deroule un match ?"<<std::endl;
std::cout<<"Un ecu est lance. Le destin decidera du premier joueur."<<std::endl;
std::cout<<"OBJECTIFS : Mettre les PV de l'adversaire a 0 OU faire qu'il n'ait plus de Creatures dans son deck."<<std::endl;
std::cout<<"Match nul, si pour les 2 joueurs, il ne leur reste plus qu'une Creature Active et plus aucune Creature dans le deck"<<std::endl;
std::cout<<std::endl;

std::cout<<"A ton tour, tu dois :"<<std::endl;
std::cout<<std::endl;
std::cout<<"1.Piocher une carte. Si tu n'as pas de Creature Active sur le terrain. Tu pioches jusqu'a en obtenir une."<<std::endl;
std::cout<<"(On remet les Energie et Speciale dans la pioche."<<std::endl;
std::cout<<"Si tu as une Creature en jeu, tu pioches juste la premiere carte."<<std::endl;
std::cout<<"Si c'est une ENERGIE, elle ira rejoindre ta RESERVE pour attaquer."<<std::endl;
std::cout<<"Si c'est une CREATURE, tu pourras l'echanger si tu le souhaites avec celle active."<<std::endl;
std::cout<<"Si c'est une SPECIALE, tu pourras la jouer si tu le veux."<<std::endl;
std::cout<<std::endl;
std::cout<<"2.Attaquer (ou non)."<<std::endl;
std::cout<<"Tu dois avoir assez d'Energie pour attaquer. Regarde bien le prix de chaque Attaque et ta Reserve d'Energie !"<<std::endl;
std::cout<<"Si la Creature adverse a 0 PV, elle va au cimetiere. Et le reste des degats de ton attaque touchera les PV de ton adversaire."<<std::endl;
std::cout<<std::endl;
std::cout<<std::endl;
std::cout<<"ET VOILA ! Tout simple, n'est-ce pas?"<<std::endl;

std::cout<<"A toi d'etre stratege..."<<std::endl;
std::cout<<"QUE LE MEILLEUR COMBATTANT GAGNE !"<<std::endl;
std::cout<<std::endl;
std::cout << "[Appuyez sur entrer pour Retour au menu]" << std::endl;
int touche=0;
while (touche!=0x0D){
touche=getch();
}
}



#endif // JEU_H_INCLUDED
