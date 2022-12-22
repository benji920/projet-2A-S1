#include "Belier.h"
#include <iostream>
//onstructeur de la Classe Belier qui initialise ces informations
Belier::Belier():Creature(3,"Belier","Au plus pres du combat, le belier detruit les derniers remparts.",9,3){

m_A=new Attaque("Brise-Porte",6,2,3,0,0);
m_A2=new Attaque("Charge ravageuse",7,1,1,2,3);

}

Attaque* Belier::getAttaque1(){

return m_A;
}
Attaque* Belier::getAttaque2(){
return m_A2;
}

void Belier::afficher() const{

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



