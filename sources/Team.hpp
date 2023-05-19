#ifndef TEAM_HPP
#define TEAM_HPP

#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"

#include <iostream>
#include <string>
#include <array>

using namespace std;
namespace ariel {
    const int maxCharacter = 10;
    class Team{
    public:
        Team(Character *captain);
        virtual ~Team();
        Team(const Team &other)=default;
        Team & operator=(const Team &other);
        Team(Team &&) = default;
        Team &operator=(Team &&) = default;
        void add(Character *character);
        virtual void attack(Team *enemyteam);
        void newcaptain();
        Character* selectenemy(Team *enemyteam) const;
        int stillAlive();
        unsigned int getnumOfWarriors();
        Character& getCaptain();
        std::array<Character*, maxCharacter>& getWarriors();
        virtual void print();

    private:
        Character *captain;
        array<Character*, maxCharacter> warriors;
        unsigned int numOfWarriors;
    };
}

#endif //TEAM_HPP
