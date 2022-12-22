#ifndef GUERRIER_H
#define GUERRIER_H
#include "Creature.h"
#include "Attaque.h"
#include <iostream>

class Guerrier : public Creature
{
    public:
        Guerrier();

Attaque* getAttaque1();
Attaque* getAttaque2();

virtual void afficher() const;
    private:
};

#endif // GUERRIER_H
