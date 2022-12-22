#ifndef JOUEUR_H
#define JOUEUR_H
#include <string>
#include <vector>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Carte.h"
#include <queue>
#include "Creature.h"
#include "Cavalier.h"
#include "Arbaletrier.h"
#include "Catapulte.h"
#include"Belier.h"
#include"Arthur_Pendragon.h"
#include "Jeanne_D_arc.h"
#include "Lancelot_duLac.h"
#include "Archer.h"
#include "Guerrier.h"
#include <fstream>
#include "Energie.h"
#include <iostream>
#pragma once
#include "Speciale.h"
#include "console.h"
class Speciale;


class Joueur
{
    public:
        Joueur(std::string nomJoueur);
        Joueur();
        ~Joueur();

         std::string getNomJoueur()const{return m_nomJoueur;};
        int getArgent()const{return m_argent;};
        int getPV() const{return m_PVJoueur;};
        int getTailleDeck() const{return m_deck.size();};
        int getNbCreatureDeck() const {return m_nbCreatureDeck;};
        bool getVague(){return m_vague;};
        bool getCreatureActiveVide()const{return m_CreatureActiveVide;};
        bool getSpecialeActiveVide()const{return m_SpecialeActiveVide;};
        Creature* getCreatureActive() const{return CreatureActive;};
        Speciale* getSpecialeActive() const{return SpecialeActive;};
        Carte* getEnjeu() const {return m_Enjeu;};
        std::queue<Carte*>getDeck() const{return m_deck;};
 std::vector<Carte*> getCollection(){return m_collection;};


        void setNom(std::string nom);
        void setSpecialeActive(Speciale* Spe);
                void setCreatureActive(Creature* C);
        void setPV(int PV){m_PVJoueur=PV;};
        void setVague(bool vague){m_vague=vague;};
        void setCreatureActiveVide(bool vide){m_CreatureActiveVide=vide;};
void setEnjeu(Carte *C){m_Enjeu=C;};
void setCollection(std::vector<Carte*> Collection){m_collection=Collection;};
void setArgent(int argent){m_argent=argent;};

void afficherDeck();
      void afficherCollec() const;
      void afficherCollecNom() const;
void afficherCimetiere() const;
void afficherReserveEnergie() const;
        void afficherboutique();
         void afficherCreatureActive() const;
         void afficherSpecialeActive() const;

        void afficherReserveEnergieTerrain(int x, int y) const;
         void afficherCreatureActiveTerrain(int x, int y) const;
         void afficherSpecialeActiveTerrain(int x, int y) const;
         void afficherCimetiereTerrain(int x, int y) const;


         void menuBoutique();

        void ajouterCarteCollec(Carte* C);
        void ajouterCarteDeck(Carte* C);
        void ajouterCarteCimetiere(Carte* C);

               void CreerDeck();

        void seconnecter2();
        void seconnecterMenu();


 void sauvegarderCollec();


  void piocher(Joueur& J);
  void piocherEnjeu();
        void charger();
        void SupprimerFichier();
        void attaquerJoueur(Joueur& J);
void melangerDeck();
void refusSpeciale(Speciale* Spe);



    private:
      std::string m_nomJoueur;
        int m_PVJoueur = 8;
        int m_argent=45;
        //Collection où on stocke les cartes que le joueur achete. Nb infini.
        std::vector <Carte*> m_collection;
        //Deck de 21 cartes que le joueur choisit pour jouer une partie
        std::queue <Carte*> m_deck;
        //Cimetière où iront les cartes mortes ou rejetées
        std::vector <Carte*> m_cimetiere;
       Creature* CreatureActive;
        Speciale* SpecialeActive;

        Console* pConsole = Console::getInstance();

        bool m_SpecialeActiveVide=true;
         bool m_CreatureActiveVide=true; //booleen pour savoir si le joueur a une Créature Active ou non
       int m_nbCaC=0; //nombre de cartes Energie de type Cac piochée par le joueur
         int m_nbDistance=0;
         int m_nbMachine=0;
         int m_nbHeros=0;
         int m_nbCreatureDeck=0;
        Carte* m_Enjeu;
            bool m_galva=false;
            bool m_vague=false;
        std::vector <Carte*> boutique;
};

#endif // JOUEUR_H
