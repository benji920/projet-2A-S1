#ifndef ATTAQUE_H
#define ATTAQUE_H
#include <string>
#include <iostream>
#include "console.h"

class Attaque
{
    public:
        Attaque();
        Attaque(std::string description,int degats,int nbEnergie,int typeEnergie, int nb2Energie, int type2Energie);
        ~Attaque();


        int getDegat() const {return m_degats;};
        int getNbEnergie() const {return m_nbEnergie;};
        int getNbEnergie2() const{return m_nb2Energie;};
        int getTypeEnergie() const {return m_typeEnergie;};
        int getTypeEnergie2()  const{return m_type2Energie;};
void setDegat(int degat){m_degats=degat;};
void afficherAttaque();
void afficherAttaqueTerrain(int x, int y, int z);


    private:

        std::string m_description;
        int m_degats;
        int m_nbEnergie;
        int m_typeEnergie;
        int m_nb2Energie;
        int m_type2Energie;
        Console* pConsole = Console::getInstance();

};

#endif // ATTAQUE_H
