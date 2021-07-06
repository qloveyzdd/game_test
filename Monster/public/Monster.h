#pragma once
#include <vector>
#include "Adventure.h"

enum MonsterType
{
    TIGER,
    EAGLE,
    WITCH,
    MUMMY,
    DRAGON,
};

class Monster : public Creature
{
private:
    MonsterType m_type;

public:
    Monster(int basedamage, MonsterType type, int id);
    virtual ~Monster(){};

    virtual void CloseAttack(Creature &one) = 0;
    virtual void DistanceAttackNoMp(Creature &a){};
    virtual bool DistanceMagic(Creature &a) { return false; }
    virtual bool DistanceMagic(Creature &a, Creature &b) { return false; }
    virtual bool DistanceMagic(Creature &a, Creature &b, Creature &c) { return false; }
    virtual void KillSky(std::vector<Adventure *> &all) {}
    virtual bool IsUsedKS() const { return false; }

    MonsterType ReturnType() const { return m_type; }
    void AddHp(int delta);
};
