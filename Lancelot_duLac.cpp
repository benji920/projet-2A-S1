#include "Lancelot_duLac.h"
#include <iostream>
//Constructeur de la classe Lancelot_duLac. Initialise tous les attributs personnels d'un Lancelot_duLac qui est une Creature

Lancelot_duLac::Lancelot_duLac():Creature(4,"Lancelot du lac","Son epee benie a la main. Il guide ses troupes avec fougue.",13,4){

m_A=new Attaque("Attaque salvatrice",8,1,1,1,4);
m_A2=new Attaque("Epee de justice",9,2,4,0,0);

}

Attaque* Lancelot_duLac::getAttaque1(){

return m_A;
}
Attaque* Lancelot_duLac::getAttaque2(){
return m_A2;
}

void Lancelot_duLac::afficher() const{

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


