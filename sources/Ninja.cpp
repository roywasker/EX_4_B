#include "Ninja.hpp"

using namespace ariel;

/**
 * Constructor for Ninja
 * @param name Ninja name
 * @param location Ninja location
 */
Ninja::Ninja(std::string name, const Point &location, int hitpoint , int speed) : Character(location,name,hitpoint) ,speed(speed) {}

/**
 *  move Ninja to enemy
 * @param enemy pointer of the enemy
 */
void Ninja::move(const Character *enemy) {
    if (enemy==NULL){
        throw invalid_argument("not given enemy\n");
    }
    if (isAlive()){
        setLocation(Point::moveTowards(this->getLocation(),enemy->getLocation(), this->speed));
    }
}

/**
 * Hit the enemy by 31 hit point
 * @param enemy pointer to enemy
 */
void Ninja::slash(Character *enemy) const {
    if (enemy == NULL){
        throw invalid_argument("not given enemy\n");
    }
    if (!isAlive()){
        throw runtime_error("the Ninja are dead\n");
    }
    if (!enemy->isAlive()){
        throw runtime_error("the enemy is dead\n");
    }
    if (this == enemy){
        throw runtime_error("the Ninja can not shoot himself\n");
    }
    if (this->distance(enemy)<=1){
        enemy->hit(40);
    }
}

/**
 * Print the values of the Ninja
 * @return string to print
 */
std::string Ninja::print() {
    string print="";
    print="N "+ Character::print();
    return print;
}