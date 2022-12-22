#include "Carte.h"
#include <iostream>
//Constructeur par défaut de Carte
Carte::Carte()
{
m_prix=1;
       m_nom= " - ";
     m_description= " none";
}
//Constructeur qui initialise une carte avec les informations reçues
Carte::Carte(int prix, std::string nom, std::string description):m_prix(prix),m_nom(nom),m_description(description){}

Carte::~Carte()//destructeur de Carte
{

}

void Carte :: afficherNom() const{//Méthode pour afficher uniquement le nom de la Carte pour alleger le jeu
std::cout << m_nom;
}

void Carte::afficher() const{//Méthode pour afficher les information de la Carte

 std::cout<<"Nom : " <<m_nom<<std::endl;
std::cout<<"Description : "<< m_description<<std::endl;

 }
