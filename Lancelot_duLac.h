#ifndef LANCELOT_DULAC_H
#define LANCELOT_DULAC_H
#include "Attaque.h"
#include "Creature.h"


class Lancelot_duLac: public Creature
{
    public:
Lancelot_duLac();
Attaque* getAttaque1();
Attaque* getAttaque2();
virtual void afficher() const;




    private:
};

#endif // LANCELOT_DULAC_H
