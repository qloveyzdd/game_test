#pragma once
#include "Monster.h"

class Mummy : public Monster
{
public:
    Mummy(int id)
        : Monster(25, MUMMY, id)
    {
    }
    ~Mummy(){};

    void CloseAttack(Creature &one);

};
