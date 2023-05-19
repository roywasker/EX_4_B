#include "Character.hpp"

using namespace ariel;


/**
 * Constructor for Character
 * @param location Character location
 * @param hitpoint Character hitpoint
 * @param name Character name
 */
Character::Character(const Point&location, std::string name, int hitpoint ): location(location) , name(name) , hitpoint(hitpoint) , inTeam(
        false){}

/**
 * Copy Constructor
 * @param other Character to Copy
 */
Character::Character(const Character &other) {
    this->location=other.getLocation();
    this->name=other.getName();
    this->hitpoint=other.gethitpoint();
}

/**
 * assignment operator
 * @param other Character to assignment
 * @return new Character
 */
Character &Character::operator=(const Character &other){
    if (this == &other) {
        return *this;
    }
    this->location=other.getLocation();
    this->name=other.getName();
    this->hitpoint=other.gethitpoint();
    return *this;
}

/**
 * Check if  Character is alive
 * @return return ture if he alive , otherwise false
 */
bool Character::isAlive() const {
    return this->hitpoint>0;
}

/**
 * Calculation of distance between 2 Character
 * @param other location of second Character
 * @return return the distance
 */
double Character::distance(const Character *other) const {
    return this->location.distance(other->getLocation());
}

/**
 * Subtracts the hit points from the character
 * @param hitpoint how much hit point to subtracts
 */
void Character::hit(int hitpoint) {
    if (hitpoint<0){
        throw invalid_argument("can hit negative value\n");
    }
    this->hitpoint-=hitpoint;
}

/**
 * return Character name
 * @return Character name
 */
std::string Character::getName() const {
    return this->name;
}

/**
 * return Character hit point
 * @return Character hit point
 */
int Character::gethitpoint() const {
    return this->hitpoint;
}

/**
 * return Character location
 * @return Character location
 */
Point Character::getLocation() const {
    return this->location;
}

/**
 * set location for Character
 */
void Character::setLocation(ariel::Point location) {
    this->location=location;
}

/**
 * set in team for Character
 * @param inteam
 */
void Character::setinteam(bool inteam) {
    this->inTeam=inteam;
}

/**
 * return if Character is in team
 * @return if Character is in team
 */
bool Character::getinteam() const {return this->inTeam;}

/**
 * Print the values of the Character
 * @return return the values of the Character
 */
std::string Character::print() {
    string print="";
    if (this->isAlive()){
        print=""+ this->name+" health "+ to_string(this->hitpoint)+" location "+ this->location.print();
    } else{
        print="("+ this->name+") location "+ this->location.print();
    }
    return print;
}
