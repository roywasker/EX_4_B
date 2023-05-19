#include "Cowboy.hpp"

using namespace ariel;

/**
 * Constructor for Cowboy
 * @param name Cowboy name
 * @param location  Cowboy location
 */
Cowboy::Cowboy(std::string  name, const Point &location) : Character(location,name,110) , bullets(6){}

/**
 * Cowboy shoots the enemy, subtracting hit points from the enemy
 * @param enemy pointer to  enemy
 */
void Cowboy::shoot(Character *enemy) {
    if (enemy == NULL){
        throw invalid_argument("not given enemy\n");
    }
    if (!isAlive()){
        throw runtime_error("the cowboy are dead\n");
    }
    if (!enemy->isAlive()){
        throw runtime_error("the enemy is dead\n");
    }
    if (this == enemy){
        throw runtime_error("the cowboy can not shoot himself\n");
    }
    if (hasboolets()){
        enemy->hit(10);
        this->bullets--;
    }
}

/**
 * Check if cowboy have bullet
 * @return return ture if he have bullet , otherwise false
 */
bool Cowboy::hasboolets() const {
    return bullets>0;
}

/**
 * reload cowboy gun with 6 bullet
 */
void Cowboy::reload() {
    if (!isAlive()){
        throw runtime_error("the cowboy are dead");
    }
    this->bullets=6;
}

/**
 * Print the values of the cowboy
 * @return string to print
 */
std::string Cowboy::print() {
    string print="";
    print="C "+ Character::print();
    return print;
}