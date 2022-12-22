#include "Joueur.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "Buffer.h"

void gotoligcolJoueur( int lig, int col )
{
// ressources
COORD mycoord;

mycoord.X = col;
mycoord.Y = lig;
SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}


//Source : http://www.cplusplus.com/reference/algorithm/random_shuffle/
//Utilisation de la fonction random_shuffle pour melanger les elements d'un vector
template <class RandomAccessIterator, class RandomNumberGenerator> inline
  void random_shuffle (RandomAccessIterator first, RandomAccessIterator last,
                       RandomNumberGenerator& gen);

Joueur::Joueur(std::string nomJoueur):m_nomJoueur(nomJoueur) //constructeur de Joueur qui initialise un nom et les elements de la boutique
{
    //Ajoute toutes les cartes dans la boutique
    boutique.push_back(new Archer);
    boutique.push_back(new Arbaletrier);
        boutique.push_back(new Guerrier);
        boutique.push_back(new Cavalier);
        boutique.push_back(new Catapulte);
        boutique.push_back(new Belier);
        boutique.push_back(new Jeanne_D_arc);
        boutique.push_back(new Lancelot_duLac);
        boutique.push_back(new Arthur_Pendragon);

 boutique.push_back(new Energie(1,1,"Corps a corps","Energie Corps a corps"));
 boutique.push_back(new Energie(1,2,"Distance","Energie Distance"));
 boutique.push_back(new Energie(1,3,"Machine","Energie Machine"));
boutique.push_back(new Energie(2,4,"Heros","Energie Heros"));

 boutique.push_back(new Speciale(1,"Priere","Ajoute 2 PV a votre creature",true,true));
 boutique.push_back(new Speciale(2,"Galvanisation","Multiplie par 2 la puissance d'attaque de la creature mais elle perd la moitie de ses PV",true,false));
 boutique.push_back(new Speciale(1,"Resurrection","Recupere une carte aleatoire du cimetiere",false,true));
 boutique.push_back(new Speciale(1,"Espion","Vous pouvez regardez la premiere carte du Deck de l'adversaire",false,true));
 boutique.push_back(new Speciale(2,"Vague","Diminue les PV des creatures de 2PV",true,false));
 boutique.push_back(new Speciale(1,"Butin","Vous pouvez regarder votre enjeu et le changer",false,true));


}

Joueur::Joueur() // Constructeur par defaut de Joueur qui initialise les elements de la boutique
{
  boutique.push_back(new Archer);
    boutique.push_back(new Arbaletrier);
        boutique.push_back(new Guerrier);
        boutique.push_back(new Cavalier);
        boutique.push_back(new Catapulte);
        boutique.push_back(new Belier);
        boutique.push_back(new Arthur_Pendragon);
        boutique.push_back(new Lancelot_duLac);
        boutique.push_back(new Jeanne_D_arc);


 boutique.push_back(new Energie(1,1,"Corps a corps","Energie Corps a corps"));
 boutique.push_back(new Energie(1,2,"Distance","Energie Distance"));
 boutique.push_back(new Energie(1,3,"Machine","Energie Machine"));
boutique.push_back(new Energie(2,4,"Heros","Energie Heros"));

 boutique.push_back(new Speciale(1,"Priere","Ajoute 2 PV a votre creature",true,true));
 boutique.push_back(new Speciale(1,"Butin","Vous pouvez regarder votre enjeu et le changer",false,true));
 boutique.push_back(new Speciale(1,"Espion","Vous pouvez regardez la premiere carte du Deck de l'adversaire",false,true));
 boutique.push_back(new Speciale(1,"Resurrection","Recupere une carte aleatoire du cimetiere",false,true));
 boutique.push_back(new Speciale(2,"Vague","Diminue les PV des creatures de 2PV",true,false));
 boutique.push_back(new Speciale(2,"Galvanisation","Multiplie par 2 la puissance d'attaque de la creature mais elle perd la moitie de ses PV",true,false));

}

Joueur::~Joueur()//Destructeur de Joueur
{

}

void Joueur::setNom(std::string nom){//Setter qui permet de changer le nom du Joueur

m_nomJoueur=nom;

}


 void Joueur::ajouterCarteCollec(Carte* C){ //Méthode qui ajouter une carte rentrée en paramètre dans la collection du Joueur. Il perd dans son argent l'équivalent du prix de la carte

if(m_argent>=C->getPrix()){//Condition qui verifie que le joueur a assez d'argent pour payer la carte qui a un prix

m_collection.push_back(C);
m_argent-=C->getPrix();

}
else {

    std::cout <<"Vous n'avez pas assez d'or !"<<std::endl;//Si le joueur n'a pas assez d'argent

std::cout << "[Appuyez sur entrer pour continuer]" << std::endl;
if(pConsole->getInputKey()){}
}

 }

void Joueur::ajouterCarteDeck(Carte* C){//Méthode qui ajoute une carte entrée en paramètre dans le deck du joueur qui est une file

m_deck.push(C);
}
 void Joueur::ajouterCarteCimetiere(Carte* C){//Méthode qui ajoute une carte rentree en parametre dans le cimetiere du joueur

m_cimetiere.push_back(C);//La carte est ajoutee dans le vector m_cimetiere du joueur


 }
void Joueur::afficherDeck(){//Methode pour afficher le deck du joueur
std::queue<Carte*> tempo;//Création d'une file temporaire de Carte* pour y transférer les cartes avant de les pop
std::cout<<"Voici votre deck :"<<std::endl;

int taille= m_deck.size();//initialise la variable taille avec la taille du deck du joueur.

    for(int i=0; i<taille; i++ ){//Boucle for qui affiche chacune des cartes du deck

    m_deck.front()->afficher();//Affiche la carte au début de la file
    tempo.push(m_deck.front());//Ajoute la carte au début du queue temporaire
    m_deck.pop();//supprime la carte au début du deck

        std::cout << std::endl;
        }
        for(int i=0; i<taille; i++){//Boucle for qui rajoute un par un les elements places dans le queue temporaire
            m_deck.push(tempo.front());
            tempo.pop();
        }
}

void Joueur::piocherEnjeu(){//Méthode qui permet au joueur de piocher l'enjeu en début de match
bool carte=false;
int i=0;

if(m_deck.front()->getTypeCarte()==1){//Condition If Si la premiere carte piochee est une Creature
    m_nbCreatureDeck--;//On enleve une Creature du nombre de Creatures dans le deck
}
m_Enjeu=m_deck.front();//Initialise la Carte m_Enjeu du joueur avec celle située au dessus du deck
m_deck.pop();//Supprime la carte du deck

for(auto elem:m_collection){//Boucle for qui parcourt toute la collection pour trouver l'emplacement de l'Enjeu
        if(elem->getNomCarte()==m_Enjeu->getNomCarte()){//Si l'element a le meme nom de la carte
                carte=true;//On change le bool en true, pour ne pas compter une Carte avec le même nom
        }
        if(elem->getNomCarte()!=m_Enjeu->getNomCarte() && carte==false){//SI l'element ne correspond pas au nom et que le bool est faux
            i++;//On increment i pour continuer la boucle
                    }
}

m_collection.erase(m_collection.begin()+i);//On efface la carte Enjeu situee à l'emplacement i

}


void Joueur::melangerDeck(){//Méthode qui permet de mélanger le Deck du joueur en début de match
std::srand (unsigned (std::time(0)));//utilisation de srand pour effectuer cela aléatoirement

int taille= m_deck.size();
std::vector<Carte*>melange;//Création d'un vector de Carte* temporaire pour mélanger les cartes du queue

    for(int i=0; i<taille; i++ ){//Boucle for pour ajouter chacune des cartes du deck dans le vector melange

    melange.push_back(m_deck.front());
    m_deck.pop();//Suppression de chacune des cartes du deck
        }

std::random_shuffle (melange.begin(), melange.end());//Utilisation de random_shuffle pour mélanger aléatoirement les éléments d'un vector

        for(auto elem:melange){//On remet les cartes dans le deck après le mélange dans le vector
            m_deck.push(elem);
        }

}

void Joueur::afficherCimetiere() const{//Méthode qui permet d'afficher le cimetiere
 std::cout << std::endl;
    std::cout << "Votre cimetiere :" << std::endl;

    for (auto elem:m_cimetiere)//Boucle for qui affiche chacun des elements du cimetiere du Joueur
        {elem->afficherNom();//Permet d'afficher uniquement le nom de la Carte
        std::cout << std::endl;}

}

void Joueur::piocher(Joueur& J){//méthode pour faire piocher le joueur dans son deck
int choixUtilisationSpe;
int choix;
int typeEnergie;
typeEnergie=((Energie*)m_deck.front())->getTypeEnergie();//Variable pour simplifier l'ecriture

if(m_CreatureActiveVide==true && m_nbCreatureDeck!=0){ //Si le joueur n'a pas de CreatureActive en jeu et qu'il lui reste des Creatures a piocher dans son deck
std::cout<<"Vous n'avez pas de creature active."<<std::endl;
std::cout<<"Tu as pioche comme Creature Active :"<<std::endl;

do{

if(m_deck.front()->getTypeCarte()==1){ //si la carte piochee est une Creature (type=1)
m_deck.front()->afficher(); // Afficher premiere carte du deck
    setCreatureActive((Creature*)m_deck.front());//On place la premiere carte du deck en tant que Creature Active
 m_nbCreatureDeck--;//On decremente le nombre de Creatures dans le deck
 }
else if(m_deck.front()->getTypeCarte()==2){ //si carte piochee est Energie (type=2)
        m_deck.push(m_deck.front());//Carte renvoyee en dessous de la pioche

}
else if(m_deck.front()->getTypeCarte()==3){ //Si la carte piochee est une carte Speciale (type 3)

m_deck.push(m_deck.front());//Carte renvoyee en dessous de la pioche
}

m_deck.pop();//On supprime la carte au dessus du deck que le joueur vient de piocher
}while(m_CreatureActiveVide==true);//Cette boucle do while s'effectue tant que le Joueur n'a pas de Créature Active sur le terrain

}
//Si le joueur a déjà une Créature Active donc si CreatureActiveVide = false
else{
        std::cout<<"Tu as pioche :"<<std::endl;
m_deck.front()->afficher();//on affiche la Carte piochee

if(m_deck.front()->getTypeCarte()==1){ //si la carte piochee est une Creature (type=1)
while(choix!=1 && choix!=2){//On repete la question tant qu'il n'a pas choisi oui ou non
 std::cout<<"Voulez vous mettre cette creature en active ? 1.OUI  2.NON" <<std::endl;

while(true)//Blindage buffer pour saisie incorrecte
        {
            std::cin>>choix;
            if(std::cin.eof() || std::cin.bad())
            {
                std::cerr << "Une erreur interne est survenue." << std::endl;

                if(std::cin.eof()) // Si c'est la fin du flux d'entrée, il faut sortir de la boucle
                {
                    break;
                }
                vider_buffer(); // On remet cin dans un état valide et vide le buffer
                continue;
            }
            else if(std::cin.fail())
            {
                std::cerr << "Erreur, saisie incorrecte. Veuillez ressaisir un chiffre." << std::endl;
                vider_buffer(); // On remet cin dans un état valide et vide le buffer
                continue;
            }
            break; // On ne sort de la boucle que s'il n'y a eu aucune erreur ou que c'est la fin du flux d'entrée
        }
}
 if(choix==1){//Si le joueur veut mettre la creature piochee en Creature active
    setCreatureActive((Creature*)m_deck.front());//On place la premiere carte du deck en tant que Creature Active
    afficherCreatureActive();//Affichage de la Creature placée
    m_nbCreatureDeck--;// On decremente le nombre de Creatures du Deck puisque la Carte a ete piochee

 }
 else if(choix==2){//Si le joueur choisit NON
    std::cout<<"Vous gardez votre creature active. "<<std::endl;
ajouterCarteCimetiere(m_deck.front());//On met la Carte au cimetiere
    m_nbCreatureDeck--;//On decremente le nombre de Creature du deck

 }

}

else if(m_deck.front()->getTypeCarte()==2){ //si carte piochee est Energie (type=2)
    if(typeEnergie==1){//Si la carte Energie piochee est de type Corps à Corps
m_nbCaC++;//On incrémente le nombre de Carte Corps à corps que possède le joueur dans son deck
    }
    else if(typeEnergie==2){//Si la carte Energie piochee est de type Distance

        m_nbDistance++;//On incrémente le nombre de Carte Distance que possède le joueur dans son deck
    }
    else if(typeEnergie==3){//Si la carte Energie piochee est de type Machine
m_nbMachine++;//On incrémente le nombre de Carte Machine que possède le joueur dans son deck
    }
     else if(typeEnergie==4){//Si la carte Energie piochee est de type Héros
m_nbHeros++;//On incrémente le nombre de Carte Héros que possède le joueur dans son deck
    }
}
else if(m_deck.front()->getTypeCarte()==3){ //Si la carte piochee est une carte Speciale (type 3)
while(choixUtilisationSpe!=2 && choixUtilisationSpe!=1){//Boucle repetee tant que le joueur saisit mal OUI ou NON
std::cout<<"Voulez-vous utiliser cette carte Speciale? 1.OUI   2.NON"<<std::endl;
std::cin>>choixUtilisationSpe;
}
if(choixUtilisationSpe==1){//S'il veut utiliser la Carte Speciale

        if(m_deck.front()->getNomCarte()=="Priere"){//Si la Carte SPeciale est Priere


CreatureActive->setPV(CreatureActive->getPV()+2);//La Creature Active du joueur gagne 2 PV
ajouterCarteCimetiere(m_deck.front());//oOn met la Carte Speciale utilisee au cimetiere

        }
        else if(m_deck.front()->getNomCarte()=="Espion")//Si la carte Speciale est Espion
        {
        std::cout<<"Carte vue :"<<std::endl;
J.getDeck().front()->afficher();//On affiche la premiere carte du deck
ajouterCarteCimetiere(m_deck.front());//On ajoute la carte utilisee au cimetiere


        }
        else if(m_deck.front()->getNomCarte()=="Resurrection"){//Si la carte Speciale est Resurrection

Carte* C=new Carte;
int nbrand =rand()%m_cimetiere.size();//On prend un nombre aleatoire pour saisir une carte aleatoire du cimetiere
C=m_cimetiere[nbrand];
C->afficher();//on affiche la carte aleatoire du cimetiere
ajouterCarteCimetiere(m_deck.front());//On ajoute la carte utilisee dans le cimetiere

int chx;
std::cout<<"Voulez-vous recuperer cette carte dans votre deck?  1.OUI  2.NON"<<std::endl;
while(true)//Blindage buffer
        {
            std::cin>>chx;
            if(std::cin.eof() || std::cin.bad())
            {
                std::cerr << "Une erreur interne est survenue." << std::endl;

                if(std::cin.eof()) // Si c'est la fin du flux d'entrée, il faut sortir de la boucle
                {
                    break;
                }
                vider_buffer(); // On remet cin dans un état valide et vide le buffer
                continue;
            }
            else if(std::cin.fail())
            {
                std::cerr << "Erreur, saisie incorrecte. Veuillez ressaisir un chiffre." << std::endl;
                vider_buffer(); // On remet cin dans un état valide et vide le buffer
                continue;
            }
            break; // On ne sort de la boucle que s'il n'y a eu aucune erreur ou que c'est la fin du flux d'entrée
        }
if(chx==1){//S'il veut garder la carte vue

m_deck.push(C);//La carte est rajoutee a la fin de son deck
m_cimetiere.erase(m_cimetiere.begin()+nbrand);//On efface la carte du cimetiere
    }
if(chx==2){//S'il ne veut pas garder la carte, on ne fait rien. Elle reste au cimetiere
    std::cout<<"Cette carte reste au cimetiere"<<std::endl;
}
}

else if(m_deck.front()->getNomCarte()=="Galvanisation"){//Si la carte Speciale est Galvanisation

if(m_SpecialeActiveVide==true){//S'il n'a pas de Speciale Active Persistance
//On met Galvanisation en Speciale ACtive
setSpecialeActive(new Speciale(2,"Galvanisation","Multiplie par 2 la puissance d'attaque de la creature mais elle perd la moitie de ses PV",true,false));

m_SpecialeActiveVide=false;//Il a maintenant une Speciale Active
}else{//S'il a une SPeciale Active déjà
    int choixgalva;
std::cout<<"Vous avez deja une Speciale active. Voulez-vous la remplacer?  1.OUI   2.NON"<<std::endl;
while(true)
        {
            std::cin>>choixgalva;
            if(std::cin.eof() || std::cin.bad())
            {
                std::cerr << "Une erreur interne est survenue." << std::endl;

                if(std::cin.eof()) // Si c'est la fin du flux d'entrée, il faut sortir de la boucle
                {
                    break;
                }
                vider_buffer(); // On remet cin dans un état valide et vide le buffer
                continue;
            }
            else if(std::cin.fail())
            {
                std::cerr << "Erreur, saisie incorrecte. Veuillez ressaisir un chiffre." << std::endl;
                vider_buffer(); // On remet cin dans un état valide et vide le buffer
                continue;
            }
            break; // On ne sort de la boucle que s'il n'y a eu aucune erreur ou que c'est la fin du flux d'entrée
        }
if(choixgalva==1){//S'il veut remplacer sa speciale
    setSpecialeActive(new Speciale(2,"Galvanisation","Multiplie par 2 la puissance d'attaque de la creature mais elle perd la moitie de ses PV",true,false));
//on la remplace
}
if(choixgalva==2){//S'il ne veut pas remplacer sa Speciale
ajouterCarteCimetiere(m_deck.front());//On ajoute la carte piochee au cimetiere

    std::cout<<"Vous gardez votre Speciale Active."<<std::endl;
}
}
}
else if(m_deck.front()->getNomCarte()=="Butin")//Si la carte Speciale est Butin
        {
            ajouterCarteCimetiere(m_deck.front());//on ajoute la carte utilisee au cimetiere

            int choixx;
            std::cout<<"Voici votre enjeu : "<<std::endl;
            m_Enjeu->afficherNom();//on affiche l'enjeu
            std::cout<<std::endl;
            std::cout<<"Voulez-vous le changer? 1.OUI 2.NON "<<std::endl;
            std::cin>>choixx;
            m_deck.pop();//on supprime la carte piochee
            std::cout<<std::endl;
            if(choixx==1)//S'il veut changer l'enjeu
            {
                setEnjeu(m_deck.front());//on met une carte en Enjeu
                std::cout<<"Votre enjeu a ete modifie."<<std::endl;
            }
            else if(choixx==2){//S'il ne veut pas changer son Enjeu
                std::cout<<"Vous gardez votre enjeu."<<std::endl;
            }
        }
        else if(m_deck.front()->getNomCarte()=="Vague Glacee"){//Si la Carte SPeciale est Vague Glacee

if(m_SpecialeActiveVide==true){//S'il n' a pas déjà une persistante Active
//On met Vague Glacee en SpecialeACtive
setSpecialeActive(new Speciale(2,"Vague Glacee","Diminue les PV des creatures de 2PV",true,false));

m_SpecialeActiveVide=false;
}else{//s'il a déjà une Speciale Active
    int choixVague;
std::cout<<"Vous avez deja une Speciale active. Voulez-vous la remplacer?  1.OUI   2.NON"<<std::endl;
std::cin>>choixVague;
if(choixVague==1){//S'il  veut remplacer sa carte Speciale
    setSpecialeActive(new Speciale(2,"Vague Glacee","Diminue les PV des creatures de 2PV",true,false));

}
if(choixVague==2){//S'il ne veut pas remplacer sa carte Speciale

    std::cout<<"Vous gardez votre Speciale Active."<<std::endl;
ajouterCarteCimetiere(m_deck.front());

}
}
        }

}
if(choixUtilisationSpe==2){//Si le joueur ne veut pas utiliser la Carte Speciale qu'il a pioché

refusSpeciale((Speciale*)m_deck.front());//La carte Speciale refusee va soit au cimetiere ou dans la pioche selon sa description
ajouterCarteCimetiere(m_deck.front());

}
}
m_deck.pop();//On supprime la carte au dessus du deck que le joueur vient de piocher

}

}

void Joueur::afficherCollec() const//Méthode pour Afficher la collection du joueur
{

    std::cout << std::endl;
    std::cout << "Votre collection :" << std::endl;

    for (auto elem:m_collection)//Boucle pour affiche chacun des elements du vector
        {elem->afficher();
        std::cout << std::endl;}
}


void Joueur::afficherReserveEnergie() const{//Méthode pour afficher le nombre de cartes Energie que le joueur a déjà pioché

std::cout<<"Votre reserve d'energie : "<<std::endl;
std::cout<<"Corps a corps : " <<m_nbCaC<<"               "<<"   Machine : " <<m_nbMachine<<std::endl;//Affichage de chacun des types de Cartes Energie
std::cout<<"Distance : " <<m_nbDistance<<"                       "<<"Heros : " <<m_nbHeros<<std::endl;
std::cout<<std::endl;

}
void Joueur::setCreatureActive(Creature* C)//Setter qui permet de placer ou modifier la Créature Active
{
    CreatureActive=C;//Remplace la Créature Active par celle choisie
    m_CreatureActiveVide=false;//Mets le boolean à false. Cela signifie que la place de Créature Active n'est pas vie. Elle est maintenant occupée.
}

void Joueur::setSpecialeActive(Speciale* Spe){

        SpecialeActive=Spe;//Remplace la Speciale Active par celle choisie
}

void Joueur::afficherCreatureActive() const//Méthode qui affiche la Créature Active ou non
{
    if(m_CreatureActiveVide==false){//Condition If qui vérifie que la place de Créature Active est occupée
    std::cout << "Votre creature active :" << std::endl;
    CreatureActive->afficher();//Affiche uniquement le nom de la Créature
    std::cout <<std::endl;
    }
    else{//Si le boolean = true, le joueur n'a pas de Créature Active pour le moment
        std::cout<<"Il n'y a pas de Creature Active" <<std::endl;
    }
}

 void Joueur :: CreerDeck(){//Méthode qui permet de créer un deck
//Création de variables qui vont contenir le nombre de Cartes possédées par le Joueur dans sa collection
int nbArcher=0;
int nbGuerrier=0;
int nbCavalier=0;
int nbArbaletrier=0;
int nbCatapulte=0;
int nbBelier=0;
int nbArthur=0;
int nbJeanne=0;
int nbLancelot=0;

int nbCaC=0;
int nbDistance=0;
int nbMachine=0;
int nbHeros=0;

int nbGalvanisation=0;
int nbPriere=0;
int nbVague=0;
int nbResurrection=0;
int nbEspion=0;
int nbButin=0;

//Création de variables qui vont contenir le nombre de Cartes choisies par le joueur dans son deck


int nbArcherDeck=0;
int nbGuerrierDeck=0;
int nbCavalierDeck=0;
int nbArbaletrierDeck=0;
int nbCatapulteDeck=0;
int nbBelierDeck=0;
int nbArthurDeck=0;
int nbJeanneDeck=0;
int nbLancelotDeck=0;

int nbCaCDeck=0;
int nbDistanceDeck=0;
int nbMachineDeck=0;
int nbHerosDeck=0;

int nbGalvanisationDeck=0;
int nbPriereDeck=0;
int nbVagueDeck=0;
int nbResurrectionDeck=0;
int nbEspionDeck=0;
int nbButinDeck=0;

int nbCartesRestantes=21; //Nombre de cartes restantes à mettre dans le deck

//Ici, on va parcourir la collection du joueur et incrémenter les variables à chaque fois qu'on trouve la carte Correspondante
     for(auto elem : m_collection){
            if(elem->getNomCarte()=="Archer"){//Condition if où on va regarder le nom de la Carte
                nbArcher++;}//on incrémente le nombre de Cartes possédées avec ce nom là
            if(elem->getNomCarte()=="Guerrier"){
                nbGuerrier++;}
                if(elem->getNomCarte()=="Cavalier"){
                nbCavalier++;}
                if(elem->getNomCarte()=="Arbaletrier"){
                nbArbaletrier++;}
                if(elem->getNomCarte()=="Catapulte"){
                nbCatapulte++;}
                if(elem->getNomCarte()=="Belier"){
                nbBelier++;}
                if(elem->getNomCarte()=="Arthur Pendragon"){
                nbArthur++;}
                if(elem->getNomCarte()=="Jeanne d'Arc"){
                nbJeanne++;}
                if(elem->getNomCarte()=="Lancelot du lac"){
                nbLancelot++;}

                if(elem->getNomCarte()=="Corps a corps"){
                nbCaC++;}
                if(elem->getNomCarte()=="Distance"){
                nbDistance++;}
                if(elem->getNomCarte()=="Machine"){
                nbMachine++;}
                if(elem->getNomCarte()=="Heros"){
                nbHeros++;}

            if(elem->getNomCarte()=="Galvanisation"){
                nbGalvanisation++;}

            if(elem->getNomCarte()=="Vague Glacee"){
                nbVague++;}
                if(elem->getNomCarte()=="Priere"){
                nbPriere++;}
                if(elem->getNomCarte()=="Resurrection"){
                nbResurrection++;}
                if(elem->getNomCarte()=="Butin"){
                nbButin++;}
                if(elem->getNomCarte()=="Espion"){
                nbEspion++;}
     }


 while(m_deck.size()<21){// Boucle while tant que le joueur n'a pas choisi 21 cartes. Donc tant que la taille de son deck <21
        int choix;
         system("cls");
std::cout<<"                                        "<<m_nomJoueur<<", A toi de creer ton Deck !"<<std::endl;
std::cout<<"Vous avez dans votre collection :                                           Vous avez dans votre deck :" <<std::endl;//Affichage de chaque carte de la collection et leur nombre
std::cout<<"        Creature :                                                                      Creature :"<<std::endl;
std::cout<<"1. Guerrier (nb= " <<nbGuerrier<<")"<<"                                                             1. Guerrier(nb= " <<nbGuerrierDeck<<")"<<std::endl;
std::cout<<"2. Cavalier (nb= " <<nbCavalier<<")"<<"                                                             2. Cavalier (nb= " <<nbCavalierDeck<<")"<<std::endl;
std::cout<<"3. Archer (nb= " <<nbArcher<<")"<<"                                                               3. Archer (nb= " <<nbArcherDeck<<")"<<std::endl;
std::cout<<"4. Arbaletrier (nb= " <<nbArbaletrier<<")"<<"                                                          4. Arbaletrier (nb= " <<nbArbaletrierDeck<<")"<<std::endl;
std::cout<<"5. Catapulte (nb= " <<nbCatapulte<<")"<<"                                                            5. Catapulte (nb= " <<nbCatapulteDeck<<")"<<std::endl;
std::cout<<"6. Belier (nb= " <<nbBelier<<")"<<"                                                               6. Belier (nb= " <<nbBelierDeck<<")"<<std::endl;
std::cout<<"7. Arthur Pendragon (nb= " <<nbArthur<<")"<<"                                                     7. Arthur Pendragon (nb= " <<nbArthurDeck<<")"<<std::endl;
std::cout<<"8. Jeanne d'Arc (nb= " <<nbJeanne<<")"<<"                                                         8. Jeanne d'Arc (nb= " <<nbJeanneDeck<<")"<<std::endl;
std::cout<<"9. Lancelot du lac (nb= " <<nbLancelot<<")"<<"                                                      9. Lancelot du lac (nb= " <<nbLancelotDeck<<")"<<std::endl;

std::cout<<"        Speciale :                                                                       Speciale :"<<std::endl;
std::cout<<"10.Galvanisation (nb= " <<nbGalvanisation<<")"<<"                                                        10.Galvanisation (nb= " <<nbGalvanisationDeck<<")"<<std::endl;
std::cout<<"11.Priere (nb= " <<nbPriere<<")"<<"                                                               11.Priere (nb= " <<nbPriereDeck<<")"<<std::endl;
std::cout<<"12.Butin (nb= " <<nbButin<<")"<<"                                                                12.Butin (nb= " <<nbButinDeck<<")"<<std::endl;
std::cout<<"13.Espion (nb= " <<nbEspion<<")"<<"                                                               13.Espion (nb= " <<nbEspionDeck<<")"<<std::endl;
std::cout<<"14.Vague Glacee (nb= " <<nbVague<<")"<<"                                                         14.Vague Glacee (nb= " <<nbVagueDeck<<")"<<std::endl;
std::cout<<"15.Resurrection (nb= " <<nbResurrection<<")"<<"                                                         15.Resurrection (nb= " <<nbResurrectionDeck<<")"<<std::endl;

std::cout<<"        Energie :                                                                        Energie :"<<std::endl;
std::cout<<"16.Energie Corps a Corps (nb= " <<nbCaC<<")"<<"                                                16.Energie Corps a Corps (nb= " <<nbCaCDeck<<")"<<std::endl;
std::cout<<"17.Energie Distance (nb= " <<nbDistance<<")"<<"                                                     17.Energie Distance (nb= " <<nbDistanceDeck<<")"<<std::endl;
std::cout<<"18.Energie Machine (nb= " <<nbMachine<<")"<<"                                                      18.Energie Machine (nb= " <<nbMachineDeck<<")"<<std::endl;
std::cout<<"19.Energie Heros (nb= " <<nbHeros<<")"<<"                                                        19.Energie Heros (nb= " <<nbHerosDeck<<")"<<std::endl;
std::cout<<std::endl;
std::cout<<"Il vous reste encore "<<nbCartesRestantes<<" places pour rejoindre votre armee"<<std::endl;

std::cout<<"Quelle carte voulez-vous ajouter dans votre deck ?"<<std::endl;
while(true)
        {
            std::cin>>choix;
            if(std::cin.eof() || std::cin.bad())
            {
                std::cerr << "Une erreur interne est survenue." << std::endl;

                if(std::cin.eof()) // Si c'est la fin du flux d'entrée, il faut sortir de la boucle
                {
                    break;
                }
                vider_buffer(); // On remet cin dans un état valide et vide le buffer
                continue;
            }
            else if(std::cin.fail())
            {
                std::cerr << "Erreur, saisie incorrecte. Veuillez ressaisir un chiffre." << std::endl;
                vider_buffer(); // On remet cin dans un état valide et vide le buffer
                continue;
            }
            break; // On ne sort de la boucle que s'il n'y a eu aucune erreur ou que c'est la fin du flux d'entrée
        }



        switch(choix)//Switch pour le choix de la Carte de la collection que le joueur veut ajouter dans son deck
        {

        case 1 :
            if(nbGuerrier>0)//s'il a bien au moins une Carte de ce type
            {
                ajouterCarteDeck(new Guerrier);//On ajoute la carte dans son deck
                m_nbCreatureDeck++;//On incremente le nombre de Cartes Creatures dans le Deck
                nbCartesRestantes--;//On decremente lenombre de Cartes restantes à placer dans le deck
                nbGuerrier--;//On decremente le nombre de cartes de ce type dans la collection
                nbGuerrierDeck++;//On incremente le nombre de cette carte précise dans le deck
            }
            else//S'il n'a pas au moins une fois cette carte dans sa collection
            {
                std::cout<<"Vous n'avez plus cette carte dans votre collection. Rachetez-en !" <<std::endl;
                std::cout << "[Appuyez sur entrer pour continuer.]" << std::endl;
                if(pConsole->getInputKey()) {}
            }
            break;
        case 2 :
            if(nbCavalier>0)
            {
                ajouterCarteDeck(new Cavalier);
                nbCavalier--;
                nbCavalierDeck++;
                m_nbCreatureDeck++;
                nbCartesRestantes--;
            }
            else
            {
                std::cout<<"Vous n'avez plus cette carte dans votre collection. Rachetez-en !" <<std::endl;
                std::cout << "[Appuyez sur entrer pour continuer.]" << std::endl;
                if(pConsole->getInputKey()) {}
            }
            break;

        case 3 :
            if(nbArcher>0)
            {
                nbCartesRestantes--;
                ajouterCarteDeck(new Archer);
                m_nbCreatureDeck++;
                nbArcherDeck++;
                nbArcher--;
            }
            else
            {
                std::cout<<"Vous n'avez plus cette carte dans votre collection. Rachetez-en !" <<std::endl;
                std::cout << "[Appuyez sur entrer pour continuer.]" << std::endl;
                if(pConsole->getInputKey()) {}
            }
            break;
        case 4 :
            if(nbArbaletrier>0)
            {
                m_nbCreatureDeck++;
                nbArbaletrierDeck++;
                ajouterCarteDeck(new Arbaletrier);
                nbArbaletrier--;
                nbCartesRestantes--;
            }
            else
            {
                std::cout<<"Vous n'avez plus cette carte dans votre collection. Rachetez-en !" <<std::endl;
                std::cout << "[Appuyez sur entrer pour continuer.]" << std::endl;
                if(pConsole->getInputKey()) {}
            }
            break;
        case 5 :
            if(nbCatapulte>0)
            {
                ajouterCarteDeck(new Catapulte);
                nbCatapulte--;
                nbCartesRestantes--;
                m_nbCreatureDeck++;
                nbCatapulteDeck++;
            }
            else
            {
                std::cout<<"Vous n'avez plus cette carte dans votre collection. Rachetez-en !" <<std::endl;
                std::cout << "[Appuyez sur entrer pour continuer.]" << std::endl;
                if(pConsole->getInputKey()) {}
            }
            break;
        case 6:
            if(nbBelier>0)
            {
                ajouterCarteDeck(new Belier);
                nbBelier--;
                nbCartesRestantes--;
                m_nbCreatureDeck++;
                nbBelierDeck++;
            }
            else
            {
                std::cout<<"Vous n'avez plus cette carte dans votre collection. Rachetez-en !" <<std::endl;
                std::cout << "[Appuyez sur entrer pour continuer.]" << std::endl;
                if(pConsole->getInputKey()) {}
            }
            break;
        case 7 :
            if(nbArthur>0)
            {
                ajouterCarteDeck(new Arthur_Pendragon);
                nbArthur--;
                m_nbCreatureDeck++;
                nbCartesRestantes--;
                nbArthurDeck++;
            }
            else
            {
                std::cout<<"Vous n'avez plus cette carte dans votre collection. Rachetez-en !" <<std::endl;
                std::cout << "[Appuyez sur entrer pour continuer.]" << std::endl;
                if(pConsole->getInputKey()) {}
            }
            break;
        case 8:
            if(nbJeanne>0)
            {
                ajouterCarteDeck(new Jeanne_D_arc);
                nbJeanne--;
                nbCartesRestantes--;
                m_nbCreatureDeck++;
                nbJeanneDeck++;
            }
            else
            {
                std::cout<<"Vous n'avez plus cette carte dans votre collection. Rachetez-en !" <<std::endl;
                std::cout << "[Appuyez sur entrer pour continuer.]" << std::endl;
                if(pConsole->getInputKey()) {}
            }
            break;
        case 9 :
            if(nbLancelot>0)
            {
                ajouterCarteDeck(new Lancelot_duLac);
                nbLancelot--;
                nbCartesRestantes--;
                m_nbCreatureDeck++;
                nbLancelotDeck++;
            }
            else
            {
                std::cout<<"Vous n'avez plus cette carte dans votre collection. Rachetez-en !" <<std::endl;
                std::cout << "[Appuyez sur entrer pour continuer.]" << std::endl;
                if(pConsole->getInputKey()) {}
            }
            break;
        case 10 :
            if(nbGalvanisation>0)
            {
                ajouterCarteDeck(new Speciale(2,"Galvanisation","Multiplie par 2 la puissance d'attaque de la creature mais elle perd la moitie de ses PV",true,false));
                nbGalvanisation--;
                nbCartesRestantes--;
                nbGalvanisationDeck++;
            }

            else
            {
                std::cout<<"Vous n'avez plus cette carte dans votre collection. Rachetez-en !" <<std::endl;
                std::cout << "[Appuyez sur entrer pour continuer.]" << std::endl;
                if(pConsole->getInputKey()) {}
            }
            break;
        case 11 :
            if(nbPriere>0)
            {
                ajouterCarteDeck(new Speciale(1,"Priere","Ajoute 2 PV a votre creature",true,true));
                nbPriere--;
                nbCartesRestantes--;
                nbPriereDeck++;
            }
            else
            {
                std::cout<<"Vous n'avez plus cette carte dans votre collection. Rachetez-en !" <<std::endl;
                std::cout << "[Appuyez sur entrer pour continuer.]" << std::endl;
                if(pConsole->getInputKey()) {}
            }
            break;
        case 12 :
            if(nbButin>0)
            {
                ajouterCarteDeck(new Speciale(1,"Butin","Vous pouvez regarder votre enjeu et le changer",false,true));
                nbButin--;
                nbCartesRestantes--;
                nbButinDeck++;
            }
            else
            {
                std::cout<<"Vous n'avez plus cette carte dans votre collection. Rachetez-en !" <<std::endl;
                std::cout << "[Appuyez sur entrer pour continuer.]" << std::endl;
                if(pConsole->getInputKey()) {}
            }
            break;
        case 13 :
            if(nbEspion>0)
            {
                ajouterCarteDeck(new Speciale(1,"Espion","Vous pouvez regardez la premiere carte du Deck de l'adversaire",false,true));
                nbEspion--;
                nbEspionDeck++;
                nbCartesRestantes--;
            }
            else
            {
                std::cout<<"Vous n'avez plus cette carte dans votre collection. Rachetez-en !" <<std::endl;
                std::cout << "[Appuyez sur entrer pour continuer.]" << std::endl;
                if(pConsole->getInputKey()) {}
            }
            break;
        case 14 :
            if(nbVague>0)
            {
                ajouterCarteDeck(new Speciale(2,"Vague Glacee","Diminue les PV des creatures de 2PV",true,false));
                nbVague--;
                nbVagueDeck++;
                nbCartesRestantes--;
            }
            else
            {
                std::cout<<"Vous n'avez plus cette carte dans votre collection. Rachetez-en !" <<std::endl;
                std::cout << "[Appuyez sur entrer pour continuer.]" << std::endl;
                if(pConsole->getInputKey()) {}
            }
            break;
        case 15 :
            if(nbResurrection>0)
            {
                ajouterCarteDeck(new Speciale(1,"Resurrection","Recupere une carte aleatoire du cimetiere",false,true));
                nbResurrection--;
                nbCartesRestantes--;
                nbResurrectionDeck++;
            }
            else
            {
                std::cout<<"Vous n'avez plus cette carte dans votre collection. Rachetez-en !" <<std::endl;
                std::cout << "[Appuyez sur entrer pour continuer.]" << std::endl;
                if(pConsole->getInputKey()) {}
            }
            break;
        case 16 :
            if(nbCaC>0)
            {
                ajouterCarteDeck(new Energie(1,1,"Corps a corps","Energie Corps a corps"));
                nbCaC--;
                nbCartesRestantes--;
                nbCaCDeck++;
            }
            else
            {
                std::cout<<"Vous n'avez plus cette carte dans votre collection. Rachetez-en !" <<std::endl;
                std::cout << "[Appuyez sur entrer pour continuer.]" << std::endl;
                if(pConsole->getInputKey()) {}
            }
            break;
        case 17 :
            if(nbDistance>0)
            {
                ajouterCarteDeck(new Energie(1,2,"Distance","Energie Distance"));
                nbDistance--;
                nbCartesRestantes--;
                nbDistanceDeck++;
            }
            else
            {
                std::cout<<"Vous n'avez plus cette carte dans votre collection. Rachetez-en !" <<std::endl;
                std::cout << "[Appuyez sur entrer pour continuer.]" << std::endl;
                if(pConsole->getInputKey()) {}
            }
            break;
        case 18 :
            if(nbMachine>0)
            {
                ajouterCarteDeck(new Energie(1,3,"Machine","Energie Machine"));
                nbMachine--;
                nbMachineDeck++;
                nbCartesRestantes--;
            }
            else
            {
                std::cout<<"Vous n'avez plus cette carte dans votre collection. Rachetez-en !" <<std::endl;
                std::cout << "[Appuyez sur entrer pour continuer.]" << std::endl;
                if(pConsole->getInputKey()) {}
            }
            break;
        case 19 :
            if(nbHeros>0)
            {
                ajouterCarteDeck(new Energie(2,4,"Heros","Energie Heros"));
                nbHeros--;
                nbHerosDeck++;
                nbCartesRestantes--;
            }
            else
            {
                std::cout<<"Vous n'avez plus cette carte dans votre collection. Rachetez-en !" <<std::endl;
                std::cout << "[Appuyez sur entrer pour continuer.]" << std::endl;
                if(pConsole->getInputKey()) {}
            }
            break;
        }
 }


 }
void Joueur::sauvegarderCollec()//Permet de sauvegarder la collection du joueur dans des fichiers
{
    std::string const nomFichier("sauv.txt");//dans le fichier de ce nom
    std::ofstream monFlux;
    monFlux.open(nomFichier.c_str(),std::ios::app);//on ouvre monFlux

    if(monFlux)
    {
        for(auto elem:m_collection){
            monFlux<< elem->getNomCarte() << std::endl;//On copie les noms de chaque element de la collection dan sun fichier
        }
            monFlux<< std::endl;

    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
    monFlux.close();


}

void Joueur::charger()//Pour charger le fichier et recuperer les informations des joueurss
{
    std::string ligne;

    std::vector <std::string> tab;
    bool fin=false;




    std::ifstream monFlux("sauv.txt");

    if(monFlux){

    while (fin==false && getline(monFlux,ligne))//on parcourt le fichier
        if(ligne==m_nomJoueur){//des qu'on arrive au nom du joeur, on enregistre ses données dans tab
        while(fin==false && getline(monFlux,ligne)){
            if(ligne.empty())//quand on arrive a la fin de la collaction d'un joueur, on sort du fichier
                fin=true;

            tab.push_back(ligne);
//Si on trouve une ligne avec le nom d'une carte, on rajoute cette carte dans la collection
if(ligne=="Archer"){
                ajouterCarteCollec(new Archer);}
            if(ligne=="Guerrier"){
                ajouterCarteCollec(new Guerrier);}
                if(ligne=="Arbaletrier"){
ajouterCarteCollec(new Arbaletrier);}
if(ligne=="Cavalier"){
ajouterCarteCollec(new Cavalier);}
if(ligne=="Catapulte"){
ajouterCarteCollec(new Catapulte);}
if(ligne=="Belier"){
ajouterCarteCollec(new Belier);}
if(ligne=="Jeanne d'Arc"){
ajouterCarteCollec(new Jeanne_D_arc);}
if(ligne=="Lancelot du lac"){
ajouterCarteCollec(new Lancelot_duLac);}
if(ligne=="Arthur Pendragon")
    ajouterCarteCollec(new Arthur_Pendragon);

if(ligne=="Corps a corps"){
ajouterCarteCollec(new Energie(1,1,"Corps a corps","Energie Corps a corps"));}
if(ligne=="Distance"){
ajouterCarteCollec(new Energie(1,2,"Distance","Energie Distance"));}
if(ligne=="Machine"){
ajouterCarteCollec(new Energie(1,3,"Machine","Energie Distance"));}
if(ligne=="Heros")
ajouterCarteCollec(new Energie(2,4,"Heros","Energie Heros"));




if(ligne=="Priere"){
ajouterCarteCollec(new Speciale(1,"Priere","Ajoute 2 PV a votre creature",false,true));}
if(ligne=="Galvanisation"){
ajouterCarteCollec(new Speciale(2,"Galvanisation","Multiplie par 2 la puissance d'attaque de la creature mais elle perd la moitie de ses PV",true,false));}
if(ligne=="Resurrection"){
ajouterCarteCollec(new Speciale(1,"Resurrection","Recupere une carte aleatoire du cimetiere",false,true));}
if(ligne=="Espion"){
ajouterCarteCollec(new Speciale(1,"Espion","Vous pouvez regardez la premiere carte du Deck de l'adversaire",false,true));
}
if(ligne=="Vague"){
ajouterCarteCollec(new Speciale(2,"Vague","Diminue les PV des creatures de 2PV",true,false));
}
if(ligne=="Butin"){
ajouterCarteCollec(new Speciale(1,"Butin","Vous pouvez regarder votre enjeu et le changer",false,true));
}


}
        }
        }



    else
   {
      std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." <<std::endl;
   }

   m_argent = std::stoi(tab[0]);// on charge l'argent du joueur correspondant a la premiere ligne du fichier
}

void Joueur::seconnecter2()
{

    charger();
    afficherCollecNom();
    std::cout << std::endl << "Votre argent : " << m_argent << std::endl << std::endl;




}

void Joueur::afficherCollecNom() const{//Permet d'afficher une collection et uniquement le nom des cartes de la collection

std::cout << std::endl;
    std::cout << "Votre collection : " ;
    if(!m_collection.empty())
    for (auto elem:m_collection)
        {;
        std::cout << elem->getNomCarte() << ", ";}

        else
        {
            std::cout << "Pas de cartes dans la collection ";
        }
        std::cout << std::endl;

}

void Joueur::seconnecterMenu() //second menu apres connexion
{
    std::cout << "1. Entrer dans la boutique" << std::endl;
    std::cout << "2. Creer un deck " << std::endl;
    std::cout << "0. Quitter" << std::endl;
}

void Joueur::SupprimerFichier()//supprime tous les elments du joueur
{

       std::string ligne;
    std::string nomtest;

    std::vector <std::string> tab;
    std::vector<std::string>::iterator it;
    std::vector<std::string>::iterator it1;
    std::vector<std::string>::iterator it2;
    bool fin1=false;
    bool fin2=false;

    std::string buffer;

    std::ifstream monFlux("sauv.txt");


//int nbr=0;
    if(monFlux){
    while (getline(monFlux,ligne))
            tab.push_back(ligne);
    }
    else
   {
      std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." <<std::endl;
   }

    for(it=tab.begin(); it!=tab.end();)
    {
        if (*it==m_nomJoueur)
           {it1=it;
           fin1=true;}

        if(fin1==true && fin2==false && *it=="")
          {it2=it;
           fin2=true;}
        else
            ++it;

    }
    tab.erase(it1,it2);

std::cout <<    std::endl;

std::ofstream monFlux2("sauv.txt");

    if(monFlux2)
    {


        for(auto elem:tab)
        monFlux2 << elem << std::endl;

 monFlux2 <<std::endl<< m_nomJoueur << std::endl;
        monFlux2 << m_argent << std::endl;

    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}


void Joueur::menuBoutique()//Menu d'affichage de la boutiques
{


    std:: cout <<"                      \\\\\\BOUTIQUE//////      "<<std::endl << std::endl;

    std::cout<< "Quel type de carte voulez vous acheter ?" << std::endl;
    std::cout << " 1. Carte Energie" << std::endl;
    std::cout << " 2. Carte Creature" << std::endl;
    std::cout << " 3. Carte Speciale" << std::endl;
    std::cout << " 0. Quitter" << std::endl;
}

void AfficherBoutique(int curs,int x, int y)//permet d'afficher la boutique via gotoligcol
{


    gotoligcolJoueur(x,y);
    printf("%c",(curs==1)?'>':' ');
    gotoligcolJoueur(x+1,y);
    printf("%c",(curs==2)?'>':' ');
    gotoligcolJoueur(x+2,y);
    printf("%c",(curs==3)?'>':' ');
    gotoligcolJoueur(x+3,y);
    printf("%c",(curs==0)?'>':' ');


}

int ChoisirBoutique(int x,int y)//Permet au joueur d'utiliser un curseur pour faire son choix dans la boutique
{
    int curs = 1;
    int touche;
    do
    {
        AfficherBoutique(curs, x , y);
        touche = _getch();
        if (touche==0xE0) // fleche : le code fleche renvoie 2 caracteres.
        {
            touche = _getch();
            if (touche==0x50 && curs==1)  // fleche bas
                curs = 2;
            else if (touche==0x50 && curs==2)  // fleche bas
                curs = 3;
else if (touche==0x50 && curs==3)  // fleche bas
                curs = 0;
            else if (touche==0x48 && curs==2)  // fleche haut
                curs = 1;
                else if (touche==0x48 && curs==3)  // fleche haut
                curs = 2;
                else if (touche==0x48 && curs==0)  // fleche haut
                curs = 3;
        }
    } while (touche!=0x0D);
    gotoligcolJoueur(x+4,y);  // enter
    return curs;
}


void Joueur::afficherboutique()//Permet d'afficher la boutique des CArtes
{

    system("cls");
    int choix=30;
    int choix2;

    while(choix!=0){

    menuBoutique();

choix=ChoisirBoutique(3,0);


switch(choix){//Switch qui permet de choisir le type de cartes que l'on veut acheter
case 1://Switch qui permet d'acheter une CArte Energie
    {


        while(choix2!=0){
        system("cls");
        int i=1;

        std::cout << "Votre Collection : ";
        for (auto elem:m_collection)//Affichage de toutes les cartes de la collection
        {
            std::cout << elem->getNomCarte() << ", ";
        }

std::cout<<std::endl;
        for(auto elem:boutique)
            if(elem->getTypeCarte()==2)
        {std::cout << std::endl << "Carte numero "<< i << std::endl;//Chaque carte est indiquee avec un numero pour pouvoir choisir
            elem->afficher();
            i++;
        }


        std::cout << std::endl << "Saisissez le numero de la carte a acheter. Vous avez " << m_argent << " pieces d'or. " <<std::endl;
        std::cout << " 0 pour quitter "<< std::endl;
        while(true)
        {
            std::cin>>choix2;
            if(std::cin.eof() || std::cin.bad())
            {
                std::cerr << "Une erreur interne est survenue." << std::endl;

                if(std::cin.eof()) // Si c'est la fin du flux d'entrée, il faut sortir de la boucle
                {
                    break;
                }
                vider_buffer(); // On remet cin dans un état valide et vide le buffer
                continue;
            }
            else if(std::cin.fail())
            {
                std::cerr << "Erreur, saisie incorrecte. Veuillez ressaisir un chiffre." << std::endl;
                vider_buffer(); // On remet cin dans un état valide et vide le buffer
                continue;
            }
            break; // On ne sort de la boucle que s'il n'y a eu aucune erreur ou que c'est la fin du flux d'entrée
        }
        switch(choix2)//Switch qui permet d'acheter une CArte Energie
{
    case 1:
        ajouterCarteCollec(new Energie(1,1,"Corps a corps","Energie CaC"));
        break;

    case 2:
        ajouterCarteCollec(new Energie(1,2,"Distance","Energie Distance"));
        break;

    case 3:
ajouterCarteCollec(new Energie(1,3,"Machine","Energie Distance"));

        break;

    case 4:
        ajouterCarteCollec(new Energie(2,4,"Heros","Energie Heros"));

        break;

}

}

        choix2=30;
        break;
    }
    case 2://Switch qui permet d'acheter une CArte Creature
    {


        while(choix2!=0){
                system("cls");
                int i=1;
                std::cout << "Votre Collection : ";
        for (auto elem:m_collection)
        {
            std::cout << elem->getNomCarte() << ", ";
        }
std::cout<<std::endl;
        for(auto elem:boutique)
            if(elem->getTypeCarte()==1)
        {   std::cout<<std::endl;
            std::cout << "Carte numero "<< i << std::endl;
            elem->afficher();
            i++;
        }


        std::cout << std::endl << "Saisissez le numero de la carte a acheter. Vous avez " << m_argent << " pieces d'or. " <<std::endl;
        std::cout << " 0 pour quitter "<< std::endl;
        std::cin >> choix2;
        switch(choix2)
{
    case 1:

                ajouterCarteCollec(new Guerrier);

        break;

    case 2:
                ajouterCarteCollec(new Cavalier);

        break;

    case 3:
          ajouterCarteCollec(new Archer);
        break;
    case 4:
                ajouterCarteCollec(new Arbaletrier);

        break;
    case 5:
    ajouterCarteCollec(new Catapulte);
    break;
    case 6:
                ajouterCarteCollec(new Belier);


        break;
    case 7:
                ajouterCarteCollec(new Arthur_Pendragon);


        break;
    case 8:
        ajouterCarteCollec(new Lancelot_duLac);
        break;
            case 9:
        ajouterCarteCollec(new Jeanne_D_arc);
        break;

}

}
choix2=30;
        break;
    }
    case 3://Switch qui permet d'acheter une CArte Speciale
    {

        while(choix2!=0){
                system("cls");
                 int i=1;
        std::cout << "Votre Collection : ";
        for (auto elem:m_collection)
        {
            std::cout << elem->getNomCarte() << ", ";
        }
        std::cout<<std::endl;

        for(auto elem:boutique)
            if(elem->getTypeCarte()==3)
        {std::cout << std::endl << "Carte numero "<< i << std::endl;
            elem->afficher();
            i++;
        }

        std::cout << std::endl << "Saisissez le numero de la carte a acheter. Vous avez " << m_argent << " pieces d'or. " <<std::endl;
        std::cout << " 0 pour quitter "<< std::endl;
        std::cin >> choix2;
        switch(choix2)
{
    case 1:
        ajouterCarteCollec(new Speciale(1,"Priere","Ajoute 2 PV a votre creature",true,true));
        break;

    case 2:
        ajouterCarteCollec(new Speciale(1,"Butin","Vous pouvez regarder votre enjeu et le changer",false,true));

        break;

    case 3:
        ajouterCarteCollec(new Speciale(1,"Espion","Vous pouvez regardez la premiere carte du Deck de l'adversaire",false,true));

        break;
    case 4:
        ajouterCarteCollec(new Speciale(1,"Resurrection","Recupere une carte aleatoire du cimetiere",false,true));

        break;
         case 5:
               ajouterCarteCollec(new Speciale(2,"Vague","Diminue les PV des creatures de 2PV",true,false));

        break;
         case 6:
        ajouterCarteCollec(new Speciale(2,"Galvanisation","Multiplie par 2 la puissance d'attaque de la creature mais elle perd la moitie de ses PV",true,false));

        break;
}

}
choix2=30;
        break;
    }

}

system("cls");
}

}

void Joueur::attaquerJoueur(Joueur& J){//Permet à un joueur d'attaquer un autre joueur.

    bool attaquePossible=true;
            int choixattaque;
            int a,b,c,d;
            int AttaqueOuNon;

    Attaque* A =new Attaque;//Création d'une attaque temporaire pour simplifier le code
while(attaquePossible==true){//Boucle while qui se repete tant que le joueur n'a pas une attaque valide ou refuse d'attaquer

    std::cout<<"Voulez-vous attaquer ? (Il faut avoir assez d'energie.)  1.OUI    2.NON"<<std::endl;
    while(true)
        {
              std::cin>>AttaqueOuNon;
            if(std::cin.eof() || std::cin.bad())
            {
                std::cerr << "Une erreur interne est survenue." << std::endl;

                if(std::cin.eof()) // Si c'est la fin du flux d'entrée, il faut sortir de la boucle
                {
                    break;
                }
                vider_buffer(); // On remet cin dans un état valide et vide le buffer
                continue;
            }
            else if(std::cin.fail())
            {
                std::cerr << "Erreur, saisie incorrecte. Veuillez ressaisir 1 ou 2." << std::endl;
                vider_buffer(); // On remet cin dans un état valide et vide le buffer
                continue;
            }
            break; // On ne sort de la boucle que s'il n'y a eu aucune erreur ou que c'est la fin du flux d'entrée
        }




    if(AttaqueOuNon==1){//S'il veut attaquer

    std::cout<<"Choisissez votre Attaque : 1 OU 2 ? "<<std::endl;

 while(true)
        {
              std::cin>>choixattaque;
            if(std::cin.eof() || std::cin.bad())
            {
                std::cerr << "Une erreur interne est survenue." << std::endl;

                if(std::cin.eof()) // Si c'est la fin du flux d'entrée, il faut sortir de la boucle
                {
                    break;
                }
                vider_buffer(); // On remet cin dans un état valide et vide le buffer
                continue;
            }
            else if(std::cin.fail())
            {
                std::cerr << "Erreur, saisie incorrecte. Veuillez ressaisir 1 ou 2." << std::endl;
                vider_buffer(); // On remet cin dans un état valide et vide le buffer
                continue;
            }
            break; // On ne sort de la boucle que s'il n'y a eu aucune erreur ou que c'est la fin du flux d'entrée
        }


if(choixattaque==1){ // si le joueur choisit l'attaque 1 de sa créature

    A = CreatureActive->getAttaque1();//Affectation de l'attaque 1

}
if(choixattaque==2){ // si le joueur choisit l'attaque 2 de sa créature

    A = CreatureActive->getAttaque2();//Affectation de l'attaque 2
}

if(m_SpecialeActiveVide==false){//S'il a une Speciale Active
if(SpecialeActive->getNomCarte()=="Galvanisation" && m_galva==false){//SI le joueur a active Galvanisation, cet effet n'a lieu qu'une seule fois

    a=CreatureActive->getAttaque1()->getDegat()+2;//On multiplie pa deux les degats d'Attaque de la Creature
    CreatureActive->getAttaque1()->setDegat(a);

        c=CreatureActive->getAttaque2()->getDegat()+2;//On multiplie pa deux les degats d'Attaque de la Creature
    CreatureActive->getAttaque2()->setDegat(c);

    CreatureActive->setPV(CreatureActive->getPV()%2);//On diminue de moitie les PV de la Creature
    m_galva=true; //Galvanisation active une fois
}
else if(m_galva==true && SpecialeActive->getNomCarte()!="Galvanisation")//Si l'on n'a plus Galvanisation en active mais que Galva a été activé
    {
b=CreatureActive->getAttaque1()->getDegat()-2;//On remet à la normale les parametres des deux joueurs
 CreatureActive->getAttaque1()->setDegat(b);

 d=CreatureActive->getAttaque2()->getDegat()-2;
 CreatureActive->getAttaque2()->setDegat(d);

     CreatureActive->setPV(CreatureActive->getPV()*2);

 m_galva=false;//Remet le bool à false pour la prochaine utilisation d'une autre Carte Galvanisation
}
}

if(A->getTypeEnergie()==1 && A->getTypeEnergie2()==0){//si le premier type d'energie necessaire est CaC et qu'il n'y a pas besoin de deuxieme type

if(m_nbCaC>=A->getNbEnergie()){//Si le Joueur a un nombre D'energie de premier type supérieur ou égale au nombre d'energie necessaire

 if( A == CreatureActive->getAttaque1()){//Si le joueur a choisi la premiere Attaque
    CreatureActive->attaquerCreature(J.getCreatureActive());//On appelle l'Attaque 1 sur le joueur adverse
    }
    else{//Si le joueur a choisi la deuxieme Attaque
        CreatureActive->attaquerCreature2(J.getCreatureActive());//On appelle l'Attaque 2 sur le joueur adverse

    }
    attaquePossible=false;//l'attaque a eu lieu
m_nbCaC=m_nbCaC-(A->getNbEnergie());//On decremente le nombre d'energie dans sa reserve par le nombre d'energie utilise lors de l'attaque
for(int i(0);i<A->getNbEnergie();i++){//on rajoute dans le cimetiere autant d'energies utilisees pour l'attaque
ajouterCarteCimetiere(new Energie(1,2,"Corps a corps","Energie Corps a corps"));
}
}
    else {//S'il n'a pas assez d'energie pour l'attaque
        std::cout<<"Vous n'avez pas assez d'energie"<<std::endl;
    }
}
//De même pour les prochaines If, on vérifie seulement les différents types d'energie et leurs nombres necessaires
if(A->getTypeEnergie()==2 && A->getTypeEnergie2()==0){
if(m_nbDistance>=A->getNbEnergie()){

 if( A == CreatureActive->getAttaque1()){
    CreatureActive->attaquerCreature(J.getCreatureActive());

    }
else{
        CreatureActive->attaquerCreature2(J.getCreatureActive());

    }
    attaquePossible=false;
    m_nbDistance=m_nbDistance-A->getNbEnergie();
for(int i(0);i<A->getNbEnergie();i++){
ajouterCarteCimetiere(new Energie(1,2,"Distance","Energie Distance"));
}
}
    else {
        std::cout<<"Vous n'avez pas assez d'energie"<<std::endl;


    }
}
if(A->getTypeEnergie()==3 && A->getTypeEnergie2()==0){
if(m_nbMachine>=A->getNbEnergie()){
 if( A == CreatureActive->getAttaque1()){
    CreatureActive->attaquerCreature(J.getCreatureActive());

    }
else{
        CreatureActive->attaquerCreature2(J.getCreatureActive());

    }
     attaquePossible=false;
m_nbMachine=m_nbMachine-A->getNbEnergie();
for(int i(0);i<A->getNbEnergie();i++){
ajouterCarteCimetiere(new Energie(1,2,"Machine","Energie Machine"));
}
}
    else {
        std::cout<<"Vous n'avez pas assez d'energie"<<std::endl;

    }
}
if(A->getTypeEnergie()==4 && A->getTypeEnergie2()==0){
if(m_nbHeros>=A->getNbEnergie()){

 if( A == CreatureActive->getAttaque1()){
    CreatureActive->attaquerCreature(J.getCreatureActive());

    }
else{
        CreatureActive->attaquerCreature2(J.getCreatureActive());

    }
    attaquePossible=false;
m_nbHeros=m_nbHeros-A->getNbEnergie();
for(int i(0);i<A->getNbEnergie();i++){
ajouterCarteCimetiere(new Energie(2,2,"Heros","Energie Heros"));
}
}
    else {
        std::cout<<"Vous n'avez pas assez d'energie"<<std::endl;

    }
}
if(A->getTypeEnergie()==1 && A->getTypeEnergie2()==2){
if(m_nbCaC>=A->getNbEnergie()){
if(m_nbDistance>=A->getNbEnergie2()){

 if( A == CreatureActive->getAttaque1()){
    CreatureActive->attaquerCreature(J.getCreatureActive());

    }
else{
        CreatureActive->attaquerCreature2(J.getCreatureActive());

    }
    attaquePossible=false;
    m_nbCaC=m_nbCaC-A->getNbEnergie();
m_nbDistance=m_nbDistance-(A->getNbEnergie2());
for(int i(0);i<A->getNbEnergie();i++){
ajouterCarteCimetiere(new Energie(1,2,"Corps a corps","Energie Corps a corps"));
}
for(int i(0);i<A->getNbEnergie2();i++){
ajouterCarteCimetiere(new Energie(1,2,"Distance","Energie Distance"));
}
}
else {
        std::cout<<"Vous n'avez pas assez d'energie"<<std::endl;

    }
}
 else {
        std::cout<<"Vous n'avez pas assez d'energie"<<std::endl;

    }
}

if(A->getTypeEnergie()==1 && A->getTypeEnergie2()==3){
if(m_nbCaC>=A->getNbEnergie()){
if(m_nbMachine>=A->getNbEnergie2()){

  if( A == CreatureActive->getAttaque1()){

    CreatureActive->attaquerCreature(J.getCreatureActive());

    }
else{

CreatureActive->attaquerCreature2(J.getCreatureActive());

    }
    attaquePossible=false;
m_nbCaC=m_nbCaC-(A->getNbEnergie());
m_nbMachine=m_nbMachine-A->getNbEnergie2();
for(int i(0);i<A->getNbEnergie();i++){
ajouterCarteCimetiere(new Energie(1,2,"Corps a corps","Energie Corps a corps"));
}
for(int i(0);i<A->getNbEnergie2();i++){
ajouterCarteCimetiere(new Energie(1,2,"Machine","Energie Machine"));
}
}
else {
        std::cout<<"Vous n'avez pas assez d'energie pour cette attaque"<<std::endl;

    }
}
    else {
        std::cout<<"Vous n'avez pas assez d'energie pour cette attaque"<<std::endl;

    }
}
if(A->getTypeEnergie()==1 && A->getTypeEnergie2()==4){
if(m_nbCaC>=A->getNbEnergie()){
if(m_nbHeros>=A->getNbEnergie2()){
  if( A == CreatureActive->getAttaque1()){
    CreatureActive->attaquerCreature(J.getCreatureActive());

    }
    if( A == CreatureActive->getAttaque2()){

        CreatureActive->attaquerCreature2(J.getCreatureActive());

    }
    attaquePossible=false;
 m_nbCaC=m_nbCaC-(A->getNbEnergie());
m_nbHeros=m_nbHeros-A->getNbEnergie2();
for(int i(0);i<A->getNbEnergie();i++){
ajouterCarteCimetiere(new Energie(1,2,"Corps a corps","Energie Corps a corps"));
}
for(int i(0);i<A->getNbEnergie2();i++){
ajouterCarteCimetiere(new Energie(2,2,"Heros","Energie Heros"));
}
}
else {
        std::cout<<"Vous n'avez pas assez d'energie pour cette attaque"<<std::endl;

    }

}
 else {
        std::cout<<"Vous n'avez pas assez d'energie pour cette attaque"<<std::endl;

    }
}
if(A->getTypeEnergie()==2 && A->getTypeEnergie2()==3){
if(m_nbDistance>=A->getNbEnergie()){
if(m_nbMachine>=A->getNbEnergie2()){
  if( A == CreatureActive->getAttaque1()){
    CreatureActive->attaquerCreature(J.getCreatureActive());

    }
    if( A == CreatureActive->getAttaque2()){
        CreatureActive->attaquerCreature2(J.getCreatureActive());

    }
    attaquePossible=false;
    m_nbDistance=m_nbDistance-A->getNbEnergie();
m_nbMachine=m_nbMachine-A->getNbEnergie2();
for(int i(0);i<A->getNbEnergie();i++){
ajouterCarteCimetiere(new Energie(1,2,"Distance","Energiees Distance"));
}
for(int i(0);i<A->getNbEnergie2();i++){
ajouterCarteCimetiere(new Energie(1,2,"Machine","Energie Machine"));
}
}
else {
        std::cout<<"Vous n'avez pas assez d'energie pour cette attaque"<<std::endl;

    }

}
 else {
        std::cout<<"Vous n'avez pas assez d'energie pour cette attaque"<<std::endl;

    }
}
if(A->getTypeEnergie()==2 && A->getTypeEnergie2()==4){
if(m_nbDistance>=A->getNbEnergie()){
if(m_nbHeros>=A->getNbEnergie2()){
  if( A == CreatureActive->getAttaque1()){
    CreatureActive->attaquerCreature(J.getCreatureActive());

    }
    if( A == CreatureActive->getAttaque2()){
        CreatureActive->attaquerCreature2(J.getCreatureActive());

    }
    attaquePossible=false;
    m_nbDistance=m_nbDistance-A->getNbEnergie();
m_nbHeros=m_nbHeros-A->getNbEnergie2();
for(int i(0);i<A->getNbEnergie();i++){
ajouterCarteCimetiere(new Energie(1,2,"Distance","Energie Distance"));
}
for(int i(0);i<A->getNbEnergie2();i++){
ajouterCarteCimetiere(new Energie(2,2,"Heros","Energie Heros"));
}
}
else {
        std::cout<<"Vous n'avez pas assez d'energie pour cette attaque"<<std::endl;

    }

}
 else {
        std::cout<<"Vous n'avez pas assez d'energie pour cette attaque"<<std::endl;

    }
}
if(A->getTypeEnergie()==3 && A->getTypeEnergie2()==4){
if(m_nbMachine>=A->getNbEnergie()){
if(m_nbHeros>=A->getNbEnergie2()){
  if( A == CreatureActive->getAttaque1()){
    CreatureActive->attaquerCreature(J.getCreatureActive());

    }
    if( A == CreatureActive->getAttaque2()){
        CreatureActive->attaquerCreature2(J.getCreatureActive());

    }
    attaquePossible=false;
    m_nbMachine= m_nbMachine-A->getNbEnergie();
m_nbHeros=m_nbHeros-A->getNbEnergie2();
for(int i(0);i<A->getNbEnergie();i++){
ajouterCarteCimetiere(new Energie(1,2,"Machine","Energie Machine"));
}
for(int i(0);i<A->getNbEnergie2();i++){
ajouterCarteCimetiere(new Energie(2,2,"Heros","Energie Heros"));
}
}
else {
        std::cout<<"Vous n'avez pas assez d'energie pour cette attaque"<<std::endl;

    }

}
 else {
        std::cout<<"Vous n'avez pas assez d'energie pour cette attaque"<<std::endl;
    }
}
}else if(AttaqueOuNon==2){//Si le joueur refuse d'attaquer
attaquePossible=false;
        std::cout<<"Vous n'attaquez pas."<<std::endl;
    }
    }

}

void Joueur::refusSpeciale(Speciale* Spe){ //Méthode pour savoir si la carte refusée va dans le deck ou dans le cimetiere
if(Spe->getRefus()==false){

    m_deck.push(m_deck.front());//si le refus est  à false, la carte refusee retourne sous la pioche

}
if(Spe->getRefus()==true){

    ajouterCarteCimetiere(m_deck.front());//si le refus est true, la carte refusee va au cimetiere
}

}

void Joueur::afficherSpecialeActive() const{//on affiche la speciale Active
    std::cout<<"Voici votre Speciale Active : "<<std::endl;
std::cout <<SpecialeActive->getNomCarte() << std::endl;}



void Joueur::afficherReserveEnergieTerrain(int x, int y) const//On affiche la Reserve d'energie pour le terrain
{
    pConsole->gotoLigCol(x,y);
std::cout<<"Corps a corps : " <<m_nbCaC<<"               "<<"   Machine : " <<m_nbMachine<<std::endl;//Affichage de chacun des types de Cartes Energie
pConsole->gotoLigCol(x+1,y);
std::cout<<"Distance : " <<m_nbDistance<<"                       "<<"Heros : " <<m_nbHeros<<std::endl;

}

void Joueur::afficherCreatureActiveTerrain(int x, int y) const//Méthode qui affiche la Créature Active ou non
{
    if(m_CreatureActiveVide==false){//Condition If qui vérifie que la place de Créature Active est occupée


    pConsole->gotoLigCol(x+1,y);
    std::cout<<CreatureActive->getNomCarte();//Affiche uniquement le nom de la Créature
    pConsole->gotoLigCol(x+2,y);
    std::cout << "PV: "<< CreatureActive->getPV();

    }
    else{//Si le boolean = true, le joueur n'a pas de Créature Active pour le moment
        pConsole->gotoLigCol(x+2,y-8);
        std::cout<<"Pas de Creature Active" <<std::endl;
    }
}

void Joueur::afficherSpecialeActiveTerrain(int x, int y) const{//On affiche la Speciale Active pour le terrain
if(getSpecialeActiveVide()==false){
pConsole->gotoLigCol(x-2,y+8);
std::cout << SpecialeActive->getNomCarte() << std::endl;}
else{
        pConsole->gotoLigCol(x-2,y+8);
    std::cout<<"Pas de Speciale"<<std::endl;
}
}

void Joueur::afficherCimetiereTerrain(int x,int y) const{//Méthode qui permet d'afficher le cimetiere
 pConsole->gotoLigCol(x,y);
    std::cout << "Cimetiere de " << m_nomJoueur << " : ";

    pConsole->gotoLigCol(x,y+17+m_nomJoueur.size());
    for (auto elem:m_cimetiere)//Boucle for qui affiche chacun des elements du cimetiere du Joueur
        {std::cout << elem->getNomCarte() << ", " ;
        //Permet d'afficher uniquement le nom de la Carte
        }

}
