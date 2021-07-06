#pragma once

#include "Adventure.h"

class Warrior : public Adventure
{
public:
    Warrior(std::string name, int age, int id)
        : Adventure(23, name, age, Warriors, id)
    {
    }
    ~Warrior(){};

    void CloseAttack(Creature &one) { one.BeDamaged(m_basedamage + ReturnRandom()); }
};
