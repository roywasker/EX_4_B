#include "SmartTeam.hpp"

using namespace ariel;

/**
 *  Constructor for team
 * @param captain Character to be a captain
 */
SmartTeam::SmartTeam(ariel::Character *captain) : Team(captain){}

/**
 * attack enemy team
 * @param enemyteam pointer to enemy team
 */
void SmartTeam::attack(Team *enemyteam) {
    if (enemyteam == NULL){
        throw invalid_argument("enemy team are null\n");
    }

    if (this == enemyteam){
        throw invalid_argument("team can not attack himself\n");
    }
    if (enemyteam->stillAlive()<=0){
        throw runtime_error("can not attack a dead team \n");
    }
    if (!this->getCaptain().isAlive()){
        newcaptain();
    }

    array teamwarriors = getWarriors();
    Character* enemytoattack = chooseEnemy(enemyteam); // get enemy with the lowest hit point
    for (unsigned int i = 0; i < this->getnumOfWarriors(); ++i) {
        auto &character = *teamwarriors.at(i);
        if (enemytoattack==NULL){ // this team win
            break;
        }
        if (!enemytoattack->isAlive()){
            enemytoattack= chooseEnemy(enemyteam);// get enemy with the lowest hit point
        }
        if (enemytoattack==NULL){ // this team win
            break;
        }
        if (typeid(character) == typeid(Cowboy)){
            Cowboy* cowboyattacker = dynamic_cast <Cowboy*> (&character);
            if (cowboyattacker->isAlive()) {
                if (cowboyattacker->hasboolets()) {
                    cowboyattacker->shoot(enemytoattack);
                } else {
                    cowboyattacker->reload();
                }
            }
        }
    }
    for (unsigned int i = 0; i < this->getnumOfWarriors(); ++i) {
        auto &character = *teamwarriors.at(i);
        if (typeid(character) != typeid(Cowboy)) {
            Ninja *ninjaattacker = dynamic_cast <Ninja *> (&character);
            if (ninjaattacker->isAlive()) {
                if (selectEnemyByDistance(enemyteam, ninjaattacker)->getLocation().distance(ninjaattacker->getLocation()) <=1) {// get enemy with the lowest distance from warriors
                    ninjaattacker->slash(enemytoattack);
                } else {
                    ninjaattacker->move(enemytoattack);
                }
            }
        }
    }
}
/**
 * select new enemy that he have lowest hitpoint
 * @param enemyteam enemy team
 * @return pointer to enemy
 */
Character* SmartTeam::chooseEnemy(Team *enemyteam) const {
    Character* enemy = NULL;
    int minhit=99999;
    array teamwarriors = enemyteam->getWarriors();
    for (unsigned int i = 0; i < enemyteam->getnumOfWarriors(); ++i) { // go over all enemy team warriors
        auto Character = teamwarriors.at(i);
        int hitpoint = Character->gethitpoint();
        if (hitpoint<minhit && Character->isAlive()){ // check the hit point
            minhit=hitpoint;
            enemy=Character;
        }
    }
    return enemy;
}


/**
 * select new enemy by lowest distance from warriors
 * @return pointer to enemy
 */
Character* SmartTeam::selectEnemyByDistance(Team *enemyteam, Character *warriors) const {
    Character* enemy = NULL;
    double mindistance=99999;
    array teamwarriors = enemyteam->getWarriors();
    for (unsigned int i = 0; i < enemyteam->getnumOfWarriors(); ++i) { // go over all enemy team warriors
        auto Character = teamwarriors.at(i);
        double distance = warriors->getLocation().distance(Character->getLocation()); //check the distance
        if (distance<mindistance && Character->isAlive()){
            mindistance=distance;
            enemy=Character;
        }
    }
    return enemy;
}

/**
 * print all the Character in the team
 * @return string to print
 */
void SmartTeam::print() {
    array team2warriors = getWarriors();
    for (unsigned int i = 0; i < this->getnumOfWarriors(); ++i) {
        auto &Character = *team2warriors.at(i);
        std::cout<<Character.print()<<std::endl;
    }
}
