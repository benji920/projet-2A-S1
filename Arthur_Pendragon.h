#ifndef ARTHUR_PENDRAGON_H
#define ARTHUR_PENDRAGON_H
#include "Attaque.h"
#include "Creature.h"


class Arthur_Pendragon: public Creature
{
    public:
        Arthur_Pendragon();
        Attaque* getAttaque1();
Attaque* getAttaque2();
virtual void afficher() const;



    private:
};

#endif // ARTHUR_PENDRAGON_H
