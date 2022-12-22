#ifndef ARBALETRIER_H
#define ARBALETRIER_H
#include "Creature.h"
#include "Attaque.h"


class Arbaletrier : public Creature
{
    public:
        Arbaletrier();
        Attaque* getAttaque1();
Attaque* getAttaque2();
virtual void afficher() const;

    private:
};

#endif // ARBALETRIER_H
