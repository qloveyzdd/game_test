#pragma once
#include "Monster.h"

class Witch : public Monster
{
private:
    int m_distancedamage;
    int m_maxmp;
    int m_curmp;

public:
    Witch(int id)
        : Monster(5, WITCH, id), m_distancedamage(27), m_maxmp(100), m_curmp(m_maxmp)
    {
    }
    ~Witch(){};

    void CloseAttack(Creature &one) { one.BeDamaged(m_basedamage + ReturnRandom()); }

    void DistanceAttack(Creature &a) { a.BeDamaged(m_distancedamage + ReturnRandom()); }

    bool DistanceMagic(Creature &a);
    bool DistanceMagic(Creature &a, Creature &b);
    bool DistanceMagic(Creature &a, Creature &b, Creature &c);
};
