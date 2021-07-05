#pragma once
#include"Monster.h"

class Tiger :public Monster
{
public:
    Tiger(int id)
    :Monster(20,TIGER,id)
    {}
    ~Tiger(){};

    void CloseAttack(Creature&one){one.BeDamaged(m_basedamage + ReturnRandom());}
};
