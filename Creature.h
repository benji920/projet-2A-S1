#ifndef CREATURE_H
#define CREATURE_H
#include "Carte.h"
#include "Attaque.h"
#include <vector>

class Creature : public Carte
{
    public:
        Creature();
        Creature(int prix, std::string nom, std::string description, int PV,int energie);
        virtual void afficher() const;
        virtual void afficherNom() const ;
        int getPV();
        void setPV(int PV){m_PV=PV;};
virtual Attaque* getAttaque1();
virtual Attaque* getAttaque2();
        void attaquerCreature(Creature* C);
        void attaquerCreature2(Creature* C);
    protected:
        int m_PV;
        Attaque* m_A;
        Attaque* m_A2;
        //1 = CAC / 2 = Distance / 3= Machine / 4 = Hero
        int m_energie;


};

#endif // CREATURE_H
