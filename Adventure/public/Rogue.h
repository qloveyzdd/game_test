#pragma once

#include "Adventure.h"

class Rogue : public Adventure
{
private:
    int m_distancedamage;

public:
    Rogue(std::string name, int age, int id)
        : Adventure(23, name, age, Rogues, id),m_distancedamage(17)
    {
    }
    ~Rogue(){};

    void CloseAttack(Creature&one);//盗贼近距离攻击可回血
    void DistanceAttackNoMp(Creature&one);//远距离攻击不耗费蓝
};
