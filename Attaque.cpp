#include "Attaque.h"
#include "Energie.h"


Attaque::Attaque(){//Constructeur par défaut de la classe Attaque

}
//Constructeur qui initialise et Crée une Attaque
Attaque::Attaque(std::string description,int degats,int nbEnergie,int typeEnergie, int nb2Energie, int type2Energie)
{
    m_description=description;
    m_degats=degats;
    m_nbEnergie=nbEnergie;
    m_typeEnergie=typeEnergie;
    m_nb2Energie=nb2Energie;
    m_type2Energie=type2Energie;
}


Attaque::~Attaque()//Destructeur d'Attaque
{
    //dtor
}


     void Attaque::afficherAttaque(){ //Méthode pour afficher les informations des attaques

     std::cout<<"Attaque :"<<m_description <<std::endl;
          std::cout<<"Degat : "<<m_degats<<std::endl;
              std::cout<<"Vous avez besoin de :"<<std::endl;//Ecrit le nombre de Carte Energie nécessaire selon le type
          if(m_typeEnergie==1){

    std::cout<<m_nbEnergie<<" Carte(s) Corps a corps"<<std::endl;
          }
          else if(m_typeEnergie==2){

             std::cout<<m_nbEnergie<<" Carte(s) Distance"<<std::endl;
          }
           else if(m_typeEnergie==3){

             std::cout<<m_nbEnergie<<" Carte(s) Machine"<<std::endl;
          }
           else if(m_typeEnergie==4){

             std::cout<<m_nbEnergie<<" Carte(s) Heros"<<std::endl;
          }
           if(m_type2Energie==1){ //AFfichage du nombre d'energie de type 2 necessaires

    std::cout<<m_nb2Energie<<" Carte(s) Corps a corps"<<std::endl;
          }
          else if(m_type2Energie==2){

             std::cout<<m_nb2Energie<<" Carte(s) Distance"<<std::endl;
          }
           else if(m_type2Energie==3){

             std::cout<<m_nb2Energie<<" Carte(s) Machine"<<std::endl;
          }
           else if(m_type2Energie==4){

             std::cout<<m_nb2Energie<<" Carte(s) Heros"<<std::endl;
          }
     }

     void Attaque::afficherAttaqueTerrain(int x, int y, int z){//Méthode qui permet d'afficher l'attaque sur le Terrain pendant le matchs

     pConsole->gotoLigCol(x,y);

        std::cout<<"Attaque "<<z<<" : "<<m_description;
     pConsole->gotoLigCol(x+1,y);
          std::cout<<"Degat : "<<m_degats;
          pConsole->gotoLigCol(x+2,y);
              std::cout<<"Vous avez besoin de :"<<std::endl;

          if(m_typeEnergie==1){
            pConsole->gotoLigCol(x+3,y);
    std::cout<<m_nbEnergie<<" Carte(s) Corps a corps"<<std::endl;
          }
          else if(m_typeEnergie==2){
pConsole->gotoLigCol(x+3,y);
             std::cout<<m_nbEnergie<<" Carte(s) Distance"<<std::endl;
          }
           else if(m_typeEnergie==3){
pConsole->gotoLigCol(x+3,y);
             std::cout<<m_nbEnergie<<" Carte(s) Machine"<<std::endl;
          }
           else if(m_typeEnergie==4){
pConsole->gotoLigCol(x+3,y);
             std::cout<<m_nbEnergie<<" Carte(s) Heros"<<std::endl;
          }
           if(m_type2Energie==1){ //AFfichage du nombre d'energie de type 2 necessaires
pConsole->gotoLigCol(x+4,y);
    std::cout<<m_nb2Energie<<" Carte(s) Corps a corps"<<std::endl;
          }
          else if(m_type2Energie==2){
pConsole->gotoLigCol(x+4,y);
             std::cout<<m_nb2Energie<<" Carte(s) Distance"<<std::endl;
          }
           else if(m_type2Energie==3){
pConsole->gotoLigCol(x+4,y);
             std::cout<<m_nb2Energie<<" Carte(s) Machine"<<std::endl;
          }
           else if(m_type2Energie==4){
pConsole->gotoLigCol(x+4,y);
             std::cout<<m_nb2Energie<<" Carte(s) Heros"<<std::endl;
          }
     }

