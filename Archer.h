#ifndef ARCHER_H
#define ARCHER_H
#include "Creature.h"
#include "Attaque.h"

class Archer : public Creature
{
    public:
        Archer();
Attaque* getAttaque1();
Attaque* getAttaque2();
virtual void afficher() const;
//void creationArcher();
    private:

};

#endif // ARCHER_H
