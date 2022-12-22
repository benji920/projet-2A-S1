#include "Cavalier.h"
#include <iostream>
//Constructeur qui initialise un Cavalier avec ses informations personnelles.
Cavalier ::Cavalier():Creature(2,"Cavalier","",9,1){

m_A=new Attaque("Lance d'argent",4,2,1,0,0);
m_A2=new Attaque("Joute mortelle",6,2,1,1,2);

}

Attaque* Cavalier::getAttaque1(){

return m_A;
}
Attaque* Cavalier::getAttaque2(){
return m_A2;
}

void Cavalier::afficher() const{

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
