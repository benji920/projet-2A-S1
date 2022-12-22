#include "Creature.h"
#include <iostream>
//Constructeur par défaut d'une Creature
Creature::Creature():Carte(),m_PV(2),m_energie(0){m_typeCarte=1;}
//Constructeur surchargé qui initialise une Creature avec les informations reçues
Creature::Creature(int prix, std::string nom, std::string description, int PV,int energie):Carte(prix,nom,description),m_PV(PV),m_energie(energie){m_typeCarte=1;}// Le type de la Carte est de 1 pour les Creatures

int Creature ::getPV(){//Getter pour récupérer les PV de la Créatures

return m_PV;

}


Attaque* Creature:: getAttaque1(){//Getter pour récupérer les attaques

return m_A;
}

Attaque* Creature:: getAttaque2(){

return m_A2;
}

void Creature::afficher() const{//Pour afficher les information de la Creatures

 std::cout<<"Nom : " <<m_nom<<std::endl;
std::cout<<"Description : "<< m_description<<std::endl;
std::cout<<m_PV<<std::endl;
if(m_energie==1){//Ecris le type qui correspond a chaque creature
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
std::cout<<"Prix : "<<m_prix<<" piece(s) d'or"<<std::endl;

 }

void Creature::afficherNom() const {//Méthode pour juste afficher le nom de la Creature pour alleger le jeu

std::cout<<m_nom;
}

 void Creature::attaquerCreature(Creature* C2){//Méthode qui permet a une Creature d'en attaquer une autre

std::cout<<"Votre Creature a inflige "<<m_A->getDegat()<<" degats"<<std::endl;//affiche les degats infliges

int a= C2->getPV()-m_A->getDegat();//Calcule la difference entre les PV de la Creature attaquee et les degats qu'on lui inflige
C2->setPV(a);//On attribue ses nouveaux PV a la Creature Attaquee

if(a>0){//Si la Creature Adverse est encore en vie
std::cout<<"Il reste "<<C2->getPV()<<" PV a la Creature adverse."<<std::endl;
}
else{//Si le Creature Adverse est morte
std::cout<<"La Creature adverse est morte."<<std::endl;
}

 }

  void Creature::attaquerCreature2(Creature* C2){//méthode identique mais avec la deuxieme attaque de la Creature
std::cout<<"Votre Creature a inflige "<<m_A2->getDegat()<<" degats"<<std::endl;

int a= C2->getPV()-m_A2->getDegat();
C2->setPV(a);

if(a>0){//Si la Creature Adverse est encore en vie
std::cout<<"Il reste "<<C2->getPV()<<" PV a la Creature adverse."<<std::endl;
}
else{//Si le Creature Adverse est morte
std::cout<<"La Creature adverse est morte."<<std::endl;
}
 }
