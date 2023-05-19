#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include "Point.hpp"

using namespace std;

const int defulthitpoint = 100;

namespace ariel {
    class Character{
    public:
        Character(const Point&location = Point(2,2), std::string name = "gust", int hitpoint =defulthitpoint );
        virtual ~Character() = default;
        Character(const Character &other);
        Character(Character &&) = default;
        Character &operator=(Character &&) = default;
        Character & operator = (const Character &other);
        bool isAlive() const;
        double distance(const Character *other) const;
        void hit(int hitpoint);
        std::string getName() const;
        Point getLocation() const;
        void setLocation(Point location);
        void setinteam(bool inteam);
        bool getinteam() const;
        int gethitpoint() const;
        virtual std::string print();

    private:
        Point location;
        int hitpoint;
        std::string name;
        bool inTeam;
    };
}

#endif //CHARACTER_HPP
