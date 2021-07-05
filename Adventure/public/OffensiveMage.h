#pragma once
#include "Adventure.h"

class OffensiveMage : public Adventure
{
private:
    int m_distancedamage;
    int m_maxmp;
    int m_curmp;

public:
    OffensiveMage(std::string name, int age, int id)
        : Adventure(7, name, age, OffensiveMages, id), m_distancedamage(27)
    {
    }
    ~OffensiveMage(){};

    void CloseAttack(Creature&a);//近战伤害
    void DistanceAttackNoMp(Creature&a);//远程伤害
    bool DistanceMagic(Creature&a);//魔法攻击
    bool DistanceMagic(Creature&a,Creature&b);
    bool DistanceMagic(Creature&a,Creature&b,Creature&c);
    void MpRestore(){m_curmp = m_maxmp;};
};
