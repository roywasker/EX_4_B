#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"
#include <istream>
#include <string>


using namespace std;

namespace ariel {
    class Cowboy : public Character{
    public:
        Cowboy(std::string name, const Point &location);
        void shoot(Character *enemy);
        bool hasboolets() const;
        void reload();
        std::string print() override;

    private:
        int bullets;
    };
}

#endif //COWBOY_HPP
