#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"
#include <iostream>
#include <string>

using namespace std;

namespace ariel {
    class Ninja : public Character{
    public:
        Ninja (std::string name, const Point &location, int hitpoint , int speed);
        void move(const Character *enemy);
        void slash(Character *enemy)const;
        std::string print() override;

    private:
        int speed;
    };
}
#endif //NINJA_HPP