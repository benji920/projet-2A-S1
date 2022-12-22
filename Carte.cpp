#include "Carte.h"
#include <iostream>
//Constructeur par d�faut de Carte
Carte::Carte()
{
m_prix=1;
       m_nom= " - ";
     m_description= " none";
}
//Constructeur qui initialise une carte avec les informations re�ues
Carte::Carte(int prix, std::string nom, std::string description):m_prix(prix),m_nom(nom),m_description(description){}

Carte::~Carte()//destructeur de Carte
{

}

void Carte :: afficherNom() const{//M�thode pour afficher uniquement le nom de la Carte pour alleger le jeu
std::cout << m_nom;
}

void Carte::afficher() const{//M�thode pour afficher les information de la Carte

 std::cout<<"Nom : " <<m_nom<<std::endl;
std::cout<<"Description : "<< m_description<<std::endl;

 }
