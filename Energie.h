#ifndef ENERGIE_H
#define ENERGIE_H
#include "Carte.h"


class Energie : public Carte
{
    public:

        Energie(int prix,int type, std::string nom, std::string description);
        ~Energie();
        int getTypeEnergie() const{return m_type;};
        virtual void afficher() const;
        virtual void afficherNom() const ;
    private:
        // 1 =CAC ; 2 = Distance ; 3= Machine ; 4=Heros
int m_type;
};

#endif // ENERGIE_H
