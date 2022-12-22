#ifndef BELIER_H
#define BELIER_H
#include "Creature.h"
#include "Attaque.h"

class Belier: public Creature
{
    public:
        Belier();
                Attaque* getAttaque1();
Attaque* getAttaque2();
virtual void afficher() const;


    private:
};

#endif // BELIER_H
