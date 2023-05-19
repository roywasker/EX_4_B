#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP

#include "Ninja.hpp"
#include <iostream>
#include <string>

using namespace std;

namespace ariel {
    class YoungNinja : public Ninja{
    public:
        YoungNinja(std::string name, const Point &location);
    };
}
#endif //YOUNGNINJA_HPP
