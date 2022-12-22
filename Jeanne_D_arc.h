#ifndef JEANNE_D_ARC_H
#define JEANNE_D_ARC_H
#include "Attaque.h"
#include "Creature.h"


class Jeanne_D_arc:public Creature
{
    public:
        Jeanne_D_arc();
        Attaque* getAttaque1();
Attaque* getAttaque2();
virtual void afficher() const;

    private:
};

#endif // JEANNE_D_ARC_H
