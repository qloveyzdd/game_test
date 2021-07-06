#pragma once
#include "Monster.h"


class Dragon : public Monster
{
private:
    int m_distancedamage;
    bool usedKS;

public:
    Dragon(int id)
        : Monster(18, DRAGON, id), m_distancedamage(22), usedKS(false)
    {
    }
    ~Dragon(){};

    void CloseAttack(Creature &one) { one.BeDamaged(m_basedamage + ReturnRandom()); }

    void DistanceAttack(Creature &a) { a.BeDamaged(m_distancedamage + ReturnRandom()); }

    void KillSKY(std::vector<Adventure*>&all);

    bool IsUsedKS()const {return usedKS;}
};
