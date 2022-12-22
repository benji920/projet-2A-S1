#include "Guerrier.h"
//Constructeur qui initialise un Guerrier avec ses informations personnelles
Guerrier::Guerrier():Creature(2,"Guerrier","Arme de sa fidele hache, il nettoie les champs de bataille",10,1){

m_A=new Attaque("Lame guerrière",4,2,1,0,0);
m_A2=new Attaque("Hache vengeresse",6,2,1,1,3);

}
Attaque* Guerrier::getAttaque1(){

return m_A;
}
Attaque* Guerrier::getAttaque2(){
return m_A2;
}

void Guerrier::afficher() const{

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
