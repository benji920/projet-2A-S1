#ifndef CARTE_H
#define CARTE_H
#include <string>

class Carte
{
    public:
        Carte();
        Carte(int prix, std::string nom, std::string description);
        ~Carte();
       virtual void afficher() const;
        int getPrix() const {return m_prix;};
        int getTypeCarte() const {return m_typeCarte;};
        std::string getNomCarte() const {return m_nom;};
        virtual void afficherNom() const ;

    protected:
        int m_prix;
        std::string m_nom;
        std::string m_description;
        //Type de la carte : (1)Créature , (2)Energie , (3)Speciale
        int m_typeCarte;



};

#endif // CARTE_H
