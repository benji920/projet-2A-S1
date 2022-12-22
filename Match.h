#ifndef MATCH_H
#define MATCH_H
#include "Joueur.h"
#include "Carte.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "console.h"

class Match
{
    public:
        Match();
void LancerMatch();
void Tour(Joueur& J,Joueur& J2);
void InfoTerrain(Joueur& J);
void Vague(Joueur& J, Joueur &J2);
void Victoire(Joueur& J, Joueur &J2);
void afficherTerrain();
 void afficherCarte(int x, int y);
    private:
        Joueur m_J1;
        Joueur m_J2;
        Console* pConsole = Console::getInstance();

};

#endif // MATCH_H
