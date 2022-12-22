#include "Match.h"
#include <iostream>


Match::Match()
{



}

void Match::InfoTerrain(Joueur& J){ // On affiche toutes les informations de terrain du joueur qui joue
    system("cls");
    std::cout<<" C'est ton tour "<<J.getNomJoueur()<<": "<<std::endl;
std::cout<<" Informations de ton terrain : "<<std::endl;
std::cout<< "PV : "<<J.getPV()<<std::endl;

if(J.getCreatureActiveVide()==false){
J.afficherCreatureActive(); // Affichage de la Creature Active du joueur J
}

J.afficherReserveEnergie(); // Affichage des energies qu'il a pioche

if(J.getSpecialeActiveVide()==false){
J.afficherSpecialeActive(); //Affichage de la carte Speciale Active/persistante
}

}

void Match::Tour(Joueur& J,Joueur& J2){//Actions que le joueur effectue a chaque tour

if(J.getDeck().size()!=0){//Si le joueur a encore des cartes à piocher
J.piocher(J2);
}
else{
    std::cout<<"Vous n'avez plus de cartes a piocher !"<<std::endl;
}

std::cout << "[Appuyez sur entrer pour continuer]" << std::endl;
if(pConsole->getInputKey()){}

    system("cls");
afficherTerrain();//on affiche le terrain en le mettant à jour

std::cout<<J.getNomJoueur()<<", A toi d'attaquer !"<<std::endl;

if(J2.getCreatureActiveVide()==false){//Si le joueur adverse a une Creature active
J.attaquerJoueur(J2);
}else{//si l'adversaire n'a pas de creature active
std::cout<<"Vous ne pouvez pas attaquer. L'adversaire n'a pas de Creature."<<std::endl;
}

std::cout << "[Appuyez sur entrer pour continuer]" << std::endl;
if(pConsole->getInputKey()){}
}

void Match::Vague(Joueur& J, Joueur &J2){//Méthode pour utiliser la carte Speciale Vague Glacee

int nouveauPV,ancienPV;
int nouveauPV2,ancienPV2;
Creature* c;
Creature* c2;
c=J.getCreatureActive();//Pour simplifier l'écriture
c2=J2.getCreatureActive();

        if(J.getSpecialeActiveVide()==false){//condition si le joueur a bien une carte Speciale Active persistante
if(J.getSpecialeActive()->getNomCarte()=="Vague Glacee" && J.getVague()==false){//SI le joueur a active Vague Glacee, cet effet n'a lieu qu'une seule fois

    nouveauPV=c->getPV()-2;//on enleve 2 PV à la créature Active du Joueur J
    c->setPV(nouveauPV);
    nouveauPV2=c2->getPV()-2;//on enleve 2 PV à la créature Active du Joueur J
    c2->setPV(nouveauPV2);
if(c->getPV()==0){//Si la creature est morte
    J.ajouterCarteCimetiere(J.getCreatureActive());//On ajoute la creature au cimetiere
 J.setCreatureActiveVide(true);//on remet le boolen a true
}
if( c->getPV()<0){//Si la creature est morte ET que les degats touchent le joueur

J.setPV(J.getPV()+c->getPV());//on affecte les nouveaux PV au joueur
 J.setCreatureActiveVide(true);
}
if(c2->getPV()==0){//de même pour la creature de l'adversaire
    J2.ajouterCarteCimetiere(J2.getCreatureActive());
 J2.setCreatureActiveVide(true);
}
if( c2->getPV()<0){

J2.setPV(J2.getPV()+c2->getPV());
 J2.setCreatureActiveVide(true);
}
    J.setVague(true);//on met le bool à true pour ne pas refaire les mêmes changements
}
else if(J.getVague()==true && J.getSpecialeActive()->getNomCarte()!="Vague Glacee")//Si vague glacee a ete utilisee mais n'est plus en active
    {
ancienPV=c->getPV()+2;//on remet à l'état normal les parametres modifies
 c->setPV(ancienPV);

ancienPV2=c2->getPV()+2;
 c2->setPV(ancienPV2);

 J.setVague(false);//Remet le bool à false pour la prochaine utilisation d'une autre Carte Galvanisation
}
}
}

void Match::Victoire(Joueur&J, Joueur& J2){//Joueur J gagnant remporte l'enjeu et JOueur J2 perdant
std::vector<Carte*> CollecTemp;//Vecteur de cartes temporaire

for(auto elem:J.getCollection()){//On met toutes les cartes de la collection dans le vecteur temporaire

CollecTemp.push_back(elem);
}

CollecTemp.push_back(J.getEnjeu());//On rajoute les deux enjeux à la collection temporaire
CollecTemp.push_back(J2.getEnjeu());
J.setCollection(CollecTemp);//On attribue la nouvelle collection au joueur gagnant

}

void Match::LancerMatch(){//Pour lancer le match

bool test=false;
std::string ligne;

std::string nom1;
std::string nom2;

bool defaite1=false;
bool defaite2=false;
bool MatchNul=false;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


do{

           std::cout << "saisir Nom Joueur 1" << std::endl;
std::cin >> nom1;
           test=false;
      std::ifstream monFlux1("sauv.txt");

    if(monFlux1){

    while (getline(monFlux1,ligne))
       if(ligne==nom1)
        {test=true;
        }
    }
    else
   {
      std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." <<std::endl;
   }

   if(test==false)
    std::cout << std::endl << " Ce joueur n'existe pas ! " << std::endl << std::endl;

}while(test!=true);

do{
          std::cout << "saisir Nom Joueur 2" << std::endl;
std::cin >> nom2;

           test=false;
      std::ifstream monFlux1("sauv.txt");

    if(monFlux1){

    while (getline(monFlux1,ligne))

       if(ligne==nom2)
        {test=true;
        }
    }
    else
   {
      std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." <<std::endl;
   }
   if(test==false)
    std::cout << std::endl << " Ce joueur n'existe pas ! " << std::endl << std::endl;

}while(test!=true);


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int premierJoueur=0;
srand (time(NULL));

premierJoueur= (rand()%2)+1;//On prend un nombre aleatoire pour choisir le premier joueur qui joueura
if(premierJoueur==1){
m_J1.setNom(nom1);
m_J2.setNom(nom2);
}

if(premierJoueur==2){
m_J1.setNom(nom2);
m_J2.setNom(nom1);
}

std::cout << "[Appuyez sur entrer pour continuer]" << std::endl;
if(pConsole->getInputKey()){}

//Blindage connection Joueur
m_J1.charger(); //On récupère les informations des joueurs connectés
m_J2.charger();

system("cls");
if(m_J1.getCollection().size()>=21 && m_J2.getCollection().size()>=21){
//Chaque joueur crée son deck pour la partie
m_J1.CreerDeck();
system("cls");

m_J2.CreerDeck();


m_J1.melangerDeck();//on melange aleatoirement chacun des decks
m_J2.melangerDeck();


m_J1.piocherEnjeu();//Chaque joueur pioche son enjeu et le met de côté
m_J2.piocherEnjeu();

std::cout << "[Appuyez sur entrer pour lancer le match]" << std::endl;
if(pConsole->getInputKey()){}
system("cls");


std::cout<<m_J1.getNomJoueur()<<", tu es PILE"<<std::endl;
std::cout<<m_J2.getNomJoueur()<<", tu es FACE"<<std::endl;
std::cout <<"On lance l'ecu";
Sleep(700);
std::cout<<".";
Sleep(700);
std::cout<<".";
Sleep(700);
std::cout<<"."<<std::endl;
if(premierJoueur==1){

        std::cout<<"PILE ! "<<nom1<<" commence."<<std::endl;
}
if(premierJoueur==2){

        std::cout<<"FACE ! "<<nom2<<" commence."<<std::endl;
}

std::cout<<std::endl;
std::cout<<std::endl;
std::cout<<"                                             QUE ";
Sleep(500);
std::cout<<"LE ";
Sleep(500);
std::cout<<"COMBAT ";
Sleep(500);
std::cout<<"COMMENCE ";
Sleep(500);
std::cout<<"!";
Sleep(500);
std::cout<<"!";
Sleep(500);
std::cout<<"!";
Sleep(500);

do{

    system("cls");

afficherTerrain();//on affiche le terrain

if(m_J1.getNbCreatureDeck()==0 && m_J1.getCreatureActiveVide()==true){//Si le Joueur 1 n'a plus de Creature Active et plus de Creatures dans son deck,on déclare une défaite
defaite1=true;
}
else {//Sinon, le joueur joue son tour normalement


std::cout<<m_J1.getNomJoueur()<<", c'est ton tour !"<<std::endl;
std::cout << "[Appuyez sur entrer pour piocher]" << std::endl;
if(pConsole->getInputKey()){}

    Tour(m_J1,m_J2); //Affiche les actions du joueur 1

Vague(m_J1,m_J2);//Verifie s'il a utilise Vague Glacee

if(m_J2.getCreatureActiveVide()==false){//Si le joueur qu'il a attaque a bien une Creature Active
if(m_J2.getCreatureActive()->getPV()<=0){//Si laCreature attaquee est morte
    m_J2.ajouterCarteCimetiere(m_J1.getCreatureActive());//On met la Creature au cimetiere
m_J2.setCreatureActiveVide(true);//On met le bool à true puisqu'il n'y a plus de Creature
if( m_J2.getCreatureActive()->getPV()<0){//Si le joueur subit aussi des degats
    m_J2.setPV(m_J1.getPV()+m_J1.getCreatureActive()->getPV());//On enleve au PV du joueur, les dégats infligés en trop à la créature
}
}
}
}


//FIN TOUR J1
////DEBUT TOUR J2

    system("cls");
//De même que pour le joueur J1
afficherTerrain();
if(m_J2.getNbCreatureDeck()==0 && m_J2.getCreatureActiveVide()==true){
 defaite2=true;
}
else{
std::cout<<m_J2.getNomJoueur()<<", c'est ton tour !"<<std::endl;

std::cout << "[Appuyez sur entrer pour Piocher.]" << std::endl;
if(pConsole->getInputKey()){}

Tour(m_J2,m_J1);

Vague(m_J2,m_J1);
if(m_J1.getCreatureActiveVide()==false){
if(m_J1.getCreatureActive()->getPV()<=0){
    m_J1.ajouterCarteCimetiere(m_J1.getCreatureActive());
m_J1.setCreatureActiveVide(true);

if( m_J1.getCreatureActive()->getPV()<0){
    m_J1.setPV(m_J1.getPV()+m_J1.getCreatureActive()->getPV());//On enleve au PV du joueur, les dégats infligés en trop à la créature
}
}
}

}

if(m_J1.getCreatureActiveVide()==false && m_J2.getCreatureActiveVide()==false && m_J1.getDeck().size()==0 && m_J2.getDeck().size()==0){
    MatchNul=true;
}//On verifie qu'il n'y a pas match nul

}while(m_J1.getPV()!=0 && m_J2.getPV()!=0 &&  defaite1==false && defaite2==false && MatchNul==false); // Le jeu s'arrete quand l'un des joueurs n'a plus de PV ou n'a plus de creatures dans son deck

//Affichagedes enjeux
std::cout<<"Le combat est fini."<<std::endl;
std::cout<<"Enjeu de "<<m_J1.getNomJoueur()<<std::endl;
m_J1.getEnjeu()->afficher();
std::cout<<std::endl;
std::cout<<"Enjeu de "<<m_J2.getNomJoueur()<<std::endl;
m_J2.getEnjeu()->afficher();
std::cout<<std::endl;


if(m_J1.getPV()==0){//Si c'est le joueur J1 qui n'avait plus de PV
    std::cout<<m_J1.getNomJoueur()<<" a perdu..."<<std::endl;
        std::cout<<m_J2.getNomJoueur()<<" a gagne !!! Vous remportez 5 pieces d'or"<<std::endl;
Victoire(m_J2,m_J1);//J2 gagne
m_J2.setArgent(m_J2.getArgent()+5);//J2 recupere 5 pieces d or

}
else if(m_J2.getPV()==0){//Si J2 n'a plus de PV
        std::cout<<m_J2.getNomJoueur()<<" a perdu..."<<std::endl;
    std::cout<<m_J1.getNomJoueur()<<" a gagne!!! Vous remportez 5 pieces d'or"<<std::endl;
Victoire(m_J1,m_J2);
m_J1.setArgent(m_J1.getArgent()+5);
}
else if(defaite1){//Si defaite J1 par manque d cartes Creatures
        std::cout<<m_J1.getNomJoueur()<<" a perdu puisqu'il ne peut plus jouer de Creatures"<<std::endl;
    std::cout<<m_J2.getNomJoueur()<<" a gagne !!!! Vous remportez 5 pieces d'or"<<std::endl;
Victoire(m_J2,m_J1);
m_J2.setArgent(m_J2.getArgent()+5);

}
else if(defaite2){

        std::cout<<m_J2.getNomJoueur()<<"a perdu puisqu'il ne peut plus jouer de Creatures"<<std::endl;
Victoire(m_J1,m_J2);
    std::cout<<m_J1.getNomJoueur()<<" a gagne!!!! Vous remportez 5 pieces d'or"<<std::endl;
    m_J1.setArgent(m_J1.getArgent()+5);
}
else if(MatchNul==true){//Si match nul

std::cout<<"MATCH NUL ! Vous recuperez vos enjeux!"<<std::endl;
m_J1.getCollection().push_back(m_J1.getEnjeu());
m_J2.getCollection().push_back(m_J2.getEnjeu());
}
}
else{//Else de la condition if qui vériife que le joueur a assez de carte spour creer un deck
    if(m_J1.getCollection().size()<21){
        std::cout<<m_J1.getNomJoueur()<<" n'a pas assez de cartes."<<std::endl;
    }
if(m_J2.getCollection().size()<21){
        std::cout<<m_J2.getNomJoueur()<<" n'a pas assez de cartes."<<std::endl;
    }

}
m_J1.setPV(8);//Remise des PV à 8 pour les joueurs
m_J2.setPV(8);
std::cout << "[Appuyez sur entrer pour Retour au menu]" << std::endl;
if(pConsole->getInputKey()){}

}


void Match::afficherCarte(int x, int y)
{
    for(int i=1;i<11;i++){
    pConsole->gotoLigCol(x-1,y+i);
    std::cout<< "_";
    pConsole->gotoLigCol(x+8,y+i);
    std::cout<< "_";}

    for(int i=0;i<9;i++){
    pConsole->gotoLigCol(x+i,y);
    std::cout<< "|" << std::endl;
   pConsole->gotoLigCol(x+i,y+11);
    std::cout<< "|";}


}

void Match::afficherTerrain(){


for(int i=0;i<30;i++)
{pConsole->gotoLigCol(i,70);
std::cout<< "||" << std::endl;

}
for(int i=0;i<150;i++)
{pConsole->gotoLigCol(30,i);
std::cout<< "-" << std::endl;

}


pConsole->gotoLigCol(1,30);
std::cout << "Joueur 1: " << m_J1.getNomJoueur();
pConsole->gotoLigCol(2,36);
std::cout << "PV: " << m_J1.getPV();

pConsole->gotoLigCol(1,100);
std::cout << "Joueur 2: " << m_J2.getNomJoueur();
pConsole->gotoLigCol(2,106);
std::cout << "PV: " << m_J2.getPV();

//afficher infos Creatures J1
pConsole->gotoLigCol(5,43);
std::cout << "Creature Active";
afficherCarte(7,45);
m_J1.afficherCreatureActiveTerrain(9,48);

//afficher infos Creatures J2
pConsole->gotoLigCol(5,84);
std::cout << "Creature Active";
afficherCarte(7,86);
m_J2.afficherCreatureActiveTerrain(9,89);

pConsole->gotoLigCol(5,21);
std::cout << "Speciale";
afficherCarte(7,20);

pConsole->gotoLigCol(5,116);
std::cout << "Speciale";
afficherCarte(7,115);

pConsole->gotoLigCol(24,5);
std::cout << "Energies";
m_J1.afficherReserveEnergieTerrain(25,5);

pConsole->gotoLigCol(24,75);
std::cout << "Energies";
m_J2.afficherReserveEnergieTerrain(25,75);


m_J1.afficherSpecialeActiveTerrain(13,10); //Affichage de la carte Speciale Active/persistante
m_J2.afficherSpecialeActiveTerrain(13,106);

m_J1.afficherCimetiereTerrain(28,5);
m_J2.afficherCimetiereTerrain(29,5);
if(m_J1.getCreatureActiveVide()==false){
m_J1.getCreatureActive()->getAttaque1()->afficherAttaqueTerrain(18,5,1);
m_J1.getCreatureActive()->getAttaque2()->afficherAttaqueTerrain(18,38,2);}

if(m_J2.getCreatureActiveVide()==false){
m_J2.getCreatureActive()->getAttaque1()->afficherAttaqueTerrain(19,75,1);
m_J2.getCreatureActive()->getAttaque2()->afficherAttaqueTerrain(19,108,2);}

pConsole->gotoLigCol(32,5);

}


