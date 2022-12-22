#include "Catapulte.h"
#include <iostream>
//Constructeur qui initialise les informations des Catapultes
Catapulte ::Catapulte():Creature(3,"Catapulte","Machine de guerre, elle fait des ravages dans les troupes ennemies",10,3){

m_A=new Attaque("Boulet de fer",7,2,3,0,0);
m_A2=new Attaque("Projectile lourd",8,1,2,2,3);

}

Attaque* Catapulte::getAttaque1(){

return m_A;
}
Attaque* Catapulte::getAttaque2(){
return m_A2;
}

void Catapulte::afficher() const{

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


