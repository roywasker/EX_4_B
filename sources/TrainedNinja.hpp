#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP

#include "Ninja.hpp"
#include <iostream>
#include <string>

using namespace std;

namespace ariel {
    class TrainedNinja : public Ninja{
    public:
        TrainedNinja(std::string name, const Point &location);
    };
}

#endif //TRAINEDNINJA_HPP