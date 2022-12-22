#include "Arbaletrier.h"
#include <iostream>

//Constructeur de la classe Arbaletrier. Initialise tous les attributs personnels d'un arbaletrier qui est une Creature
Arbaletrier ::Arbaletrier():Creature(1,"Arbaletrier","Loin du champ de bataille,sa precision lui permet de proteger ses allies",7,2){

m_A=new Attaque("Tir de precision",7,2,2,0,0); // initialise les deux attaques personnelles des Arbaletriers
m_A2=new Attaque("Triple-Carreaux",8,1,1,2,2);

}

Attaque* Arbaletrier::getAttaque1(){//Getter des Deux attaques

return m_A;
}
Attaque* Arbaletrier::getAttaque2(){
return m_A2;
}

void Arbaletrier::afficher() const{//Méthode pour afficher les informations de la carte Arbaletrier

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

