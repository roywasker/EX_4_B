#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Character.hpp"
#include "Team.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace ariel {
    class Team2 :public Team{
    public:
        Team2(Character *captain);
        void attack(Team *enemyteam) override;
        void print() override;
    };
}
#endif //TEAM2_HPP
