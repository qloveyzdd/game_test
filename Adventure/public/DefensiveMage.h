#pragma once
#include "Adventure.h"

class DefensiveMage : public Adventure
{
private:
    int m_gain;
    int m_maxmp;
    int m_curmp;

public:
    DefensiveMage(std::string name, int age, int id)
        : Adventure(7, name, age, DefensiveMages, id), m_gain(24), m_maxmp(100), m_curmp(m_maxmp)
    {
    }
    ~DefensiveMage(){};

    void CloseAttack(Creature&a);//近战伤害
    void DistanceAttackNoMp(Creature&a);//远程伤害
    bool DistanceMagic(Creature&a);//魔法攻击
    bool DistanceMagic(Creature&a,Creature&b);
    bool DistanceMagic(Creature&a,Creature&b,Creature&c);
    void MpRestore(){m_curmp = m_maxmp;};
};

