#include "Team.hpp"

using namespace ariel;

/**
 * Constructor
 * @param other team to Copy
 */
Team::Team(ariel::Character *captain) {
    if (captain==NULL){
        throw runtime_error("captain is not exists\n");
    }
    if (!captain->isAlive()){
        throw runtime_error("captain is dead\n");
    }
    if (captain->getinteam()){
        throw runtime_error("captain is already in a team\n");
    }
    numOfWarriors=0;
    this->captain=captain;
    warriors.at(numOfWarriors++)=captain;
    captain->setinteam(true);
}

/**
 * destructor for Character
 */
Team::~Team() {
    for (unsigned int i = 0; i < numOfWarriors; ++i) {
        delete warriors.at(i);
    }
}

/**
 * add Character to team
 * @param character Character to add
 */
void Team::add(Character *character) {
    if (character==NULL){
        throw runtime_error("character is not exists\n");
    }
    if (!character->isAlive()){
        throw runtime_error("character is dead\n");
    }
    if (character->getinteam()){
        throw runtime_error("character is already in a team\n");
    }
    if (numOfWarriors >= maxCharacter){
        throw runtime_error("the team is full\n");
    }
    warriors.at(numOfWarriors++)=character;
    character->setinteam(true);
}

/**
 * attack enemy team
 * @param enemyteam pointer to enemy team
 */
void Team::attack(Team *enemyteam) {
    if (enemyteam == NULL){
        throw invalid_argument("enemy team are null\n");
    }

    if (this == enemyteam){
        throw invalid_argument("team can not attack himself\n");
    }
    if (enemyteam->stillAlive()<=0){
        throw runtime_error("can not attack a dead team \n");
    }
    if (!this->captain->isAlive()){
        newcaptain();
    }

    Character* enemytoattack = selectenemy(enemyteam);
    for (unsigned int i = 0; i < numOfWarriors; ++i) { // go over all the cowboy
        auto &character = *warriors.at(i);
        if (enemytoattack==NULL){ // this team win
            break;
        }
        if (!enemytoattack->isAlive()){
            enemytoattack= selectenemy(enemyteam);
        }
        if (enemytoattack==NULL){ // this team win
            break;
        }
        if (typeid(character) == typeid(Cowboy)){
            Cowboy* cowboyattacker = dynamic_cast <Cowboy*> (&character); // convert character to cowboy
            if (cowboyattacker->isAlive()) {
                if (cowboyattacker->hasboolets()) {
                    cowboyattacker->shoot(enemytoattack);
                } else {
                    cowboyattacker->reload();
                }
            }
        }
    }

    for (unsigned int i = 0; i < numOfWarriors; ++i) { // go over all the ninja
        auto &character = *warriors.at(i);
        if (enemytoattack==NULL){ // this team win
            break;
        }
        if (!enemytoattack->isAlive()){
            enemytoattack= selectenemy(enemyteam);
        }
        if (enemytoattack==NULL){ // this team win
            break;
        }
        if (typeid(character) != typeid(Cowboy)){ // convert character to ninja
            Ninja* ninjaattacker = dynamic_cast <Ninja*> (&character);
            if (ninjaattacker->isAlive()) {
                if (ninjaattacker->getLocation().distance(enemytoattack->getLocation()) <= 1) {
                    ninjaattacker->slash(enemytoattack);
                } else {
                    ninjaattacker->move(enemytoattack);
                }
            }
        }
    }
}

/**
 * if captain is not alive select new captain
 */
void Team::newcaptain(){
    auto newcaptain = this->captain;
    double mindistance=99999;
    for (unsigned int i = 0; i < numOfWarriors; ++i) { // go over all this team warriors
        auto Character = warriors.at(i);
        double distance = this->captain->getLocation().distance(Character->getLocation());
        if (distance<mindistance && Character->isAlive()){ //check the distance
            mindistance=distance;
            newcaptain=Character;
        }
    }
    this->captain=newcaptain;
}

/**
 * select new enemy that he closest to the captain
 * @return pointer to enemy
 */
Character* Team::selectenemy(Team *enemyteam) const{
    Character* enemy = NULL;
    double mindistance=99999;
    for (unsigned int i = 0; i < enemyteam->numOfWarriors; ++i) { // go over all enemy team warriors
        auto Character = enemyteam->warriors.at(i);
        double distance = this->captain->getLocation().distance(Character->getLocation());
        if (distance<mindistance && Character->isAlive()){  //check the distance
            mindistance=distance;
            enemy=Character;
        }
    }
    return enemy;
}

/**
 *  how much Character in team are alive
 * @return number of Character in team are alive
 */
int Team::stillAlive() {
    int count = 0;
    for (unsigned int i = 0; i < numOfWarriors; ++i) {
        if (warriors.at(i)->isAlive()){
            count++;
        }
    }
    return count;
}

/**
 * getter fo team captain
 * @return pointer to captain
 */
Character& Team::getCaptain() {
    return *this->captain;
}

/**
 * return number of Warriors in team
 * @return number of Warriors in team
 */
unsigned int Team::getnumOfWarriors() {return this->numOfWarriors;}

/**
 * return array of warriors
 * @return array of warriors
 */
std::array<Character*, maxCharacter>& Team::getWarriors(){return this->warriors;}

/**
 * print all the Character in the team
 * @return string to print
 */
void Team::print() {
    for (unsigned int i = 0; i < numOfWarriors; ++i) { // go over all the cowboy
        auto &Character = *warriors.at(i);
        if (typeid(Character) == typeid(Cowboy)){
            std::cout<<Character.print()<<std::endl;
        }
    }
    for (unsigned int i = 0; i < numOfWarriors; ++i) { // go over all the ninja
        auto &Character = *warriors.at(i);
        if (typeid(Character) != typeid(Cowboy)){
            std::cout<<Character.print()<<std::endl;
        }
    }
}