#include "Speciale.h"
#include <iostream>
//Constructeur surchargé qui initialise une Carte Speciale avec les parametres reçus
Speciale::Speciale(int prix, std::string nom, std::string description,bool refus, bool usage):Carte(prix, nom, description),m_refus(refus),m_usage(usage)
{
m_typeCarte=3;//Si le type de la carte est 3, c'est une Carte Speciale
}

Speciale::~Speciale()
{
    //dtor
}
void Speciale::afficher() const{//affiche les infos de la Carte

 std::cout<<"Nom : " <<m_nom<<std::endl;
std::cout<<"Description : "<< m_description<<std::endl;
if(m_refus==true){
    std::cout<<"Si refusee, retourne dans la pioche."<<std::endl;
}else{
    std::cout<<"Si refusee, va au cimetiere."<<std::endl;
}
if(m_usage==true){
    std::cout<<"Usage Unique"<<std::endl;
}
else {

    std::cout<<"Carte qui persiste sur le terrain sauf si changement."<<std::endl;
}
std::cout<<"Prix : "<<m_prix<<" piece(s) d'or"<<std::endl;

 }

void Speciale::afficherNom() const {

std::cout<<m_nom;
}




