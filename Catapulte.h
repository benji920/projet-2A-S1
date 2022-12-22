#ifndef CATAPULTE_H
#define CATAPULTE_H
#include "Creature.h"
#include "Attaque.h"

class Catapulte: public Creature
{
    public:
        Catapulte();
        Attaque* getAttaque1();
Attaque* getAttaque2();
virtual void afficher() const;



    private:
};

#endif // CATAPULTE_H
