#ifndef CAVALIER_H
#define CAVALIER_H
#include "Creature.h"
#include "Attaque.h"

class Cavalier:public Creature
{
    public:
Cavalier();
Attaque* getAttaque1();
Attaque* getAttaque2();
virtual void afficher() const;



    private:
};

#endif // CAVALIER_H
