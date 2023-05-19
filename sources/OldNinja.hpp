#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP

#include "Ninja.hpp"
#include <iostream>
#include <string>

using namespace std;

namespace ariel {
    class OldNinja : public Ninja{
    public:
        OldNinja (std::string name, const Point &location);
    };
}
#endif //OLDNINJA_HPP
