#pragma once
#include "Monster.h"

class Eagle : public Monster
{
private:
    int m_distancedamage;

public:
    Eagle(int id)
        : Monster(15, EAGLE, id), m_distancedamage(20)
    {
    }
    ~Eagle(){};

    void CloseAttack(Creature &one) { one.BeDamaged(m_basedamage + ReturnRandom()); }

    void DistanceAttack(Creature &a) { a.BeDamaged(m_distancedamage + ReturnRandom()); }
};
