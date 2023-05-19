#include "YoungNinja.hpp"

using namespace ariel;

/**
 * Constructor for YoungNinja
 * @param name YoungNinja name
 * @param location YoungNinja location
 */
YoungNinja::YoungNinja(std::string name, const Point &location) : Ninja(name,location,100,14) {}