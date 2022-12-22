#ifndef SPECIALE_H
#define SPECIALE_H
#include "Carte.h"

#pragma once
#include "Joueur.h"
class Joueur;

class Speciale : public Carte
{
    public:
        Speciale(int prix, std::string nom, std::string description,bool refus, bool usage);
        ~Speciale();
  virtual void afficher() const;
        virtual void afficherNom() const ;

bool getRefus() const{return m_refus;};
bool getUsage() const{return m_usage;};


    private:
        // Apres carte piochee est refusee, false = cimetiere, true = sous la pioche
        bool m_refus;
        // APRES CARTE UTILISEE, true= usage unique = cimetiere, false = Persistante
        bool m_usage;
};

#endif // SPECIALE_H
