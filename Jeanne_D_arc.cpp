#include "Jeanne_D_arc.h"
#include <iostream>
//Constructeur qui initialise JeanneD'arc avec ses informations personnelles et ses propres attaques
Jeanne_D_arc::Jeanne_D_arc():Creature(4,"Jeanne d'Arc","Chef de guerre redoutable. Elle est prete à se sacrifier pour la victoire.",13,4){

m_A=new Attaque("Bucher",12,1,3,1,4);
m_A2=new Attaque("Colere divine",9,2,4,0,0);

}

Attaque* Jeanne_D_arc::getAttaque1(){

return m_A;
}
Attaque* Jeanne_D_arc::getAttaque2(){
return m_A2;
}

void Jeanne_D_arc::afficher() const{

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


