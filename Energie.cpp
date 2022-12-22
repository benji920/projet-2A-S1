#include <iostream>
#include "Energie.h"
//Constructeur surcharge qui initialise une CArte Energie avec les parametres reçus
Energie::Energie(int prix, int type, std::string nom, std::string description):Carte(prix,nom,description),m_type(type){
    m_typeCarte=2;//Si le type=2; c'est une carte Energie
}


Energie::~Energie(){
    //dtor
}
void Energie::afficher() const{//Affiche les informations de la carte

 std::cout<<"Nom : " <<m_nom<<std::endl;
std::cout<<"Description : "<< m_description<<std::endl;
std::cout<<"Prix : "<<m_prix<<" piece(s) d'or"<<std::endl;


 }

void Energie::afficherNom() const {//Affiche le nom

std::cout <<m_nom;
}
