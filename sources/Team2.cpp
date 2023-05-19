#include "Team2.hpp"

using namespace ariel;

/**
 * Constructor for team
 * @param captain Character to be a captain
 */
Team2::Team2(Character *captain) : Team(captain){}

/**
 * attack enemy team
 * @param enemyteam pointer to enemy team
 */
void Team2::attack(Team *enemyteam) {
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

    array team2warriors = getWarriors();
    Character* enemytoattack = selectenemy(enemyteam); // choose enemy to attack
    for (unsigned int i = 0; i < this->getnumOfWarriors(); ++i) {
        auto &character = *team2warriors.at(i);
        if (!enemytoattack->isAlive()){
            enemytoattack= selectenemy(enemyteam);
        }
        if (enemytoattack==NULL){ // this team win
            break;
        }
        if (typeid(character) == typeid(Cowboy)){ // if the warriors is cowboy
            Cowboy* cowboyattacker = dynamic_cast <Cowboy*> (&character); //convert the warriors to cowboy
            if (cowboyattacker->isAlive()) {
                if (cowboyattacker->hasboolets()) {
                    cowboyattacker->shoot(enemytoattack);
                } else { // if he get 0 bullet
                    cowboyattacker->reload();
                }
            }
        } else{ // The warriors is ninja
            Ninja* ninjaattacker = dynamic_cast <Ninja*> (&character);//convert the warriors to ninja
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
 * print all the Character in the team
 * @return string to print
 */
void Team2::print() {
    array team2warriors = getWarriors(); // get team warriors
    for (unsigned int i = 0; i < this->getnumOfWarriors(); ++i) { //go over all team warriors
        auto &Character = *team2warriors.at(i);
        std::cout<<Character.print()<<std::endl;
    }
}
