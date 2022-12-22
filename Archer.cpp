#include "Archer.h"
#include <iostream>

//Constructeur Classe Archer qui initialise les informations personnelles des Archers avec ces deux attaques
Archer::Archer():Creature(1,"Archer","Avec son arbre en bois d'if,  plus aucun ennemi n'est a l'abri.",7,2){

m_A=new Attaque("Fleche enflammee",6,2,2,0,0);
m_A2=new Attaque("Pluie de fleches",7,2,2,1,3);

}

Attaque* Archer::getAttaque1(){

return m_A;
}
Attaque* Archer::getAttaque2(){
return m_A2;
}

void Archer::afficher() const{//Méthode pour afficher les informations de la carte

 std::cout<<"Nom : " <<m_nom<<std::endl;
std::cout<<"Description : "<< m_description<<std::endl;
std::cout<<"PV:" << m_PV<<std::endl;
if(m_energie==1){
    std::cout<<"Type : Corps a corps "<<std::endl;
}
else if(m_energie==2){
        std::cout<<"Type : Distance "<<std::endl;
}
else if(m_energie==3){
        std::cout<<"Type : Machine "<<std::endl;
}
else if(m_energie==4){
        std::cout<<"Type : Heros "<<std::endl;
}

 }
