#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP

#include "Character.hpp"
#include "Team.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace ariel {
    class SmartTeam :public Team{
    public:
        SmartTeam(Character *captain);
        void attack(Team *enemyteam) override;
        void print() override;
        Character* chooseEnemy(Team *enemyteam)const;
        Character* selectEnemyByDistance(Team *enemyteam,Character * warriors) const;
    };
}

#endif //SMARTTEAM_HPP
