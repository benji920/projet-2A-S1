#include "Arthur_Pendragon.h"
#include <iostream>
//Constructeur qui initialise les informations d'Arthur
Arthur_Pendragon::Arthur_Pendragon():Creature(4,"Arthur Pendragon","Le seul et unique Elu. Un Roi admire par ses soldats et hai par l'ennemi.",15,4){

m_A=new Attaque("Appel aux armes",8,1,3,1,4);//Initialise les informations personnelles des deux attaques
m_A2=new Attaque("Frappe d'Escalibur",10,2,4,0,0);

}

Attaque* Arthur_Pendragon::getAttaque1(){

return m_A;
}
Attaque* Arthur_Pendragon::getAttaque2(){
return m_A2;
}

void Arthur_Pendragon::afficher() const{

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




