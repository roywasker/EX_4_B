#include "TrainedNinja.hpp"

using namespace ariel;

/**
 * Constructor for TrainedNinja
 * @param name TrainedNinja name
 * @param location TrainedNinja location
 */
TrainedNinja::TrainedNinja(std::string name, const Point &location) : Ninja(name,location,120,12) {}